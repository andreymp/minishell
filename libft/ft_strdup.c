/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:03:59 by jobject           #+#    #+#             */
/*   Updated: 2021/10/08 14:04:00 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char	*str)
{
	char	*res;
	size_t	length;

	length = ft_strlen(str) + 1;
	res = (char *) malloc(length * sizeof(char));
	if (res)
		return (ft_memcpy(res, str, length));
	return (0);
}
