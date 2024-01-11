/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:23:31 by dapetros          #+#    #+#             */
/*   Updated: 2023/11/02 15:21:43 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void	*left_node;
	void	*right_node;

	if (!root || !data_ref || !cmpf)
		return (NULL);
	left_node = btree_search_item(root->left, data_ref, cmpf);
	if (cmpf(root->item, data_ref) == 0)
		return (root->item);
	right_node = btree_search_item(root->right, data_ref, cmpf);
	if (left_node != NULL)
		return (left_node);
	return (right_node);
}

/*
#include <stdio.h>

t_btree	*btree_create_node(void *item)
{
	t_btree	*node;

	node = (t_btree *)malloc(sizeof(t_btree));
	if (!node)
		return (NULL);
	node->item = item;
	node->right = NULL;
	node->left = NULL;
	return (node);
}

int	ft_strcmp(void *s11, void *s22)
{
	char *s1 = (char *)s11;
	char *s2 = (char *)s22;

	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		++s1;
		++s2;
	}
	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

int main()
{
	t_btree *root = btree_create_node("1");
	t_btree *left1 = btree_create_node("2");
	t_btree *right1 = btree_create_node("3");
	t_btree *left2 = btree_create_node("4");
	t_btree *right2 = btree_create_node("5");
	t_btree *left3 = btree_create_node("6");
	t_btree *right3 = btree_create_node("7");

	root->left = left1;
	root->right = right1;

	left1->left = left2;
	left1->right = right2;

	right1->left = left3;
	right1->right = right3;

	char *str = btree_search_item(root, "2", &ft_strcmp);
	if (str == NULL)
		printf("APE NULL EM, VOR TPES INDZI SEGFAULT EM TALU, BA QEZI PETQA\n");
	else
	{
		printf("node item = %s\n", str);
	}
}
*/
