#ifndef MINISHELL_H
# define MINISHELL_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/types.h>
# include <errno.h>
# include <sys/ioctl.h>

# include <readline/readline.h>
# include <readline/history.h>

typedef struct	s_list
{
	char			*var;
	struct s_list	*next;
}				t_list;

void	ft_putstr_fd(char *s, int fd);
int		parcer(char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		mini_echo(char *str, int n);
int		mini_pwd(void);
int		mini_cd(char *path);
int		ft_atoi(const char *str);
void	mini_exit(char *str);
void	mini_env(t_list *list);
t_list	*ft_lstnew(void	*content);
void	ft_lstadd_back(t_list	**lst, t_list	*new);
t_list	*ft_lstlast(t_list *lst);
void	mini_export(t_list **list, char *str);

#endif
