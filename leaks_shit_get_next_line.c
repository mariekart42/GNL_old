/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 19:09:22 by mmensing          #+#    #+#             */
/*   Updated: 2022/06/09 22:35:10 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>

// int ft_strchr_mod(const char *str, int c)
// {
// 	int	i;

// 	i = 0;
// 	if (str[0] == (char) c)
// 		return ((char *) str);
// 	while (str[i] != '\0')
// 	{
// 		if ((c == '\0') && (str[i + 1] == '\0'))
// 			return ((char *) str + i + 1);
// 		if (str[i] == (char)c)
// 		{
// 			return ((char *) str + i);
// 		}
// 		i++;
// 	}
// 	return ((char *) '\0');
// }

/**
 * @brief	function that searches for first '\n' cuts after it and cut again
 *			at next occurence of '\n' or if end of string is reached
 *			Bsp.:  before: halt'\n'deine fresse'\n'danke
 *					after:         deine fresse
 * @param temp_ptr 
 * @return char* 	returns string without any '\n'
 */
char *ultimate_NULL_cutter(char *temp_ptr)
{
	char *new_ptr;
	int i = 0;
	//int len = ft_strlen(temp_ptr);
	//int malloc_size;
	int k = 0;
	//malloc_size = 0;

	// if there is no '\n' at all in string
	if(ft_strchr(temp_ptr, '\n') == NULL)
	{
		return (temp_ptr);
	}
	while (temp_ptr[i] != '\n')
		i++;
	i++;
	while (temp_ptr[i] != '\n' && i < ft_strlen(temp_ptr))	// < or <= ?
	{
		new_ptr[k] = temp_ptr[i];
		i++;
		k++;
		//malloc_size++;
	}
	free(temp_ptr);
	new_ptr = (char *) malloc(k+1);
	if(!new_ptr)
	{
		return(NULL);
	}
	//new_ptr[i] = '\n';
	//printf("i: %d\n", i);
	return (new_ptr);
}


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


// /**
//  * @brief function allocates and frees memory if needed
//  * @param temp_ptr 	content is empty or the contetnt of ptr
//  * 				of the prev gnl call
//  * @param BUFF size of BUFFER
//  * @return checks if something is alrady in temp_ptr
//  *		if not -> returns empty allocated string size of BUFF
//  * 		if yes -> returns allocated string with content of prev 
//  *				temp_ptr, size of BUFF + len of temp_ptr
//  *				-> frees the temp_ptr
//  */
// char *realloc_temp_ptr(char *temp_ptr, int BUFF)
// {
// 	int len = 0;
// 	char *new_ptr;

// 	if(temp_ptr == 0)
// 	{
// 		temp_ptr = (char *) malloc(BUFFER_SIZE);
// 		if(!temp_ptr)
// 			return(NULL);
// 		return (temp_ptr);
// 	}
// 	else 
// 	{
// 		// len = BUFF + ft_strlen(temp_ptr);
// 		// new_ptr = (char *) malloc (len);
// 		// new_ptr = ft_memmove(new_ptr, temp_ptr, len);
// 		// free(temp_ptr);
// 		// return (new_ptr);
// 	}
// }

// char *realloc_temp_and_join_temp(char *temp, int BUFF, char *temp_ptr)
// {
// 	char *new_ptr;
// 	int len;

// 	len = ft_strlen(temp_ptr) + BUFF;
// 	new_ptr = (char *) malloc(len);
// 	new_ptr = ft_strjoin(temp_ptr, );
// 	free(temp_ptr);
// }

// char *free_and_allocate(char *temp, int BUFF, int mem)
// {
// 	char *new_ptr;
// 	int val = 0;
// 	int val2 = 0;
// 	//size_t	size;






// 	// if (temp == 0)	// is working!		same as (!temp) or (temp == NULL)
// 	// {		
// 	// 	temp = (char *) malloc(BUFF*mem);
// 	// 	if(!temp)
// 	// 		return (NULL);
// 	// 	return(temp);
// 	// }
// 	// else if(temp != 0 && mem != 1)	// mem != 1 means we are already inside the while loop
// 	// {
// 	// 	if(ft_strchr(temp, '\n') != 0)
// 	// 	{
// 	// 		printf("KASASAAAA\n\n");
// 	// 		val2++;
// 	// 	}
// 	// 	new_ptr = (char *) malloc (BUFF*mem);
// 	// 	if(!new_ptr)
// 	// 		return (NULL);
// 	// }
// 	// else
// 	// {
// 	// 	new_ptr = (char *) malloc (BUFF*mem + ft_strlen(temp));
// 	// 	if(!new_ptr)
// 	// 		return (NULL);
// 	// 	// int del = 5;
// 	// 	// del += strlen(temp);
// 	// 	// printf("del: %d\n", del);
// 	// 	// printf("AHHHHHHHH temp: %s\n\n", temp);
// 	// 	// printf("len temp: %zu\n", strlen(temp));
// 	// 	// printf("ft_len temp: %zu\n", ft_strlen(temp));
// 	// }

