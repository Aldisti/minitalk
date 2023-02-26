/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:11:38 by adi-stef          #+#    #+#             */
/*   Updated: 2023/02/26 15:02:29 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf/printflibft.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void	ft_send(int pid, char *str)
{
	unsigned char	c;
	int				i;
	int				j;

	i = 0;
	while (1)
	{
		j = -1;
		c = (unsigned char)str[i];
		while (++j < 8)
		{
			if ((c >> j) % 2)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(250);
		}
		if (str[i++] == 0)
			break ;
	}
}

void	ft_handler(int signum)
{
	static int	n;

	if (signum == SIGUSR1)
		n += ft_printf("Character received...\n") * 0 + 1;
	else if (signum == SIGUSR2)
		ft_printf("%d characters received.\nMessage received!\n", n);
}

int	main(int ac, char **av)
{
	int	i;

	if (ac != 3)
		exit(ft_printf("Error\nType: wrong number of arguments\n") * 0);
	i = 0;
	while (av[1][i] && av[1][i] <= 57 && av[1][i] >= 48)
		i++;
	if (av[1][i])
		exit(ft_printf("Error\nType: invalid pid\n") * 0);
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	ft_printf("Starting to send the message\n");
	ft_printf("Message lenght is of %d characters\n", ft_strlen(av[2]));
	ft_send(ft_atoi(av[1]), av[2]);
	return (0);
}
