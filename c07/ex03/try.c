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

int lenghts(char *str, char **strs, char *sep, int size)
{
	int	counter;
	int	lenght;

	counter = size - 1;
	lenght = 0;
	while (counter >= 0)
	{
		lenght += (sizeof(strs[counter]) / 2);
		counter--;
	}
	&str = malloc((lenght + ((sizeof(sep) / 2) * (size - 1)) + 1) * sizeof(char));
	counter++;
	return (counter);
}

void insert_strs(char *str, char **strs, int counter, int *x)
{
	int	i;

	i = 0;
		while (strs[counter][i])
		{
			str[*x] = strs[counter][i];
			(*x)++;
			i++;
		}
}

void insert_sep(char *str, char *sep, int *x)
{
	long unsigned int i;
	
	i = 0;
	while (i < (sizeof(sep) / 2))
	{
		str[*x] = sep[i];
		(*x)++;
		i++;
	}
}

char *ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		counter;
	int		please;
	int		x;

	x = 0;
	if	(size == 0)
	{
		str = malloc(1 * sizeof(char));
		*str = '\0';
		return (str);
	}
	counter = lenghts(str, strs, sep, size);
	while (counter < size)
	{
		insert_strs(str, strs, counter, &x);
		if (counter < size -1)
			insert_sep(str, sep, &x);
		counter++;
	}
	please = (sizeof(str) / 2);
	str[please] = '\0';
	return (str);
}


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
	printf("%lu ", sizeof(miao));
	free (stringhe);
	return (0);

}