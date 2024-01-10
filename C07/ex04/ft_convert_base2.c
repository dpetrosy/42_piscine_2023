/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:51:02 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/31 19:51:04 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

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

bool	is_base_correct(char *base)
{
	int	base_len;
	int	i;
	int	j;

	i = -1;
	base_len = ft_strlen(base);
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
				|| base[j] == ' ' || (base[j] >= 9 && base[j] <= 13))
				return (false);
			++j;
		}
	}
	return (true);
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
