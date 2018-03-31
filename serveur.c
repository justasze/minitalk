/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 11:41:44 by bcozic            #+#    #+#             */
/*   Updated: 2018/03/31 14:45:09 by bcozic           ###   ########.fr       */
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
		if (k % 8 == 0)
	ft_printf("\n");
	write(1, str, 10);
	ft_printf("1 %d %c ", k, str[k / 8]);
	str[k / 8] = str[k / 8] & (str[k / 8] >> (k % 8) | (1 << (k % 8)));
	k++;
}

void handleSigusr2(int sig)
{
	if (k % 8 == 0)
	ft_printf("\n");
		write(1, str, 10);
	ft_printf("0 %d %b ", k, str[k / 8]);
	str[k / 8] = str[k / 8] & (str[k / 8] >> (k % 8) | (0xFC << (k % 8)));
	k++;
}

// void nb(int sig)
// {
// 	ft_printf("++1\n");
// 	k++;
// }

// void	create_str(int sig)
// {
// 	ft_printf("%d\n", k);
// 	if (!(str = malloc(k)))
// 		exit(0);
// }

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
		if (k != 0 && str[((k) / 8)] == 0)
			break ;
		usleep(100);
	}
	ft_printf("%s\n", str);
	free(str);
	return (0); 
}
