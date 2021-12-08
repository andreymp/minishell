/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:39:38 by jobject           #+#    #+#             */
/*   Updated: 2021/12/07 18:25:57 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_lst   *ft_lstlastlast(t_lst *lst)
{
    if (!lst)
        return (0);
    while (lst->next->next)
        lst = lst->next;
    return (lst);
}

void    ft_lstadd_preback(t_lst **lst, t_lst *new)
{
    if (*lst)
        ft_lstlastlast(*lst)->next = new;
    else
        *lst = new;
}

int if_same(t_lst **list, char *str)
{
    int i;
    i = 0;
    while (str[i] != '=')
        i++;
    while ((*list)->next)
    {
        if (!ft_strncmp((*list)->var, str, i))
        {
            (*list)->var = str;
            return (1);
        }
        list = &(*list)->next;
    }
    return (0);
}

t_lst	*lst_copy(t_lst *list)
{
	t_lst	*new;

	if (list == NULL)
		return (NULL);
	else
	{
		new = (t_lst *)malloc(sizeof(t_lst));
		new->var = list->var;
		new->next = lst_copy(list->next);
		return (new);
	}
}

void    print_sorted_env(t_lst  *list)
{
    char    *temp;
    t_lst   *tmp1;
    t_lst   *tmp2;
	t_lst	*head;

    tmp1 = lst_copy(list);
	head = tmp1;
    while (tmp1->next->next)
    {
        tmp2 = tmp1->next;
        while (tmp2->next)
        {
            if (ft_strcmp(tmp1->var, tmp2->var) > 0)
            {
                temp = tmp1->var;
                tmp1->var = tmp2->var;
                tmp2->var = temp;
            }
            tmp2 = tmp2->next;
        }
        tmp1 = tmp1->next;
    }
	tmp1 = head;
    while (tmp1->next)
    {
        ft_putendl_fd(tmp1->var, 1);
        tmp1 = tmp1->next;
    }
}

int mini_export(t_lst **list, char **str, bool *flag)
{
    int     j;
    char    *tmp;
    t_lst   *last;

    j = 1;
    *flag = true;
    g_sig.ex_code = 0;
    if (!pre_export_check(str, *list))
        return (0);
    last = ft_lstlast_rem(*list);
    tmp = last->var;
    if (!make_export(str, list))
        return (0);
    ft_lstadd_back_rem(list, ft_lstnew_rem(tmp));
    return (0);
}

bool    pre_export_check(char   **strs, t_lst   *list)
{
    int i;

    if (!strs[1])
    {
        print_sorted_env(list);
        return (0);
    }
    i = 0;
    while (strs[++i])
        if (!ft_strncmp(strs[i], "=", 1) && ft_strcmp(strs[i], "="))
        {
            ft_putstr_fd(ERROR"minishell: ", 2);
            ft_putstr_fd(strs[i] + 1, 2);
            ft_putendl_fd(" not found"TEXT, 2);
            if (i == 1 || !ft_strcmp(strs[1], "="))
                g_sig.ex_code = 1;
            return (false) ;
        }
    return (true);
}

int check_export_exception(char *str, int *index)
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
    return (2);
}

bool    make_export(char **str, t_lst **list)
{
    int j;
    int i;
    int result_of_exp;

    j = 1;
    while (str[j])
    {
        result_of_exp = check_export_exception(str[j], &j);
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
        j++;
    }
    return (true);
}