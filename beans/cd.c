/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:40:07 by jobject           #+#    #+#             */
/*   Updated: 2021/12/06 20:28:19 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	change_pwd(char	*pwd, char	*old_pwd, t_lst	**list)
{
	t_lst	*tmp;
	char	*temp;

	tmp = *list;
	while (tmp && ft_strncmp(tmp->var, "PWD=", 4))
		tmp = tmp->next;
	temp = ft_strdup("PWD=");
	// free(tmp->var);
	tmp->var = ft_strjoin(temp, pwd);
	while (tmp && ft_strncmp(tmp->var, "OLDPWD==", 7))
		tmp = tmp->next;
	temp = ft_strdup("OLDPWD=");
	// free(tmp->var);
	tmp->var = ft_strjoin(temp, old_pwd);
	free(pwd);
	free(old_pwd);
}

int	mini_cd(char *path, t_lst	**list, bool *flag)
{
	char	*temp;
	char	*pwd;
	char	*old_pwd;
	
	if (!path || !ft_strcmp(path, "~") || !ft_strcmp(path, "~/"))
	{
		temp = ft_strdup("/Users/");
		temp = ft_strjoin(temp, getenv("USER"));
		old_pwd = pwd_cur();
		chdir(temp);
		change_pwd(temp, old_pwd, list);
		return (0);
	}
	old_pwd = pwd_cur();
	if (chdir(path) == -1)
	{
		ft_putstr_fd(ERROR"cd: no such file or directory: "TEXT, 2);
		ft_putendl_fd(path, 2);
	}
	pwd = pwd_cur();
	change_pwd(pwd, old_pwd, list);
	*flag = true;
	return (0);
}