#define PATH "./numbers.dict"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	file_size(char *file_path)
{
	int	fd; // file descriptor
	char	tmp[1024];
	int	bytes;
	int	total;
	
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Error opening file", 18);
		return 1;
	}
	total = 0;
	while ((bytes = read(fd, tmp, 1024)) > 0) // till there's bytes not read, offset at the end
		total += bytes;
	close(fd);
	return (total);
}

void	copy_file(char *file_path, char *buffer, int file_size)
{
	int	fd;
	
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Error opening file", 18);
		return ;
	}
	read(fd, buffer, file_size);
	buffer[file_size + 1] = '\0';
	close(fd);
}

int	count_lines(char *file)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while(file[i])
	{
		if (file[i] == '\n')
			counter++;
		i++;
	}
	printf("number of lines: %d\n", counter);
	return (counter);
}

int	main(void)
{
	char	*file;
	char	**lines_matrix;
	int	size;
	int	lines;

	size = file_size(PATH);   
	file = (char *) malloc ((size + 1) * sizeof(char));
	copy_file(PATH, file, size);
	printf("%s", file);
	printf("--------------------------------------------------------------\n");
	
	lines = count_lines(file);

	lines_matrix = (char **) malloc (lines * sizeof(char *));

	int	i;
	int	j;
	int	line_len;
	
	// allocates memory for the strings in tha matrix
	i = 0;
	j = 0;
	line_len = 0;
	while (i < lines)
	{
	    line_len = 0;
	    while (file[j + line_len] != '\n' && file[j + line_len] != '\0')
		line_len++;
	    lines_matrix[i] = malloc(line_len + 1);
	    j += line_len + 1;
	    i++;
	}
	// copy the lines in the matrix strings
	i = 0;
	j = 0;
	while (i < lines)
	{
	    line_len = 0;
	    while (file[j + line_len] != '\n' && file[j + line_len] != '\0')
	    {
		lines_matrix[i][line_len] = file[j + line_len];
		line_len++;
	    }
	    lines_matrix[i][line_len] = '\0';
	    printf("Line %d: %s\n", i, lines_matrix[i]);
	    j += line_len + 1;
	    i++;
}
	free(file);
	// matrice da liberare
}
