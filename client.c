/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:33:01 by liperman          #+#    #+#             */
/*   Updated: 2022/09/06 11:27:30 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

void	ft_signal(unsigned char *binary, int pid)
{
	int	i;

	i = 0;
	while (binary[i] != '\0')
	{
		if (binary[i] == '1')
			kill(pid, SIGUSR1);
		if (binary[i] == '0')
			kill(pid, SIGUSR2);
		i++;
		usleep(250);
	}
}

void	ft_atob(unsigned char character, int pid)
{
	unsigned char	*binary;
	size_t			i;

	i = 8;
	binary = malloc(9);
	while (i)
	{
		binary[--i] = (character % 2) + 48;
		character = character / 2;
	}
	binary[8] = '\0';
	ft_signal(binary, pid);
	free(binary);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	pid;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i] != '\0')
	{
		ft_atob(argv[2][i], pid);
		i++;
	}
	return (0);
}
