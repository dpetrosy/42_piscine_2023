/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:12:00 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/26 18:38:04 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*ret_arr;
	int	i;

	if (!tab || !f)
		return (NULL);
	ret_arr = (int *)malloc(sizeof(int) * length);
	if (!ret_arr)
		return (NULL);
	i = -1;
	while (++i < length)
		ret_arr[i] = f(tab[i]);
	return (ret_arr);
}

/*
#include <stdio.h>

int	power_2(int i)
{
	return (i * i);
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	int *ret_arr = ft_map(arr, 5, &power_2);
	for (int i = 0; i < 5; ++i)
		printf("number = %d\n", ret_arr[i]);
}
*/
