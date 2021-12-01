/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:36:41 by jobject           #+#    #+#             */
/*   Updated: 2021/12/01 18:04:19 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

# include "parser.h"
# include <sys/wait.h>
# include <sys/types.h>

typedef struct s_cmd
{
	t_list	*lst;
	char	**mypaths;
	char	*cmd_path;
}				t_cmd;

typedef struct s_proccess
{
	int		fds[2];
	pid_t	parent;
}				t_proccess;

void	init_env(char	**envp, t_cmd	*cmds);
void	init_cmd_path(t_cmd	**cmds);
void	run(t_cmd	*cmds, char	**envp, t_proccess	*proc, t_list	*lst);

#endif