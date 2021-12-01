/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:56:19 by jobject           #+#    #+#             */
/*   Updated: 2021/12/01 13:12:44 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 42

char	*get_next_line(int fd);
size_t	ft_strlengnl(const char	*str);
void	*ft_memcpygnl(void	*dest, const void	*src, size_t	num);
char	*ft_strjoingnl(char	*s1, char const	*s2);
char	*ft_strdupgnl(const char	*str);

#endif