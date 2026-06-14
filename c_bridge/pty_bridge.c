#define _XOPEN_SOURCE 600
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    int master_fd = posix_openpt(O_RDWR | O_NOCTTY);
    if (master_fd < 0) { perror("posix_openpt"); return 1; }

    grantpt(master_fd);
    unlockpt(master_fd);

    printf("Connect using: screen %s\n", ptsname(master_fd));
    fflush(stdout);

    int fd = open("test.fifo", O_WRONLY);
    if (fd < 0) { perror("posix_openpt"); return 1; }
    char buf[1];
    while(1){
        int n = read(master_fd,buf,1);
        if (n <= 0) break; // EOF or error
        printf("recieved: %c\n", buf[0]);
        write(fd, buf, 1);
        printf("sent: %c\n", buf[0]);
        fflush(stdout);
    }
    return 0;
}