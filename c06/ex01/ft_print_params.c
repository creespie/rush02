/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lurossi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:17:01 by lurossi           #+#    #+#             */
/*   Updated: 2026/01/26 17:17:03 by lurossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	y;

	y = 1;
	if (argc == 1)
		return (0);
	while (y < argc)
	{
		i = 0;
		while (argv[y][i])
		{
			write(1, &argv[y][i], 1);
			i++;
		}
		write(1, "\n", 1);
		y++;
	}
}
