/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:42:52 by pandalaf          #+#    #+#             */
/*   Updated: 2022/08/26 18:42:52 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "get_next_line.h"

//Function joins the initial string with reads from a descriptor until newline.
char	*joining(int fd, char *initial)
{
	char	*read;
	char	*temp;
	char	*joinout;

	read = ft_fetch(fd, BUFFER_SIZE);
	if (!read)
		return ((char *) 0);
	if (read[0] == '\0')
	{
		free(read);
		return (initial);
	}
	joinout = ft_strjoin(initial, read);
	while (ft_strsrch(read, '\n') == 0 && read[0] != '\0')
	{
		free(read);
		read = ft_fetch(fd, BUFFER_SIZE);
		temp = ft_strjoin(joinout, read);
		free(joinout);
		joinout = temp;
	}
	free(read);
	return (joinout);
}

/* Test
//gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c && ./a.out
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*ptr;
	int		fd;

	fd = open("sample.txt", O_RDONLY, 0);
	ptr = joining(fd, ptr);
	printf("Joined: %s\n", ptr);
	free(ptr);
	return (0);
}
//*/

//Function trims the input string such that contents after newline are cut.
char	*output(char *candidate)
{
	int		i;
	char	*outout;

	i = 0;
	while (candidate[i] != '\0' && candidate[i] != '\n')
		i++;
	if (candidate[i] == '\n' || candidate[i] == '\0')
	{
		outout = malloc((i + 2) * sizeof(char));
		outout[i + 1] = '\0';
		if (candidate[i] == '\n')
		{
			while (i-- >= 0)
				outout[i + 1] = candidate[i + 1];
		}
		else
		{
			outout[i] = '\n';
			while (i-- >= 0)
				outout[i] = candidate[i];
		}
	}
	else
		return ((char *) 0);
	return (outout);
}

/*Test
//gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c && ./a.out
#include <stdio.h>

int	main(void)
{
	char	test1[] = "Hello there\nan\nd \neverything else";
	char	test2[] = "Hello there";
	char	test3[] = "";
	char	test4[] = "\n\n";
	char	*ptr;

	ptr = output(test1);
	printf("Newline Test  : %s\n", ptr);
	free(ptr);
	ptr = output(test2);
	printf("Null-Term Test: %s\n", ptr);
	free(ptr);
	ptr = output(test3);
	printf("Empty Test    : %s\n", ptr);
	free(ptr);
	ptr = output(test4);
	printf("Newlines Test : %s\n", ptr);
	free(ptr);
	return (0);
}
//*/

//Function takes input string and returns contents after the first newline.
char	*remaining(char *candidate)
{
	int		ii[2];
	char	*remout;

	ii[0] = 0;
	while (candidate[ii[0]] != '\0' && candidate[ii[0]] != '\n')
		ii[0]++;
	remout = malloc((ft_strlen(candidate) - ii[0] + 1) * sizeof(char));
	if (candidate[ii[0]] == '\0' || !remout)
	{
		free(candidate);
		free(remout);
		return ((char *) 0);
	}
	ii[0]++;
	ii[1] = 0;
	while(candidate[ii[0]] != '\0')
	{
		remout[ii[1]] = candidate[ii[0]];
		ii[0]++;
		ii[1]++;
	}
	remout[ii[1]] = '\0';
	free(candidate);
	return (remout);
}

/*Test
//gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c && ./a.out
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*ptr;
	char	*test1;
	test1 = strdup("xxxx\nxx\nxxx\nx\n\n");
	char	*test2;
	test2 = strdup("xx");
	char	*test3;
	test3 = strdup("xxxxxxxx\n\n");
	char	*test4;
	test4 = malloc(2 * sizeof(char));
	test4[0] = '\0';
	test4[1] = '\0';
	char	*test5;
	test5 = strdup("\n\n");

	ptr = remaining(test1);
	printf("Newline Test: %s\n", ptr);
	free(ptr);
	ptr = remaining(test2);
	printf("Nothing Test: %s\n", ptr);
	free(ptr);
	ptr = remaining(test3);
	printf("Newlast Test: %s\n", ptr);
	free(ptr);
	ptr = remaining(test4);
	printf("Empty Test  : %s\n", ptr);
	free(ptr);
	ptr = remaining(test5);
	printf("Just Newline: %s\n", ptr);
	free(ptr);
	return (0);
}
//*/

char	*get_next_line(int fd)
{
	static char	*ptr = "";
	char		*out;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return ((char *) 0);
	ptr = joining(fd, ptr);
	if (!ptr)
		return ((char *) 0);
	out = output(ptr);
	if (!out)
		return ((char *) 0);
	ptr = remaining(ptr);
	return (out);
}

/*Test
//gcc get_next_line.c get_next_line_utils.c && ./a.out | cat -e
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		i;
	char	*ptr;

	i = 1;
	fd = open("sample.txt", O_RDONLY, 0);
	ptr = get_next_line(fd);
	while (ptr != (char *) 0)
	{
		printf("Line%d: %s", i, ptr);
		free(ptr);
		ptr = get_next_line(fd);
		i++;
	}
	free(ptr);
	return (0);
}
//*/