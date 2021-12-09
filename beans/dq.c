/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dq.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:36:26 by jobject           #+#    #+#             */
/*   Updated: 2021/12/09 14:56:03 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	mini_dq(char	*str, bool *flag)
{
	*flag = true;
	ft_putstr_fd(ERROR"minishell: command not found: ", 2);
	ft_putnbr_fd(g_sig.ex_code, 2);
	str += 2;
	if (*str)
		ft_putstr_fd(str, 2);
	ft_putendl_fd(TEXT, 2);
	g_sig.ex_code = 127;
}
