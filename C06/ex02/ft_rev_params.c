/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 00:51:36 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/17 00:51:38 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int		j;
	char	*str;

	while (--argc >= 1)
	{
		j = -1;
		str = argv[argc];
		while (str[++j] != '\0')
			write(1, &str[j], 1);
		write(1, "\n", 1);
	}
	return (0);
}
