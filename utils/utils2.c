/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:51:51 by jobject           #+#    #+#             */
/*   Updated: 2021/12/09 20:17:10 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	get_size_pipes(char const	*s, char c)
{
	int	size;
	int	i;
	int	j;

	size = 0;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) != c)
			size++;
		j = i;
		while (*(s + i) != c && *(s + i))
			i++;
		while (*(s + j) && *(s + j) != c
			&& (*(s + j) == ' ' || *(s + j) == '\t'))
			j++;
		if (j == i)
			size--;
		if (*(s + i))
			i++;
	}
	return (size);
}

bool	pre_export_check(char	**strs, t_lst	*list)
{
	int		i;
	t_lst	*tmp;

	tmp = list;
	if (!strs[1])
	{
		print_sorted_env(tmp);
		return (0);
	}
	i = 0;
	while (strs[++i])
	{
		if (!ft_strncmp(strs[i], "=", 1) && ft_strcmp(strs[i], "="))
		{
			ft_putstr_fd(ERROR"minishell: ", 2);
			ft_putstr_fd(strs[i] + 1, 2);
			ft_putendl_fd(" not found"TEXT, 2);
			if (i == 1 || !ft_strcmp(strs[1], "="))
				g_sig.ex_code = 1;
			return (false);
		}
	}
	return (true);
}

t_lst	*make_copy_env(t_lst	*list)
{
	t_lst	*copy;

	copy = NULL;
	while (list)
	{
		if (!copy)
			copy = ft_lstnew_rem(list->var);
		else
			ft_lstadd_back_rem(&copy, ft_lstnew_rem(list->var));
		list = list->next;
	}
	return (copy);
}

int	check_export_exception(char	*str, int *index)
{
	if (!ft_strcmp(str, "=") && *index == 1)
	{
		ft_putendl_fd(ERROR"minishell: bad assigment"TEXT, 2);
		return (0);
	}
	if (!ft_strcmp(str, "=") && *index != 1)
	{
		ft_putendl_fd(ERROR"minishell: bad assigment"TEXT, 2);
		(*index)++;
		return (1);
	}
	if (ft_isdigit(*str))
	{
		ft_putstr_fd(ERROR"export: not an identifier: ", 2);
		ft_putendl_fd(str, 2);
		(*index)++;
		return (1);
	}
	return (2);
}

bool	make_export(char	**str, t_lst	**list)
{
	int	j;
	int	i;
	int	result_of_exp;

	j = 0;
	while (str[j])
	{
		result_of_exp = check_export_exception(str[++j], &j);
		if (!result_of_exp)
			return (0);
		else if (result_of_exp == 1)
			continue ;
		i = 0;
		while (str[j][i] && str[j][i] != '=')
			i++;
		if (!str[j][i])
			return (false);
		if (if_same(list, str[j]))
			return (false);
		if (j == 1)
			ft_lstadd_preback(list, ft_lstnew_rem(str[j]));
		else
			ft_lstadd_back_rem(list, ft_lstnew_rem(str[j]));
	}
	return (true);
}
