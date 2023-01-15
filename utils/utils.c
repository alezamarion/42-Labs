/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:18:17 by joeduard          #+#    #+#             */
/*   Updated: 2023/01/14 21:39:59 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/labs.h"

void	free_table(char **table)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		free(table[i]);
		i++;
	}
	free(table);
}

void	free_tree(t_node *root)
{
	if (root == NULL)
		return ;
	free_tree(root->left);
	free_tree(root->right);
	free(root);
}

void	init_data(t_huff *data)
{
	bzero(&data->text, sizeof(t_huff));
	bzero(&data->tree, sizeof(t_node));
	bzero(&data->encoded, sizeof(char));
	bzero(&data->decoded, sizeof(char));
}
