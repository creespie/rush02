/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_lookup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrios <wrios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:40:14 by wrios             #+#    #+#             */
/*   Updated: 2026/01/31 19:25:04 by gipaglie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

char	*dict_get(t_dict *d, char *key)
{
	int	i;

	if (!d || !key)
		return (NULL);
	i = 0;
	while (i < d->size)
	{
		if (ft_strcmp(d->e[i].key, key) == 0)
			return (d->e[i].val);
		i++;
	}
	return (NULL);
}
