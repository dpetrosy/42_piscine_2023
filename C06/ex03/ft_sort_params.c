/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:24:56 by dapetros          #+#    #+#             */
/*   Updated: 2024/01/10 14:53:09 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	display_sorted_args(int argc, char **argv)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		str = argv[i];
		while (str[++j])
			write (1, &str[j], 1);
		write (1, "\n", 1);
	}
}

void	swap(int j, char **argv)
{
	char	*tmp;

	tmp = argv[j];
	argv[j] = argv[j + 1];
	argv[j + 1] = tmp;
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		++s1;
		++s2;
	}
	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*str1;
	char	*str2;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (++j < argc - i)
		{
			str1 = argv[j];
			str2 = argv[j + 1];
			if (ft_strcmp(str1, str2) > 0)
				swap(j, argv);
		}
	}
	display_sorted_args(argc, argv);
	return (0);
}
