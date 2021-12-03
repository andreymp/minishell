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
# include "parser.h"
# include "pipe.h"

typedef struct s_lst
{
	char			*var;
	struct s_lst	*next;
}				t_lst;

t_lst	*ft_lstnew_rem(void	*content);
void	ft_lstdelone_rem(t_lst	*lst, void (*del)(void *));
void	ft_lstclear_rem(t_lst	**lst, void (*del)(void *));
void	ft_lstadd_back_rem(t_lst	**lst, t_lst	*new);
t_lst	*ft_lstlast_rem(t_lst *lst);
t_lst	*envp_copy(char *envp[]);
int		ft_strcmp(const char *s1, const char *s2);
int		mini_echo(char **str);
int		mini_pwd(void);
int		mini_cd(char *path, t_lst	**list);
void	mini_exit(char *str);
int		mini_env(t_lst *list);
int		mini_export(t_lst **list, char **str);
void	del(void *var);
char	*pwd_cur(void);
int		mini_unset(t_lst **list, char **str);
int 	mini_history(t_list	*history);
int		ft_lstsize_rem(t_lst	*lst);
t_list	*make_history(char	*str, t_list	*lst);

#endif
