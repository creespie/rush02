/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipaglie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 19:01:59 by gipaglie          #+#    #+#             */
/*   Updated: 2026/02/01 10:59:07 by gipaglie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "dict.h"

int		parse_args(int argc, char **argv, char **dict_path, char **num);
char	**load_lines(char *dict_path, int *out_lines);
void	free_lines(char **lines, int n);
int		print_number(t_dict *d, char *num);

static void	putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

int	main(int argc, char **argv)
{
	t_dict	*d;
	char	**lines;
	char	*dict_path;
	char	*num;
	int		n_lines;

	if (parse_args(argc, argv, &dict_path, &num) < 0)
		return (putstr("Error\n"), 1);
	lines = load_lines(dict_path, &n_lines);
	if (!lines)
		return (putstr("Dict Error\n"), 1);
	d = dict_build(lines, n_lines);
	free_lines(lines, n_lines);
	if (!d)
		return (putstr("Dict Error\n"), 1);
	if (print_number(d, num) < 0)
	{
		dict_free(d);
		return (putstr("Dict Error\n"), 1);
	}
	dict_free(d);
	return (0);
}
