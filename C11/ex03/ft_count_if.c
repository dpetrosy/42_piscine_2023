/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 23:48:00 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/26 18:38:31 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	count;
	int	i;

	if (!tab || !f)
		return (0);
	i = -1;
	count = 0;
	while (++i < length)
	{
		if (f(tab[i]) != 0)
			++count;
	}
	return (count);
}
