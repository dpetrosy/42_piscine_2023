/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:24:15 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/19 17:24:17 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
		return (0);
	i = 1;
	while (i * i < nb)
	{
		if (i >= 46341)
			return (0);
		++i;
	}
	if (i * i == nb)
		return (i);
	else
		return (0);
}

/*
#include <stdio.h>

int main()
{
	printf("%d\n", ft_sqrt(-1));
	printf("%d\n", ft_sqrt(0));
	printf("%d\n", ft_sqrt(1));
	printf("%d\n", ft_sqrt(2));
	printf("%d\n", ft_sqrt(3));
	printf("%d\n", ft_sqrt(4));
	printf("%d\n", ft_sqrt(13));
	printf("%d\n", ft_sqrt(225));
	printf("%d\n", ft_sqrt(2147483647));
}
*/
