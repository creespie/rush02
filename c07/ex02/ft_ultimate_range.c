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

int	ft_ultimate_range(int **range, int min, int max)
{
	void	*f;
	int		i;
	int		diff;

	f = NULL;
	i = 0;
	diff = max - min;
	if (min >= max)
	{
		*range = f;
		return (0);
	}
	*range = malloc((max - min) * sizeof(int));
	while ((*range)[i - 1] < (max - 1))
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (**range);
}

int	main(void)
{
	int *array;
	ft_ultimate_range(&array, 2, 14);
	int i = 0;
	while (i < 13)
	{
		printf("%d ", array[i]);
		i++;
	}

	free(array);
}