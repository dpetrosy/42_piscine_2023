/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anishkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:21:39 by anishkha          #+#    #+#             */
/*   Updated: 2023/10/15 23:08:28 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int a, int b);

int	ft_atoi(char *str)
{
	int		minus;
	int		num;
	int		i;

	minus = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		++i;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			minus = -1;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10;
		num = num + (str[i] - '0');
		++i;
	}
	num = num * minus;
	return (num);
}

int	main(int argc, char **argv)
{
	int	a;
	int	b;

	if (argc != 3)
	{
		write(1, "Incorrect Input\n", 16);
		return (0);
	}
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[2]);
	if (a <= 0 || b <= 0)
	{
		write(1, "Incorrect Input\n", 16);
		return (0);
	}
	rush(b, a);
	return (0);
}
