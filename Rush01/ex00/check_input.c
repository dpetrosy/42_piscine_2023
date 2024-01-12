/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:33:36 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/22 18:50:38 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "utils.h"

bool	is_data_correct(char **str_arr, t_size *data_size)
{
	int	size;
	int	i;

	size = 0;
	while (str_arr[size])
		++size;
	if (!(size >= 16 && size <= 36 && (size % 4 == 0)))
		return (false);
	i = -1;
	data_size->i = 4;
	data_size->j = size / 4;
	while (str_arr[++i])
	{
		size = ft_strlen(str_arr[i]);
		if (size <= 0 || size >= 2)
			return (false);
		if (!(str_arr[i][0] >= '1' && str_arr[i][0] <= data_size->j + '0'))
			return (false);
	}
	return (true);
}

void	move_into_int_matrix(int **matrix, char **str_arr, t_size *data_size)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = -1;
	while (++i < data_size->i)
	{
		j = -1;
		while (++j < data_size->j)
			matrix[i][j] = str_arr[++k][0] - '0';
	}
}

int	**check_input(char *input_str, t_size *data_size)
{
	char	**str_arr;
	int		**data_matrix;
	bool	is_correct;

	str_arr = ft_split(input_str, ' ');
	is_correct = is_data_correct(str_arr, data_size);
	if (is_correct)
	{
		data_matrix = make_int_matrix(data_size->i, data_size->j);
		if (!data_matrix)
		{
			free_str_matrix(str_arr, data_size->i * data_size->j);
			return (NULL);
		}
		move_into_int_matrix(data_matrix, str_arr, data_size);
		free_str_matrix(str_arr, data_size->i * data_size->j);
		return (data_matrix);
	}
	free_str_matrix(str_arr, data_size->i * data_size->j);
	return (NULL);
}
