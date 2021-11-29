/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:04:18 by jobject           #+#    #+#             */
/*   Updated: 2021/10/08 14:04:19 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char	*s1, const char *s2, size_t	n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*s1 != *s2 || !(*s1) || !(*s2))
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		i++;
		s1++;
		s2++;
	}
	return (0);
}
