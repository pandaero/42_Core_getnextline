/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:42:49 by pandalaf          #+#    #+#             */
/*   Updated: 2022/08/26 18:42:49 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
# include <stddef.h>

//Function that outputs lines from a given file descriptor.
char	*get_next_line(int fd);
//Function determines length of the string (number of characters).
size_t	ft_strlen(const char *str);
//Function searches for char and returns first location. 0 not found. 1 is 1st.
int		ft_strsrch(char *str, int ch);
//Function joins two character strings, creates a new char string.
char	*ft_strjoin(char *s1, const char *s2);
//Function joins the initial string with reads from a descriptor until newline.
char	*joining(int fd, char *initial);
//Function trims the input string such that contents after newline are cut.
char	*output(char *candidate);
//Function takes input string and returns contents after the first newline.
char	*remaining(char *candidate);

#endif