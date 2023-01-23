/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:18:17 by joeduard          #+#    #+#             */
/*   Updated: 2023/01/15 19:49:22 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "labs.h"

void	free_table(char **table)
{
	int	i;

	i = 0;
	while (i < SIZEBLOCK)
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
