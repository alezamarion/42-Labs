/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:05:09 by joeduard          #+#    #+#             */
/*   Updated: 2023/01/15 19:48:36 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "labs.h"

int	calculate_string_size(char **dictionary, unsigned char *text)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (text[i] != '\0')
	{
		size = size + strlen(dictionary[text[i]]);
		i++;
	}
	return (size + 1);
}

char	*code(char **dictionary, unsigned char *text)
{
	int		i;
	int		size;
	char	*code;

	i = 0;
	size = 0;
	size = calculate_string_size(dictionary, text);
	code = calloc(size, sizeof(char));
	while (text[i] != '\0')
	{
		strcat(code, dictionary[text[i]]);
		i++;
	}
	return (code);
}

void	compress_file(char str[])
{
	int				i;
	int				j;
	unsigned char	mask;
	unsigned char	byte;

	i = 0;
	j = 7;
	byte = 0;
	FILE *file = fopen("compressed.jrg", "wb");
	if (file)
	{
		while(str[i] != '\0')
		{
			mask = 1;
			if(str[i] == '1')
			{
				mask = mask << j;
				byte = byte | mask;
			}
			j--;
			if (j < 0)
			{
				fwrite(&byte, sizeof(unsigned char), 1, file);
				byte = 0;
				j = 7;	
			}
			i++;
		}
		if (j != 7)
			fwrite(&byte, sizeof(unsigned char), 1, file);
		fclose(file);		
	}
	else
		printf("Error\n Open/Create file in compress_bits!\n");
}
