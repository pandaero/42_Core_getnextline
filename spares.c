/*
Unused functions developed during the get_next_line project.
*/

//Function searches for char and returns first location. 0 not found. 1 is 1st.
int	ft_strsrch(const char *str, char ch)
{
	unsigned int	i;
	int				loc;

	loc = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
			return(i + 1);
		i++;
	}
	return(loc);
}

/*Test strsrch
//gcc -Wall -Werror -Wextra get_next_line_utils.c && ./a.out
#include <stdio.h>

int	main(void)
{
	char	*str="Hello";
	char	ch='3';

	printf("Str: %s, Ch: %c, Out: %d\n", str, ch, ft_strsrch(str, ch));
	return (0);
}
//*/

//Function reads from a file descriptor, creating a string for its output.
char	*ft_fetch(int fd, int buffsize)
{
	char	*string;
	int		rdout;

	rdout = 0;
	string = malloc ((buffsize + 1) * sizeof(char));
	if (!string)
		return ((char *) 0);
	string[0] = '\0';
	rdout = read(fd, string, buffsize);
	if (rdout == -1 || string[0] == '\0')
	{
		free(string);
		return ((char *) 0);
	}
	string[buffsize] = '\0';
	return (string);
}

/* Test | gcc -Wall -Werror -Wextra get_next_line_utils.c && ./a.out
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*fetched;
	int		fd;
	int		buffsize;
	int		i;

	fd = open("sample.txt", O_RDONLY, 0);
	buffsize = 6;
	i = 1;
	while (i < 20)
	{
		fetched = ft_fetch(fd, buffsize);
		printf("Read%d: %s\n", i, fetched);
		free(fetched);
		i++;
	}
	return (0);
}
//*/

//Function counts on a static variable array. Input determines counter mode.
int	*ft_count(int ctr)
{
	static int count[2] = {0, 0};
	if (ctr == 1)
		count[0] += 1;
	else if (ctr == 2)
		count[1] += 1;
	else if (ctr += 3)
	{
		count[0] += 1;
		count[1] += 1;
	}
	else
		return count;
	return count;
}

/*Test count
//gcc -Wall -Werror -Wextra get_next_line_utils.c && ./a.out
#include <stdio.h>

int	main(void)
{
	int	*p;

	p = ft_count(3);
	printf("1 - Var[0]: %d, Var[1]: %d\n", p[0], p[1]);
	p = ft_count(3);
	printf("2 - Var[0]: %d, Var[1]: %d\n", p[0], p[1]);
	return (0);
}
//*/