/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:04:16 by jobject           #+#    #+#             */
/*   Updated: 2021/10/08 14:52:39 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const	*s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	str = (char *) malloc(ft_strlen(s) + 1);
	if (str)
	{
		i = 0;
		while (*(s + i))
		{
			*(str + i) = (*f)(i, *(s + i));
			i++;
		}
		*(str + i) = '\0';
	}
	return (str);
}
