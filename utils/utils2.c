/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:51:51 by jobject           #+#    #+#             */
/*   Updated: 2021/12/07 12:29:27 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	get_size_pipes(char const	*s, char c)
{
	int	size;
	int	i;
	int	j;

	size = 0;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) != c)
			size++;
		j = i;
		while (*(s + i) != c && *(s + i))
			i++;
		while ( *(s + j) && *(s + j) != c
			&& (*(s + j) == ' ' || *(s + j) == '\t'))
			j++;
		if (j == i)
			size--;
		if (*(s + i))
			i++;
	}
	return (size);
}
