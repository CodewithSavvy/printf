#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - function my printf
 * @format: string with format to print
 * Return: number of chars that print
 */

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;
    char c;

    while ((c = *format++) != '\0') {
        if (c == '%') {
            c = *format++;
            if (c == 'c') {
                int arg = va_arg(args, int);
                putchar(arg);
                count++;
            } else if (c == 's') {
                char *arg = va_arg(args, char *);
                while (*arg != '\0') {
                    putchar(*arg++);
                    count++;
                }
            } else if (c == '%') {
                putchar('%');
                count++;
            } else {
                
            }
        } else {
            putchar(c);
            count++;
        }
    }

    va_end(args);

    return count;
}

