#include "shell.h"

void lire_commande(char *command, size_t size){
    
    if (fgets(command, size, stdin) ==  NULL)
    {
        if (feof(stdin))
        {
            my_printer("\nFin de l'entrée.\n");
            exit(EXIT_SUCCESS);
        } else
        {
             perror("fgets");
             exit(EXIT_FAILURE);
        }  
    }    
    command[strcspn(command, "\n")] = '\0';
}
