/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triplet_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipaglie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:00:00 by gipaglie          #+#    #+#             */
/*   Updated: 2026/02/01 15:00:01 by gipaglie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

int	is_triplet_zero(char a, char b, char c)
{
	return (a == '0' && b == '0' && c == '0');
}

void	set_triplet(t_triplet *trip, char t[3], int idx)
{
	trip->n1 = t[0];
	trip->n2 = t[1];
	trip->n3 = t[2];
	trip->index = idx;
}
