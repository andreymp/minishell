/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:03:05 by jobject           #+#    #+#             */
/*   Updated: 2021/12/01 15:39:11 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(char	*content)
{
	t_list	*elem;

	elem = (t_list *) malloc(sizeof(t_list));
	if (elem)
	{
		elem->content = (char *) malloc(ft_strlen(content) + 1);
		ft_strlcpy(elem->content, content, ft_strlen(content) + 1);
		free (content);
		elem->cmd = NULL;
		elem->next = NULL;
	}
	return (elem);
}
