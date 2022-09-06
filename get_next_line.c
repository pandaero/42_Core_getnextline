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

}

//Function trims the input string such that contents after newline are cut.
char	*output()
{

}

//Function takes input string and returns contents after the first newline.
char	*remaining()
{

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