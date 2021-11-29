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

# include <readline/readline.h>
# include <readline/history.h>

typedef struct	s_param
{
	int		error;
	char	*str[16];
	int		hiscnt;
}				t_param;

typedef struct	s_pars
{
	int	quo;
	int	dblquo;
	int	slash;

}				t_pars;

void	ft_putstr_fd(char *s, int fd);
char	*get_next_line(int fd);
char	*ft_strjoin(char	*s1, char const	*s2);
char	*ft_strdup(char *s1);
size_t	ft_strlen(const char	*str);
void	*ft_memcpy(void	*dest, const void	*src, size_t	num);
int		parcer(char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		mini_echo(char *str, int n);
int		mini_pwd(void);
int		mini_cd(char *path);

#endif
