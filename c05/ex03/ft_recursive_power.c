/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lurossi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:38:53 by lurossi           #+#    #+#             */
/*   Updated: 2026/01/26 14:38:55 by lurossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	int	n;

	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
	{
		return (1);
	}
	if (nb == 0)
		return (0);
	if (power == 0)
		return (1);
	if (power > 0)
	{
		n = nb * ft_recursive_power(nb, power - 1);
	}
	return (n);
}
/*
int	main(void)
{
	int nb = ft_recursive_power(4, 3);
	printf("%d", nb);
}*/
