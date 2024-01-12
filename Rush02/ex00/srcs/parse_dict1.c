/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:58:06 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/29 22:09:39 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	is_only_0_for_dict(char *str, char num[], int *i)
{
	while (str[*i] == '0')
		*i += 1;
	if (str[*i] == ' ' || str[*i] == ':')
	{
		num[0] = '0';
		num[1] = '\0';
		return (true);
	}
	else
		return (false);
}

void	ft_atoi_for_dict(char *str, char num[], int i, int j)
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
	if (is_only_0_for_dict(str, num, &i))
		return ;
	while (str[i] >= '0' && str[i] <= '9' && j < 38)
	{
		num[j] = str[i];
		++i;
		++j;
	}
	num[j] = '\0';
}

char	*get_value(char *line)
{
	char	*str;
	int		count;
	int		j;
	int		i;
	int		k;

	i = 0;
	while (line[i] && (line[i] < 33 || line[i] > 126))
		++i;
	if (line[i] == '\0')
		return (NULL);
	--i;
	j = i;
	count = 0;
	while (line[++i] >= 33 && line[i] <= 126 && line[i])
		++count;
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	k = -1;
	while (line[++j] >= 33 && line[j] <= 126 && line[i])
		str[++k] = line[j];
	str[k + 1] = '\0';
	return (str);
}

bool	check_num(char *line, char num[])
{
	int		i;
	int		j;

	num[0] = '\0';
	num[37] = '\0';
	i = 0;
	j = 0;
	ft_atoi_for_dict(line, num, i, j);
	if (num[0] == '\0' || num[37] != '\0')
		return (false);
	return (true);
}
