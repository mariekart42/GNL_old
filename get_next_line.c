/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@wolfsburg.42student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 19:09:22 by mmensing          #+#    #+#             */
/*   Updated: 2022/06/08 19:35:26 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *copy_up_to_NULL(char * ptr)
{
	int i = 0;
	char *tempi;
	tempi = ptr;
	if (ptr[i] == '\n')
		return (ptr);

	while (ptr[i] != '\n')
	{
		tempi[i] = ptr[i];
		i++;
	}
	ptr[i] = '\0';
	//printf("TEST: %s\n", temp);
	return (tempi);
}

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
	char *temp_temp;
	temp_temp = (char *) malloc (BUFFER_SIZE);

	char *temp_ptr;
	temp_ptr = (char *) malloc(BUFFER_SIZE);

	
	int mem = 1;
	int val = 0;

	char *ptr;
	ptr = (char *) malloc(BUFFER_SIZE);
	if(!ptr)
		return (NULL);


	static char *temp;
	temp = (char *) malloc(BUFFER_SIZE * sizeof(char));
	if (!temp)
		return (NULL);


	// if we are in the second round calling the function, we need
	// extra memory from the previouse calling
	if(ft_strlen(temp) != 0)
	{
		free_and_allocate(temp, BUFFER_SIZE + ft_strlen(temp), 1);
	}

	
	//printf("BUFFer: %d\n", BUFFER_SIZE);
	
	val = read(fd, ptr, BUFFER_SIZE);
	
	
	if(val < 0)
		return(NULL);
	//printf("fail\n");
	if (val == 0)
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
	//printf("ptr: %s\n", ptr);
	//printf("temp_before: %s\n", temp);

	//test = copy_up_to_NULL(ptr);
	//printf("test: %s\n",test);


	// tempus so the value of ptr doesnt get changed
	//tempus = ft_strdup(ptr);

	//printf("\nptr_before: %s\n\n", ptr);

	//temp = ft_strjoin(temp, copy_up_to_NULL(ptr));

	// printf("\ntempus_after: %s\n\n", tempus);

	// printf("ptr_after: %s\n", ptr);
	// printf("temp_after: %s\n", temp);
	//printf("ptr_before: %s\n", ptr);



	// temp_ptr = end cut of ptr -> is WORKING!
	temp_ptr = ft_strdup(ptr);
	//printf("00 temp_ptr: %s\n", temp_ptr);
	temp_ptr = ft_strchr(temp_ptr, '\n');
	//printf("00 temp_ptr: %s\n", temp_ptr);




	temp_temp = ft_strjoin(temp, copy_up_to_NULL(ptr));


	// +1 cause the first character would be '\n' and we dont want that lol
	temp = strdup(temp_ptr+1);

	//printf("TEMP: %s\n", temp);
	//temp = ft_strchr(temp_ptr);
	// printf("ptr_after: %s\n", ptr);
	// printf("!!temp: %s\n", temp);
	//temp = strchr()


	return (temp_temp);
}



// int main()
// {
	 
// 	int fd = open("test.txt", O_RDONLY, 0);
// 	//int fd = open("test.txt", O_RDONLY, 0);
// 	printf("fd: %d\n", fd);
	
// 	char *prr = get_next_line(fd);
// 	printf("main: %s\n", prr);
	
// 	prr = get_next_line(fd);
// 	//prr = get_next_line(fd);
// 	printf("second: %s\n", prr);
	
// 	prr = get_next_line(fd);
// 	printf("third: %s\n", prr);
	
// 	prr = get_next_line(fd);
// 	printf("four: %s\n", prr);
	
// 	// prr = get_next_line(fd);
// 	// printf("last: %s\n", prr);

// 	// prr = get_next_line(fd);
// 	// printf("second main: %s\n\n", prr);

// 	//close(fd1);
// 	//int fd2 = open("test2.txt", O_RDONLY, 0);
// 	//printf("open()-fd = %d\n", fd); 
	
// 	//printf("fd = %d\n", fd2); 
// 	//int fd = 3;
//     return 0; 
// }