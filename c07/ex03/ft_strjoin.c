/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lurossi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:33:49 by lurossi           #+#    #+#             */
/*   Updated: 2026/01/27 14:33:51 by lurossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		counter;
	int		lenght;
	int		i;
	int		seplen;
	int		y;
	char	*returning;

	lenght = 0;
	counter = size - 1;
	if (size == 0)
	{
		str = malloc(1 * sizeof(char));
		*str = '\0';
		return (str);
	}
	while (counter >= 0)
	{
		lenght += ft_strlen(strs[counter]);
		counter--;
	}
	seplen = ft_strlen(sep);
	str = malloc((lenght + (seplen * (size - 1)) + 1) * sizeof(char));
	returning = str;
	counter++;
	while (counter < size)
	{
		i = 0;
		while (strs[counter][i])
		{
			*str = strs[counter][i];
			str++;
			i++;
		}
		y = 0;
		if (counter < size - 1)
		{
			while (y < seplen)
			{
				*str = sep[y];
				str++;
				y++;
			}
		}
		counter++;
	}
	*str = '\0';
	return (returning);
}
/*
int	main(void)
{
	char *arr[] =
	{
		"ciao",
		"aiuto",
		"mamma",
	};
	char *miao = "miao";
	char *stringhe = ft_strjoin(3, arr, miao);
	printf("%s ", stringhe);
	free (stringhe);
	return (0);
}*/