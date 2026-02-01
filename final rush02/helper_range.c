/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_range.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrios <wrios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:36:32 by wrios             #+#    #+#             */
/*   Updated: 2026/01/31 19:29:01 by gipaglie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

char	*ft_strdup_range(char *s, int start, int end)
{
	char	*out;
	int		i;
	int		len;

	if (end < start)
		return (NULL);
	len = end - start;
	out = (char *)malloc(len + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (i < len)
	{
		out[i] = s[start + i];
		i++;
	}
	out[i] = '\0';
	return (out);
}
