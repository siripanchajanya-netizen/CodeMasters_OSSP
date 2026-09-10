#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int pid[3];

    for(int i=0; i<3; i++)
    {
        pid[i] = fork();

        if(pid[i] == 0)
        {
            printf("Child %d\n", i+1);
            sleep(i+1);
            exit(0);
        }
    }

    wait(NULL);
    printf("Parent: one child is completed with wait()\n");

    waitpid(pid[2], NULL, 0);
    printf("Parent: child 3 has completed with waitpid()\n");

    wait(NULL);
    printf("Parent: all the children are completed\n");

    return 0;
}
