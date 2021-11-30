/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:14:42 by jobject           #+#    #+#             */
/*   Updated: 2021/11/30 20:54:51 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	input(char	*str)
{
	int		i;
	char	*filename;
	int		fd;

	i = -1;
	while (*(str + ++i + 1))
	{
		if(*(str + i) == '<' && *(str + i + 1) != '<')
			break;
	}
	filename = get_filename(str, i + 1);
	fd = open(filename, O_RDONLY, 0777);
	if (fd < 0)
	{
		printf("minishell: no such file or directory: %s", filename);
		free(filename);
		return ;
	}
	dup2(fd, STDIN_FILENO);
}

void	trunc_otput(char	*str)
{
	int		i;
	char	*filename;
	int		fd;

	i = -1;
	while (*(str + ++i + 1))
	{
		if(*(str + i) == '>' && *(str + i + 1) != '>')
			break;
	}
	filename = get_filename(str, i + 1);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd < 0)
	dup2(fd, STDIN_FILENO);
}