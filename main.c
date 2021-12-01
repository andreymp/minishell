/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:28:54 by jobject           #+#    #+#             */
/*   Updated: 2021/12/01 19:06:03 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "pipe.h"

void	free_mem(char	**strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

int main(int argc, char	**argv, char	**envp)
{
	(void) argc;
	(void) argv;
	t_list	*lst;
	t_list	*tmp;
	t_cmd	cmds;
	t_proccess	proc;
	
	char *str = ft_strdup("/bin/cat -e pipe.h"); //This is command in shell
	puts(str);
	lst = do_split(str);
	tmp = lst;
	while (tmp)
	{
		tmp->content = parser(tmp->content, envp);
		tmp->cmd = ft_split(tmp->content, ' ');
		tmp = tmp->next;
	}
	run(&cmds, envp, &proc, lst);
	ft_lstclear(&lst, free);
}
