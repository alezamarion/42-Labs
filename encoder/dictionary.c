/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:45:30 by joeduard          #+#    #+#             */
/*   Updated: 2023/01/14 03:35:46 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/labs.h"

char	**allocate_dictionary(int colunms)
{
	char	**dictionary;
	int		i;

	i = 0;
	dictionary = malloc(sizeof(char *) * SIZE);
	if (!dictionary)
	{
		printf("ERROR: Malloc failure in allocate_dictionary!\n");
		exit(EXIT_FAILURE);
	}
	while (i < SIZE)
	{
		dictionary[i] = calloc(colunms, sizeof(char));
		i++;
	}
	return (dictionary);
}

void	generate_dictionary(char **dict, t_node *root, char *path, int colunms)
{
	char	left[colunms];
	char	right[colunms];

	if (root->left == NULL && root->right == NULL)
	{
		strcpy(dict[root->character], path);
	}
	else
	{
		strcpy(left, path);
		strcpy(right, path);
		strcat(left, "0");
		strcat(right, "1");
		generate_dictionary(dict, root->left, left, colunms);
		generate_dictionary(dict, root->right, right, colunms);
	}
}

void	print_dictionary(char **dictionary)
{
	int	i;

	printf("\t---DICIONARIO:---\n");
	i = 0;
	while (i < SIZE)
	{
		if (strlen(dictionary[i]) > 0)
			printf("\t%3d: %s\n", i, dictionary[i]);
		i++;
	}
}
