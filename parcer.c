/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:31:43 by jobject           #+#    #+#             */
/*   Updated: 2021/11/29 21:30:43 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
/*
обработать "", '', \, $, ;, |, >, >>, <, <<
*/

char	*do_gap(char	*str, int	*i)
{
	int	j;

	j = *i;
	(*i)++;
	while (*(str + *i) && *(str + *i) != '\'')
		(*i)++;
	if (*(str + *i))
		return (multi_join(str, *i, j));
	return (NULL);
}
char	*do_gap2(char	*str, int *i);
char	*do_backslash(char	*str, int *i);
bool	check_str(char	*str);

void	parser(char	*str)
{
	int	i;
	
	i = -1;
	while (*(str + ++i))
	{
		if (*(str + i) == '\'')
			str = do_gap(str, &i);
		if (*(str + i) == '"')
			str = do_gap2(str, &i);
		if (*(str + i) == '\\')
			str = do_backslash(str, &i);
	}
}