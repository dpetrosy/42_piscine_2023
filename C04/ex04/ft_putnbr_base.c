/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:39:10 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/17 20:39:21 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

int	check_base(char *base, int base_len)
{
	int	i;
	int	j;

	i = -1;
	if (!base || base[0] == '\0' || base_len <= 1)
		return (0);
	if (base[0] == '-' || base[0] == '+')
		return (0);
	while (++i < base_len - 1)
	{
		j = i + 1;
		while (j < base_len)
		{
			if (base[j] == '-' || base[j] == '+' || base[i] == base[j])
				return (0);
			++j;
		}
	}
	return (1);
}

void	putnbr_base(long num, char *base, int base_len)
{
	if (num >= base_len)
		putnbr_base(num / base_len, base, base_len);
	write(1, &base[num % base_len], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	num;
	int		base_len;

	num = nbr;
	base_len = ft_strlen(base);
	if (!check_base(base, base_len))
		return ;
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	putnbr_base(num, base, base_len);
}

/*
int main()
{
	ft_putnbr_base(-89, "012345");
}
*/
