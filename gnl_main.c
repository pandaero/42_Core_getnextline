//*Test
//gcc gnl_main.c get_next_line.c get_next_line_utils.c && ./a.out | cat -e
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
	int		fd;
	int		i;
	char	*ptr;

	//Standard Input, close it with CTRL + D
	fd = 0;
	fd = open("sample.txt", O_RDONLY, 0);
	i = 1;
	while (ptr != (char *) 0)
	{
		ptr = get_next_line(fd);
		printf("Line%d: %s", i, ptr);
		free(ptr);
		i++;
	}
	return (0);
}
//*/