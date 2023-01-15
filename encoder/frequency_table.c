/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frequency_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 03:08:20 by joeduard          #+#    #+#             */
/*   Updated: 2023/01/14 03:35:41 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/labs.h"

//-------------------parte 1: Tabela de Frequencia---------------------

void	initialize_table(unsigned int tab[])
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		tab[i] = 0;
		i++;
	}
}

void	fill_frequency_table(unsigned char text[], unsigned int tab[])
{
	int	i;

	i = 0;
	while (text[i] != '\0')
	{
		tab[text[i]]++;
		i++;
	}
}

void	print_frequecy_table(unsigned int tab[])
{
	int	i;

	i = 0;
	printf("\t ---TABELA DE FREQUENCIA---\n");
	while (i < SIZE)
	{
		if (tab[i] > 0)
			printf("\t DEC:%d \t FREQUENCIA = %u \t  CHAR = %c\n", i, tab[i], i);
		i++;
	}
}
