/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 11:41:43 by bcozic            #+#    #+#             */
/*   Updated: 2018/04/01 14:11:22 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	usage(char *name)
{
	ft_printf("usage: %s <pid> <msg>\n", name);
}

static void	transmit_end_of_string(int pid, int i)
{
	int	bit_shift;

	bit_shift = -1;
	while (++bit_shift < 8)
	{
		if (kill(pid, SIGUSR2) == -1)
			exit(1);
		usleep(20);
	}
	if (i % SIZE == SIZE - 1)
	{
		usleep(80);
		transmit_end_of_string(pid, i + 1);
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
			usleep(20);
		}
		i++;
		if (i != 0 && i % SIZE == 0)
			usleep(80);
	}
	transmit_end_of_string(pid, i);
}

int			main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		usage(av[0]);
		return (0);
	}
	pid = ft_atoi(av[1]);
	transmit_message(pid, av[2]);
	return (0);
}
