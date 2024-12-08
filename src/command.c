#include "brainfuck.h"
#include <stdio.h>
#include <stdlib.h>

return_code_t process_command(brainfuck_t *interpreter, char command)
{
    switch (command) {
        case '>':
            if (interpreter->pointer >= interpreter->memory + interpreter->memory_size - 1) {
                fprintf(stderr, "Memory out of bounds.\n");
                return (ERROR);
            }
            interpreter->pointer++;
            break;
        case '<':
            if (interpreter->pointer <= interpreter->memory) {
                fprintf(stderr, "Memory out of bounds.\n");
                return (ERROR);
            }
            interpreter->pointer--;
            break;
        case '+':
            (*interpreter->pointer)++;
            break;
        case '-':
            (*interpreter->pointer)--;
            break;
        case '.':
            putchar((*interpreter->pointer >= 32 && *interpreter->pointer <= 126) ? *interpreter->pointer : '?');
            break;
        case ',':
            *interpreter->pointer = getchar();
            break;
        case '^':
            if (*interpreter->pointer >= 'a' && *interpreter->pointer <= 'z')
                *interpreter->pointer -= 32;
            break;
        case '_':
            if (*interpreter->pointer >= 'A' && *interpreter->pointer <= 'Z')
                *interpreter->pointer += 32;
            break;
        case '@':
            *interpreter->pointer = 0;
            break;
        case '~':
            *interpreter->pointer = ~(*interpreter->pointer);
            break;
        case '#':
            printf("%d", *interpreter->pointer);
            break;
        case ':':
            if (interpreter->register_value == 0) {
                interpreter->register_value = *interpreter->pointer;
            } else {
                unsigned char temp = *interpreter->pointer;
                *interpreter->pointer = interpreter->register_value;
                interpreter->register_value = temp;
            }
            break;
        case '?':
            *interpreter->pointer = rand() % 256;
            break;
        case ';':
            while (*interpreter->pointer != 0) {
                putchar((*interpreter->pointer >= 32 && *interpreter->pointer <= 126) ? *interpreter->pointer : '?');
                interpreter->pointer++;
            }
            break;
        case '|':
            if (*interpreter->pointer + 97 < 123)
                *interpreter->pointer = *interpreter->pointer + 123 - 26;
            break;
        case '!':
            return (EXIT);
        default:
            break;
    }
    return (SUCCESS);
}