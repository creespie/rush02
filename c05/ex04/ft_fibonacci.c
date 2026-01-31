/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lurossi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:44:10 by lurossi           #+#    #+#             */
/*   Updated: 2026/01/26 15:44:12 by lurossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_fibonacci(int index)
{
	int	one;
	int	two;
	int	temp;
	int	counter;

	one = 0;
	two = 1;
	counter = 3;
	if (index == 0)
		return (0);
	else if (index == 1 || index == 2)
		return (1);
	while (counter <= index)
	{
		temp = one;
		one = two;
		two = temp + one;
		counter++;
	}
	return (two);
}
/*
int	main(void)
{
	printf("%d", ft_fibonacci(5));
	printf("%d", ft_fibonacci(6));
	printf("%d", ft_fibonacci(7));
	printf("%d", ft_fibonacci(8));
	printf("%d", ft_fibonacci(9));
	printf("%d", ft_fibonacci(10));
}
*/
