/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrios <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 18:09:00 by wrios             #+#    #+#             */
/*   Updated: 2026/01/31 18:09:04 by wrios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "dict.h"

void	print_set_dict(t_dict *d);
void	print_reset(void);
int		print_has_error(void);
void	hundreds(char n1, char n2, char n3, int index);

static int	is_triplet_zero(char a, char b, char c)
{
	return (a == '0' && b == '0' && c == '0');
}

static void	get_triplet(char *num, int len, int *start, char t[3])
{
	if ((len - *start) % 3 == 1)
		t[0] = '0', t[1] = '0', t[2] = num[(*start)++];
	else if ((len - *start) % 3 == 2)
		t[0] = '0', t[1] = num[*start], t[2] = num[*start + 1], *start += 2;
	else
		t[0] = num[*start], t[1] = num[*start + 1], t[2] = num[*start + 2], *start += 3;
}

int	print_number(t_dict *d, char *num)
{
	int		len;
	int		groups;
	int		g;
	int		start;
	char	t[3];

	print_set_dict(d);
	print_reset();
	len = ft_strlen(num);
	if (len == 1 && num[0] == '0')
		return (hundreds('0', '0', '0', 0), write(1, "0\n", 2), 1);
	groups = (len + 2) / 3;
	g = 0;
	start = 0;
	while (g < groups)
	{
		get_triplet(num, len, &start, t);
		if (!is_triplet_zero(t[0], t[1], t[2]))
			hundreds(t[0], t[1], t[2], (groups - 1 - g) * 3);
		g++;
	}
	write(1, "\n", 1);
	if (print_has_error())
		return (-1);
	return (1);
}
