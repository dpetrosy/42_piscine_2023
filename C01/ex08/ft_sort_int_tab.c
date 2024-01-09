/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:46:03 by dapetros          #+#    #+#             */
/*   Updated: 2024/01/09 17:56:08 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i++ < size - 1)
	{
		j = 0;
		while (j <= (size - i - 1))
		{
			if (tab[j] > tab[j + 1])
				swap(&tab[j], &tab[j + 1]);
			++j;
		}
	}
}
