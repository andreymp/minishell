/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:40:01 by jobject           #+#    #+#             */
/*   Updated: 2021/12/10 13:06:33 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
				ft_putstr_fd(ERROR"minishell: no such user or directory: ", 1);
				ft_putstr_fd(TEXT, 1);
				ft_putstr_fd(str + 1, 1);
				return (false);
			}
		}
	}
	return (true);
}

static bool	init_nflag(char	*str, int	*i)
{
	int		j;
	bool	nflag;

	nflag = false;
	if (str && !ft_strncmp(str, "-n", 2))
	{
		j = 1;
		while (str[j] && str[j] == 'n')
			j++;
		if (!str[j])
			nflag = true;
		else
			nflag = false;
	}
	if (nflag)
		*i = 1;
	return (nflag);
}

static char	*special_case(char	*str)
{
	if (!ft_strncmp("$?", str, 2))
	{
		ft_putnbr_fd(g_sig.ex_code, 1);
		str += 2;
	}
	return (str);
}

int	mini_echo(char **str, bool *flag, char	**envp)
{
	bool	nflag;
	int		i;

	i = 0;
	nflag = init_nflag(str[1], &i);
	while (str[++i])
	{
		if (str[i] && !ft_strncmp(str[i], "-n", 2) && flag)
			continue ;
		str[i] = special_case(str[i]);
		if (!tilda(str[i], envp))
			break ;
		while (*str[i] == '~')
			str[i]++;
		ft_putstr_fd(str[i], 1);
		if (str[i + 1])
			ft_putchar_fd(' ', 1);
	}
	if (!nflag)
		ft_putchar_fd('\n', 1);
	*flag = true;
	g_sig.ex_code = 0;
	return (0);
}
