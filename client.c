/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 11:41:43 by bcozic            #+#    #+#             */
/*   Updated: 2018/03/31 15:10:08 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft.h"

int main(int ac, char **av)
{
	int i;
	int	k;
	int	pid;

	if (ac != 3)
		return (0);
	i = 0;
	pid = ft_atoi(av[1]);
	// while (i--)
	// {
	// 	if (kill(pid, SIGUSR1) == -1)
	// 		return (1);
	// 	usleep(10);
	// }
	// if (kill(pid, SIGUSR2) == -1)
	// 	return (1);
	while (av[2][i])
	{
		k = -1;
		ft_printf("%8hhb\n", av[2][i]);
		while (++k < 8)
		{
			ft_printf("A");
			if ((av[2][i] & (0b10000000 >> k)) == 0)
			{
				if (kill(pid, SIGUSR2) == -1)
					return (1);
			}
			else
				if (kill(pid, SIGUSR1) == -1)
					return (1);
			usleep(100);
		}
		i++;
	}
	k = -1;
	while (++k < 8)
	{
		if (kill(pid, SIGUSR2) == -1)
			return (1);
		usleep(100);
	}
	return (0);
}
