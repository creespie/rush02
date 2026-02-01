/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrios <wrios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:37:48 by wrios             #+#    #+#             */
/*   Updated: 2026/01/31 14:20:59 by wrios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

int	skip_spaces(char *s, int i)
{
	while (s[i] && ft_is_space(s[i]) && s[i] != '\n')
		i++;
	return (i);
}

int	parse_key(char *s, int *i, int *kstart, int *kend)
{
	*i = skip_spaces(s, *i);
	*kstart = *i;
	while (s[*i] && ft_is_digit(s[*i]))
		(*i)++;
	*kend = *i;
	if (*kend == *kstart)
		return (-1);
	return (1);
}

int	expect_colon(char *s, int *i)
{
	*i = skip_spaces(s, *i);
	if (s[*i] != ':')
		return (-1);
	(*i)++;
	return (1);
}

int	parse_value(char *s, int *i, int *vstart, int *vend)
{
	*i = skip_spaces(s, *i);
	*vstart = *i;
	while (s[*i] && s[*i] != '\n')
		(*i)++;
	*vend = *i;
	while (*vend > *vstart && ft_is_space(s[*vend - 1]))
		(*vend)--;
	if (*vend == *vstart)
		return (-1);
	return (1);
}
