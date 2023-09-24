#include "shell.h"

void my_printer(const char *str){
    write(1, str, strlen(str));
}