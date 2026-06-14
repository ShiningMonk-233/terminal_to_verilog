#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int fd = open("test.fifo",O_RDONLY);
    char buf[100];
    int n = read(fd,buf,sizeof(buf));
    write(1, buf, n); // write to stdout
    close(fd);
    return 0;
}