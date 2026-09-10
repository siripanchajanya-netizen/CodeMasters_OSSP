#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    char msg[50];

    mkfifo("fifo", 0666);

    if (fork() == 0) {
        // Client
        int fd = open("fifo", O_WRONLY);
        printf("Client: Hello Server\n");
        write(fd, "Hello Server", 13);
        close(fd);
    } 
    else {
        // Server
        int fd = open("fifo", O_RDONLY);
        read(fd, msg, 50);
        printf("Server received: %s\n", msg);
        close(fd);
        unlink("fifo");
    }

    return 0;
}
