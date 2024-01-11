/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:45:41 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/27 00:09:05 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	if (begin_list == 0)
		return (0);
	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
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
	t_list *last = ft_list_last(node1);
	printf("%s\n", last->data);
}
*/
