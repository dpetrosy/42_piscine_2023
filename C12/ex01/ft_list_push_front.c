/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:32:21 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/27 16:07:26 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*node;

	node = ft_create_elem(data);
	if (!node)
		return ;
	node->next = *begin_list;
	*begin_list = node;
}

/*
#include <stdio.h>

int main()
{
	char *str = "Hello";
	char *str1 = "World";
	t_list *node = ft_create_elem(str);
	t_list **begin = &node;

	ft_list_push_front(begin, str);
	printf("%s\n", (*begin)->data);

	ft_list_push_front(begin, str1);
	printf("%s\n", (*begin)->data);
}
*/
