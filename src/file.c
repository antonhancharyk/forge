#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "template.h"

int create_file_from_template(const char *template_path, const char *output_path, char *vars[], int var_count)
{
    FILE *template = fopen(template_path, "r");
    if (!template)
    {
        perror("Error opening template");
        return 1;
    }

    fseek(template, 0, SEEK_END);
    long length = ftell(template);
    fseek(template, 0, SEEK_SET);

    char *buffer = malloc(length + 1);
    fread(buffer, 1, length, template);
    buffer[length] = '\0';
    fclose(template);

    char *rendered = buffer;
    for (int i = 0; i < var_count; i++)
    {
        char *eq = strchr(vars[i], '=');
        if (!eq)
            continue;
        *eq = '\0';
        const char *key = vars[i];
        const char *value = eq + 1;

        char *new_rendered = render_template(rendered, key, value);
        if (rendered != buffer)
            free(rendered);
        rendered = new_rendered;
    }

    FILE *output = fopen(output_path, "w");
    if (!output)
    {
        perror("Error creating output file");
        free(rendered);
        return 1;
    }

    fputs(rendered, output);
    fclose(output);
    free(rendered);

    return 0;
}
