/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:56:16 by jobject           #+#    #+#             */
/*   Updated: 2021/12/07 12:17:04 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static char	*get_after(char	*str)
{
	size_t	i;
	char	*res;

	i = 0;
	while (*(str + i) != '\n' && *(str + i))
		i++;
	if (*(str + i))
	{
		res = (char *) malloc(ft_strlengnl(str) - i + 1);
		if (!res)
			return (NULL);
		ft_memcpygnl(res, str + i + 1, ft_strlengnl(str) - i);
		free(str);
		return (res);
	}
	free (str);
	return (NULL);
}

static char	*get_until(char	*str)
{
	int			i;
	char		*res;

	i = 0;
	while (*(str + i) != '\n' && *(str + i))
		i++;
	res = (char *) malloc(i + 2);
	if (!res)
		return (NULL);
	ft_memcpygnl(res, str, i + 1);
	return (res);
}

static int	full_line(char	*str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (*(str + i) && *(str + i) != '\n')
		i++;
	if (!*(str + i))
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*res;
	char		*str;
	int			r;
	char		buf[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	r = 1;
	while (r && !full_line(res))
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0 || (!r && !res))
			return (NULL);
		if (!r && !*res)
		{
			free(res);
			return (NULL);
		}
		*(buf + r) = '\0';
		res = ft_strjoingnl(res, buf);
	}
	str = get_until(res);
	res = get_after(res);
	return (str);
}
