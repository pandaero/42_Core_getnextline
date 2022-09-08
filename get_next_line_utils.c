/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:42:54 by pandalaf          #+#    #+#             */
/*   Updated: 2022/08/26 18:42:54 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include "get_next_line.h"

//Function determines length of the string (number of characters).
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/* Test | gcc -Wall -Werror -Wextra get_next_line_utils.c && ./a.out
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *f = "Hello World";
	char *d = "";
	printf("Test 1: %s, strlen: %lu,
				ft_strlen: %lu\n", f, strlen(f), ft_strlen(f));
	printf("Test 2: %s, strlen: %lu,
				ft_strlen: %lu\n", d, strlen(d), ft_strlen(d));
	return (0);
}
//*/

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
			return (i + 1);
		i++;
	}
	return (loc);
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

	string = malloc ((buffsize + 1) * sizeof(char));
	if (!string)
		return ((char *) 0);
	rdout = read(fd, string, buffsize);
	if (rdout == -1 || string[0] == '\0')
	{
		free(string);
		return ((char *) 0);
	}
	string[buffsize + 1] = '\0';
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

//Function joins two character strings, creates a new char string.
char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned char	*ptr;
	unsigned int	i;
	unsigned int	j;

	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return ((char *) 0);
	i = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = 0;
	return ((char *) ptr);
}

/* Test | gcc -Wall -Werror -Wextra get_next_line_utils.c && ./a.out
#include <stdio.h>

int	main(void)
{
	char	s1[] = "You";
	char	s2[] = " and me";
	char	*join;

	join = ft_strjoin(s1, s2);
	printf("Test: s1-%s, s2-%s, Out-%s\n", s1, s2, join);
	free(join);
	return (0);
}
//*/