/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:37:00 by jobject           #+#    #+#             */
/*   Updated: 2021/12/07 15:41:17 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_list	*make_history(char	*str, t_list	*lst)
{
	if (!lst)
			lst = ft_lstnew(str);
	else
		ft_lstadd_back(&lst, ft_lstnew(str));
	return (lst);
}

static void	print(t_list	*lst, int i)
{
	while (lst)
	{
		i++;
		ft_putstr_fd("  ", 1);
		ft_putnbr_fd(i, 1);
		ft_putstr_fd("  ", 1);
		ft_putendl_fd(lst->content, 1);
		lst = lst->next;
	}
}

int mini_history(t_list	*history, bool *flag)
{
    int i;
	int	size;

	if (ft_lstsize(history) <= 16)
		print(history, 0);
	else
	{
		i = ft_lstsize(history);
		size = i;
		while (i != 16)
		{
			history = history->next;
			i--;
		}
		print(history, size - i);
	}
	*flag = true;
	g_exit = 0;
	return (0);
}