// 	// new_ptr = memmove(new_ptr, temp, (BUFF * (mem-1)));
// 	// //new_ptr = strdup(new_ptr, temp);
// 	// free(temp);
// 	return (new_ptr);
// }



char *realloc_and_join_temp(char *temp, int BUFF, char *ptr)
{
	char *new_ptr;

	if(ft_strlen(temp) == 0)
	{
		temp = ft_memmove (temp, ptr, BUFF);
		//free(ptr);
		return(temp);
	}
	else
	{
		new_ptr = (char *) malloc (ft_strlen(temp) + BUFF);
		new_ptr = ft_strjoin(temp, ptr);
		free(temp);
		//free(ptr);
	}
	return(new_ptr);
}




char *get_next_line(int fd)
{
	static int delete_later = 1;
	printf("\n--------------- %d ---------------------\n\n", delete_later);
	delete_later++;

	//int mem = 1;
	int val = 0;
	// temp_temp: in the end joins whole temp with the beginning of
	// ptr including '\n'
	char *temp_temp;
	temp_temp = (char *) malloc (BUFFER_SIZE + 1);
	if(!temp_temp)
	{
		free(temp_temp);
		return (NULL);

	}

	// temp_ptr: saves in the very end the end of ptr without '\n' at the beginning
	// calloc cause we will cut temp_ptr later and it will be not the full BUFFERSIZE

	//temp_ptr = realloc_temp_ptr(temp_ptr, BUFFER_SIZE);
	//temp_ptr = free_and_allocate(temp, BUFFER_SIZE, mem, temp_ptr);
	//temp_ptr = (char *) malloc(BUFFER_SIZE);
	// if(!temp_ptr)
	// 	return (NULL);
	
	char *ptr;
	ptr = (char *) malloc(BUFFER_SIZE + 1);
	if(!ptr)
	{
		free(ptr);
		return (NULL);
	}
	printf("after ptr alloc\n");
	// printf("1. strlen: %zu\n", ft_strlen(temp+1));
	char *temp;
	//temp = (char *) malloc(BUFFER_SIZE * sizeof(char));
	// if (!temp)
	// 	return (NULL);




	static char *temp_ptr;
	//printf("--temp_ptr: %s\n", temp_ptr);
	//temp_ptr = "hdhdhd";
	if (temp_ptr == 0)
	{
		temp_ptr = (char *) malloc(BUFFER_SIZE + 1);
		if(!temp_ptr)
		{
			printf("no\n");
			free(temp_ptr);
			return(NULL);
		}
		//printf("here\n");
	}
	printf("after temp_ptr alloc\n");
	temp = (char *) malloc (BUFFER_SIZE + ft_strlen(temp_ptr));
	if(!temp)
	{
		free(temp);
		return (NULL);
	}
	//printf("AAAtemp_ptr: %s\n", temp_ptr);
	temp = ft_memmove(temp, temp_ptr, BUFFER_SIZE+ft_strlen(temp_ptr));
	//printf("BBBtemp_ptr: %s\n", temp_ptr);
	//free(temp_ptr);
	
	printf("IMPORTANT temp: %s\n\n", temp);


	val = read(fd, ptr, BUFFER_SIZE);
	


	if (val == 0 && ft_strlen(temp) != 0)
	{
		free(ptr);
		free(temp_temp);
		//free(temp_ptr);
		return (temp);
	}
	else if (val <= 0)
	{
		free(ptr);
		free(temp_temp);
		//free(temp_ptr);
		free(temp);
		return (NULL);

	}
	printf("2. strlen: %zu\n", ft_strlen(temp));


	// if we are in the second round calling the function, we need
	// extra memory from the previouse calling
	// if(ft_strlen(temp) != 0)
	// {
	// 	free_and_allocate(temp, BUFFER_SIZE + ft_strlen(temp), 1);
	// }

	
	


	// //printf("fail\n");
	// if (val == 0)
	

	// while '\n' not found in ptr
	while (ft_strchr(ptr, '\n') == 0)
	{
		temp = realloc_and_join_temp(temp, BUFFER_SIZE, ptr);
		free(ptr);
		ptr = (char *) malloc (BUFFER_SIZE);
		val = read(fd, ptr, BUFFER_SIZE);
		if (val == 0)
		{
			free(ptr);
			//free(temp_ptr);
			free(temp_temp);
			return(temp);
		}
	}
		





	// while '\n' not found in ptr
	// while (ft_strchr(ptr, '\n') == 0)
	// {
	// 	if (mem != 1)
	// 	{
	// 		temp = free_and_allocate(temp, BUFFER_SIZE, mem);
	// 		if(!temp)
	// 			return (NULL);
	// 		temp = ft_strjoin(temp, ptr);
	// 	}
	// 	else if (mem == 1)
	// 	{
	// 		temp = ft_memmove(temp, ptr, BUFFER_SIZE);
				
	// 	}
	// 	//free(ptr);	// should be fine
	// 	val = read (fd, ptr, BUFFER_SIZE);
	// 	mem++;
	// }
	//printf("PTR: %s\n\n", ptr);
	//printf("TEMP: %s\n\n", temp);
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


	//printf("00 before ptr: %s\n\n", ptr);

	// temp_ptr: is the end cut of ptr without the beginning '\n'(temp_ptr++ is doing that)   
	// -> is WORKING!
	temp_ptr = ft_strdup(ptr);
	
	// printf("->00 before temp_ptr: %s\n\n", temp_ptr);
	
	//printf("BUFFer: %d\n", BUFFER_SIZE);
	
	
	
	// printf("scurr\n");
	//write(1, "fiude", 10);
	
	

	//	function that searches for first '\n' cuts after it and cut again 
	//	at next occurence of '\n' or if end of string is reached
	temp_ptr = ultimate_NULL_cutter(temp_ptr);
	if(!temp_ptr)
	{
		free(temp_ptr);
		return(NULL);
	}
	// temp_ptr = ft_strchr(temp_ptr, '\n');
	// temp_ptr++;
	//printf("temp_ptr: %s\n", temp_ptr);
	//printf("00 after temp_ptr: %s\n", temp_ptr);



	//printf("ptr before: %s\n\n", ptr);

	// temp_temp is now the whole line with '\n' at the end
	temp_temp = ft_strjoin(temp, copy_up_to_NULL(ptr));
	// printf("temp_temp: %s\n\n", temp_temp);
	// printf("ptr after: %s\n\n", ptr);


	//printf("temp_before: %s\n", temp);


	// temp is now the content of the end of ptr (without '\n' at beginning)
			//temp = ft_strdup(temp_ptr);
	//printf("temp_after: %s\n", temp);

	
	// printf("TEMP: %s\n", temp);
	//temp = ft_strchr(temp_ptr);
	// printf("ptr_after: %s\n", ptr);
	// printf("!!temp: %s\n", temp);
	//temp = strchr()

	//printf("ptr END: %s\n\n", ptr);

	//free(temp_ptr);
	free(ptr);
	//printf("temp_temp: %s\n", temp_temp);
	//printf("temp_ptr: %s\n", temp_ptr);
	return (temp_temp);
}

int main()
{
	int fd = open("test.txt", O_RDONLY, 0);
	//int fd = open("test.txt", O_RDONLY, 0);
	printf("fd: %d\n\n", fd);
	
	char *prr = get_next_line(fd);
	printf("main: %s\n\n", prr);
	
	prr = get_next_line(fd);
	//prr = get_next_line(fd);
	printf("second: %s\n\n", prr);
	
	prr = get_next_line(fd);
	printf("third: %s\n\n", prr);
	
	prr = get_next_line(fd);
	printf("four: %s\n\n", prr);
	
	prr = get_next_line(fd);
	printf("last: %s\n", prr);

	prr = get_next_line(fd);
	printf("second main: %s\n\n", prr);

	//close(fd1);
	//int fd2 = open("test2.txt", O_RDONLY, 0);
	//printf("open()-fd = %d\n", fd); 
	
	//printf("fd = %d\n", fd2); 
	//int fd = 3;
    return 0; 
}