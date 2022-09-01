#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_fetch(int fd)
{
	char	*string;
	int		rdout;

	string = malloc ((4 + 1) * sizeof(char));
	if (!string)
		return ((char *) 0);
	rdout = read(fd, string, 4);
	if (rdout == -1)
	{
		free(string);
		return ((char *) 0);
	}
	return (string);
}

int	main(void)
{
	int		fd;
	char	*ptr;

	fd = open("sample.txt", O_RDONLY, 0);
	ptr = stringy(fd);
	printf("Read1: %s\n", ptr);
	free(ptr);
	ptr = stringy(fd);
	printf("Read2: %s\n", ptr);
	free(ptr);
	return (0);
}

//gcc -Wall -Werror -Wextra readwrite.c && ./a.out | cat -e