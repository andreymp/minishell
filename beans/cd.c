/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:40:07 by jobject           #+#    #+#             */
/*   Updated: 2021/12/10 13:11:50 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	change_pwd(char	*pwd, char	*old_pwd, t_lst	**list)
{
	t_lst	*tmp;
	char	*temp;

	tmp = *list;
	while (tmp && ft_strncmp(tmp->var, "PWD=", 4))
		tmp = tmp->next;
	if (!tmp)
		return (1);
	temp = ft_strdup("PWD=");
	tmp->var = ft_strjoin(temp, pwd);
	while (tmp && ft_strncmp(tmp->var, "OLDPWD=", 7))
		tmp = tmp->next;
	if (!tmp)
		return (1);
	temp = ft_strdup("OLDPWD=");
	tmp->var = ft_strjoin(temp, old_pwd);
	free(pwd);
	free(old_pwd);
	return (0);
}

void	if_no_globe(char *old_pwd, t_lst **list)
{
	char	*str[4];
	char	*tmp1;
	char	*tmp2;
	bool	flag;

	flag = false;
	str[0] = ft_strdup("export");
	tmp1 = ft_strdup("PWD=");
	tmp1 = ft_strjoin(tmp1, pwd_cur());
	str[1] = ft_strdup(tmp1);
	free(tmp1);
	tmp2 = ft_strdup("OLDPWD=");
	tmp2 = ft_strjoin(tmp2, old_pwd);
	str[2] = ft_strdup(tmp2);
	str[3] = NULL;
	mini_export(list, str, &flag);
	free(tmp2);
}

static void	check_no_cd(char	*path)
{
	if (chdir(path) == -1)
	{
		ft_putstr_fd(ERROR"cd: no such file or directory: "TEXT, 2);
		ft_putendl_fd(path, 2);
		g_sig.ex_code = 1;
	}
}

int	mini_cd(char *path, t_lst **list, bool *flag)
{
	char	*temp;
	char	*pwd;
	char	*old_pwd;

	g_sig.ex_code = 0;
	*flag = true;
	if (!path || !ft_strcmp(path, "~") || !ft_strcmp(path, "~/"))
	{
		temp = ft_strdup("/Users/");
		temp = ft_strjoin(temp, getenv("USER"));
		old_pwd = pwd_cur();
		chdir(temp);
		if (change_pwd(temp, old_pwd, list))
			if_no_globe(old_pwd, list);
		return (0);
	}
	old_pwd = pwd_cur();
	check_no_cd(path);
	pwd = pwd_cur();
	if (change_pwd(pwd, old_pwd, list))
		if_no_globe(old_pwd, list);
	return (0);
}
