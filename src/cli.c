#include <stdio.h>
#include <string.h>

#include "cli.h"
#include "forge.h"

void parse_args(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: forge <template> <output>\n");
        return;
    }
    
    run_forge(argv[1], argv[2]);
}
