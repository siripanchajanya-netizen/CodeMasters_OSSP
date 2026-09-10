#include <stdio.h>
#include <unistd.h>

int main()
{
    int pipefd[2];
    int data = 10;

    pipe(pipefd);

    if(fork() == 0)
    {
        read(pipefd[0], &data, sizeof(data));
        printf("Child consumed %d", data);
    }
    else
    {
        printf("Parent generated %d\n", data);
        write(pipefd[1], &data, sizeof(data));
    }
}
