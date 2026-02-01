#include <stdlib.h>


void        free_lines(char **lines, int n)
{
        int        i;


        i = 0;
        while (i < n)
        {
                free(lines[i]);
                i++;
        }
        free(lines);
}