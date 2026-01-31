/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lurossi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:56:07 by lurossi           #+#    #+#             */
/*   Updated: 2026/01/26 16:56:08 by lurossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	i = 3;
	if (nb <= 1)
		return (0);
	else if (nb == 2)
		return (1);
	else if ((nb % 2) == 0)
		return (0);
	while ((nb % i) != 0 && i < nb)
		i += 2;
	if (i >= nb)
		return (1);
	return (0);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	i = nb + 1;
	while (i > nb)
	{
		if (ft_is_prime(i) == 1)
			return (i);
		i++;
	}
	return (0);
}
/*
int main(void)
{
	printf("%d", ft_find_next_prime(8));
}*/
