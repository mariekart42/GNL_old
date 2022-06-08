/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:58:00 by mmensing          #+#    #+#             */
/*   Updated: 2022/06/03 18:45:23 by mmensing         ###   ########.fr       */
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

// function read: returns 0 if end of file
// ?? what is the buffer here?


char *get_next_line(int fd)
{
	int val;
	
	// c has to be static !!
	//static 
	char c = '\0';
	char *ptr;
	if(!(ptr = (char *) calloc(50, sizeof(char))))
		return(NULL);
	
	// if(!(ptr = (char *) ft_calloc(50, sizeof(char))))
	// 	return(NULL);
	
	
	// i NOT static!
	int i = 0;
	
	
	// skips all \n characters
	while (c == '\n')
		c++;
	

	//val = read(fd, ptr, 2);
	//printf("val: %d\n", val);
	//printf("fd: %d\nread()-val: %d\n", fd, val); 
	
	//ptr[val] = '\n';
	// printf("\ncontent: %s\n\n", ptr);
	// printf("ptr[25]: %c\n", ptr[25]);
	
	
	//int array[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	//static int i = 0;
	
	// char *array;
	// if(!(array = (char *) calloc(50, sizeof(char))))
	// 	return (NULL);
	//while (ptr[i] != '\n' && i < 50 )
	//printf("\nread: %zd\n\n\n",read(fd, ptr, 1));
	//while ((read(fd, ptr, 1) > 0) && (*ptr != '\n'))	
	//while((read(fd, &c, 1) > 0) && (c != '\n'))
	int check = 0;

	
	// we call read inside of loop, so loop will continue 
	// on more time if there is a '\n'
	while (c != '\n')
	{
		
		//printf("\nread: %zd\n\n\n",read(fd, ptr, 1));
		//val = read(fd, ptr, 0);
		val = read(fd, &c, 1);
		if (val < 1 && check == 0)
			return(NULL);
		else if(val < 1)
			return(ptr);
		//printf("VAL: %d\n", val);
		//printf("%d.\tc: %c\n", i, c);
		
		
		// checks if end of file is reached and doesnt end with '\n'
		if(val == 0 && c != '\n')
			return(ptr);
		else
			ptr[i] = c;
		check++;
		

		//array[i] = ptr[0];
		//printf("array[i]: %c\n\n", array[i]);
		i++;
		
	}
	// if (c == '\n')
	// {
	// 	printf("YESUS\n");
	// 	return (ptr);
	// }
	// else
	return (ptr);

	// if (read(fd, ptr, 1) == 0 && (read(fd, ptr, 1) != -1))
	// 	return (ptr);
	// else if (read(fd, ptr, 1) > 0)
	// {
	// 	ptr[i] = '\n';
	// 	return (ptr);
	// }
	// else
	// 	return (NULL);

	//ptr[i] = '\n';
	//printf("end  %c  (should be /n)\n", ptr[i]);
	
	// checks for end of file
	//printf("\nend read: %zd\n\n\n",read(fd, ptr, 1));
	//return(ptr);
}

// int main()
// {
	 
// 	int fd = open("test.txt", O_RDONLY, 0);
// 	//int fd = open("test.txt", O_RDONLY, 0);
// 	printf("fd: %d\n", fd);
	
// 	char *prr = get_next_line(fd);
// 	printf("main: %s\n\n", prr);
	
// 	prr = get_next_line(fd);
// 	//prr = get_next_line(fd);
// 	printf("second: %s\n", prr);
	
// 	prr = get_next_line(fd);
// 	printf("third: %s\n", prr);
	
// 	prr = get_next_line(fd);
// 	printf("four: %s\n", prr);
	
// 	prr = get_next_line(fd);
// 	printf("last: %s\n", prr);

// 	// prr = get_next_line(fd);
// 	// printf("second main: %s\n\n", prr);

// 	//close(fd1);
// 	//int fd2 = open("test2.txt", O_RDONLY, 0);
// 	//printf("open()-fd = %d\n", fd); 
	
// 	//printf("fd = %d\n", fd2); 
// 	//int fd = 3;
//     return 0; 
// }






// BUFFERSIZE=4
// Karla\n     is
// here

