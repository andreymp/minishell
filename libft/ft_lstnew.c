/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:03:05 by jobject           #+#    #+#             */
/*   Updated: 2021/12/09 20:12:59 by jobject          ###   ########.fr       */
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
		elem->content = ft_strdup(content);
		elem->cmd = NULL;
		elem->next = NULL;
	}
	return (elem);
}
