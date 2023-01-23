/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:14:14 by joeduard          #+#    #+#             */
/*   Updated: 2023/01/15 19:49:13 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "labs.h"

int get_file_size()
{
    FILE *file;
    int size;

    size = 0;
    file = fopen("test.txt", "r");
    
    if(file)
    {
        while(fgetc(file) != -1)
        {
            size++;
        }
        fclose(file);

    }
    else
        printf("Error\n Open file in get_file_size!\n");
    return(size);
}

void	read_text(unsigned char *text)
{
	FILE *file;
	int i;
	char letter;

	i = 0;
    file = fopen("test.txt", "r");
    
    if(file)
    {
		while(!feof(file))
		{
			letter = fgetc(file);
			if(letter != -1)
			{
				text[i] = letter;
				i++;
			}		
		}
        fclose(file);

    }
    else
        printf("Error\n Open file in read_text!\n");
}
