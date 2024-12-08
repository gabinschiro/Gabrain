#ifndef COMMAND_H
    #define COMMAND_H

typedef enum return_code_e return_code_t;
typedef struct brainfuck_s brainfuck_t;

return_code_t process_command(brainfuck_t *interpreter, char command);

#endif
