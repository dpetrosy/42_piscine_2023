/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 12:41:47 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/29 22:39:07 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	fill_str_by_symbol(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
		str[i] = c;
}

void	free_dict(t_line *dict)
{
	int	i;

	if (!dict)
		return ;
	i = -1;
	while (++i < DICT_SIZE)
	{
		free(dict[i].key);
		free(dict[i].value);
	}
	free(dict);
}

void	free_all(t_line *dict, char *filename, char *num)
{
	free(filename);
	free(num);
	free_dict(dict);
}

void	free_str_matrix(char **matrix, int alloc_count)
{
	int	i;

	i = 0;
	while (i < alloc_count)
	{
		free(matrix[i]);
		++i;
	}
	free(matrix);
}

void	fill_dict_null(t_line *dict)
{
	int	i;

	i = -1;
	while (++i < DICT_SIZE)
	{
		dict[i].key = NULL;
		dict[i].value = NULL;
	}
}
