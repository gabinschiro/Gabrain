#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int interpret_char(unsigned char **current, const char c,
    unsigned char *memory_table, const size_t memory_size)
{
    switch (c) {
        case '>':
            if (*current >= memory_table + memory_size) {
                fprintf(stderr, "Memory out of bounds.\n");
                return (1);
            }
            (*current)++;
            break;
        case '<':
            if (*current <= memory_table) {
                fprintf(stderr, "Memory out of bounds.\n");
                return (1);
            }
            (*current)--;
            break;
        case '+':
            (**current)++;
            break;
        case '-':
            (**current)--;
            break;
        case '.':
            if (**current >= 32 && **current <= 126)
                putchar(**current);
            break;
        case ',':
            **current = getchar();
            break;
        case '^':
            if (**current >= 'a' && **current <= 'z')
                **current -= 32;
            break;
        case '_':
            if (**current >= 'A' && **current <= 'Z')
                **current += 32;
            break;
        default:
            break;
    }
    return (0);
}

int interpret_brainfuck(const char *file_name)
{
    const size_t memory_size = 30000;
    unsigned char *memory_table = calloc(memory_size, sizeof(unsigned char));
    char *program = NULL;
    unsigned char *current;
    size_t program_counter = 0;
    size_t program_length;

    if (memory_table == NULL) {
        fprintf(stderr, "Failed to allocate memory.\n");
        return (1);
    }
    current = memory_table;
    program = load_program(file_name);
    if (program == NULL) {
        fprintf(stderr, "Failed to load program.\n");
        free(memory_table);
        return (1);
    }
    program_length = strlen(program);
    while (program_counter < program_length) {
        if (interpret_char(&current, program[program_counter], memory_table, memory_size)) {
            free(memory_table);
            free(program);
            return (1);
        }
        program_counter++;
    }
    free(memory_table);
    free(program);
    return (0);
}
