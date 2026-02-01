#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


int        file_size(char *file_path)
{
        int        fd;
        char        tmp[1024];
        int        bytes;
        int        total;


        fd = open(file_path, O_RDONLY);
        if (fd == -1)
                return (-1);
        total = 0;
        while ((bytes = read(fd, tmp, 1024)) > 0)
                total += bytes;
        close(fd);
        return (total);
}


static int        copy_file(char *file_path, char *buffer, int size)
{
        int        fd;


        fd = open(file_path, O_RDONLY);
        if (fd == -1)
                return (-1);
        if (read(fd, buffer, size) < 0)
                return (close(fd), -1);
        buffer[size] = '\0';
        close(fd);
        return (1);
}


static int        count_lines(char *file)
{
        int        i;
        int        counter;


        i = 0;
        counter = 0;
        while (file[i])
        {
                if (file[i] == '\n')
                        counter++;
                i++;
        }
        return (counter);
}


static void        alloc_lines(char **m, char *file, int lines)
{
        int        i;
        int        j;
        int        len;


        i = 0;
        j = 0;
        while (i < lines)
        {
                len = 0;
                while (file[j + len] != '\n' && file[j + len] != '\0')
                        len++;
                m[i] = (char *)malloc(len + 1);
                j += len + 1;
                i++;
        }
}


static void        fill_lines(char **m, char *file, int lines)
{
        int        i;
        int        j;
        int        len;


        i = 0;
        j = 0;
        while (i < lines)
        {
                len = 0;
                while (file[j + len] != '\n' && file[j + len] != '\0')
                {
                        m[i][len] = file[j + len];
                        len++;
                }
                m[i][len] = '\0';
                j += len + 1;
                i++;
        }
}


char        **load_lines(char *dict_path, int *out_lines)
{
        char        *file;
        char        **m;
        int                size;
        int                lines;


        size = file_size(dict_path);
        if (size < 0)
                return (NULL);
        file = (char *)malloc(size + 1);
        if (!file)
                return (NULL);
        if (copy_file(dict_path, file, size) < 0)
                return (free(file), NULL);
        lines = count_lines(file);
        m = (char **)malloc(sizeof(char *) * lines);
        if (!m)
                return (free(file), NULL);
        alloc_lines(m, file, lines);
        fill_lines(m, file, lines);
        free(file);
        *out_lines = lines;
        return (m);
}