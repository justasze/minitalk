/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 11:41:44 by bcozic            #+#    #+#             */
/*   Updated: 2018/03/31 13:51:24 by bcozic           ###   ########.fr       */
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
	ft_printf("1");
	str[k / 4] = str[k / 4] & (*str >> (k % 4) | (1 << (k % 4)));
	ft_printf(" ");
	k++;
}

void handleSigusr2(int sig)
{
	ft_printf("0");
	*str = *str & (*str >> k & 0b0);
	k++;
}

void nb(int sig)
{
	ft_printf("++1\n");
	k++;
}

void	create_str(int sig)
{
	ft_printf("%d\n", k);
	if (!(str = malloc(k)))
		exit(0);
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
	ft_printf("A %d\n", len);
	signal(SIGUSR1, handleSigusr1);
	signal(SIGUSR2, handleSigusr2);
	ft_printf("B\n");
	ft_printf("%s\n", str);
	free(str);
	str = NULL;
	ft_printf("test");
	while(1)
		pause();
	ft_printf("where");
	return (0); 
}
