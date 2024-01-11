/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:17:21 by dapetros          #+#    #+#             */
/*   Updated: 2024/01/11 14:56:25 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	node->data = data;
	node->next = NULL;
	return (node);
}

/*
#include <stdio.h>

int main()
{
	char *str = "Hello World";
	t_list *node = ft_create_elem(str);
	printf("%s\n", node->data);
}
*/
