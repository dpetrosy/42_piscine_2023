/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anishkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:45:09 by anishkha          #+#    #+#             */
/*   Updated: 2023/10/15 19:06:41 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c);

void	rush(int a, int b)
{
	int	i;
	int	j;

	if (a <= 0 || b <= 0)
	{
		write(1, "Incorrect Input\n", 16);
		exit(1);
	}
	i = 0;
	while (++i <= a)
	{
		j = 0;
		while (++j <= b)
		{
			if ((i == 1 || i == a) && (j == 1 || j == b))
				ft_putchar('o');
			else if ((i == 1 && j < b) || (i == a && j < b))
				ft_putchar('-');
			else if ((j > 1 && j < b) && (i > 1 && i < a))
				ft_putchar(' ');
			else
				ft_putchar('|');
		}
		ft_putchar('\n');
	}
}
