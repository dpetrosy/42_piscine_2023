/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:05:42 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/31 23:28:31 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.h"

int	main(int argc, char **argv)
{
	int		i;

	if (argc == 1)
		process_stdin();
	else
	{
		i = 0;
		while (++i < argc)
			display_file(argv[i], argv[0]);
	}
	return (0);
}
