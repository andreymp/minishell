/* не рвботает :(((( */

#include "../minishell.h"

void	err_print(char *name)
{
	if (errno == EACCES)
		write(2, "cd error: permission denied: ", 29);
	else if (errno == ENFILE)
		write(2, "cd error: too many opend threads: ", 34);
	else if (errno == ENOENT)
		write(2, "cd error: no such file or directory: ", 37);
	else if (errno == ENOMEM)
		write(2, "cd error: not enough memory: ", 29);
	else if (errno == ENOTDIR)
		write(2, "cd error: \"", 11);
	ft_putstr_fd(name, 2);
	if (errno == ENOTDIR)
		write(2, "\" not a directory", 18);
	write(2, "\n", 1);
}

int	mini_cd(char *path)
{
	errno = 0;
	
	chdir(path);
	opendir(path);
	if (errno != 0)
	{
		err_print(path);
		return (errno);
	}
	chdir(path);
	return (0);
}