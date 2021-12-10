/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:47:08 by jobject           #+#    #+#             */
/*   Updated: 2021/12/10 15:57:11 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*read_heredoc(char	*lim, char	*str, int i, int j)
{
	int		fd;
	char	*line;

	fd = open("heredoc", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	while (1)
	{
		ft_putstr_fd(MINISHELL"heredoc> "TEXT, 2);
		line = get_next_line(0);
		if (!line)
		{
			g_sig.ex_code = 130;
			ft_putstr_fd("\b\b\b\b\b\b\b\b\b\b\b\b\b", 1);
			return (free_fd(str, lim, j, i));
		}
		if (!ft_strncmp(line, lim, ft_strlen(lim)))
			break ;
		ft_putstr_fd(line, fd);
		free(line);
	}
	close(fd);
	free(line);
	return (NULL);
}

bool	check_filename(char	*filename, char	*str)
{
	int	k;

	k = 1;
	while (*(filename + k))
	{
		if (ft_isdigit(*(filename + k - 1)) && *(filename + k) == '>')
		{
			ft_putendl_fd(ERROR"Redirect error"TEXT, 2);
			free(str);
			return (false);
		}
		k++;
	}
	return (true);
}

char	*dollar_join(char	*tmp, char	*str, int i, int j)
{
	char	*res;

	free(tmp);
	res = ft_substr(str, 0, j);
	tmp = ft_strdup(str + i);
	res = ft_strjoin(res, tmp);
	free(tmp);
	free(str);
	return (res);
}

bool	dollar_valid(char	*str, int *i, int j)
{
	while (*(str + *i) && ft_iskey(*(str + *i)))
		(*i)++;
	if (*i == j + 1 || (*str + *i) == '?')
		return (false);
	return (true);
}

char	*after_check(char	*str, t_mini	*mini)
{
	if (!check_pipes(str))
	{
		free(str);
		ft_putendl_fd(ERROR"Parsing error (pipes)"TEXT, 2);
		return (NULL);
	}
	if (!str)
		return (NULL);
	str = redirect(str, &mini);
	return (str);
}
