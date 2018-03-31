/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 11:41:44 by bcozic            #+#    #+#             */
/*   Updated: 2018/03/31 17:31:38 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "libft.h"
#include "minitalk.h"

t_data			data;

void	handle_sigusr1(int sig)
{
	data.str[data.bit / 8] |= (0x80 >> ((data.bit % 8)));
	data.bit++;
}

void	handle_sigusr2(int sig)
{
	data.str[data.bit / 8] ^= (0x80 >> ((data.bit % 8)));
	data.bit++;
}

int		main(int ac, char **av) 
{
	int		enter;

	data.bit = 0;
	ft_printf("Server running (PID : %d):\n", getpid());
	data.str[SIZE] = '\0';
	ft_memset(data.str, 0xFF, SIZE);
	signal(SIGUSR1, handle_sigusr1);
	signal(SIGUSR2, handle_sigusr2);
	while(1)
	{
		if (data.bit != 0 && (data.str[((data.bit - 1) / 8)] == 0 || ((data.bit) / 8) >= SIZE))
		{
			enter = (((data.bit) / 8) < SIZE) ? 1 : 0;
			data.bit = 0;
			ft_printf("%s", data.str);
			if (enter)
				ft_printf("\n");
			ft_memset(data.str, 0xFF, SIZE);
		}
		//usleep(50);
	}
	return (0); 
}
