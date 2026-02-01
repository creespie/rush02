/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_dict_line_second.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrios <wrios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:38:58 by wrios             #+#    #+#             */
/*   Updated: 2026/01/31 14:21:08 by wrios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	file_size(char *file_path)
{
	int		fd;
	char	tmp[1024];
	int		bytes;
	int		total;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (-1);
	total = 0;
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, tmp, 1024);
		total += bytes;
	}
	close(fd);
	return (total);
}

int	copy_file(char *file_path, char *buffer, int size)
{
	int		fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (-1);
	if (read(fd, buffer, size) < 0)
		return (close(fd), -1);
	buffer[size] = '\0';
	close(fd);
	return (1);
}
