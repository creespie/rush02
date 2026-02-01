/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_triplet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipaglie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:00:00 by gipaglie          #+#    #+#             */
/*   Updated: 2026/02/01 15:00:01 by gipaglie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

static void	get_one_digit(char *num, int *start, char t[3])
{
	t[0] = '0';
	t[1] = '0';
	t[2] = num[(*start)++];
}

static void	get_two_digits(char *num, int *start, char t[3])
{
	t[0] = '0';
	t[1] = num[*start];
	t[2] = num[*start + 1];
	*start += 2;
}

static void	get_three_digits(char *num, int *start, char t[3])
{
	t[0] = num[*start];
	t[1] = num[*start + 1];
	t[2] = num[*start + 2];
	*start += 3;
}

void	get_triplet(char *num, int len, int *start, char t[3])
{
	int	remainder;

	remainder = (len - *start) % 3;
	if (remainder == 1)
		get_one_digit(num, start, t);
	else if (remainder == 2)
		get_two_digits(num, start, t);
	else
		get_three_digits(num, start, t);
}
