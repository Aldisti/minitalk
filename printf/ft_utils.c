/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:29:29 by adi-stef          #+#    #+#             */
/*   Updated: 2023/02/26 12:25:26 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printflibft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putlnbr(unsigned long long n)
{
	char	*base;
	char	*ptr;
	int		count;
	int		i;

	if (!n)
		return (ft_putchar(48));
	base = "0123456789abcdef";
	ptr = (char *) malloc(17 * sizeof (char));
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

int	ft_nlen(long n)
{
	int		i;

	i = 1;
	if (n < 0)
		i++;
	if (n == 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

char	*ft_itoa(long n)
{
	char	*ptr;
	int		i;

	i = ft_nlen(n);
	ptr = ft_calloc(i, sizeof (char));
	if (!ptr)
		return (0);
	if (n < 0)
		ptr[0] = 45;
	else if (n < 10 && n >= 0)
	{
		ptr[0] = n + 48;
		return (ptr);
	}
	i--;
	while (--i >= 0 && n)
	{
		ptr[i] = ft_abs(n % 10) + 48;
		n /= 10;
	}
	return (ptr);
}
