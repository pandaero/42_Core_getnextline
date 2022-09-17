//*Test
//gcc gnl_main.c get_next_line.c get_next_line_utils.c && ./a.out | cat -e
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd1, fd2, fd3, fd4;
	int		i;
	char	*line;

	fd1 = open("./samples/sample1.txt", O_RDONLY, 0);
	fd2 = open("./samples/sample2.txt", O_RDONLY, 0);
	fd3 = open("./samples/sample3.txt", O_RDONLY, 0);
	line = get_next_line(fd1);
	printf("Fd: %d, Line%d: %s", 1, 1, line);
	free(line);
	line = get_next_line(fd2);
	printf("Fd: %d, Line%d: %s", 2, 1, line);
	free(line);
	line = get_next_line(fd3);
	printf("Fd: %d, Line%d: %s", 3, 1, line);
	free(line);
	line = get_next_line(fd3);
	printf("Fd: %d, Line%d: %s", 3, 2, line);
	free(line);
	line = get_next_line(fd1);
	printf("Fd: %d, Line%d: %s", 1, 2, line);
	free(line);
	line = get_next_line(fd1);
	printf("Fd: %d, Line%d: %s", 1, 3, line);
	free(line);
	line = get_next_line(fd1);
	printf("Fd: %d, Line%d: %s", 1, 4, line);
	free(line);
	line = get_next_line(fd3);
	printf("Fd: %d, Line%d: %s", 3, 3, line);
	free(line);
	line = get_next_line(fd3);
	printf("Fd: %d, Line%d: %s", 3, 4, line);
	free(line);
	return (0);
}
//*/