/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:05:40 by adi-stef          #+#    #+#             */
/*   Updated: 2023/02/26 15:10:35 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf/printflibft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_pow(int n, int e)
{
	int	i;

	i = 1;
	while (e--)
		i *= n;
	return (i);
}

/* SIGUSR1:1 SIGUSR2:0 */
void	handler(int signum, siginfo_t *info, void *p)
{
	static unsigned char	c;
	static int				i;

	(void)p;
	c += ft_pow(2, i++) * (signum == SIGUSR1);
	if (i >= 8)
	{
		write(1, &c, 1);
		if (!c)
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR2);
		}
		else
			kill(info->si_pid, SIGUSR1);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	action;

	ft_printf("Program started with pid number: %d\n", getpid());
	action.sa_sigaction = handler;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, 0);
	sigaction(SIGUSR2, &action, 0);
	while (1)
		pause();
	ft_printf("Progam ended correctly\n");
	return (0);
}
