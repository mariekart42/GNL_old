/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Laptop_gnl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@wolfsburg.42student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:33:26 by mmensing          #+#    #+#             */
/*   Updated: 2022/06/19 14:21:59 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief function shows all '\n' characters
 * include this to header:
 *
	# define GRN   "\x1B[32m"
	# define YEL   "\x1B[33m"
	# define MAG   "\x1B[35m"
	# define BLU   "\x1B[34m"
	# define RESET "\x1B[0m"
	# endif
 * 
 * @param string 
*/
void	show_new_line(char *string, char *content)
{
	int		len;
	int		i;
	char		*ptr;

	printf(YEL"\n------------------------->\n"RESET);
	printf("-> %s\n", content);
	if(string == NULL)
	{
		printf(MAG"(NULL)"RESET);
		printf(YEL"\n<-------------------------\n\n"RESET);
		return ;
	}
	len = strlen(string);
	i = 0;
	ptr = strdup(string);
	if (!strchr(ptr, '\n'))
		printf(MAG "-> no newline character --\n" RESET);
	printf(YEL"RESULT: "RESET);

	while (i < len)
	{

		if (ptr[i] == '\n')
			printf(GRN"'\\n'"RESET);
		if(ptr[i] == '\0')
			printf(BLU"'\\0'"RESET);
		else
			printf("%c", ptr[i]);
		i++;
	}
	printf(YEL"\n<-------------------------\n\n"RESET);
	free(ptr);
}

void free_func(char *ptr1, char* ptr2, char *ptr3)
{
     if(ptr1)
     {
          free(ptr1);
          ptr1 = NULL;
     }
     if(ptr2)
     {
          free(ptr2);
          ptr2 = NULL;
     }
     if(ptr3)
     {
          free(ptr3);
          ptr3 = NULL;
     }
}

/**
 * @brief function searches for first occurense of '\n' and returns a pointer
 *        with all the previouse content before the '\n'
 *        returned string ends with '\0'
 * 
 * @param ptr 
 * @return char* 
 */
char *new_line_cutter(char *ptr)
{
     char *new_ptr;
     size_t i = 0;
	size_t k = 0;

     if (ptr[0] == '\n')
     {
          new_ptr = (char *) malloc(1);
		if(!new_ptr)
		{
			free(new_ptr);
			return(NULL);
		}
          new_ptr[0] = '\0';
          return (new_ptr);
     }
     while (ptr[i] != '\n')
     {
          
          if (i == ft_strlen(ptr)) // means there is no '\n'
               return(NULL);
          i++;
     }
     new_ptr = (char *) ft_calloc(i+1+1, sizeof(char));
	k = i;
     i = 0;
     while (ptr[i] != '\n' && i < k)
     {
          new_ptr[i] = ptr[i];
          i++;
     }
	if(ptr[i] == '\n')
	{
		new_ptr[i] = '\n';
		i++;
	}
	new_ptr[i] = '\0';

     return(new_ptr);
}




/**
 * @brief function returns ptr content after first '\n' and before the next '\n'
 * 
 * @param ptr 
 * @return char* 
 */
char *temp_ptr_content(char *ptr)
{
     int i = 0;
	int k = 0;
	int count = 0;
	char *new_ptr;
     
     while (ptr[i] != '\n')
          i++;
	i++;

	k = i;
	while (ptr[k++] != '\0')
	{
		count++;
		//k++;
	}
	new_ptr = (char *) ft_calloc(count+1+1, sizeof(char));
	if(!new_ptr)
	{
		//free(new_ptr);
		return(NULL);
	}
	k = 0;
	while (ptr[i++] != '\0')
	{
		new_ptr[k++] = ptr[i-1];	// new (alright like this?->shorter)
		//k++;
		//i++;
	}
	//free(temp_ptr);	//?
	//free(ptr);
	if(ptr[i] == '\n')
	{
		new_ptr[k++] = '\n';
		//k++;
	}

	new_ptr[k] = '\0';
	return (new_ptr);
}



char *func_for_reading(char *temp, int fd)
{
	int val;
	char *ptr;
     static char *temp_ptr;

	if (temp_ptr)
	{
		temp = ft_strjoin("\0", temp_ptr);
	}
     if (!temp_ptr)
     {
          temp_ptr = (char *) ft_calloc (BUFFER_SIZE+1, sizeof(char));
          if (!temp_ptr)
               return (NULL);
     }

	ptr = (char *) ft_calloc(BUFFER_SIZE+1, sizeof(char));
     if (!ptr)
     {
          free_func(temp_ptr, temp, 0);
          return (NULL);
     }
	
	if (ft_strchr(temp, '\n') != NULL)
	{
		temp_ptr = temp_ptr_content(temp);

		
		temp = new_line_cutter(temp);
		return(temp);
	}

	val = read(fd, ptr, BUFFER_SIZE);

	while (val > 0)
	{
		if (ft_strchr(ptr, '\n') != NULL)
		{
			temp = ft_strjoin(temp, new_line_cutter(ptr));
			
			temp_ptr = temp_ptr_content(ptr);
			free_func(ptr, 0, 0);	//new
			return (temp);
		}
		temp = ft_strjoin(temp, ptr);
		
		val = read(fd, ptr, BUFFER_SIZE);

	}
	if (val < 0)
	{
		free_func(temp_ptr, ptr, 0);	//new
		return(NULL);
	}
	if (val == 0)
	{
		if (ft_strlen(temp) != 0)
		{
			temp[ft_strlen(temp)] = '\0';
			ft_bzero(temp_ptr, ft_strlen(temp_ptr));
			free_func(temp_ptr, ptr, 0);	// new
			return (temp);
		}
		else
			return (NULL);
		
	}
	
	return (temp);
}



/**
 * @brief function reallocates mem based on the lengh of passed string
 *		adds always one BUFFER_SIZE to the lengh of the actual string
 *		frees previouse ptr
 *		content gets copied too
 * @param string 
 * @param size normal write BUFFER_SIZE
 * @copy_content 	if 1 -> content gets copied
 *				if 0 -> no copy content 
 * @return char* 
 */
char *reallocate(char *string, int size, int copy_content)
{
	char *new_ptr;
	size_t i = 0;
	
	new_ptr = (char *) malloc(ft_strlen(string) + size);

	if(!new_ptr || !string)
	{
		free(new_ptr);
		free(string);
		return(NULL);
	}
	if (copy_content == 1)
	{
		while (i < ft_strlen(string))
		{
			new_ptr[i] = string[i];
			i++;
		}
	}
	free(string);
	return (new_ptr);
}



char *get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

     char *temp;
     temp = (char *) ft_calloc (BUFFER_SIZE+1, sizeof(char));
     if(!temp)
     {
          return (NULL);
     }
	*temp = '\0';

	temp = func_for_reading(temp, fd);
	return(temp);
}

int main()
{
     int fd = open("test2.txt", O_RDONLY);
	int i = 1;
	char *ptr;
	
	while(i < 8)
	{
		ptr = get_next_line(fd);
		printf("Ptr %d: %s\n", i, ptr);
		show_new_line(ptr, "MAIN");
		free(ptr);
		i++;
	}
}