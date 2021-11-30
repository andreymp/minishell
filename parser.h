/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:31:46 by jobject           #+#    #+#             */
/*   Updated: 2021/11/30 20:28:56 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include "libft/libft.h"

# define MAX_CMD 255

// typedef struct s_cmds
// {
// 	char	**cmd[MAX_CMD];
// 	int		index;
// 	char	symbol[MAX_CMD];
// }				t_cmds;

char	*parser(char	*str, char	**envp);
char	*do_gap(char	*str, int *i);
t_list	*do_split(char	*str);
char	*do_gap2(char	*str, int *i, char	**envp);
char	*do_backslash(char	*str, int *i);
char	*do_dollar(char	*str, int	*i, char	**envp);
char	*multi_join2(char	*s1, char	*s2, int *i, int j);
char	*multi_join(char	*str, int i, int j);
bool	ft_iskey(char c);
char	*get_filename(char	*str, int i);
// t_cmds	make_cmds(char	*str);

#endif