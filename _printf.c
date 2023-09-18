#include <stdarg.h>
#include <stdio.h>
#include <main.h>

int _printf(const char *format, ...) {
    va_list args;
    const char *ptr = format;
    int count = 0;

    va_start(args, format);

    while (*ptr != '\0') {
        if (*ptr == '%') {
            ptr++; // Move past '%'
            if (*ptr == 'c') {
                int c = va_arg(args, int);
                putchar(c);
                count++;
            } else if (*ptr == 's') {
                const char *s = va_arg(args, const char *);
                while (*s != '\0') {
                    putchar(*s);
                    s++;
                    count++;
                }
            } else if (*ptr == '%') {
                putchar('%');
                count++;
            }
        } else {
            putchar(*ptr);
            count++;
        }
        ptr++;
    }

    va_end(args);

    return count;
}
