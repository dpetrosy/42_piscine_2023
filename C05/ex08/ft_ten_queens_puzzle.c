/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:45:47 by dapetros          #+#    #+#             */
/*   Updated: 2024/01/10 14:43:19 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

typedef struct s_data
{
	int	sols[10];
	int	pos;
	int	count;
}	t_data;

bool	is_safe(t_data *data, int curr_pos)
{
	int	col;

	col = -1;
	while (++col < curr_pos)
	{
		if (data->sols[col] == data->sols[curr_pos])
			return (false);
		if (data->sols[col] == data->sols[curr_pos] - (curr_pos - col))
			return (false);
		if (data->sols[col] == data->sols[curr_pos] + (curr_pos - col))
			return (false);
	}
	return (true);
}

void	run_rec(t_data *data, int curr_pos)
{
	int		i;
	char	c;

	i = -1;
	if (curr_pos == 10)
	{
		data->count += 1;
		while (++i < 10)
		{
			c = data->sols[i] + '0';
			write(1, &c, 1);
		}
		write(1, "\n", 1);
	}
	else
	{
		while (++i < 10)
		{
			data->sols[curr_pos] = i;
			if (is_safe(data, curr_pos))
				run_rec(data, curr_pos + 1);
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	t_data	data;
	int		curr_pos;
	int		i;

	i = -1;
	while (++i < 10)
		data.sols[i] = -1;
	curr_pos = 0;
	data.count = 0;
	run_rec(&data, curr_pos);
	return (data.count);
}

/*
#include <stdio.h>

int main()
{
	printf("count = %d\n", ft_ten_queens_puzzle());
}
*/
