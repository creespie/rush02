/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrios <wrios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 18:15:20 by wrios             #+#    #+#             */
/*   Updated: 2026/01/31 18:32:49 by wrios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

static char	*fill_scale(int zeros, char *key)
{
	int	i;

	key[0] = '1';
	i = 1;
	while (zeros > 0)
	{
		key[i] = '0';
		i++;
		zeros--;
	}
	key[i] = '\0';
	return (key);
}

char	*fill(char n1, char n2, int zeros, char *key)
{
	int	i;

	key[0] = n1;
	key[1] = n2;
	i = 2;
	while (zeros > 0)
	{
		key[i] = '0';
		i++;
		zeros--;
	}
	key[i] = '\0';
	return (key);
}

char	*find_line(char n1, int mode, char n2, char *key)
{
	if (mode == 0)
		return (fill(n1, '\0', 0, key));
	if (mode == 1)
		return (fill(n2, n1, 0, key));
	if (mode == 2)
		return (fill(n1, '0', 0, key));
	if (mode == -1)
		return (fill('1', '0', 1, key));
	return (fill_scale(mode, key));
}
