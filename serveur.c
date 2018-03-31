/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 11:41:44 by bcozic            #+#    #+#             */
/*   Updated: 2018/03/31 15:21:22 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "libft.h"

int		k = 0;
char	*str;

void handleSigusr1(int sig)
{
	str[k / 8] |= (0b10000000 >> ((k % 8)));
	k++;

}

void handleSigusr2(int sig)
{
	str[k / 8] ^= (0b10000000 >> ((k % 8)));
	k++;
}

int main(int ac, char **av) 
{
	int	len;
	ft_printf("Server running (PID : %d):\n", getpid());
//	signal(SIGUSR1, nb);
//	signal(SIGUSR2, create_str);
//	len = k * 4 + 4;
//	k = 0;
	if (!(str = malloc(10)))
		exit(0);
	ft_memset(str, 0xFFFF, 10);
	ft_printf("A %p", str);
	signal(SIGUSR1, handleSigusr1);
	signal(SIGUSR2, handleSigusr2);
	ft_printf("B\n");
	//k = 0;
	while(1)
	{
		if (k != 0 && str[((k - 1) / 8)] == 0)
		{
			ft_printf("%s\n", str);
			ft_memset(str, 0xFFFF, 10);
			k = 0;
		}
		usleep(100);
	}
//	ft_printf("%s\n", str);
	free(str);
	return (0); 
}
