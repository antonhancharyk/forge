#include <stdio.h>
#include <string.h>

#include "file.h"
#include "utils.h"

void run_forge(const char *template_name, const char *output_name, char *vars[], int var_count)
{
    char template_path[256];
    get_template_path(template_name, template_path, sizeof(template_path));

    if (create_file_from_template(template_path, output_name, vars, var_count) == 0)
    {
        printf("Created file: %s\n", output_name);
    }
}
