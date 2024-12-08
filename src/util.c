#include <stdio.h>
#include <stdlib.h>

char *load_program(const char *file_name)
{
    FILE *file = fopen(file_name, "r");
    size_t file_size = 0;
    char *program_content = NULL;

    if (file == NULL) {
        fprintf(stderr, "Failed to open file: %s\n", file_name);
        return (NULL);
    }
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);
    program_content = malloc(file_size + 1);
    if (program_content == NULL) {
        fprintf(stderr, "Failed to allocate memory.\n");
        fclose(file);
        return (NULL);
    }
    fread(program_content, 1, file_size, file);
    fclose(file);
    program_content[file_size] = '\0';
    return (program_content);
}
