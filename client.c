/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 11:41:43 by bcozic            #+#    #+#             */
/*   Updated: 2018/03/31 16:00:11 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static void	transmit_bits(int *bit_shift, int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		*bit_shift = -1;
		while (++(*bit_shift) < 8)
		{
			if ((msg[i] & (0x80 >> *bit_shift)) == 0)
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
}

int			main(int ac, char **av)
{
	int	bit_shift;
	int	pid;

	if (ac != 3)
		return (0);
	pid = ft_atoi(av[1]);
	transmit_bits(&bit_shift, pid, av[2]);
	bit_shift = -1;
	while (++bit_shift < 8)
	{
		if (kill(pid, SIGUSR2) == -1)
			return (1);
		usleep(100);
	}
	return (0);
}
