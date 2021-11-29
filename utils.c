/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:04:40 by jobject           #+#    #+#             */
/*   Updated: 2021/11/29 21:12:40 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*multi_join(char	*str, int i, int j)
{
	char	*tmp1;
	char	*tmp2;
	char	*res;

	res = ft_substr(str, 0, j);
	tmp1 = ft_substr(str, j + 1, i - j - 1);
	tmp2 = ft_strdup(str + i + 1);
	free(str);
	res = ft_strjoin(res, tmp1);
	free(tmp1);
	res = ft_strjoin(res, tmp2);
	free(tmp2);
	return (res);
}
