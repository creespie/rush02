/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrios <wrios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:34:29 by wrios             #+#    #+#             */
/*   Updated: 2026/01/31 14:20:17 by wrios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

int	ft_is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f')
		return (1);
	return (0);
}

int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_line_blank(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_is_space(line[i]))
		i++;
	if (line[i] == '\0')
		return (1);
	return (0);
}