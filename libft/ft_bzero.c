/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:57:32 by jobject           #+#    #+#             */
/*   Updated: 2021/10/08 13:57:36 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void	*source, size_t	length)
{
	char		*str;
	size_t		i;

	str = (char *) source;
	i = 0;
	if (!length)
		return ;
	else
	{
		while (i < length)
		{
			*(str + i) = '\0';
			i++;
		}
	}
}
