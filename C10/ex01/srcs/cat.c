/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:37:02 by dapetros          #+#    #+#             */
/*   Updated: 2024/01/11 14:39:54 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.h"

void	ft_putstr(int fd, char *str)
{
	while (*str)
	{
		write(fd, str, 1);
		++str;
	}
}

void	display_error(char *filename, char *program_name)
{
	ft_putstr(2, basename(program_name));
	write(2, ": ", 2);
	ft_putstr(2, filename);
	write(2, ": ", 2);
	ft_putstr(2, strerror(errno));
	write(2, "\n", 1);
}

void	process_stdin(void)
{
	size_t	read_bytes;
	char	buffer[1025];

	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(0, buffer, 1024);
		if (errno != 0)
		{
			display_error(NULL, NULL);
			break ;
		}
		buffer[read_bytes] = '\0';
		ft_putstr(1, buffer);
	}
}

void	display_file(char *filename, char *program_name)
{
	int		fd;
	size_t	read_bytes;
	char	buffer[1025];

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		display_error(filename, program_name);
		return ;
	}
	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buffer, 1024);
		if (errno != 0)
		{
			display_error(NULL, NULL);
			break ;
		}
		buffer[read_bytes] = '\0';
		ft_putstr(1, buffer);
	}
	close(fd);
}
