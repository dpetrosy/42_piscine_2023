/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:38:50 by dapetros          #+#    #+#             */
/*   Updated: 2024/01/11 14:57:54 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	i;

	i = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		++i;
	}
	return (i);
}

/*
#include <stdlib.h>
#include <stdio.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	node->data = data;
	node->next = NULL;
	return (node);
}

int main()
{
	t_list *node1 = ft_create_elem("1");
	t_list *node2 = ft_create_elem("2");
	t_list *node3 = ft_create_elem("3");
	node1->next = node2;
	node2->next = node3;
	printf("%d\n", ft_list_size(node1));
}
*/
