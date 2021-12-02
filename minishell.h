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
# include <signal.h>

# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_list
{
	char			*var;
	struct s_list	*next;
}				t_list;

/* либовские ф-ци, нужно будет удалить 😇 */
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);
t_list	*ft_lstnew(void	*content);
void	ft_lstadd_back(t_list	**lst, t_list	*new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list	*lst, void (*del)(void *));
void	ft_lstclear(t_list	**lst, void (*del)(void *));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);

/* мои ф-ции, нельзя удалять 😡 */
int		ft_strcmp(const char *s1, const char *s2);
int		mini_echo(char *str, int n, int ex_code);
int		mini_pwd(void);
int		mini_cd(char *path);
void	mini_exit(char *str);
int		mini_env(t_list *list);
int		mini_export(t_list **list, char **str);
void	del(void *var);
int		mini_unset(t_list **list, char **str);

#endif
