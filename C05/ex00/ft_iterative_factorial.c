/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:23:01 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/19 17:23:03 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	num;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	i = 1;
	num = 1;
	while (i <= nb)
	{
		num = num * i;
		++i;
	}
	return (num);
}

/*
#include <stdio.h>

int main()
{
	printf("%d", ft_iterative_factorial(5));
}
*/
