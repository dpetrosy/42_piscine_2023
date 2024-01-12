/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:46:27 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/22 19:49:20 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>

typedef struct t_size
{
	int	i;
	int	j;
}			t_size;

typedef struct t_position
{
	int	i;
	int	j;
}			t_pos;

typedef struct t_index
{
	int	i;
	int	j;
	int	k;
	int	alloc_count;
}			t_indexes;

typedef struct t_algo_data
{
	int	pos_i;
	int	pos_j;
	int	num;
	int	size;
}			t_data;

unsigned int	ft_strlen(char *str);
int				**make_int_matrix(int i, int j);
void			free_str_matrix(char **matrix, int alloc_count);
void			free_int_matrix(int **matrix, int alloc_count);
int				**check_input(char *input_str, t_size *data_size);
bool			solve_puzzle(int **data, t_size *data_size);
void			fill_matrix_by_num(int **matrix, int size, int num);
void			print_result(int **grid, int size);
void			ft_rev_int_tab(int *tab, int size);
bool			check_util(int **grid, int *arr_lr, int *arr_td, t_data *data);
char			**ft_split(char const *s, char c);
bool			check_repetitions(int *arr1, int *arr2, t_data *data);
bool			check_views(int **grid, int *arr_lr, int *arr_td, t_data *data);
bool			check_left_right(int **grid, int *arr, t_data *data);
bool			check_top_down(int **grid, int *arr, t_data *data);

#endif /* UTILS_H */
