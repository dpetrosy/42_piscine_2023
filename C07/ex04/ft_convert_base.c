/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:40:35 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/31 17:42:43 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

int		atoi_base(char *str, char *base, int base_len, int *index_ptr);
bool	is_base_correct(char *base);
int		ft_strlen(char *s);

int	calc_num_len(long num, int base_to_len)
{
	int	len;

	if (num == 0)
		return (1);
	len = 0;
	if (num < 0)
	{
		len = 1;
		num = -num;
	}
	while (num > 0)
	{
		num /= base_to_len;
		++len;
	}
	return (len);
}

void	calc_final_num(char *num, int num_len, long pre_num, char *base_to)
{
	int		base_len;

	if (pre_num == 0)
	{
		num[0] = base_to[0];
		return ;
	}
	base_len = ft_strlen(base_to);
	if (pre_num < 0)
	{
		num[0] = '-';
		pre_num = -pre_num;
	}
	while (pre_num > 0)
	{
		num[num_len] = base_to[pre_num % base_len];
		pre_num /= base_len;
		--num_len;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*final_num;
	int		pre_num;
	int		final_num_len;
	int		base_from_len;
	int		index;

	if (!is_base_correct(base_from) || !is_base_correct(base_to))
		return (NULL);
	index = 0;
	base_from_len = ft_strlen(base_from);
	pre_num = atoi_base(nbr, base_from, base_from_len, &index);
	final_num_len = calc_num_len(pre_num, ft_strlen(base_to));
	final_num = (char *)malloc(sizeof(char) * (final_num_len + 1));
	if (!final_num)
		return (NULL);
	final_num[final_num_len] = '\0';
	calc_final_num(final_num, final_num_len - 1, pre_num, base_to);
	return (final_num);
}

/*
#include <stdio.h>

int main()
{
	printf("%s\n", ft_convert_base("     ---123", "01234", "01"));
	printf("%s\n", ft_convert_base("2147483647", "0123456789", 
	"0123456789abcdef"));
	printf("%s\n", ft_convert_base("-2147483648", "0123456789", "012345"));
	printf("%s\n", ft_convert_base("---7fffffff", "0123456789abcdef", "01"));
	printf("%s\n", ft_convert_base("---+--0001023a", "0123456789", 
	"0123456789"));
	printf("%s\n", ft_convert_base("-0", "0123456789", "abcdef"));
	printf("%s\n", ft_convert_base("   \t\t\t\n05841fff4", 
	"0123456789abcdef", "0123"));
}
*/
