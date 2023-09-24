#include "shell.h"

char *find_executable(const char *command) {
    char *path = getenv("PATH");
    char *token = strtok(path, ":");

    while (token != NULL) {
        char *executable_path = malloc(strlen(token) + strlen(command) + 2); /* +2 pour / et \0*/
        sprintf(executable_path, "%s/%s", token, command);

        if (access(executable_path, X_OK) != -1) {
            return executable_path;
        }

        free(executable_path);
        token = strtok(NULL, ":");
    }

    return NULL;
}