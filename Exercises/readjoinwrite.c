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

char	*ft_joining(int fd)
{
	char	*first;
	char	*second;
	char	*out;

	first = ft_fetch(fd);
	second = ft_fetch(fd);
	out = ft_strjoin(first, second);
	free(first);
	free(second);
	return (out);
}

int	main(void)
{
	int 	fd;
	char	*string;

	fd = open("sample.txt", O_RDONLY, 0);
	string = ft_joining(fd);
	printf("Out: %s\n", string);
	free(string);
	return (0);
}

//gcc -Wall -Werror -Wextra readjoinwrite.c && ./a.out | cat -e