/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrios <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 18:09:00 by wrios             #+#    #+#             */
/*   Updated: 2026/02/01 15:31:38 by gipaglie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "dict.h"

void	print_ctx_init(t_print_ctx *ctx, t_dict *d);
int		print_has_error(t_print_ctx *ctx);
void	hundreds(t_print_ctx *ctx, t_triplet *trip);
void	get_triplet(char *num, int len, int *start, char t[3]);
int		is_triplet_zero(char a, char b, char c);
void	set_triplet(t_triplet *trip, char t[3], int idx);

static int	print_zero(t_print_ctx *ctx)
{
	t_triplet	trip;

	set_triplet(&trip, (char [3]){'0', '0', '0'}, 0);
	hundreds(ctx, &trip);
	write(1, "0\n", 2);
	return (1);
}

static void	process_groups(t_print_ctx *ctx, char *num, int len, int groups)
{
	t_triplet	trip;
	char		t[3];
	int			start;
	int			g;

	start = 0;
	g = 0;
	while (g < groups)
	{
		get_triplet(num, len, &start, t);
		if (!is_triplet_zero(t[0], t[1], t[2]))
		{
			set_triplet(&trip, t, (groups - 1 - g) * 3);
			hundreds(ctx, &trip);
		}
		g++;
	}
}

int	print_number(t_dict *d, char *num)
{
	t_print_ctx	ctx;
	int			len;
	int			groups;

	print_ctx_init(&ctx, d);
	len = ft_strlen(num);
	if (len == 1 && num[0] == '0')
		return (print_zero(&ctx));
	groups = (len + 2) / 3;
	process_groups(&ctx, num, len, groups);
	write(1, "\n", 1);
	if (print_has_error(&ctx))
		return (-1);
	return (1);
}
