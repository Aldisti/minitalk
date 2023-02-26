/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:40:52 by adi-stef          #+#    #+#             */
/*   Updated: 2023/02/26 11:55:15 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printflibft.h"

void	*ft_calloc(size_t num, size_t dim)
{
	char	*ptr;
	size_t	i;

	if (num >= 1247483424)
		return (0);
	ptr = (char *) malloc (num * dim);
	if (!ptr)
		return (0);
	i = 0;
	while (i < (num * dim))
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] != 43 && str[i] != 45 && (str[i] > 57 || str[i] < 48))
		return (0);
	if (str[i] == 45)
		sign *= -1;
	if (str[i] == 43 || str[i] == 45)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
		res = res * 10 + (str[i++] - 48);
	return (res * sign);
}
