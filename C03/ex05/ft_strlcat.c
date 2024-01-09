/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:46:58 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/15 21:49:01 by dapetros         ###   ########.fr       */
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len_src;
	unsigned int	len_dest;

	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	if (size < 1)
		return (size + len_src);
	i = 0;
	while (dest[i] != '\0')
		++i;
	j = 0;
	while ((src[j] != '\0') && (i < size - 1))
		dest[i++] = src[j++];
	dest[i] = '\0';
	if (size < len_dest)
		return (len_src + size);
	else
		return (len_src + len_dest);
}
