/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:53:39 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/30 17:55:46 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

void	ft_putchar(unsigned char c)
{
	write (1, &c, 1);
}

bool	is_printable(unsigned char c)
{
	if (c >= 32 && c <= 126)
		return (true);
	return (false);
}

void	print_hex(unsigned char c)
{
	char			*hex;
	unsigned char	ch1;
	unsigned char	ch2;

	hex = "0123456789abcdef";
	ch1 = hex[c / 16];
	ch2 = hex[c % 16];
	ft_putchar('\\');
	ft_putchar(ch1);
	ft_putchar(ch2);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (!is_printable(str[i]))
			print_hex(str[i]);
		else
			ft_putchar(str[i]);
	}
}

/*
int main()
{
	char *str = "Coucou\ntu vas bien ?";
	ft_putstr_non_printable(str);
}
*/
