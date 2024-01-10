/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:56:33 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/23 16:56:53 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_in_base(char *base, char ch, int *index_ptr)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == ch)
		{
			*index_ptr = i;
			return (1);
		}
		++i;
	}
	*index_ptr = -1;
	return (0);
}

long long	ft_power(int nb, int power)
{
	int	i;
	int	num;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	num = nb;
	i = 1;
	while (i < power)
	{
		num *= nb;
		++i;
	}
	return (num);
}

int	atoi_base(char *str, char *base, int base_len, int *index_ptr)
{
	int			minus;
	long long	num;
	int			power;
	int			i;
	int			j;

	minus = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		++i;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			minus = -minus;
	if (!is_in_base(base, str[i], index_ptr))
		return (0);
	num = 0;
	j = i;
	power = -1;
	while (is_in_base(base, str[i++], index_ptr))
		++power;
	while (is_in_base(base, str[j++], index_ptr))
		num = num + (*index_ptr * ft_power(base_len, power--));
	return (num * minus);
}

int	check_base(char *base, int base_len)
{
	int	i;
	int	j;

	i = -1;
	if (!base || base_len <= 1)
		return (0);
	if (base[0] == '-' || base[0] == '+' || base[0] == ' '
		|| (base[0] >= 9 && base[0] <= 13))
		return (0);
	while (++i < base_len - 1)
	{
		j = i + 1;
		while (j < base_len)
		{
			if (base[j] == '-' || base[j] == '+' || base[i] == base[j]
				|| base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
				return (0);
			++j;
		}
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	char	ch;
	int		base_len;
	int		index;

	base_len = 0;
	ch = str[base_len];
	while (ch != '\0')
		ch = base[++base_len];
	if (!check_base(base, base_len))
		return (0);
	index = 0;
	return (atoi_base(str, base, base_len, &index));
}

/*
#include <stdio.h>

int main()
{
	printf("%d\n", ft_atoi_base("          -0121", ""));
	printf("%d\n", ft_atoi_base("          -0121", "0"));
	printf("%d\n", ft_atoi_base("          -0121", "0120"));
	printf("%d\n", ft_atoi_base("          -0121", "0120"));
	printf("%d\n", ft_atoi_base("          -0121", "+012"));
	printf("%d\n", ft_atoi_base("          -0121", "-012"));
	printf("%d\n", ft_atoi_base("          -0121", "012"));
	printf("%d\n", ft_atoi_base("          -+-+-FF", "0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("          -+-+-02C", "0123456789ABC"));
	printf("%d\n", ft_atoi_base("          -+-+-2F41", "0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("          -111", "01"));
	printf("%d\n", ft_atoi_base("          -+++-22", "01234567"));
	printf("%d\n", ft_atoi_base("          -+++-2301", "0123"));
}
*/
