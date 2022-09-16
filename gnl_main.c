//*Test
//gcc gnl_main.c get_next_line.c get_next_line_utils.c && ./a.out | cat -e
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		i;
	char	*line = "";

	//Standard Input, close it with CTRL + D
	fd = 0;
	fd = open("./samples/sample1.txt", O_RDONLY, 0);
	i = 1;
	while (line != (char *) 0 && i < 14)
	{
		line = get_next_line(fd);
		printf("Line%d: %s", i, line);
		free(line);
		i++;
	}
	return (0);
}
//*/