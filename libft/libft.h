/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:59:46 by jobject           #+#    #+#             */
/*   Updated: 2021/12/01 15:38:06 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

typedef struct s_list
{
	char			*content;
	char			**cmd;
	struct s_list	*next;
}					t_list;

int			ft_isalpha(int code);
int			ft_isdigit(int code);
int			ft_isalnum(int code);
int			ft_isascii(int code);
int			ft_isprint(int code);
size_t		ft_strlen(const char	*str);
void		*ft_memset(void	*source, int code, size_t	length);
void		ft_bzero(void	*str, size_t	length);
void		*ft_memcpy(void	*dest, const void	*src, size_t	num);
void		*ft_memmove(void	*dest, const void	*src, size_t	num);
int			ft_toupper(int code);
int			ft_tolower(int code);
char		*ft_strchr(const char	*str, int code);
char		*ft_strrchr(const char	*str, int code);
int			ft_strncmp(const char	*s1, const char *s2, size_t	n);
int			ft_memcmp(const void	*s1, const void	*s2, size_t	n);
char		*ft_strnstr(const char	*big, const char	*little, size_t	len);
int			ft_atoi(const char	*nptr);
size_t		ft_strlcpy(char	*dest, const char	*src, size_t	size);
size_t		ft_strlcat(char	*dest, const char	*src, size_t	size);
void		*ft_calloc(size_t	nmemb, size_t	size);
char		*ft_strdup(const char	*str);
void		*ft_memchr(const void	*str, int code, size_t	n);
char		*ft_substr(char const	*s, unsigned int start, size_t	len);
char		*ft_strjoin(char const	*s1, char const	*s2);
char		*ft_strtrim(char const	*s1, char const	*set);
char		*ft_strmapi(char const	*s, char (*f)(unsigned int, char));
char		*ft_itoa(int n);
void		ft_striteri(char	*s, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char	*s, int fd);
void		ft_putstr_fd(char	*s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		**ft_split(char const	*s, char c);
t_list		*ft_lstnew(char	*content);
void		ft_lstadd_front(t_list	**lst, t_list	*new);
int			ft_lstsize(t_list	*lst);
t_list		*ft_lstlast(t_list	*lst);
void		ft_lstadd_back(t_list	**lst, t_list	*new);
void		ft_lstdelone(t_list	*lst, void (*del)(void *));
void		ft_lstclear(t_list	**lst, void (*del)(void *));
void		ft_lstiter(t_list	*lst, void (*f)(char *));
t_list		*ft_lstmap(t_list	*lst, char	*(*f)(char *), void	(*del)(void *));

#endif