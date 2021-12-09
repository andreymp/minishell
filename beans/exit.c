/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:39:55 by jobject           #+#    #+#             */
/*   Updated: 2021/12/07 21:22:17 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	mini_exit(char *str, bool *flag)
{
	int	i;

	i = -1;
	if (str)
	{
		while (str[++i])
		{
			if (!ft_isdigit(str[i]) && str[i] != '-')
			{
				ft_putstr_fd("exit\n"ERROR, 2);
				ft_putendl_fd("minishell: exit: numeric argument required", 2);
				ft_putstr_fd(TEXT, 2);
				g_exit = 255;
				exit(g_exit);
			}
		}
		g_exit = ft_atoi(str);
	}
	while (g_exit < 0)
		g_exit = 256 + g_exit;
	while (g_exit > 255)
		g_exit = g_exit - 256;
	*flag = true;
	write(2, "exit\n", 5);
	exit(g_exit);
}
