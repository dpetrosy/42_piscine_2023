/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:58:37 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/13 22:59:39 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	char	*ret_ptr;

	if (*to_find == '\0')
		return (str);
	i = 0;
	while (str[i])
	{
		j = 0;
		ret_ptr = &str[i];
		while ((str[i + j] == to_find[j]) && str[i + j])
		{
			if (to_find[j + 1] == '\0')
				return (ret_ptr);
			++j;
		}
		++i;
	}
	return (0);
}
