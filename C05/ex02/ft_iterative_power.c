/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:23:31 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/19 17:23:32 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	num;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	num = nb;
	i = 1;
	while (i < power)
	{
		num *= nb;
		++i;
	}
	return (num);
}

/*
#include <stdio.h>

int main()
{
	printf("%d", ft_iterative_power(5, 3));
}
*/
