/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lurossi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:34:29 by lurossi           #+#    #+#             */
/*   Updated: 2026/01/26 15:34:31 by lurossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	n;

	n = 1;
	if (power < 0)
		return (0);
	else if (nb == 0 && power == 0)
		return (1);
	else if (nb == 0)
		return (0);
	while (power > 0)
	{
		n = n * nb;
		power--;
	}
	return (n);
}
/*
int	main(void)
{
	int nb = ft_iterative_power(4, 3);
	printf("%d", nb);
	
}*/
