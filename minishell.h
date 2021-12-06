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

typedef struct	s_mini
{
	t_list				*lst;
	t_lst				*list;
	t_list				*history;
	t_cmd				cmds;
	t_proccess			proc;
	t_inside_gap_2		change;
	struct sigaction	sig;
}				t_mini;


t_lst	*ft_lstnew_rem(void	*content);
void	ft_lstdelone_rem(t_lst	*lst, void (*del)(void *));
void	ft_lstclear_rem(t_lst	**lst, void (*del)(void *));
void	ft_lstadd_back_rem(t_lst	**lst, t_lst	*new);
t_lst	*ft_lstlast_rem(t_lst *lst);
t_lst	*envp_copy(char *envp[]);
int		ft_strcmp(const char *s1, const char *s2);
int		mini_echo(char **str, t_inside_gap_2	change, bool *flag, char	**envp);
int		mini_pwd(bool *flag);
int		mini_cd(char *path, t_lst	**list, bool *flag);
void	mini_exit(char *str, bool *flag);
int		mini_env(t_lst *list, bool *flag);
int		mini_export(t_lst **list, char **str, bool *flag);
void	del(void *var);
char	*pwd_cur(void);
int		mini_unset(t_lst **list, char **str, bool *flag);
int 	mini_history(t_list	*history, bool *flag);
int		ft_lstsize_rem(t_lst	*lst);
t_list	*make_history(char	*str, t_list	*lst);
void	make_split(t_list	**lst);
bool	exec(t_list	*tmp, t_lst	*list, t_inside_gap_2	change, t_list	*history, char	**envp);
void	minishell(t_mini	*mini, char	**envp, char	*strs[]);

#endif
