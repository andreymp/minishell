/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:31:43 by jobject           #+#    #+#             */
/*   Updated: 2021/11/30 20:05:35 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
/*
обработать "", '', \, $, ;, |, >, >>, <, <<, ' ';
*/

// t_cmds	make_cmds(char	*str)
// {
// 	t_cmds	cmds;
// 	int		i;
// 	int		j;
// 	char	*tmp;

// 	i = 0;
// 	j = 0;
// 	cmds.index = 0;
// 	while (*(str + i))
// 	{
// 		cmds.symbol[cmds.index] = 46;
// 		while (*(str + i) && *(str + i) != '>' && *(str + i) != '<' && *(str + i) != '|')
// 			i++;
// 		if (*(str + i))
// 			cmds.symbol[cmds.index] = *(str + i);
// 		tmp = ft_substr(str, j, i - j);
// 		cmds.cmd[cmds.index++] = ft_split(tmp, ' ');
// 		free (tmp);
// 		i++;
// 		j = i;
// 	}
// 	return (cmds);
// }

t_list	*do_split(char	*str)
{
	t_list	*lst;
	char	**strs;
	int		i;

	i = 0;
	lst = NULL;
	strs = ft_split(str, ';');
	free(str);
	while (strs[i])
	{
		if (!lst)
			lst = ft_lstnew(strs[i]);
		else
			ft_lstadd_back(&lst, ft_lstnew(strs[i]));
		i++;
	}
	free (strs);
	return (lst);
}

char	*parser(char	*str, char	**envp)
{
	int	i;
	
	i = -1;
	while (*(str + ++i))
	{
		if (*(str + i) == '\'')
			str = do_gap(str, &i);
		if (*(str + i) == '\"')
			str = do_gap2(str, &i, envp);
		if (*(str + i) == '\\')
			str = do_backslash(str, &i);
		if (*(str + i) == '$')
			str = do_dollar(str, &i, envp);
	}
	return (str);
}