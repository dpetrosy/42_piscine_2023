/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:53:18 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/12 18:53:21 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int		start;
	int		end;
	int		tmp;

	start = 0;
	end = size - 1;
	while (start < end)
	{
		tmp = tab[start];
		tab[start] = tab[end];
		tab[end] = tmp;
		++start;
		--end;
	}
}
