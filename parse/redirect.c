/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:14:42 by jobject           #+#    #+#             */
/*   Updated: 2021/12/10 15:23:26 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*input(char	*str, int *i, t_mini	**mini)
{
	char	*filename;
	int		j;

	j = 0;
	filename = get_filename(str, *i + 1, &j);
	if (!filename || !ft_strncmp(filename, "<", 1)
		|| !ft_strncmp(filename, ">", 1))
	{
		ft_putendl_fd(ERROR"Redirect error"TEXT, 2);
		free(str);
		return (NULL);
	}
	(*mini)->proc.fdin = open(filename, O_RDONLY);
	if ((*mini)->proc.fdin < 0)
	{
		printf(ERROR"minishell: no such file or directory: %s\n"TEXT, filename);
		return (free_fd(str, filename, j, *i));
	}
	dup2((*mini)->proc.fdin, STDIN_FILENO);
	close((*mini)->proc.fdin);
	return (free_fd(str, filename, j, *i));
}

static char	*trunc_out(char	*str, int *i, t_mini	**mini)
{
	char	*filename;
	int		j;

	j = 0;
	filename = get_filename(str, *i + 1, &j);
	if (!filename || !ft_strncmp(filename, "<", 1)
		|| !ft_strncmp(filename, ">", 1))
	{
		ft_putendl_fd(ERROR"Redirect error"TEXT, 2);
		free(str);
		return (NULL);
	}
	if (!check_filename(filename, str))
		return (NULL);
	(*mini)->proc.fdout = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2((*mini)->proc.fdout, STDOUT_FILENO);
	close((*mini)->proc.fdout);
	return (free_fd(str, filename, j, *i));
}

static char	*heredoc(char	*str, int *i, t_mini	**mini)
{
	int		j;
	char	*lim;
	char	*tmp;

	lim = get_filename(str, *i + 2, &j);
	if (!lim)
	{
		ft_putendl_fd(ERROR"Redirect error"TEXT, 2);
		free(str);
		return (NULL);
	}
	tmp = read_heredoc(lim, str, *i, j);
	if (tmp)
		return (tmp);
	(*mini)->proc.fdin = open("heredoc", O_RDONLY, 0644);
	dup2((*mini)->proc.fdin, STDIN_FILENO);
	close((*mini)->proc.fdin);
	return (free_fd(str, lim, j, *i));
}

static char	*append_out(char	*str, int *i, t_mini	**mini)
{
	char	*filename;
	int		j;

	j = 0;
	filename = get_filename(str, *i + 2, &j);
	if (!filename || !ft_strncmp(filename, "<", 1)
		|| !ft_strncmp(filename, ">", 1))
	{
		ft_putendl_fd(ERROR"Redirect error"TEXT, 2);
		free(str);
		return (NULL);
	}
	(*mini)->proc.fdout = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	dup2((*mini)->proc.fdout, STDOUT_FILENO);
	close((*mini)->proc.fdout);
	return (free_fd(str, filename, j, *i));
}

char	*redirect(char	*str, t_mini	**mini)
{
	int	i;

	i = 0;
	if (!*(str + i + 1) && (*(str + i) == '<' || *(str + i) == '>'))
	{
		ft_putendl_fd(ERROR"Redirect error"TEXT, 2);
		free(str);
		return (NULL);
	}
	while (*(str + i + 1))
	{
		if (*(str + i) == '<' && *(str + i + 1) != '<')
			str = input(str, &i, mini);
		else if (*(str + i) == '<' && *(str + i + 1) == '<')
			str = heredoc(str, &i, mini);
		else if (*(str + i) == '>' && *(str + i + 1) != '>')
			str = trunc_out(str, &i, mini);
		else if (*(str + i) == '>' && *(str + i + 1) == '>')
			str = append_out(str, &i, mini);
		else
			i++;
		if (!str)
			return (NULL);
	}
	return (str);
}
