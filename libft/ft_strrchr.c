/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:04:24 by jobject           #+#    #+#             */
/*   Updated: 2021/10/08 14:04:24 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char	*str, int code)
{
	char	*ptr;
	int		i;

	i = ft_strlen(str) - 1;
	ptr = (char *) str;
	if (code == '\0')
		return (ptr + i + 1);
	while (i >= 0)
	{
		if (*(ptr + i) == (char) code)
			return (ptr + i);
		i--;
	}
	return (0);
}
