/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:05:40 by adi-stef          #+#    #+#             */
/*   Updated: 2023/02/26 15:09:49 by adi-stef         ###   ########.fr       */
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
void	ft_handler(int signum)
{
	static char	c = 0;
	static int	i = 0;

	c += ft_pow(2, i++) * (signum == SIGUSR1);
	if (i >= 8)
	{
		write(1, &c, 1);
		if (!c)
			write(1, "\n", 1);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	action;

	ft_printf("Program started correctly :)\nPid -> [%d]\n", getpid());
	while (1)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
		pause();
	}
	return (0);
}
