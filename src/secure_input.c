#include <stdio.h>
#include <string.h>

void flush_input(void)
{
    char c;
    while ( (c = getchar() != '\n') && c != EOF);
}

char* secure_input(char *const restrict buffer, int const size)
{
    char* data;

    data = fgets(buffer, size, stdin);

    if (data != NULL)
    {
        size_t const pos_last_char_in_str = strlen(buffer) -1;

        if (buffer[pos_last_char_in_str] == '\n')
        {
            buffer[pos_last_char_in_str] = '\0';
        }
        else
        {
            fscanf(stdin, "%*[^\n]");
            fgetc(stdin);
        }
    }

    return data;
}