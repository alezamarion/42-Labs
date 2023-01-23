/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompress.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:06:27 by joeduard          #+#    #+#             */
/*   Updated: 2023/01/15 19:48:28 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "labs.h"

char	*decode(char text[], t_node *root)
{
	int		i;
	t_node	*aux;
	char	*decode;
	char	temp[2];

	decode = calloc(strlen(text), sizeof(char));
	aux = root;
	i = 0;
	while (text[i] != '\0')
	{
		if (text[i] == '0')
			aux = aux->left;
		else
			aux = aux->right;
		if (aux->left == NULL && aux->right == NULL)
		{
			temp[0] = aux->character;
			temp[1] = '\0';
			strcat(decode, temp);
			aux = root;
		}
		i++;
	}
	return (decode);
}

unsigned int	is_bit_1(unsigned char byte, int i)
{
	unsigned char	mask;

	mask = 1 << i;
	return(byte & mask);
}

void	unzip_file(t_node *root)
{
	int	i;
	unsigned char	byte;
	t_node			*aux;

	aux = root;
	FILE *file = fopen("compressed.jrg", "rb");
	if (file)
	{
		
		while (fread(&byte, sizeof(unsigned char), 1, file))
		{
			i = 7;
			while (i >= 0)
			{
				if (is_bit_1(byte, i))
					aux = aux->right;
				else
					aux = aux->left;
				if (aux->left == NULL && aux->right == NULL)
				{
					printf("%c", aux->character);
					aux = root;
				}
				i--;
			}
		}
		fclose(file);
	}
	else
		printf("Error\n Open/Create file in unzip_file!\n");
}
