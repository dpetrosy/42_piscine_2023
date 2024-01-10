/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 22:22:02 by dapetros          #+#    #+#             */
/*   Updated: 2024/01/10 15:03:31 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	int		i;
	char	ch;

	i = 0;
	ch = str[i];
	while (ch != '\0')
	{
		write(1, &ch, 1);
		ch = str[++i];
	}
}

void	ft_putnbr(int nb)
{
	char	ch;
	long	num;

	num = nb;
	if (num < 0)
	{
		num *= -1;
		write(1, "-", 1);
	}
	if (num > 9 || num < -9)
		ft_putnbr(num / 10);
	ch = num % 10 + '0';
	write(1, &ch, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = -1;
	while (par[++i].str)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
	}
}

/*
#include <stdio.h>
struct	s_stock_str	*ft_strs_to_tab(int ac, char **av);

int main(int argc, char **argv)
{
	t_stock_str *struct_arr = ft_strs_to_tab(argc, argv);

	ft_show_tab(struct_arr);
}
*/
