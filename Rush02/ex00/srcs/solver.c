/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:43:14 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/29 23:36:43 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	find_in_dict_and_print(t_line *dict, char *str, char symbol)
{
	int	i;

	i = -1;
	while (++i < DICT_SIZE)
	{
		if (ft_strcmp(dict[i].key, str) == 0)
		{
			ft_putstr(dict[i].value);
			if (symbol == '-')
				write (1, "-", 1);
			else if (symbol == '#')
				write (1, " ", 1);
			return (true);
		}
	}
	return (false);
}

void	print_ten_power(t_line *dict, int len)
{
	char	ten_power[37];
	int		i;

	i = 0;
	ten_power[0] = '1';
	while (++i < len + 1)
		ten_power[i] = '0';
	ten_power[len + 1] = '\0';
	find_in_dict_and_print(dict, ten_power, '%');
	write(1, ",", 1);
	write(1, " ", 1);
}

void	print_2_nums_util(char nums3[], char str[], t_line *dict)
{
	if (!find_in_dict_and_print(dict, str, '#'))
	{
		str[0] = nums3[1];
		str[1] = '0';
		str[2] = '\0';
		if (nums3[2] != '#')
			find_in_dict_and_print(dict, str, '%');
		else
			find_in_dict_and_print(dict, str, '#');
		if (nums3[2] != '#')
		{
			str[0] = nums3[2];
			str[1] = '\0';
			write(1, "-", 1);
			find_in_dict_and_print(dict, str, '#');
		}
	}
}

void	print_2_nums(char nums3[], char str[], t_line *dict)
{
	if (nums3[1] != '#')
	{
		str[0] = nums3[1];
		str[1] = nums3[2];
		str[2] = '\0';
		print_2_nums_util(nums3, str, dict);
	}
	else if (nums3[2] != '#')
	{
		str[0] = nums3[2];
		str[1] = '\0';
		find_in_dict_and_print(dict, str, '#');
	}
}

bool	solver(t_line *dict, char *num, int len)
{
	char	nums3[3];
	char	str[3];
	bool	last;

	last = false;
	if (!check_dict_last(dict))
		return (false);
	while (len > 0)
	{
		if (len <= 3)
			last = true;
		get_nums3(num, nums3, &len);
		if (nums3[0] != '#')
		{
			str[0] = nums3[0];
			str[1] = '\0';
			find_in_dict_and_print(dict, str, '#');
			find_in_dict_and_print(dict, "100", '#');
			write (1, "and ", 4);
		}
		print_2_nums(nums3, str, dict);
		if (len > 0)
			print_ten_power(dict, len);
	}
	return (true);
}
