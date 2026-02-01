/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ctx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrios <wrios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 18:14:17 by wrios             #+#    #+#             */
/*   Updated: 2026/02/01 14:28:08 by gipaglie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "dict.h"

void	print_ctx_init(t_print_ctx *ctx, t_dict *d)
{
	ctx->dict = d;
	ctx->first = 1;
	ctx->error = 0;
}

int	print_word(t_print_ctx *ctx, char *key)
{
	char	*val;

	val = dict_get(ctx->dict, key);
	if (!val)
	{
		ctx->error = 1;
		return (-1);
	}
	if (!ctx->first)
		write(1, " ", 1);
	ctx->first = 0;
	write(1, val, ft_strlen(val));
	return (1);
}

int	print_has_error(t_print_ctx *ctx)
{
	return (ctx->error);
}
