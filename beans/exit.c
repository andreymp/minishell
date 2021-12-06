/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:39:55 by jobject           #+#    #+#             */
/*   Updated: 2021/12/06 15:56:21 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mini_exit(char *str, bool *flag)
{
	int	exit_code;
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0 && str[i] != '-')
		{
			write(2, "exit\n", 5);
			exit(255);
		}
		i++;
	}
	exit_code = ft_atoi(str);
	while (exit_code < 0)
		exit_code = 256 + exit_code;
	while(exit_code > 255)
		exit_code = exit_code - 256;
	*flag = true;
	exit(exit_code);
}