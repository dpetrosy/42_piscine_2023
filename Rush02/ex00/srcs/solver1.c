/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 22:20:18 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/29 22:22:37 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	check_dict_last(t_line *dict)
{
	int	i;
	int	j;

	i = -1;
	if (!dict)
		return (false);
	while (++i < DICT_SIZE)
	{
		if (dict[i].key == NULL || dict[i].value == NULL)
			return (false);
	}
	i = -1;
	j = -1;
	while (++i < DICT_SIZE - 1)
	{
		j = i + 1;
		while (j < DICT_SIZE)
		{
			if (ft_strcmp(dict[i].key, dict[j].key) == 0)
				return (false);
			++j;
		}
	}
	return (true);
}

void	shift_left(char number[], int shift, int *len)
{
	int		i;
	int		j;

	i = 0;
	while (i < shift)
	{
		j = 0;
		while (j < *len)
		{
			number[j] = number[j + 1];
			++j;
		}
		++i;
		*len -= 1;
	}
}

void	get_nums3(char number[], char nums_3[], int *len)
{
	if (*len % 3 == 1)
	{
		nums_3[0] = '#';
		nums_3[1] = '#';
		nums_3[2] = number[0];
		shift_left(number, 1, len);
	}
	else if (*len % 3 == 2)
	{
		nums_3[0] = '#';
		nums_3[1] = number[0];
		nums_3[2] = number[1];
		shift_left(number, 2, len);
	}
	else
	{
		nums_3[0] = number[0];
		nums_3[1] = number[1];
		nums_3[2] = number[2];
		shift_left(number, 3, len);
	}
}
