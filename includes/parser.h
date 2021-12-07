/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:31:46 by jobject           #+#    #+#             */
/*   Updated: 2021/12/07 20:08:58 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "get_next_line.h"

# define MINISHELL "\033[1;33m"
# define TEXT "\033[1;37m"
# define ERROR "\033[1;31m"

typedef struct s_lst
{
	char			*var;
	struct s_lst	*next;
}				t_lst;

typedef struct s_pre
{
	int	gap;
	int	gap2;
	int	pipes;
}				t_pre;

typedef struct s_inside_gap2
{
	char	red_in;
	char	red_out;
	char	pipe;
	char	point_coma;
	char	tilda;
	char	gap;
}				t_inside_gap_2;


char	*parser(char	*str, t_lst	*list, t_inside_gap_2 change);
char	*do_gap(char	*str, int i);
t_list	*do_split(char	*str);
char	*do_gap2(char	*str, int i, t_lst	*list, t_inside_gap_2 change);
char	*do_backslash(char	*str, int *i);
char	*do_dollar(char	*str, int	i, t_lst	*list);
char	*multi_join2(char	*s1, char	*s2, int i, int j);
char	*multi_join(char	*str, int i, int j);
bool	ft_iskey(char c);
char	*get_filename(char	*str, int i, int *j);
char	*redirect(char	*str);
char	*free_fd(char	*str, char *filename, int j, int i);
bool	result_line(char	**str, t_list	**history, t_lst	*list, t_inside_gap_2 change);
int		get_size_pipes(char const	*s, char c);
bool	check_pipes(char	*str);

#endif