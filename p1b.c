#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    pid_t pid;
    pid = vfork();
    if (pid == 1)
    {
        perror("vfork");
        return 1;
    }
    else if (pid == 0)
    {
        printf("Child Process: Hello, I'm the child\n");
        printf("Child Process: My PID is %d\n", getpid());
        printf("Child Process: My Parents PID is %d\n", getppid());
        _exit(0);
    }
    else
    {
        printf("Parent Process: Hello, I'm the Parent\n");
        printf("Parent Process: My PID is %d\n", getpid());
        printf("Parent Process: My child's PID is %d\n", pid);

        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status))
        {
            printf("Parent Process: Child Process terminated normally\n");
        }
        else
        {
            printf("Parent Process: Child Process Terminated abnormally\n");
        }
    }
    return 0;
}
