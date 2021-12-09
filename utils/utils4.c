/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:17:11 by jobject           #+#    #+#             */
/*   Updated: 2021/12/09 21:24:36 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

bool	pre_check(char	*str)
{
	if (!preparser(str))
	{
		ft_putendl_fd(ERROR"Parsing error (open gaps)"TEXT, 2);
		return (false);
	}
	if (!ft_strncmp(str, "\"\"", 2) || !ft_strncmp(str, "\'\'", 2))
		return (false);
	return (true);
}

char	*return_message(char	*str)
{
	free(str);
	ft_putendl_fd(ERROR"Parsing error (undefined symbol)"TEXT, 2);
	return (NULL);
}
