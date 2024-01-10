/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:48:12 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/31 19:49:05 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*arr;

	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	arr = (int *)malloc(sizeof(int) * (max - min));
	if (!arr)
		return (-1);
	i = 0;
	while (min < max)
	{
		arr[i] = min;
		++i;
		++min;
	}
	*range = arr;
	return (i);
}

/*
#include <stdio.h>

int main()
{
	int a = 10;
	int b = 20;
	int len = b - a;
	
	int *arr = NULL;
	int **range = &arr;

	int ret = ft_ultimate_range(range, a, b);

	printf("%d\n\n", ret);

	for (int i = 0; i < len; ++i)
		printf("%d ", range[0][i]);
	printf("\n");
}
*/
