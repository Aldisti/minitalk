/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:25:45 by adi-stef          #+#    #+#             */
/*   Updated: 2023/01/25 12:18:56 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printflibft.h"

int	ft_putchar(char c)
{
	write(1, &c, sizeof (char));
	return (1);
}

int	ft_putstr(const char *s)
{
	int	i;

	if (!s)
		return (ft_putstr("(null)"));
	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
	return (ft_strlen(s));
}

int	ft_putinbr(int n)
{
	char	*ptr;

	ptr = ft_itoa(n);
	ft_putstr(ptr);
	free(ptr);
	return (ft_nlen(n));
}

int	ft_putunbr(unsigned int n)
{
	char	*ptr;

	ptr = ft_itoa(n);
	ft_putstr(ptr);
	free(ptr);
	return (ft_nlen(n));
}

int	ft_putnbr_base(unsigned int n, int type)
{
	char	*base;
	char	*ptr;
	int		count;
	int		i;

	if (!n)
		return (ft_putchar(48));
	base = "0123456789ABCDEF";
	if (type)
		base = "0123456789abcdef";
	ptr = (char *) malloc(ft_nlen(n) + 2 * sizeof (char));
	if (!ptr)
		return (0);
	i = 0;
	while (n != 0)
	{
		ptr[i++] = base[n % 16];
		n /= 16;
	}
	ptr[i] = 0;
	count = ft_reverse(ptr);
	free(ptr);
	return (count);
}
