/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrios <wrios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:17:53 by wrios             #+#    #+#             */
/*   Updated: 2026/02/01 14:18:35 by wrios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

# include <stdlib.h>

typedef struct s_entry
{
	char	*key;
	char	*val;
}	t_entry;

typedef struct s_dict
{
	t_entry	*e;
	int		size;
}	t_dict;

typedef struct s_print_ctx
{
	t_dict	*dict;
	int		first;
	int		error;
}	t_print_ctx;

typedef struct s_triplet
{
	char	n1;
	char	n2;
	char	n3;
	int		index;
}	t_triplet;

t_dict	*dict_build(char **lines, int n_lines);
void	dict_free(t_dict *d);
char	*dict_get(t_dict *d, char *key);

int		parse_line_to_entry(char *line, t_entry *out);

int		ft_strlen(char *s);
int		ft_strcmp(char *a, char *b);
int		ft_is_space(char c);
int		ft_is_digit(char c);
int		is_line_blank(char *line);
char	*ft_strdup_range(char *s, int start, int end);

int		skip_spaces(char *s, int i);
int		parse_key(char *s, int *i, int *kstart, int *kend);
int		expect_colon(char *s, int *i);
int		parse_value(char *s, int *i, int *vstart, int *vend);

#endif
