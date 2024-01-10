/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:37:50 by dapetros          #+#    #+#             */
/*   Updated: 2024/01/10 14:57:42 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int	get_total_len(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	len;

	if (size <= 0)
		return (0);
	i = -1;
	len = 0;
	while (++i < size)
	{
		j = -1;
		while (strs[i][++j])
			++len;
	}
	return (len + ft_strlen(sep) * (size - 1));
}

void	join_strings(char *str, char **strs, char *sep, int size)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = -1;
	while (strs[0][++i])
		str[++j] = strs[0][i];
	i = 0;
	while (++i < size)
	{
		k = -1;
		while (sep[++k])
			str[++j] = sep[k];
		k = -1;
		while (strs[i][++k])
			str[++j] = strs[i][k];
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_len;
	char	*str;

	total_len = get_total_len(size, strs, sep);
	str = malloc(sizeof(char) * (total_len + 1));
	if (!str)
		return (NULL);
	if (size <= 0)
	{
		str[0] = '\0';
		return (str);
	}
	join_strings(str, strs, sep, size);
	str[total_len] = '\0';
	return (str);
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
	char *str1 = "Txen";
	char *str2 = "pti";
	char *str3 = "viz";
	char *str4 = "dni";

	char *strs[4];
	strs[0] = str1;
	strs[1] = str2;
	strs[2] = str3;
	strs[3] = str4;

	char *result = ft_strjoin(0, strs, " ");
	printf("%s\n", result);
	free(result);
}
*/
