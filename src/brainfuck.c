#include "brainfuck.h"
#include "util.h"
#include "command.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static brainfuck_t *init_interpreter(size_t memory_size, const char *program_file)
{
    brainfuck_t *interpreter = malloc(sizeof(brainfuck_t));

    if (!interpreter) {
        fprintf(stderr, "Failed to allocate memory for interpreter.\n");
        return (NULL);
    }
    interpreter->memory = calloc(memory_size, sizeof(unsigned char));
    if (!interpreter->memory) {
        fprintf(stderr, "Failed to allocate memory table.\n");
        free(interpreter);
        return (NULL);
    }
    interpreter->pointer = interpreter->memory;
    interpreter->register_value = 0;
    interpreter->memory_size = memory_size;
    interpreter->program = load_program(program_file);
    if (!interpreter->program) {
        free(interpreter->memory);
        free(interpreter);
        return (NULL);
    }
    interpreter->program_counter = 0;
    interpreter->program_length = strlen(interpreter->program);
    return (interpreter);
}

static void free_interpreter(brainfuck_t *interpreter)
{
    free(interpreter->memory);
    free(interpreter->program);
    free(interpreter);
}

int interpret_brainfuck(const char *file_name)
{
    brainfuck_t *interpreter = init_interpreter(MEMORY_SIZE, file_name);

    if (!interpreter)
        return (ERROR);
    while (interpreter->program_counter < interpreter->program_length) {
        char command = interpreter->program[interpreter->program_counter];
        const return_code_t result = process_command(interpreter, command);
        if (result == ERROR || result == EXIT) {
            free_interpreter(interpreter);
            return (result == ERROR ? ERROR : SUCCESS);
        }
        interpreter->program_counter++;
    }
    free_interpreter(interpreter);
    return (SUCCESS);
}
