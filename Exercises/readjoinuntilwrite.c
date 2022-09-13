#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_fetch(int fd)
{
	char	*string;

	string = malloc ((4 + 1) * sizeof(char));
	if (!string)
		return ((char *) 0);
	read(fd, string, 4);
	return (string);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned char	*ptr;
	unsigned int	i;
	unsigned int	j;

	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return ((char *) 0);
	i = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = 0;
	return ((char *) ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char	*ptr;
	unsigned int	i;

	if (start > ft_strlen(s))
	{
		ptr = malloc(sizeof(char));
		if (!ptr)
			return ((char *) 0);
		ptr[0] = '\0';
		return ((char *) ptr);
	}
	else if (len + start >= ft_strlen(s))
		ptr = malloc((ft_strlen(s) - start + 1) * (sizeof(char)));
	else
		ptr = malloc((len + 1) * (sizeof(char)));
	if (!ptr)
		return ((char *) 0);
	i = 0;
	while (len > i && s[start + i] != '\0')
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return ((char *) ptr);
}

char	*ft_joininguntil(int fd)
{
	char	*first;
	char	*second;
	char	*out;
	int		i;

	first = ft_fetch(fd);
	i = 0;
	while (first[i] != '\n' && i < 4)
		i++;
	if (i == 4 - 1)
		out = first;
	else if (first[i] == '\n')
		out = ft_substr(first, 0, i);
	else
	{
		second = ft_fetch(fd);
		out = ft_strjoin(first, second);
		free(second);
	}
	return (out);
}

int	main(void)
{
	int 	fd;
	char	*string;

	fd = open("sample.txt", O_RDONLY, 0);
	string = ft_joininguntil(fd);
	printf("Out: %s\n", string);
	free(string);
	return (0);
}

//gcc -Wall -Werror -Wextra readjoinwrite.c && ./a.out | cat -e