/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:27:38 by dapetros          #+#    #+#             */
/*   Updated: 2023/11/01 18:30:46 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (!root || !applyf)
		return ;
	btree_apply_suffix(root->left, applyf);
	btree_apply_suffix(root->right, applyf);
	applyf(root->item);
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

void	print_node_item(void *str)
{
	printf("%s ", (char *)str);
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

	btree_apply_suffix(root, &print_node_item);
	printf("\n");
}
*/
