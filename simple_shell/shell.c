#include "shell.h"

int main(void){

    char command[1024];

    /*afficher prompt*/
    while (true)
    {
        afficher_prompt();
        lire_commande(command, sizeof(command));
        run_commande(command);
    }
    return 0;
}