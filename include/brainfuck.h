#ifndef BRAINFUCK_H
    #define BRAINFUCK_H
    #define MEMORY_SIZE 30000

typedef __SIZE_TYPE__ size_t;

typedef enum return_code_e {
    EXIT,
    ERROR,
    SUCCESS
} return_code_t;

typedef struct brainfuck_s {
    unsigned char *memory;
    unsigned char *pointer;
    unsigned char register_value;
    size_t memory_size;
    char *program;
    size_t program_counter;
    size_t program_length;
} brainfuck_t;

int interpret_brainfuck(const char *file_name);

#endif
