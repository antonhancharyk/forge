#include <stdio.h>
#include <string.h>

#include "forge.h"
#include "file.h"

void run_forge(const char *template_name, const char *output_name) {
    char template_path[256];
    snprintf(template_path, sizeof(template_path), "templates/%s.tpl", template_name);

    if (create_file_from_template(template_path, output_name) == 0) {
        printf("Created file: %s\n", output_name);
    }
}
