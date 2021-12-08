/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:39:44 by jobject           #+#    #+#             */
/*   Updated: 2021/12/08 11:49:52 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	mini_pwd(bool	*flag)
{
	char	*dir;
	int		size;
	char	*res;

	size = 1;
	while (1)
	{
		dir = malloc(size);
		res = getcwd(dir, size);
		if (res == NULL)
			size++;
		else
		{
			ft_putstr_fd(dir, 1);
			write(1, "\n", 1);
			free(dir);
			break ;
		}	
		free(dir);
	}
	g_sig.ex_code = 0;
	*flag = true;
	return (0);
}

char	*pwd_cur(void)
{
	char	*dir;
	int		size;
	char	*res;

	size = 1;
	while (1)
	{
		dir = malloc(size);
		res = getcwd(dir, size);
		if (!res)
			size++;
		else
			break ;
		free(dir);
	}
	return (dir);
}