#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
    pid_t pid;
    int status;
    pid=fork();
    if(pid<0)
    {
        printf("Error. fork() failed");
        return 1;
    }
    else if(pid==0)
    {
        printf("This is Child Process with PID : %d\n",getppid());
        execlp("/bin/ls","ls",NULL);
        printf("This should not be printed if exec() is successful.\n");
        return 0;
    }
    else
    {
        printf("Parent Process with PID %d.\n",getpid());
        printf("Child process PID:%d\n",pid);
        wait(&status);
        printf("Child process exited with status %d\n",status);
        return 0;
    }   
}

