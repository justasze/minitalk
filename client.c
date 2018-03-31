/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 11:41:43 by bcozic            #+#    #+#             */
/*   Updated: 2018/03/31 16:06:11 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static void	transmit_end_of_string(int pid)
{
	int	bit_shift;

	bit_shift = -1;
	while (++bit_shift < 8)
	{
		if (kill(pid, SIGUSR2) == -1)
			exit(1);
		usleep(100);
	}
}

/*
** Here, we send the message bit by bit, with SIGUSR1 for 1
** and SIGUSR2 for 0
*/

static void	transmit_message(int pid, char *msg)
{
	int	i;
	int	bit_shift;

	i = 0;
	while (msg[i])
	{
		bit_shift = -1;
		while (++bit_shift < 8)
		{
			if ((msg[i] & (0x80 >> bit_shift)) == 0)
			{
				if (kill(pid, SIGUSR2) == -1)
					exit(1);
			}
			else if (kill(pid, SIGUSR1) == -1)
				exit(1);
			usleep(100);
		}
		i++;
	}
	transmit_end_of_string(pid);
}

int			main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
		return (0);
	pid = ft_atoi(av[1]);
	transmit_message(pid, av[2]);
	return (0);
}
