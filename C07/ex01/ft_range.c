/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:46:14 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/31 19:46:44 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*arr;

	if (min >= max)
		return (NULL);
	arr = (int *)malloc(sizeof(int) * (max - min));
	if (!arr)
		return (NULL);
	i = 0;
	while (min < max)
	{
		arr[i] = min;
		++i;
		++min;
	}
	return (arr);
}

/*
#include <stdio.h>

int main()
{
	int a = 10;
	int b = 20;
	int len = b - a;

	int *arr = ft_range(a, b);

	for (int i = 0; i < len; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}
*/
