#include <stdio.h>
#include <string.h>

#include "forge.h"

void parse_args(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: forge <template> <output> <arguments (key=value)>\n");
        return;
    }

    int var_count = argc - 3;

    char **vars = NULL;
    if (var_count > 0)
    {
        vars = &argv[3];
    }

    run_forge(argv[1], argv[2], vars, var_count);
}
