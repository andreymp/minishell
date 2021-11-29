/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:00:36 by remelia           #+#    #+#             */
/*   Updated: 2021/11/17 14:00:39 by remelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char		*str[10000];
	//t_param		param;
	//int			fd;
	int			i;
	
	i = 0;
	while (1)
	{
		write(1, "minishell> ", 11);
		str[i] = readline(NULL);			// readline не ставит '\0' на конец строки поэтому ft_putstr_fd поменял немного)
		add_history(str[i]);
		i++;
	}
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	return (0);
}