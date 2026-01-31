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

int	*ft_range(int min, int max)
{
	void	*output;
	int		*array;
	int		i;
	int		diff;

	output = NULL;
	i = 0;
	diff = max - min;
	if (min >= max)
	{
		array = NULL;
		return (array);
	}
	array = malloc(diff * sizeof(int));
	while (i < (diff))
	{
		array[i] = min;
		min++;
		i++;
	}
	return (array);
}

int	main(void)
{
	int *array = ft_range(2, 14);
	int i = 0;
	while (i < 13)
	{
		printf("%d ", array[i]);
		i++;
	}

	free(array);
}
