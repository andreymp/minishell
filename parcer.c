/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:31:43 by jobject           #+#    #+#             */
/*   Updated: 2021/12/01 15:36:06 by jobject          ###   ########.fr       */
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
	str = redirect(str);
	return (str);
}