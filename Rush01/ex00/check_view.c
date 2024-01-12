/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:50:35 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/22 19:48:08 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "utils.h"

bool	check_repetitions(int *arr1, int *arr2, t_data *data)
{
	int	num;
	int	count1;
	int	count2;
	int	i;

	i = -1;
	count1 = 0;
	count2 = 0;
	num = data->num;
	while (++i < data->size)
	{
		if (arr1[i] == num)
			++count1;
		if (arr2[i] == num)
			++count2;
	}
	if (count1 > 1 || count2 > 1)
		return (false);
	else
		return (true);
}

bool	check_view(int *arr, int viewer_num, t_data *data)
{
	int	i;
	int	max;
	int	visibility;

	i = 0;
	visibility = 1;
	max = arr[0];
	while (++i < data->size)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			++visibility;
		}
	}
	if (viewer_num == visibility)
		return (true);
	else
		return (false);
}

bool	check_left_right(int **grid, int *arr, t_data *data)
{
	int	viewer_num;

	viewer_num = grid[data->pos_i][0];
	if (!check_view(arr, viewer_num, data))
		return (false);
	ft_rev_int_tab(arr, data->size);
	viewer_num = grid[data->pos_i][data->size + 1];
	if (!check_view(arr, viewer_num, data))
		return (false);
	return (true);
}

bool	check_top_down(int **grid, int *arr, t_data *data)
{
	int	viewer_num;

	viewer_num = grid[0][data->pos_j];
	if (!check_view(arr, viewer_num, data))
		return (false);
	ft_rev_int_tab(arr, data->size);
	viewer_num = grid[data->size + 1][data->pos_j];
	if (!check_view(arr, viewer_num, data))
		return (false);
	return (true);
}

bool	check_views(int **grid, int *arr_lr, int *arr_td, t_data *data)
{
	int	i;

	i = -1;
	if (data->pos_i < data->size)
	{
		while (++i < data->size)
			if (arr_lr[i] == 0)
				return (true);
		if (!check_left_right(grid, arr_lr, data))
			return (false);
		i = -1;
		while (++i < data->size)
			if (arr_td[i] == 0)
				return (true);
		if (!check_top_down(grid, arr_td, data))
			return (false);
	}
	else
		if (!check_util(grid, arr_lr, arr_td, data))
			return (false);
	return (true);
}
