/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@wolfsburg.42student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:33:26 by mmensing          #+#    #+#             */
/*   Updated: 2022/06/16 14:53:38 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"

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


//----------------------------------------------

// open & close
# include <fcntl.h> 
# include <errno.h> 

//read
# include <sys/types.h>
# include <sys/uio.h>

//colour shit
# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"

# define RESET "\x1B[0m"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif
#include <unistd.h>
# include <stddef.h>

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <strings.h>
/**
 * @brief	function erases the data in the n bytes of the memory
       		starting at the location pointed to by s, by writing zeros 
			(bytes containing '\0') to that area.
 * @param str space in memory that gets sized to null
 * @param n lengh we want to str gets nulled
 */
void	ft_bzero(void *str, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = (char *) str;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}
/**
 * @brief returns lengh of str
 * 
 * @param str 
 * @return size_t lengh of str
 */
size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		k;

	if (!s1 || !s2)
		return (NULL);
	ptr = (char *) malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!ptr)
		return (NULL);
	k = 0;
	i = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[k] != '\0')
	{
		ptr[i] = s2[k];
		i++;
		k++;
	}
	ptr[i] = '\0';
	return (ptr);
}


/**
 * @brief   function searches for the FIRST occurrence in str for character c
            if str doesnt end with NUL program might crash 
 * @param str string where c should get found
 * @param c the character we are searching for 
 * @return char*    returns pointer to string at the position where 'c' was found
                    returns NULL if not found
 */
char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (str[0] == (char) c)
		return ((char *) str);
	while (str[i] != '\0')
	{
		if ((c == '\0') && (str[i + 1] == '\0'))
			return ((char *) str + i + 1);
		if (str[i] == (char)c)
		{
			return ((char *) str + i);
		}
		i++;
	}
	return ((char *) '\0');
}


// /**
//  * @brief function duplicates a string and return a pointer pointing to the 
//  * first byte of copied string 
//  * memory reserved with malloc
//  * 
//  * @param src pointer to string that gets copied
//  * @return char* 
//  */
// char	*ft_strdup(char *src)
// {
// 	int		size;
// 	char	*ptr;
// 	int		i;

// 	i = 0;
// 	size = ft_strlen(src) + 1;
// 	ptr = (char *) malloc(size * sizeof(char));
// 	if (!ptr)
// 		return (NULL);
// 	while (src[i] != '\0')
// 	{
// 		ptr[i] = src[i];
// 		i++;
// 	}
// 	ptr[i] = '\0';
// 	return (ptr);
// }

/**
 * @brief	function allocates 'nitems' bytes of memory, each in size of 'size' 
 			(int, char etc)
			different to malloc, sets all places to '\0'
 * 
 * @param count 
 * @param size 
 * @return void* returns pointer to allocated memory
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*output;

	if (count >= 4294967295 || size >= 4294967295)
		return (NULL);
	output = malloc(count * size);
	if (!output)
		return (NULL);
	ft_bzero(output, count * size);
	return (output);
}


//----------------------------------------------

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