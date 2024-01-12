/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 12:29:00 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/29 23:34:45 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	main(int argc, char **argv)
{
	t_line	*dict;
	int		len;
	char	*filename;
	char	*num;

	num = NULL;
	dict = NULL;
	if (argc != 2 && argc != 3)
		write(2, "Argument count error\n", 21);
	else if (!is_args_correct(argc, argv, &num, &filename))
		write(2, "Argument error\n", 15);
	else if (!num || !filename)
		write(2, "Memory allocation error\n", 24);
	else
	{
		dict = parse_dict(filename);
		len = ft_strlen(num);
		if (!dict)
			write(2, "Dict Error\n", 11);
		else if (!solver(dict, num, len))
			write(2, "Dict Error\n", 11);
		free_all(dict, filename, num);
	}
	return (0);
}
