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

int	ft_recursive_factorial(int nb)
{
	int	n;

	if (nb < 0)
		return (0);
	if (nb == 0)
	{
		return (1);
	}
	n = nb * ft_recursive_factorial(nb - 1);
	return (n);
}
/*
int	main(void)
{
	int nb = ft_recursive_factorial(4);
	printf("%d", nb);
}
*/
