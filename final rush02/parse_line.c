/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrios <wrios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:38:58 by wrios             #+#    #+#             */
/*   Updated: 2026/01/31 14:21:08 by wrios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

static int	fill_ranges(char *l, int *ks_ke, int *vs, int *ve)
{
	int	i;

	i = 0;
	if (parse_key(l, &i, &ks_ke[0], &ks_ke[1]) < 0)
		return (-1);
	if (expect_colon(l, &i) < 0)
		return (-1);
	if (parse_value(l, &i, vs, ve) < 0)
		return (-1);
	return (1);
}

static int	alloc_entry(char *l, t_entry *o, int *ks_ke)
{
	o->key = ft_strdup_range(l, ks_ke[0], ks_ke[1]);
	if (!o->key)
		return (-1);
	return (1);
}

static int	alloc_value(char *l, t_entry *o, int vs, int ve)
{
	o->val = ft_strdup_range(l, vs, ve);
	if (!o->val)
		return (-1);
	return (1);
}

int	parse_line_to_entry(char *line, t_entry *out)
{
	int	ks_ke[2];
	int	vs;
	int	ve;

	if (is_line_blank(line))
		return (0);
	if (fill_ranges(line, ks_ke, &vs, &ve) < 0)
		return (-1);
	out->key = NULL;
	out->val = NULL;
	if (alloc_entry(line, out, ks_ke) < 0)
		return (-1);
	if (alloc_value(line, out, vs, ve) < 0)
	{
		free(out->key);
		out->key = NULL;
		return (-1);
	}
	return (1);
}
