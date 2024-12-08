#ifndef BRAINFUCK_H
    #define BRAINFUCK_H

typedef enum return_code_e {
    EXIT,
    ERROR,
    SUCCESS
} return_code_t;

int interpret_brainfuck(const char *file_name);

#endif
