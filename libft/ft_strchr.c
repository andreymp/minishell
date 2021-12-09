/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:03:57 by jobject           #+#    #+#             */
/*   Updated: 2021/10/08 14:03:57 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char	*str, int code)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *) str;
	while (*(ptr + i))
	{
		if (*(ptr + i) == (char) code)
			return (ptr + i);
		i++;
	}
	if (code == '\0')
		return (ptr + i);
	return (0);
}
