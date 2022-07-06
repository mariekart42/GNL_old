/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:58:00 by mmensing          #+#    #+#             */
/*   Updated: 2022/07/06 23:46:33 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Get the next line object
 * Write a function that returns a line read from a file descriptor
 * 
 * @param fd The file descriptor to read from
 * @return char* Read line: correct behavior
 * NULL: there is nothing else to read, or an error occurred
 */

char	*get_next_line(int fd)
{
	int		val;
	char	c;
	char	*ptr;
	int		i;
	int		check;

	c = '\0';
	if (!(ptr = (char *) calloc(50, sizeof(char))))
		return (NULL);
	i = 0;

	while (c == '\n')
		c++;
	check = 0;
	while (c != '\n')
	{
		val = read(fd, &c, 1);
		if (val < 1 && check == 0)
			return (NULL);
		else if (val < 1)
			return (ptr);
		if (val == 0 && c != '\n')
			return (ptr);
		else
			ptr[i] = c;
		check++;
		i++;
	}
	return (ptr);
}
