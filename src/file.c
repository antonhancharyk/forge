#include <stdio.h>

#include "file.h"

int create_file_from_template(const char *template_path, const char *output_path) {
    FILE *template = fopen(template_path, "r");
    if (!template) {
        perror("Error opening template");
        return 1;
    }

    FILE *output = fopen(output_path, "w");
    if (!output) {
        perror("Error creating output file");
        fclose(template);
        return 1;
    }

    int ch;
    while ((ch = fgetc(template)) != EOF) {
        fputc(ch, output);
    }

    fclose(template);
    fclose(output);
    return 0;
}
