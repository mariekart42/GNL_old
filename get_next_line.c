/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 19:09:22 by mmensing          #+#    #+#             */
/*   Updated: 2022/06/08 17:05:31 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>



char *free_and_allocate(char *temp, int BUFF, int mem)
{
	char *new_ptr;
	//size_t	size;
	if (temp == 0)
	{
		temp = (char *) malloc(BUFF*mem);
		return(temp);
	}
	new_ptr = (char *) malloc (BUFF*mem);
	new_ptr = memmove(new_ptr, temp, (BUFF * (mem-1)));
	free(temp);
	return (new_ptr);
}


char *get_next_line(int fd)
{
	char *temp;
	char *ptr;
	ptr = (char *) malloc(BUFFER_SIZE);
	if(!ptr)
		return (NULL);
	temp = (char *) malloc(BUFFER_SIZE * sizeof(char));
	if (!temp)
		return (NULL);
	int mem = 1;
	int val = 0;
	
	printf("BUFFer: %d\n", BUFFER_SIZE);
	
	val = read(fd, ptr, BUFFER_SIZE);
	
	
	if(val < 0)
		printf("fail\n");
	if(val == 0)
		printf("end of file\n");
		
	// while '\n' not found in ptr
	while (ft_strchr(ptr, '\n') == 0)
	{
		if (mem != 1)
		{
			temp = free_and_allocate(temp, BUFFER_SIZE, mem);
			if(!temp)
				return (NULL);
			temp = ft_strjoin(temp, ptr);
		}
		else if (mem == 1)
		{
			temp = ft_memmove(temp, ptr, BUFFER_SIZE);
		}
		val = read (fd, ptr, BUFFER_SIZE);
		mem++;
	}
	printf("ptr: %s\n", ptr);
	return(temp);
}



int main()
{
	 
	int fd = open("test.txt", O_RDONLY, 0);
	//int fd = open("test.txt", O_RDONLY, 0);
	printf("fd: %d\n", fd);
	
	char *prr = get_next_line(fd);
	printf("main: %s\n\n", prr);
	
	// prr = get_next_line(fd);
	// //prr = get_next_line(fd);
	// printf("second: %s\n", prr);
	
	// prr = get_next_line(fd);
	// printf("third: %s\n", prr);
	
	// prr = get_next_line(fd);
	// printf("four: %s\n", prr);
	
	// prr = get_next_line(fd);
	// printf("last: %s\n", prr);

	// prr = get_next_line(fd);
	// printf("second main: %s\n\n", prr);

	//close(fd1);
	//int fd2 = open("test2.txt", O_RDONLY, 0);
	//printf("open()-fd = %d\n", fd); 
	
	//printf("fd = %d\n", fd2); 
	//int fd = 3;
    return 0; 
}