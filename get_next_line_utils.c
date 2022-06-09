/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@wolfsburg.42student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:25:34 by mmensing          #+#    #+#             */
/*   Updated: 2022/06/09 15:27:05 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



/**
 * @brief function connects to given strings and allocates
 * memory for them with malloc
 * 
 * @param s1 fist string
 * @param s2 second string
 * @return char pointer to allocated memory space
 */
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

/**
 * @brief   function copies str2(str2) into dest(str1) array
            does not check the validity of the destination buffer
            copies the data first to an intermediate buffer, then from the 
            buffer to destination
            -> similar to memcpy but better
			one of dst or src can be NULL but not both!
 * @param str1 destination string
 * @param str2 str2 string
 * @param n up to how many characters get copied 
 * @return void* 
 */

void	rev_func(size_t i, size_t n, char *st1, char *st2)
{
	while (i < n)
	{
		st1[i] = st2[i];
		i++;
	}
}

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	size_t	i;
	int		rev_i;
	char	*st1;
	char	*st2;

	if (!str1 && !str2)
		return (NULL);
	i = 0;
	rev_i = n - 1;
	st1 = (char *)str1;
	st2 = (char *)str2;
	if (str1 < str2)
	{
		rev_func(i, n, st1, st2);
		return (str1);
	}
	while (i++ < n)
	{
		st1[rev_i] = st2[rev_i];
		rev_i--;
	}
	return (str1);
}

/**
 * @brief	function searches for the first occurrence of the character 
			c in the first n bytes in str
 * @param str string i that c gets searched
 * @param c the character that should get found
 * @param n up to how many characters we are searching
 * @return void* 
 */
void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *) str;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char) c)
		{
			return ((void *) ptr + i);
		}
		i++;
	}
	return ((void *) '\0');
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


/**
 * @brief function duplicates a string and return a pointer pointing to the 
 * first byte of copied string 
 * memory reserved with malloc
 * 
 * @param src pointer to string that gets copied
 * @return char* 
 */
char	*ft_strdup(char *src)
{
	int		size;
	char	*ptr;
	int		i;

	i = 0;
	size = ft_strlen(src) + 1;
	ptr = (char *) malloc(size * sizeof(char));
	if (!ptr)
		return (NULL);
	while (src[i] != '\0')
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}


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