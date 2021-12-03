/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:31:43 by jobject           #+#    #+#             */
/*   Updated: 2021/12/03 21:19:02 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"


t_list	*do_split(char	*str)
{
	t_list	*lst;
	char	**strs;
	int		i;

	i = 0;
	lst = NULL;
	strs = ft_split(str, '|');
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

static bool	preparser(char	*str)
{
	int		i;
	t_pre	gaps;
	
	gaps.gap2 = 0;
	gaps.gap = 0;
	i = 0;
	while (*(str + i))
	{
		if (*(str + i) == '\'')
			gaps.gap++;
		if (*(str + i) == '\"')
			gaps.gap2++;
		if (*(str + i) == '\\' || *(str + i) == ';')
			return (false);
		i++;
	}
	if (gaps.gap % 2 || gaps.gap2 % 2)
		return (false);
	return (true);
}

char	*parser(char	*str, char	**envp)
{
	int	i;
	
	i = -1;
	if (!preparser(str))
	{
		ft_putendl_fd("Parsing error", 2);
		return (NULL);
	}
	while (*(str + ++i))
	{
		if (*(str + i) == '\'')
			str = do_gap(str, i);
		else if (*(str + i) == '\"')
			str = do_gap2(str, i, envp);
		else if (*(str + i) == '$')
			str = do_dollar(str, i, envp);
		if (!str)
			break;
	}
	if (!str)
		return (NULL);
	str = redirect(str);
	return (str);
}