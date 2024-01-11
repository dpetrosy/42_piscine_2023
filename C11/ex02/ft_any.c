/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 22:11:12 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/26 18:38:20 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char *))
{
	int	i;
	int	is_correct;

	if (!tab || !f)
		return (0);
	is_correct = 0;
	i = -1;
	while (tab[++i])
	{
		if (f(tab[i]) != 0)
			is_correct = 1;
	}
	return (is_correct);
}
