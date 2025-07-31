#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

const char *get_template_path(const char *template_name, char *buffer, size_t size)
{
    const char *env = getenv("FORGE_TEMPLATES");
    if (env)
    {
        snprintf(buffer, size, "%s/%s.tpl", env, template_name);
        return buffer;
    }

    const char *home = getenv("HOME");
    if (home)
    {
        snprintf(buffer, size, "%s/.forge/templates/%s.tpl", home, template_name);
        if (access(buffer, R_OK) == 0)
            return buffer;
    }

    snprintf(buffer, size, "/usr/local/share/forge/templates/%s.tpl", template_name);
    return buffer;
}
