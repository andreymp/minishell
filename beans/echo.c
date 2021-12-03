/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:40:01 by jobject           #+#    #+#             */
/*   Updated: 2021/12/03 11:40:02 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	mini_echo(char **str) // n - флаг "-n"
{
	bool	nflag;
	int 	i;

	nflag = false;
	i = 0;
	if (str[1] && !ft_strcmp(str[1], "-n"))
		nflag = true;
	if (nflag)
		i = 1;
	while (str[++i])
	{
		ft_putstr_fd(str[i], 1);
		if (str[i + 1])
			ft_putchar_fd(' ', 1);
	}
	if (!nflag)
		ft_putstr_fd("\n", 1);
	return (0);
}