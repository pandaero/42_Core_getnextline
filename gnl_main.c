/*Test
//gcc get_next_line.c get_next_line_utils.c && ./a.out | cat -e

int main(void)
{
	int		fd;
	int		i;
	char	*ptr;

	i = 0;
	fd = open("sample.txt", O_RDONLY, 0);
	while (ptr != (char *) 0)
	{
		ptr = get_next_line(fd);
		printf("Read%d: %s", i, ptr);
		free(ptr);
		i++;
	}
	return (0);
}

//*/