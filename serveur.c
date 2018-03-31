/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 11:41:44 by bcozic            #+#    #+#             */
/*   Updated: 2018/03/31 17:37:32 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "libft.h"
#include "minitalk.h"

t_data			g_data;

void	handle_sigusr1(int sig)
{
	g_data.str[g_data.bit / 8] |= (0x80 >> ((g_data.bit % 8)));
	g_data.bit++;
}

void	handle_sigusr2(int sig)
{
	g_data.str[g_data.bit / 8] ^= (0x80 >> ((g_data.bit % 8)));
	g_data.bit++;
}

int		main(int ac, char **av)
{
	int		enter;

	g_data.bit = 0;
	ft_printf("Server running (PID : %d):\n", getpid());
	g_data.str[SIZE] = '\0';
	ft_memset(g_data.str, 0xFF, SIZE);
	signal(SIGUSR1, handle_sigusr1);
	signal(SIGUSR2, handle_sigusr2);
	while (1)
	{
		if (g_data.bit != 0 && (g_data.str[((g_data.bit - 1) / 8)] == 0
			|| ((g_data.bit) / 8) >= SIZE))
		{
			enter = (((g_data.bit) / 8) < SIZE) ? 1 : 0;
			g_data.bit = 0;
			ft_printf("%s", g_data.str);
			if (enter)
				ft_printf("\n");
			ft_memset(g_data.str, 0xFF, SIZE);
		}
	}
	return (0);
}
