/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:39:58 by jobject           #+#    #+#             */
/*   Updated: 2021/12/07 15:04:50 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	mini_env(t_lst *list, bool *flag)
{
	while(list)
	{
		ft_putstr_fd(list->var, 1);
		write(1, "\n", 1);
		list = list->next;
	}
	*flag = true;
	g_exit = 0;
	return (0);
}