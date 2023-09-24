#include <unistd.h>
#include "shell.h"

void run_commande(const char *command){
    pid_t pid = fork();

    if(pid < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
        
    }
    else if (pid == 0)
    {
        execlp(command, command, (char *)NULL);
        perror("exec");
        exit(EXIT_FAILURE);
    }
    else
    {
        int status;
        waitpid(pid, &status,0);
        
    }
}