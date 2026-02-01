/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits_triplet.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrios <wrios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 18:16:30 by wrios             #+#    #+#             */
/*   Updated: 2026/02/01 14:34:52 by gipaglie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

char	*find_line(char n1, int mode, char n2, char *key);
int		print_word(t_print_ctx *ctx, char *key);

void	doubles(t_print_ctx *ctx, char n2, char n3)
{
	char	key[65];

	if (n2 == '0')
	{
		if (n3 != '0')
			print_word(ctx, find_line(n3, 0, 0, key));
	}
	else if (n2 == '1')
		print_word(ctx, find_line(n3, 1, n2, key));
	else
	{
		print_word(ctx, find_line(n2, 2, 0, key));
		if (n3 != '0')
			print_word(ctx, find_line(n3, 0, 0, key));
	}
}

void	hundreds(t_print_ctx *ctx, t_triplet *trip)
{
	char	key[65];

	if (trip->n1 != '0')
	{
		print_word(ctx, find_line(trip->n1, 0, 0, key));
		print_word(ctx, find_line('0', -1, 0, key));
	}
	doubles(ctx, trip->n2, trip->n3);
	if (trip->index > 0)
		print_word(ctx, find_line('0', trip->index, 0, key));
}
