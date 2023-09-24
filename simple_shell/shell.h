#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

char *find_executable(const char *command);

void my_printer(const char *str);
void afficher_prompt(void);
void lire_commande(char *command, size_t size);
void run_commande(const char *command);

#endif