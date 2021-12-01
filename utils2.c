#include "minishell.h"

void	del(void *var)
{
	var = NULL;
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
		return(1);
	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (i == n)
			return (0);
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

static int	get_length(int n)
{
	int	size;

	size = 0;
	while (n / 10)
	{
		size++;
		n /= 10;
	}
	size++;
	if (n < 0)
		size++;
	return (size);
}

char	*ft_itoa(int n)
{
	int		length;
	char	*res;
	int		i;

	if (n == -2147483648)
		return (ft_strjoin("-", "2147483648"));
	length = get_length(n);
	res = (char *) malloc((length + 1) * sizeof(char));
	if (!res)
		return (0);
	i = length - 1;
	if (n < 0)
	{
		*res = '-';
		n *= -1;
	}
	while (i && n / 10)
	{
		*(res + i) = n % 10 + 48;
		n /= 10;
		i--;
	}
	*(res + i) = n + 48;
	*(res + length) = '\0';
	return (res);
}

static char	*ft_copy(char const *s1, char const *s2, char *s12)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		s12[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		s12[i] = s2[j];
		i++;
		j++;
	}
	s12[i] = '\0';
	return (s12);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*s12;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	len = 0;
	while (s1[len] != '\0')
		len++;
	while (s2[i] != '\0')
		i++;
	len = len + i;
	s12 = (char *)malloc(len + 1);
	if (s12 == NULL)
		return (NULL);
	s12 = ft_copy(s1, s2, s12);
	return (s12);
}