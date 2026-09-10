#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pid;

    pid = fork();

    if (pid == 0)
    {
        printf("Child process\n");
        execlp("ls", "ls", NULL);
    }
    else
    {
        wait(NULL);
        printf("Parent process\n");
    }
}
