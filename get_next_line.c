/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@wolfsburg.42student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:03:25 by mmensing          #+#    #+#             */
/*   Updated: 2022/06/20 15:07:02 by mmensing         ###   ########.fr       */

/*   Created: 2022/06/10 14:33:26 by mmensing          #+#    #+#             */
/*   Updated: 2022/06/16 15:00:16 by mmensing         ###   ########.fr       */
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

     while (ptr[i] != '\n')
     {
          if (i == ft_strlen_mod(ptr)) // means there is no '\n'
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
char *temp_ptr_content(char *ptr, char *temp_ptr)
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
	while (ptr[i] != '\0')
	{
		new_ptr[k] = ptr[i];	// new (alright like this?->shorter)
		k++;
		i++;
	}
	//free(temp_ptr);	//?
	//free(ptr);
	if(ptr[i] == '\n')
	{
		new_ptr[k++] = '\n';
		//k++;
	}

	new_ptr[k] = '\0';
	if(k == 0)
		free(temp_ptr);

	return (new_ptr);
}



char *func_for_reading(char *temp, int fd)
{
	int val;
	char *ptr;
     static char *temp_ptr;
	char *move;
	//char *move2;

	if (temp_ptr)
	{
		//free_func(temp, 0, 0);
		temp = ft_strjoin("\0", temp_ptr);
	}
     // if (!temp_ptr)
     // {
     //      temp_ptr = (char *) ft_calloc (BUFFER_SIZE+1, sizeof(char));
     //      if (!temp_ptr)
     //           return (NULL);
     // }

	ptr = (char *) ft_calloc(BUFFER_SIZE+1, sizeof(char));
     if (!ptr)
     {
          free_func(temp_ptr, temp, 0);
          return (NULL);
     }
	
	if (ft_strchr(temp, '\n') != NULL)
	{
		free_func(temp_ptr, 0, 0);
		temp_ptr = temp_ptr_content(temp, 0);
		
		move = ft_strdup(temp);
		free(temp);
		temp = new_line_cutter(move);
		free(move);

		return(temp);
	}

	val = read(fd, ptr, BUFFER_SIZE);

	while (val > 0)
	{
		if (ft_strchr(ptr, '\n') != NULL)
		{
			move = ft_strdup(ptr);
			temp = ft_strjoin(temp, new_line_cutter(move));
			
			temp_ptr = temp_ptr_content(ptr, temp_ptr);
			free_func(ptr, move, 0);	//new
			return (temp);
			// free(temp_ptr);
			// temp_ptr = temp_ptr_content(ptr);
			
			// move = new_line_cutter(ptr);
			// free(ptr);
			
			// move2 = ft_strdup(temp);
			// free(temp);
			// temp = ft_strjoin(move2, move);
			// free(move);
			// free(move2);

			// //free_func(ptr, 0, 0);	//new
			// return (temp);
		}
		move = ft_strjoin(temp, ptr);
		free_func(temp, 0, 0);
		temp = ft_strdup(move);
		free(move);
		//temp = ft_strjoin(temp, ptr);
		
		val = read(fd, ptr, BUFFER_SIZE);
	}
	if (val < 0)
	{
		free_func(temp_ptr, ptr, 0);	//new
		return(NULL);
	}
	if (val == 0)
	{
		if (ft_strlen_mod(temp) != 0)
		{
			temp[ft_strlen_mod(temp)] = '\0';
			ft_bzero(temp_ptr, ft_strlen_mod(temp_ptr));
			free_func(temp_ptr, ptr, 0);

			return (temp);
		}
		else
		{
			// ft_bzero(temp_ptr, ft_strlen(temp_ptr));
			// free(temp_ptr);
			return (NULL);
		}
			
		
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
	
	new_ptr = (char *) malloc(ft_strlen_mod(string) + size);

	if(!new_ptr || !string)
	{
		free(new_ptr);
		free(string);
		return(NULL);
	}
	if (copy_content == 1)
	{
		while (i < ft_strlen_mod(string))
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
	char *not_null;
     char *temp;
	
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
		
	not_null = (char *) ft_calloc(1, sizeof(char));
     if (!not_null)
          return (NULL);
		
	*not_null = '\0';
	
	temp = func_for_reading(not_null, fd);
	
	//free(not_null);
	
	return (temp);
}

int main()
{
     int fd = open("test2.txt", O_RDONLY, 0);
	 printf("fd: %d\n", fd);
	int i = 1;
	char *ptr;
	
	while (i < 8)
	{
		ptr = get_next_line(fd);
		printf("Ptr %d: %s\n", i, ptr);
		show_new_line(ptr, "MAIN");
		free(ptr);
		i++;
	}
}

