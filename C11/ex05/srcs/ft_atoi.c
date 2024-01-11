/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 22:42:35 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/26 01:30:04 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int		minus;
	int		num;
	int		i;

	minus = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		++i;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			minus = -minus;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num = num + (str[i] - '0');
		++i;
	}
	num = num * minus;
	return (num);
}
