/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:53:11 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/30 23:02:35 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	print_base(unsigned long long num, int zero)
{
	char		str[20];
	char		*base;
	size_t		len;
	size_t		rem;
	size_t		i;

	i = 0;
	len = 16;
	base = "0123456789abcdef";
	if (num < 16)
		write(1, "0", 1);
	if (num == 0)
		write(1, "0", 1);
	while (num != 0)
	{
		rem = num % len;
		str[i] = base[rem];
		++i;
		num = num / len;
	}
	if (zero)
		while (len-- > i)
			write(1, "0", 1);
	while (i-- > 0)
		write(1, str + i, 1);
}

void	print_spaces(int i)
{
	while (i < 16)
	{
		write(1, "     ", 5);
		i += 2;
	}
}

void	process_line(unsigned char *line)
{
	int		i;

	print_base((unsigned long long)line, 1);
	write(1, ":", 1);
	i = -1;
	while (++i < 16 && line[i])
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		print_base(line[i], 0);
	}
	write(1, " ", 1);
	if (i != 15)
		print_spaces(i);
	i = -1;
	while (++i < 16 && line[i])
	{
		if (line[i] < 32 || line[i] > 126)
			write (1, ".", 1);
		else
			write (1, line + i, 1);
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	if (size <= 0)
		return (addr);
	i = 0;
	while (i < size)
	{
		process_line(addr + i);
		i += 16;
	}
	return (addr);
}
