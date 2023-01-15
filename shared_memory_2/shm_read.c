/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shm_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 03:58:11 by joeduard          #+#    #+#             */
/*   Updated: 2023/01/14 19:14:14 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <unistd.h>

# define ever ;;

typedef struct s_shm_buf
{
    int v;
}   t_shm_buf;

int main(void)
{
    int fd;
    t_shm_buf *ptr;

     // passo 1 a 3: abre/cria um area de memoria compartilhada
    fd = shm_open("/sharedmem", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);

    // ajusta o tamanho da area compartilhada para sizeof(value)
    ftruncate(fd, sizeof(t_shm_buf));

    // passo 4 a 6: mapeia a area no espaco de enderecamento deste processo
    ptr = mmap(NULL, sizeof(t_shm_buf), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    for (ever)
    {
        printf("Read valeu %i\n", ptr->v);
    }
    return(0);
}

// usar a Flag -lrt para compilar

//gcc -o shm_read shm_read.c -lrt