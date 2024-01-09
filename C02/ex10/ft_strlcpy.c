/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:35:52 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/14 22:55:20 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int		i;
	char	ch;

	i = 0;
	ch = str[i];
	while (ch != '\0')
		ch = str[++i];
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_strlen(src);
	if (size == 0)
	{
		dest[i] = '\0';
		return (len);
	}
	while ((i < size - 1) && src[i])
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (len);
}
