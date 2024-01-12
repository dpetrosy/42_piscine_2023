/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:59:12 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/29 22:04:38 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	set_values1(char **default_mat);

void	set_values(char **default_mat)
{
	default_mat[0] = ft_strdup("0");
	default_mat[1] = ft_strdup("1");
	default_mat[2] = ft_strdup("2");
	default_mat[3] = ft_strdup("3");
	default_mat[4] = ft_strdup("4");
	default_mat[5] = ft_strdup("5");
	default_mat[6] = ft_strdup("6");
	default_mat[7] = ft_strdup("7");
	default_mat[8] = ft_strdup("8");
	default_mat[9] = ft_strdup("9");
	default_mat[10] = ft_strdup("10");
	default_mat[11] = ft_strdup("11");
	default_mat[12] = ft_strdup("12");
	default_mat[13] = ft_strdup("13");
	default_mat[14] = ft_strdup("14");
	default_mat[15] = ft_strdup("15");
	default_mat[16] = ft_strdup("16");
	default_mat[17] = ft_strdup("17");
	default_mat[18] = ft_strdup("18");
	default_mat[19] = ft_strdup("19");
	default_mat[20] = ft_strdup("20");
	set_values1(default_mat);
}

void	set_values1(char **default_mat)
{
	default_mat[21] = ft_strdup("30");
	default_mat[22] = ft_strdup("40");
	default_mat[23] = ft_strdup("50");
	default_mat[24] = ft_strdup("60");
	default_mat[25] = ft_strdup("70");
	default_mat[26] = ft_strdup("80");
	default_mat[27] = ft_strdup("90");
	default_mat[28] = ft_strdup("100");
	default_mat[29] = ft_strdup("1000");
	default_mat[30] = ft_strdup("1000000");
	default_mat[31] = ft_strdup("1000000000");
	default_mat[32] = ft_strdup("1000000000000");
	default_mat[33] = ft_strdup("1000000000000000");
	default_mat[34] = ft_strdup("1000000000000000000");
	default_mat[35] = ft_strdup("1000000000000000000000");
	default_mat[36] = ft_strdup("1000000000000000000000000");
	default_mat[37] = ft_strdup("1000000000000000000000000000");
	default_mat[38] = ft_strdup("1000000000000000000000000000000");
	default_mat[39] = ft_strdup("1000000000000000000000000000000000");
	default_mat[40] = ft_strdup("1000000000000000000000000000000000000");
}
