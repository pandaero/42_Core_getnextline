#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_fetch(int fd)
{
	char	*string;
	int		rdout;

	string = malloc ((5 + 1) * sizeof(char));
	if (!string)
		return ((char *) 0);
	rdout = read(fd, string, 5);
	if (rdout == -1 || string[0] == '\0')
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
	int		i;

	fd = open("sample.txt", O_RDONLY, 0);
	i = 0;
	while (i < 17)
	{
		ptr = ft_fetch(fd);
		if (i < 10)
			printf("Read  %d: %s\n", i, ptr);
		else
			printf("Read %d: %s\n", i, ptr);
		free(ptr);
		i++;
	}
	return (0);
}
//gcc -Wall -Werror -Wextra readwrite.c && ./a.out | cat -e