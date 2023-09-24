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
        char *args[100];
        int i = 0;
        /*char copy_command[1024];*/

        /*strncpy(copy_command, command, sizeof(copy_command));*/

        char *token = strtok((char *)command, " ");

        while (token != NULL)
        {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;
        execvp(args[0], args);
        perror("exec");
        exit(EXIT_FAILURE);
    }
    else
    {
        int status;
        waitpid(pid, &status,0);
        
    }
}