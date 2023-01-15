/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 03:15:03 by joeduard          #+#    #+#             */
/*   Updated: 2023/01/14 03:32:25 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/labs.h"

void	creat_list(t_list *list)
{
	list->first_node = NULL;
	list->tam = 0;
}

void	insert_in_order(t_list *list, t_node *node)
{
	t_node	*aux;

	if (list->first_node == NULL)
		list->first_node = node;
	else if (node->frequency < list->first_node->frequency)
	{
		node->next = list->first_node;
		list->first_node = node;
	}
	else
	{
		aux = list->first_node;
		while (aux->next && aux->next->frequency <= node->frequency)
		{
			aux = aux->next;
		}
		node->next = aux->next;
		aux->next = node;
	}
	list->tam++;
}

void	fill_list(unsigned int tab[], t_list *list)
{
	int		i;
	t_node	*new;

	i = 0;
	while (i < SIZE)
	{
		if (tab[i] > 0)
		{
			new = malloc(sizeof(t_node));
			if (!new)
			{
				printf("ERROR: Malloc failure in fill_list!\n");
				exit(EXIT_FAILURE);
			}	
			new->character = i;
			new->frequency = tab[i];
			new->right = NULL;
			new->left = NULL;
			new->next = NULL;
			insert_in_order(list, new);
		}
		i++;
	}
}

void	print_list(t_list *list)
{
	t_node	*aux;

	aux = list->first_node;
	printf("\n\t---LISTA ORDENADA---\n\t Tamanho: %d\n", list->tam);
	while (aux)
	{
		printf("\tCaracter: %c Frequency: %d \n", aux->character, aux->frequency);
		aux = aux->next;
	}
}
