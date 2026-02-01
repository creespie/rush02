/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ctx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrios <wrios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 18:14:17 by wrios             #+#    #+#             */
/*   Updated: 2026/01/31 18:14:39 by wrios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "dict.h"

static t_dict	*g_dict;
static int		g_first;
static int		g_error;

void	print_set_dict(t_dict *d)
{
	g_dict = d;
}

void	print_reset(void)
{
	g_first = 1;
	g_error = 0;
}

int	print_word(char *key)
{
	char	*val;

	val = dict_get(g_dict, key);
	if (!val)
		return (g_error = 1, -1);
	if (!g_first)
		write(1, " ", 1);
	g_first = 0;
	write(1, val, ft_strlen(val));
	return (1);
}

int	print_has_error(void)
{
	return (g_error);
}

