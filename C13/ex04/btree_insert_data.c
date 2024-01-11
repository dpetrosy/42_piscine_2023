/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:52:54 by dapetros          #+#    #+#             */
/*   Updated: 2023/11/01 19:55:05 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *))
{
	if (!root || !item || !cmpf)
		return ;
	if (*root == NULL)
	{
		*root = btree_create_node(item);
		return ;
	}
	if (cmpf(item, (*root)->item) >= 0)
		btree_insert_data(&((*root)->right), item, cmpf);
	else
		btree_insert_data(&((*root)->left), item, cmpf);
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

void	print_node_item(void *str)
{
	printf("%s ", (char *)str);
}

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (!root || !applyf)
		return ;
	applyf(root->item);
	btree_apply_prefix(root->left, applyf);
	btree_apply_prefix(root->right, applyf);
}

int main()
{
	t_btree *root = btree_create_node("5");
	t_btree *left1 = btree_create_node("3");
	t_btree *right1 = btree_create_node("7");
	t_btree *left2 = btree_create_node("2");
	//t_btree *right2 = btree_create_node("4");
	t_btree *left3 = btree_create_node("6");
	t_btree *right3 = btree_create_node("8");

	root->left = left1;
	root->right = right1;

	left1->left = left2;
	//left1->right = right2;

	right1->left = left3;
	right1->right = right3;

	btree_insert_data(&root, "4", &ft_strcmp);
	btree_apply_prefix(root, &print_node_item);
	printf("\n");
}
*/
