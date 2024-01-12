/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 12:35:45 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/29 22:00:42 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	ft_isspace(char c)
{
	char	*str;
	int		i;

	i = -1;
	str = "\f\n\r\t\v ";
	while (str[++i])
		if (c == str[i])
			return (true);
	return (false);
}

bool	is_only_0(char *str, char num[], int *i)
{
	while (str[*i] == '0')
		*i += 1;
	if (str[*i] == '\0')
	{
		num[0] = '0';
		num[1] = '\0';
		return (true);
	}
	else
		return (false);
}

void	ft_atoi(char *str, char num[], int i, int j)
{
	if (str[0] == '\0')
		return ;
	while (ft_isspace(str[i]))
		++i;
	if (str[i] == '-')
		return ;
	if (str[i] == '+')
		++i;
	if (str[i] < '0' || str[i] > '9')
		return ;
	if (is_only_0(str, num, &i))
		return ;
	while (str[i] >= '0' && str[i] <= '9' && j < 40)
	{
		num[j] = str[i];
		++i;
		++j;
	}
	if (str[i] != '\0')
		num[0] = '\0';
	num[j] = '\0';
}

bool	is_number_correct(char *str, char num[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	num[0] = '\0';
	ft_atoi(str, num, i, j);
	if (num[0] == '\0' || num[39] != '\0')
		return (false);
	return (true);
}

bool	is_args_correct(int argc, char **argv, char **ret_num, char **dict)
{
	char	num[41];

	num[39] = '\0';
	fill_str_by_symbol(num, '#');
	if (argc == 2)
	{
		if (!is_number_correct(argv[1], num))
			return (false);
		*dict = ft_strdup(DICT_PATH);
	}
	else if (argc == 3)
	{
		if (!is_number_correct(argv[2], num))
			return (false);
		*dict = ft_strjoin_for_dict(DICT_DIR, argv[1]);
	}
	*ret_num = ft_strdup(num);
	return (true);
}
