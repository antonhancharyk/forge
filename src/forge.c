#include <stdio.h>
#include <string.h>

#include "file.h"

void run_forge(const char *template_name, const char *output_name, char *vars[], int var_count)
{
    char template_path[256];
    snprintf(template_path, sizeof(template_path), "templates/%s.tpl", template_name);

    get_template_path(template_name, template_path, sizeof(template_path));

    if (create_file_from_template(template_path, output_name, vars, var_count) == 0)
    {
        printf("Created file: %s\n", output_name);
    }
}
