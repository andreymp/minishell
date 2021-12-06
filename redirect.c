/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:14:42 by jobject           #+#    #+#             */
/*   Updated: 2021/12/06 20:35:48 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*input(char	*str, int *i)
{
	char	*filename;
	int		fd;
	int		j;
	
	j = 0;
	filename = get_filename(str, *i + 1, &j);
	if (!filename || !ft_strncmp(filename, "<", 1) || !ft_strncmp(filename, ">", 1))
	{
		ft_putendl_fd(ERROR"Redirect error"TEXT, 2);
		free(str);
		return (NULL);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf(ERROR"minishell: no such file or directory: %s\n"TEXT, filename);
		return (free_fd(str, filename, j, *i));
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (free_fd(str, filename, j, *i));
}

static char	*trunc_out(char	*str, int *i)
{
	char	*filename;
	int		fd;
	int		j;
	
	j = 0;
	filename = get_filename(str, *i + 1, &j);
	if (!filename || !ft_strncmp(filename, "<", 1) || !ft_strncmp(filename, ">", 1))
	{
		ft_putendl_fd(ERROR"Redirect error"TEXT, 2);
		free(str);
		return (NULL);
	}
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (free_fd(str, filename, j, *i));
}

static char	*heredoc(char	*str, int *i)
{
	int		j;
	int		fd;
	char	*lim;
	char	*line;

	lim = get_filename(str, *i + 2, &j);
	if (!lim)
	{
		ft_putendl_fd(ERROR"Redirect error"TEXT, 2);
		free(str);
		return (NULL);
	}
	fd = open("heredoc", O_RDWR | O_TRUNC, 0777);
	while (1)
	{
		ft_putstr_fd(MINISHELL"heredoc> "TEXT, 2);
		line = get_next_line(0);
		if (!ft_strncmp(line, lim, ft_strlen(lim)))
			break ;
		ft_putstr_fd(line, fd);
		free(line);
	}
	free(line);
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (free_fd(str, lim, j, *i));
}

static char	*append_out(char	*str, int *i)
{
	char	*filename;
	int		fd;
	int		j;
	
	j = 0;
	filename = get_filename(str, *i + 2, &j);
	if (!filename || !ft_strncmp(filename, "<", 1) || !ft_strncmp(filename, ">", 1))
	{
		ft_putendl_fd(ERROR"Redirect error"TEXT, 2);
		free(str);
		return (NULL);
	}
	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0777);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (free_fd(str, filename, j, *i));
}

char	*redirect(char	*str)
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
			str = input(str, &i);
		else if (*(str + i) == '<' && *(str + i + 1) == '<')
			str = heredoc(str, &i);
		else if (*(str + i) == '>' && *(str + i + 1) != '>')
			str = trunc_out(str, &i);
		else if (*(str + i) == '>' && *(str + i + 1) == '>')
			str = append_out(str, &i);
		else
			i++;
		if (!str)
			break ;
	}
	return (str);
}