/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:16:48 by jobject           #+#    #+#             */
/*   Updated: 2021/12/07 12:16:51 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_lst	*ft_lstlast_rem(t_lst *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_rem(t_lst **lst, t_lst *new)
{
	if (*lst)
		ft_lstlast_rem(*lst)->next = new;
	else
		*lst = new;
}

t_lst	*ft_lstnew_rem(void	*content)
{
	t_lst	*list;

	list = (t_lst *) malloc(sizeof(t_lst));
	if (list)
	{
		list->var = content;
		list->next = 0;
	}
	return (list);
}

void	ft_lstdelone_rem(t_lst	*lst, void (*del)(void *))
{
	if (!lst)
		return ;
	(*del)(lst->var);
	free(lst);
}

void	ft_lstclear_rem(t_lst	**lst, void (*del)(void *))
{
	t_lst	*tmp;

	if (!(*lst))
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone_rem(*lst, del);
		*lst = tmp;
	}
}