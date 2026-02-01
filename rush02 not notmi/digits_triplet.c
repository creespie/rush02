/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits_triplet.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrios <wrios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 18:16:30 by wrios             #+#    #+#             */
/*   Updated: 2026/01/31 18:24:14 by wrios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

char	*find_line(char n1, int mode, char n2, char *key);
int		print_word(char *key);

void	doubles(char n2, char n3)
{
	char	key[65];

	if (n2 == '0')
	{
		if (n3 != '0')
			print_word(find_line(n3, 0, 0, key));
	}
	else if (n2 == '1')
		print_word(find_line(n3, 1, n2, key));
	else
	{
		print_word(find_line(n2, 2, 0, key));
		if (n3 != '0')
			print_word(find_line(n3, 0, 0, key));
	}
}

void	hundreds(char n1, char n2, char n3, int index)
{
	char	key[65];

	if (n1 != '0')
	{
		print_word(find_line(n1, 0, 0, key));
		print_word(find_line('0', -1, 0, key));
	}
	doubles(n2, n3);
	if (index > 0)
		print_word(find_line('0', index, 0, key));
}

