/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   huffman_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:56:09 by joeduard          #+#    #+#             */
/*   Updated: 2023/01/15 19:49:01 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "labs.h"

t_node	*remove_first_node(t_list *list)
{
	t_node	*aux;

	aux = NULL;
	if (list->first_node)
	{
		aux = list->first_node;
		list->first_node = aux->next;
		aux->next = NULL;
		list->tam--;
	}
	return (aux);
}

t_node	*mount_tree(t_list *list)
{
	t_node	*first;
	t_node	*second;
	t_node	*new;

	while (list->tam > 1)
	{
		first = remove_first_node(list);
		second = remove_first_node(list);
		new = malloc(sizeof(t_node));
		if (new)
		{
			new->character = '+';
			new->frequency = first->frequency + second->frequency;
			new->left = first;
			new->right = second;
			new->next = NULL;
			insert_in_order(list, new);
		}
		else
		{
			printf("ERROR: Malloc failure in mount_tree!\n");
			break ;
		}
	}
	return (list->first_node);
}

void	print_tree(t_node *root, int tam)
{
	if (root->left == NULL && root->right == NULL)
		printf("\t Folha: %c\tAltura: %d\n", root->character, tam);
	else
	{
		print_tree(root->left, tam + 1);
		print_tree(root->right, tam + 1);
	}
}

int	tree_height(t_node *root)
{
	int	left;
	int	right;

	if (root == NULL)
		return (-1);
	left = tree_height(root->left) + 1;
	right = tree_height(root->right) + 1;
	if (left > right)
		return (left);
	else
		return (right);
}
