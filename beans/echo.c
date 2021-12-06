/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:40:01 by jobject           #+#    #+#             */
/*   Updated: 2021/12/06 20:27:17 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static bool	tilda(char	*str, char	**envp)
{
	int	i;

	i = 0;
	if (!ft_strncmp(str, "~", 1))
	{
		while (envp[i] && ft_strncmp(envp[i], "HOME=", 5))
			i++;
		if (!envp[i])
			ft_putstr_fd("", 1);
		else
		{
			if (!*(str + 1))
				ft_putstr_fd(envp[i] + 5, 1);
			else if (*(str + 1) && *(str + 1) == '/')
				ft_putstr_fd(envp[i] + 5, 1);
			else if (*(str + 1) && *(str + 1) != '/')
			{
				ft_putstr_fd(ERROR"minishell: no such user or named directory: "TEXT, 1);
				ft_putstr_fd(str + 1, 1);
				return (false);
			}
		}
	}
	return (true);
}

static void	uninit(char	*str, t_inside_gap_2	change)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == change.pipe)
			ft_putchar_fd('|', 1);
		else if (str[i] == change.red_in)
			ft_putchar_fd('<', 1);
		else if (str[i] == change.red_out)
			ft_putchar_fd('>', 1);
		else if (str[i] == change.point_coma)
			ft_putchar_fd(';', 1);
		else if (str[i] == change.tilda)
			ft_putchar_fd('~', 1);
		else
			ft_putchar_fd(str[i], 1);
		i++;
	}
}

int	mini_echo(char **str, t_inside_gap_2	change, bool *flag, char	**envp)
{
	bool	nflag;
	int 	i;

	nflag = false;
	i = 0;
	if (str[1] && !ft_strcmp(str[1], "-n"))
		nflag = true;
	if (nflag)
		i = 1;
	while (str[++i])
	{
		if (!tilda(str[i], envp))
			break ;
		while (*str[i] == '~')
			str[i]++;
		uninit(str[i], change);
		if (str[i + 1])
			ft_putchar_fd(' ', 1);
	}
	if (!nflag)
		ft_putchar_fd('\n', 1);
	*flag = true;
	return (0);
}