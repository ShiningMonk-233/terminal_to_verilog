#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int fd = open("test.fifo",O_WRONLY);
    write(fd,"hello",5); // write to fifo
    close(fd);
    return 0;
}