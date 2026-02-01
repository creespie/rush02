/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_build.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrios <wrios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:42:23 by wrios             #+#    #+#             */
/*   Updated: 2026/01/31 19:07:09 by gipaglie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

static int	count_entries(char **lines, int n)
{
	int		i;
	int		r;
	int		c;
	t_entry	tmp;

	i = 0;
	c = 0;
	while (i < n)
	{
		tmp.key = NULL;
		tmp.val = NULL;
		r = parse_line_to_entry(lines[i], &tmp);
		if (r < 0)
			return (-1);
		if (r == 1)
		{
			c++;
			free(tmp.key);
			free(tmp.val);
		}
		i++;
	}
	return (c);
}

static int	fill_entries(t_entry *arr, char **lines, int n)
{
	int		i;
	int		j;
	int		r;

	i = 0;
	j = 0;
	while (i < n)
	{
		r = parse_line_to_entry(lines[i], &arr[j]);
		if (r < 0)
			return (-1);
		if (r == 1)
			j++;
		i++;
	}
	return (1);
}

t_dict	*dict_build(char **lines, int n_lines)
{
	t_dict	*d;
	int		count;

	count = count_entries(lines, n_lines);
	if (count <= 0)
		return (NULL);
	d = (t_dict *)malloc(sizeof(t_dict));
	if (!d)
		return (NULL);
	d->e = (t_entry *)malloc(sizeof(t_entry) * count);
	if (!d->e)
	{
		free(d);
		return (NULL);
	}
	d->size = count;
	if (fill_entries(d->e, lines, n_lines) < 0)
	{
		dict_free(d);
		return (NULL);
	}
	return (d);
}
