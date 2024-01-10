/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:24:42 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/19 17:24:48 by dapetros         ###   ########.fr       */
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
			return (i);
		++i;
	}
	if (i * i == nb)
		return (i);
	else
		return (i);
}

int	ft_is_prime(int nb)
{
	int	i;
	int	num_sqrt;

	if (nb == 2 || nb == 3 || nb == 5)
		return (1);
	if (nb > 5 && (nb % 2 == 0 || nb % 3 == 0 || nb % 5 == 0))
		return (0);
	if (nb <= 1)
		return (0);
	i = 2;
	num_sqrt = ft_sqrt(nb) + 1;
	while (i <= num_sqrt)
	{
		if (nb % i == 0)
			return (0);
		++i;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	is_found;
	int	int_range;
	int	i;

	int_range = 2147483647;
	if (nb <= 1)
		return (2);
	is_found = 0;
	i = nb;
	if (ft_is_prime(i))
		return (i);
	while (!(is_found) && i < int_range)
	{
		++i;
		is_found = ft_is_prime(i);
	}
	return (i);
}

/*
#include <stdio.h>

int main()
{
	printf("%d\n", ft_find_next_prime(-1));
	printf("%d\n", ft_find_next_prime(0));
	printf("%d\n", ft_find_next_prime(1));
	printf("%d\n", ft_find_next_prime(2));
	printf("%d\n", ft_find_next_prime(3));
	printf("%d\n", ft_find_next_prime(7));
	printf("%d\n", ft_find_next_prime(10));
	printf("%d\n", ft_find_next_prime(13));
	printf("%d\n", ft_find_next_prime(25));
}
*/
