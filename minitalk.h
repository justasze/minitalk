/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:44:23 by bcozic            #+#    #+#             */
/*   Updated: 2018/03/31 17:36:06 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define SIZE	50

typedef struct	s_data
{
	char		str[SIZE + 1];
	size_t		bit;
}				t_data;

void			handle_sigusr2(int sig);
void			handle_sigusr1(int sig);

#endif
