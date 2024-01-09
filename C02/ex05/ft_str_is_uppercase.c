/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 23:43:30 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/12 23:43:32 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	char	ch;

	if (!str || *str == '\0')
		return (1);
	ch = *str;
	while (ch != '\0')
	{
		if (!(ch >= 'A' && ch <= 'Z'))
			return (0);
		ch = *(++str);
	}
	return (1);
}
