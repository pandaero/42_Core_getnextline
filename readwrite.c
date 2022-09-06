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

	fd = open("sample.txt", O_RDONLY, 0);
	ptr = ft_fetch(fd);
	printf("Read1:  %s\n", ptr);
	free(ptr);
	ptr = ft_fetch(fd);
	printf("Read2:  %s\n", ptr);
	free(ptr);
	ptr = ft_fetch(fd);
	printf("Read3:  %s\n", ptr);
	free(ptr);
	ptr = ft_fetch(fd);
	printf("Read4:  %s\n", ptr);
	free(ptr);
	ptr = ft_fetch(fd);
	printf("Read5:  %s\n", ptr);
	free(ptr);
	ptr = ft_fetch(fd);
	printf("Read6:  %s\n", ptr);
	free(ptr);
	ptr = ft_fetch(fd);
	printf("Read7:  %s\n", ptr);
	free(ptr);
	ptr = ft_fetch(fd);
	printf("Read8:  %s\n", ptr);
	free(ptr);
	ptr = ft_fetch(fd);
	printf("Read9:  %s\n", ptr);
	free(ptr);
	ptr = ft_fetch(fd);
	printf("Read10: %s\n", ptr);
	free(ptr);
	ptr = ft_fetch(fd);
	printf("Read11: %s\n", ptr);
	free(ptr);
	ptr = ft_fetch(fd);
	printf("Read12: %s\n", ptr);
	free(ptr);
	return (0);
}

//gcc -Wall -Werror -Wextra readwrite.c && ./a.out | cat -e