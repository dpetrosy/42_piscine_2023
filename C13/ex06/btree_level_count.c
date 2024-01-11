/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:50:52 by dapetros          #+#    #+#             */
/*   Updated: 2023/11/01 20:51:18 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int	left_subtree_depth;
	int	right_subtree_depth;

	if (!root)
		return (0);
	left_subtree_depth = btree_level_count(root->left);
	right_subtree_depth = btree_level_count(root->right);
	if (left_subtree_depth > right_subtree_depth)
		return (left_subtree_depth + 1);
	else
		return (right_subtree_depth + 1);
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

int main()
{
	t_btree *root = btree_create_node("1");
	t_btree *left1 = btree_create_node("2");
	t_btree *right1 = btree_create_node("3");
	t_btree *left2 = btree_create_node("4");
	t_btree *right2 = btree_create_node("5");
//	t_btree *left3 = btree_create_node("6");
//	t_btree *right3 = btree_create_node("8");

	root->left = left1;
	root->right = right1;

	left1->left = left2;
	left1->right = right2;

//	right1->left = left3;
//	right1->right = right3;

	printf("%d\n", btree_level_count(root));
}
*/
