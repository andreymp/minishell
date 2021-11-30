/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:28:54 by jobject           #+#    #+#             */
/*   Updated: 2021/11/30 20:07:05 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int main(int argc, char	**argv, char	**envp)
{
	(void) argc;
	(void) argv;
	t_list	*lst;
	t_list	*tmp;
	// t_cmds	cmd;
	// int j;
	
	char *str = ft_strdup("echo $USERR | hi mama < hi daddy; < hi puppy | and mummy");
	puts(str);
	lst = do_split(str);
	tmp = lst;
	while (tmp)
	{
		tmp->content = parser(tmp->content, envp);
		puts(tmp->content);
		// cmd = make_cmds(tmp->content);
		// for (int i = 0; i < cmd.index; i++)
		// {
		// 	j = 0;
		// 	while (cmd.cmd[i][j])
		// 		puts(cmd.cmd[i][j++]);
		// }
		tmp = tmp->next;
	}
	ft_lstclear(&lst, free);
}
