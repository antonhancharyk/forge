#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *render_template(const char *template_content, const char *key, const char *value)
{
    const char *pattern_format = "{{%s}}";
    size_t pattern_len = strlen(key) + 4;
    char *pattern = malloc(pattern_len + 1);
    snprintf(pattern, pattern_len + 1, pattern_format, key);

    size_t result_size = strlen(template_content) + 1;
    const char *p = template_content;

    for (int i = 0; i < 10; i++)
    {
        const char *match = strstr(p, pattern);
        if (!match)
            break;
        result_size += strlen(value) - strlen(pattern);
        p = match + strlen(pattern);
    }

    char *result = malloc(result_size);
    result[0] = '\0';

    p = template_content;
    while ((p = strstr(p, pattern)) != NULL)
    {
        strncat(result, template_content, p - template_content);
        strcat(result, value);
        template_content = p + strlen(pattern);
        p = template_content;
    }
    strcat(result, template_content);

    free(pattern);
    return result;
}
