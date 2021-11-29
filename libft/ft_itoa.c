/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:02:11 by jobject           #+#    #+#             */
/*   Updated: 2021/10/08 14:06:48 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	get_length(int n)
{
	int	size;

	size = 0;
	while (n / 10)
	{
		size++;
		n /= 10;
	}
	size++;
	if (n < 0)
		size++;
	return (size);
}

char	*ft_itoa(int n)
{
	int		length;
	char	*res;
	int		i;

	if (n == -2147483648)
		return (ft_strjoin("-", "2147483648"));
	length = get_length(n);
	res = (char *) malloc((length + 1) * sizeof(char));
	if (!res)
		return (0);
	i = length - 1;
	if (n < 0)
	{
		*res = '-';
		n *= -1;
	}
	while (i && n / 10)
	{
		*(res + i) = n % 10 + 48;
		n /= 10;
		i--;
	}
	*(res + i) = n + 48;
	*(res + length) = '\0';
	return (res);
}
