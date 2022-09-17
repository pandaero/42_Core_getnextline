//To test the variable data structure

struct		fdtable
{
	int		fd;
	char	*ptr;
};

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main()
{
	static struct fdtable	*table;
	int						i;

	table = (struct fdtable *)malloc(10 * sizeof(struct fdtable));
	table->fd = 5;
	(table + 1)->fd = 6;
	table[0].ptr = "Hello";
	table[1].ptr = "How do you do?";
	printf("fd1: %i, ptr1: %s\n", table[0].fd, table[0].ptr);
	printf("fd2: %i, ptr2: %s\n", table[1].fd, table[1].ptr);
	printf("fd3: %i, ptr3: %s\n", table[2].fd, table[2].ptr);
	free(table);
	return (0);
}