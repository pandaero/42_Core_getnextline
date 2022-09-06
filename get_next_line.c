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
	char	*out;

	read = ft_fetch(fd, BUFFER_SIZE);
	if (!read)
		return ((char *) 0);
	out = ft_strjoin(initial, read);
	while (ft_strsrch(read, '\n') == 0 && read[0] != '\0')
	{
		read = ft_fetch(fd, BUFFER_SIZE);
		out = ft_strjoin(out, read);
	}
	free(read);
	return (out);
}

/* Test
//gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c && ./a.out
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	char	*ptr = "";
	int		fd;

	fd = open("sample.txt", O_RDONLY, 0);
	ptr = joining(fd, ptr);
	printf("Joined: %s", ptr);
	free(ptr);
	return (0);
}
//*/

//Function trims the input string such that contents after newline are cut.
char	*output(char *candidate)
{
	return ("");
}

//Function takes input string and returns contents after the first newline.
char	*remaining(char *candidate)
{
	return ("");
}

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
	ptr = remaining(ptr);
	return (out);
}

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