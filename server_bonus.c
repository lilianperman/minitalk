/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:34:15 by liperman          #+#    #+#             */
/*   Updated: 2022/09/07 16:16:17 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <stdlib.h>

void	ft_handler(int signal, siginfo_t *info, void *context)
{
	static char	b;
	static char	i;

	(void)(context);
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
		if (b != 0)
		{
			write(1, &b, 1);
		}
		else
			kill(info->si_pid, SIGUSR1);
		i = 0;
		b = 0;
	}
}

int	main(void)
{
	struct sigaction	sact;

	sact.sa_sigaction = ft_handler;
	sact.sa_flags = SA_SIGINFO;
	sact.sa_mask = 0;
	sigaction(SIGUSR1, &sact, NULL);
	sigaction(SIGUSR2, &sact, NULL);
	ft_printf("the process id is: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
