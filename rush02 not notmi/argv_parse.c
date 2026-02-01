#include <unistd.h>


static int        is_digits(char *s)
{
        int        i;


        if (!s || s[0] == '\0')
                return (0);
        i = 0;
        while (s[i])
        {
                if (s[i] < '0' || s[i] > '9')
                        return (0);
                i++;
        }
        return (1);
}


static char        *skip_zeros(char *s)
{
        while (s[0] == '0' && s[1] != '\0')
                s++;
        return (s);
}


int        parse_args(int argc, char **argv, char **dict_path, char **num)
{
        if (argc == 2)
        {
                *dict_path = "./numbers.dict";
                *num = argv[1];
        }
        else if (argc == 3)
        {
                *dict_path = argv[1];
                *num = argv[2];
        }
        else
                return (-1);
        if (!is_digits(*num))
                return (-1);
        *num = skip_zeros(*num);
        return (1);
}