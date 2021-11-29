/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:03:35 by jobject           #+#    #+#             */
/*   Updated: 2021/10/08 14:11:10 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

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

void	ft_putnbr_fd(int n, int fd)
{
	int		length;
	int		i;
	char	res[11];

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	length = get_length(n);
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
	ft_putstr_fd(res, fd);
}
