#include "brainfuck.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(const int argc, char **argv)
{
    char *filename;

    srand(time(NULL));
    if (argc < 2) {
        printf("Usage: %s <brainfuck_script.bf>\n", argv[0]);
        return (1);
    }
    filename = argv[1];
    if (!interpret_brainfuck(filename)) {
        printf("Error interpreting Brainfuck script.\n");
        return (1);
    }
    return (0);
}
