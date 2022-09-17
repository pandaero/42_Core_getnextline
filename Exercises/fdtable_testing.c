//To test the variable data structure

struct		fdtable
{
	int		fd;
	char	*ptr;
};

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*remaining(char *candidate)
{
	int		ii[2];
	char	*remout;

	ii[0] = 0;
	while (candidate[ii[0]] != '\0' && candidate[ii[0]] != '\n')
		ii[0]++;
	if (candidate[ii[0]] == '\0')
	{
		free(candidate);
		return ((char *) 0);
	}
	remout = malloc((strlen(candidate) - ii[0] + 1) * sizeof(*remout));
	if (!remout)
		return ((char *) 0);
	ii[0]++;
	ii[1] = 0;
	while (candidate[ii[0]] != '\0')
	{
		remout[ii[1]] = candidate[ii[0]];
		ii[0]++;
		ii[1]++;
	}
	remout[ii[1]] = '\0';
	free(candidate);
	return (remout);
}

unsigned int	readtable(int fd, struct fdtable *ptrtable)
{
	unsigned int	i;
	unsigned int	j;

	if (fd == 0)
		return (0);
	i = 1;
	while ((ptrtable + i)->fd != fd && i < 100)
		i++;
	if (i == 100)
	{
		j = 1;
		while (ptrtable[j].fd != 0 && j < 100)
			j++;
		(ptrtable + j)->fd = fd;
		return (j);
	}
	else
		return (i);
}

int	main()
{
	static struct fdtable	*table;
	int						i;

	table = (struct fdtable *)malloc(100 * sizeof(struct fdtable));
	table->fd = 5;
	(table + 1)->fd = 6;
	table[0].ptr = strdup("Hello");
	table[1].ptr = strdup("How do you do?\nHello");
	printf("fd1: %i, ptr1: %s\n", table[0].fd, table[0].ptr);
	printf("fd2: %i, ptr2: %s\n", table[1].fd, table[1].ptr);
	printf("fd3: %i, ptr3: %s\n", table[2].fd, table[2].ptr);
	table[1].ptr = remaining(table[1].ptr);
	printf("fd2: %i, ptr2: %s\n", table[1].fd, table[1].ptr);
	i = readtable(9, table);
	printf("fd3: %i, ptr3: %s, i: %i\n", table[2].fd, table[2].ptr, i);
	free(table);
	return (0);
}