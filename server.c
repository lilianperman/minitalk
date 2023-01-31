/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:34:15 by liperman          #+#    #+#             */
/*   Updated: 2022/09/07 14:29:36 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <stdlib.h>

void	ft_handler(int signal)
{
	static char	b;
	static char	i;

	if (!i)
		i = 0;
	if (signal == SIGUSR1)
	{
		b = b | 1 << (7 - i);
		i++;
	}
	if (signal == SIGUSR2)
		i++;
	if (i == 8)
	{
		write(1, &b, 1);
		i = 0;
		b = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	ft_printf("the process id is: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
