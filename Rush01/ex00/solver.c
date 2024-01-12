/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:51:05 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/22 19:39:40 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "utils.h"

void	decrease_pos(t_data *data)
{
	if (data->pos_j == 1)
	{
		data->pos_i -= 1;
		data->pos_j = data->size;
	}
	else
		data->pos_j -= 1;
}

void	fill_grid(int **data, int **grid, int grid_size, int data_size)
{
	int	i;

	fill_matrix_by_num(grid, grid_size, 0);
	i = -1;
	while (++i < data_size)
	{
		grid[0][i + 1] = data[0][i];
		grid[grid_size - 1][i + 1] = data[1][i];
	}
	i = -1;
	while (++i < data_size)
	{
		grid[i + 1][0] = data[2][i];
		grid[i + 1][grid_size - 1] = data[3][i];
	}
}

bool	is_safe(int **grid, t_data *data)
{
	int	*arr_top_down;
	int	*arr_left_right;
	int	arr_i;
	int	i;

	arr_top_down = (int *)malloc(sizeof(int) * data->size);
	arr_left_right = (int *)malloc(sizeof(int) * data->size);
	if (!arr_top_down || !arr_left_right)
		return (false);
	arr_i = -1;
	i = 1;
	while (++arr_i < data->size)
	{
		arr_top_down[arr_i] = grid[i][data->pos_j];
		arr_left_right[arr_i] = grid[data->pos_i][i];
		++i;
	}
	if (!check_repetitions(arr_left_right, arr_top_down, data))
		return (false);
	if (!check_views(grid, arr_left_right, arr_top_down, data))
		return (false);
	return (true);
}

bool	run_recursion(int **grid, t_data *data)
{
	int		num;

	if (data->pos_i > data->size)
		return (true);
	num = 0;
	while (++num <= data->size)
	{
		data->num = num;
		grid[data->pos_i][data->pos_j] = num;
		if (is_safe(grid, data))
		{
			if (data->pos_j == data->size)
			{
				data->pos_i += 1;
				data->pos_j = 1;
			}
			else
				data->pos_j += 1;
			if (run_recursion(grid, data))
				return (true);
		}
		grid[data->pos_i][data->pos_j] = 0;
	}
	decrease_pos(data);
	return (false);
}

bool	solve_puzzle(int **data, t_size *data_size)
{
	int		board_size;
	int		grid_size;
	int		**grid;
	t_data	algo_data;

	board_size = data_size->j;
	grid_size = board_size + 2;
	grid = make_int_matrix(grid_size, grid_size);
	if (!grid)
		return (false);
	fill_grid(data, grid, grid_size, board_size);
	algo_data.pos_i = 1;
	algo_data.pos_j = 1;
	algo_data.num = 1;
	algo_data.size = board_size;
	if (run_recursion(grid, &algo_data))
	{
		print_result(grid, board_size);
		free_int_matrix(grid, grid_size);
		return (true);
	}
	free_int_matrix(grid, grid_size);
	return (false);
}
