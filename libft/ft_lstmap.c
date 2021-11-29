/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:03:02 by jobject           #+#    #+#             */
/*   Updated: 2021/10/08 15:48:48 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list	*lst, void	*(*f)(void *), void	(*del)(void *))
{
	t_list	*new;
	t_list	*temp;

	new = NULL;
	if (!lst)
		return (new);
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		ft_lstadd_back(&new, temp);
		lst = lst->next;
	}
	return (new);
}
