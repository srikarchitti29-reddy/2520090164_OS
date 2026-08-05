#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid == 0) {
        printf("Child Process ID: %d\n", getpid());

        execl("/bin/ls", "ls", "-l", NULL);

        printf("Command execution failed\n");
    }
    else {
        wait(NULL);
        printf("Parent Process ID: %d\n", getpid());
        printf("Child process completed.\n");
    }

    return 0;
}
