/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:35:02 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/29 23:34:55 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_line
{
	char	*key;
	char	*value;
}	t_line;

# define DICT_PATH "dict/numbers.dict"
# define DICT_DIR "dict/"

# define DICT_SIZE 41

void	fill_str_by_symbol(char *str, char c);
void	free_all(t_line *dict, char *filename, char *num);
bool	is_args_correct(int argc, char **argv, char **ret_num, char **dict);
t_line	*parse_dict(char *filename);
char	*ft_strdup(char *s1);
size_t	ft_strlen(char *str);
bool	ft_isspace(char c);
bool	is_only_0(char *str, char num[], int *i);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strcmp(char *s1, char *s2);
void	free_str_matrix(char **matrix, int alloc_count);
bool	is_only_0_for_dict(char *str, char num[], int *i);
void	ft_atoi_for_dict(char *str, char num[], int i, int j);
char	*get_value(char *line);
bool	check_num(char *line, char num[]);
void	set_values(char **default_mat);
void	free_dict(t_line *dict);
char	*ft_strjoin_for_dict(char *s1, char *s2);
bool	solver(t_line *dict, char *num, int len);
void	ft_putstr(char *str);
void	fill_dict_null(t_line *dict);
bool	check_dict_last(t_line *dict);
void	shift_left(char number[], int shift, int *len);
void	get_nums3(char number[], char nums_3[], int *len);

#endif /* UTILS_H */
