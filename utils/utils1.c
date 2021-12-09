/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:16:39 by jobject           #+#    #+#             */
/*   Updated: 2021/12/07 12:16:40 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

int	ft_minmax(int cnt, int znak, int num)
{
	if (cnt > 10 && znak == -1)
		return (0);
	else if (cnt > 10 && znak == 1)
		return (-1);
	return (num);
}

int	ft_sign(int *i, char str, int znak)
{
	if (str == 45)
	{
		znak = znak * -1;
		*i = *i + 1;
	}
	if (str == 43)
		*i = *i + 1;
	return (znak);
}

void	del(void *var)
{
	var = NULL;
}

int	ft_lstsize_rem(t_lst	*lst)
{
	int		size;
	t_lst	*tmp;

	if (!lst)
		return (0);
	tmp = lst;
	size = 0;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
