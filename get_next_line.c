/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:33:26 by mmensing          #+#    #+#             */
/*   Updated: 2022/06/11 23:38:16 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


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
     
     while (ptr[i] != '\n')		// no leng check needed cause there has to be an '\n'
          i++;
	i++;		// was '\n'

	k = i;
	while (ptr[k] != '\n')
	{
		count++;
		k++;
	}
	new_ptr = (char *) malloc(count);
	if(!new_ptr)
	{
		free(new_ptr);
		return(NULL);
	}
	k = 0;
	while (ptr[i] != '\n')
	{
		new_ptr[k] = ptr[i];
		k++;
		i++;
	}
	free(ptr);
	return (new_ptr);
}





// char *try(char *temp, char *ptr)
// {
//      char *new_ptr;
//      char *new_temp;
//      char *test_new_ptr;
//      int i = 0;
     
//      if (ptr[0] == '\n')
//      {
//           new_temp = (char *) malloc(1);
//           new_temp[0] = '\n'; // so while loop gets skipped
//      }
//      new_temp = (char *) malloc(ft_strlen(ptr) - ft_strlen(ft_strchr(ptr, '\n')) + 1);
//      if (!new_temp)
//           return(NULL);
//      while (ptr[i] != '\n')
//      {
//           new_temp[i] = ptr[i];
//           i++;
//      }
//      new_temp[i] = '\n';     
//      new_ptr = ft_strchr(ptr, '\n');
//      new_ptr += 1;
//      new_new_ptr = ft_strchr(new_ptr, '\n');
//      if(test_new_ptr != NULL)
//      {
//           new_ptr[ft_strlen(ptr) - ft_strlen(test_new_ptr)] = '\0';    // right place?
//           new_ptr = ft_substr(new_ptr);
//      }
//      free(new_new_ptr);
//      if(p == 1)
//      {
//           free()
//           return(new_temp);

//      }
//      if(p == 2)
//      {

//           return(new_ptr);
//      }
// }



/**
 * @brief function searches for first occurense of '\n' and returns a pointer
 *        with all the previouse content before the '\n'
 *        ends with '\n'
 * 
 * @param ptr 
 * @return char* 
 */
char *new_line_cutter(char *ptr)
{
     char *new_ptr;
     int i = 0;

     if (ptr[0] == '\n')
     {
          new_ptr = (char *) malloc(1);
		if(!new_ptr)
		{
			free(new_ptr);
			return(NULL);
		}
          new_ptr[0] = '\n';
          return (new_ptr);
     }
     while (ptr[i] != '\n')
     {
          i++;
     }
     new_ptr = (char *) malloc(i+1);
     i = 0;
     while (ptr[i] != '\n')
     {
          new_ptr[i] = ptr[i];
          i++;
     }
     new_ptr[i] = '\n';
     return(new_ptr);
}

// /**
//  * @brief function reallocates mem for temp if including the     
//  *        len of temp_ptr(static)
//  *        puts content from temp_ptr to temp
//  * @param temp 
//  * @param BUFFER 
//  * @return char* 
//  */
// char *realloc_temp_outside_loop(char *temp, int BUFFER, char *temp_ptr)
// {
//      char *new_ptr;
//      int i = 0;

//      new_ptr = (char *) malloc (BUFFER + ft_strlen(temp_ptr));
//      if(!temp || !new_ptr)
//      {
//           free(new_ptr);
//           free(temp);
//           return(NULL);
//      }
//      while (i < ft_strlen(temp_ptr))	//((BUFFER * mem) + ))
//      {
//           new_ptr[i] = temp_ptr[i];
//           i++;
//      }
//      free(temp_ptr);
//      return (new_ptr);
// }

// /**
//  * @brief	funcion allocates mem based on strlen of temp + always one BUFFER
//  * 		purs old content in new allocated ptr 
//  * @param temp 
//  * @param BUFFER 
//  * @return char* 
//  */
// char *realloc_temp_inside_loop(char *temp, int BUFFER)
// {
// 	char *new_ptr;
// 	int i = 0;

// 	new_ptr = (char *) malloc (ft_strlen(temp) + BUFFER);
// 	if (!new_ptr)
// 	{
// 		free(new_ptr);
// 		free(temp);
// 		return (NULL);
// 	}
// 	while (i < ft_strlen(temp))
// 	{
// 		new_ptr[i] = temp[i];
// 		i++;
// 	}
// 	free(temp);
// 	return (new_ptr);
// }

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
	int i = 0;
	
	new_ptr = (char *) malloc(ft_strlen(string) + size);
	if(copy_content == 0)
		printf("LEN_PTR: %zu\n\n", ft_strlen(string));
	if(copy_content == 1)
		printf("LEN_TEMP: %zu\n\n", ft_strlen(string));
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
		printf("FUNC: %s\n\n", new_ptr);
	}
	free(string);
	return(new_ptr);
}


/**
 * @brief function puts content in new allocated pointer with new size
 * 
 * @param temp_ptr 
 * @param BUFFER 
 * @return char* 
 */
char *realloc_temp_ptr(char *temp_ptr, int BUFFER)
{
     char *new_ptr;
     int i = 0;

     if(!temp_ptr)
     {
          free(temp_ptr);
          return(NULL);
     }
     new_ptr = (char *) malloc (BUFFER + ft_strlen(temp_ptr));
     if(!new_ptr)
     {

          free(new_ptr);
          free(temp_ptr);
          return(NULL);
     }
     while (i < (BUFFER + ft_strlen(temp_ptr)))
     {
          new_ptr[i] = temp_ptr[i];
          i++;
     }
     free(temp_ptr);
     return (new_ptr);
}


char *get_next_line(int fd)
{
     int mem = 1;

     // val takes return value from read function
     int val;


     // temp_ptr stores the content of previouse function callings
     static char *temp_ptr;
     // allocating mem depending on if temp_ptr is already used before of not
     if (temp_ptr == 0)       // if its the first calling -> normal BUFF size
     {
          temp_ptr = (char *) malloc (BUFFER_SIZE);
          if (!temp_ptr)
          {
               free(temp_ptr);
               return (NULL);
          }
          // CHANGED -> temp_ptr = "";      // so it can be used it join (see 'test_join.c') -> works!
     }
	
     // // dump shit i guess:
     // else      // if there was min 1 prev call -> BUFF size + len of temp_ptr PLUS reallocating
     // {
     //      temp_ptr = realloc_temp_ptr(temp_ptr, BUFFER_SIZE);
     //      if (!temp_ptr)
     //      {
     //           //free(temp_ptr); -> not free here! already freed in function
     //           return(NULL);
     //      }
     //      
     // }


     // ptr has content of .txt file in amount of BUFFERSIZE
     char *ptr;
     ptr = (char *) malloc(BUFFER_SIZE);
     if (!ptr)
     {
          free(ptr);
          return (NULL);
     }

	
     // temp stores previouse content of ptr in loop -> temp_ptr
     char *temp;
     temp = (char *) malloc (BUFFER_SIZE);
     if(!temp)
     {
          free(ptr);
          free(temp);
          return (NULL);
     }
	*temp = '\0';		// def do it like this!!
	if(ft_strlen(temp_ptr) != 0)
		temp = ft_strjoin(temp, temp_ptr);
     val = read(fd, ptr, BUFFER_SIZE);

	printf("---------- in loop ----------------\n\n");
     while (val > 0 && ft_strchr(ptr, '\n') == NULL)
	{
		temp = ft_strjoin(temp, ptr);
		temp = reallocate(temp, BUFFER_SIZE, 1);
		if(!temp)
		{
			//free(ptr);	//?
			return(NULL);
		}
		val = read(fd, ptr, BUFFER_SIZE);
	}
	printf("---------- out loop ----------------\n\n");
	if (val == 0)
	{
		// return vals checke what if there is no '\n' at the end etc
	}
     if (val < 0)   // in case of error in read
     {
          free(temp);
          free(ptr);
          return (NULL);
     }

	printf("TEMP: %s\n", temp);
	printf("PTR: %s\n", ptr);

	printf("1 temp: %s\n", temp);

     temp = ft_strjoin(temp, new_line_cutter(ptr));
	printf("2 temp: %s\n", temp);
     temp_ptr = temp_ptr_content(ptr, temp_ptr);

	
     //printf("try: %s\n", try(temp, ptr));

	// cut ptr in half and maybe at the and '\n'


     return(temp);
}

int main()
{
     int fd = open("test2.txt", O_RDONLY, 0);
printf("-------- 1 -------------\n\n");
     char *ptr1;
     ptr1 = get_next_line(fd);
     printf("MAIN_1: %s\n", ptr1);
printf("-------- 2 -------------\n\n");
     char *ptr2;
     ptr2 = get_next_line(fd);
     printf("MAIN_2: %s\n", ptr2);
printf("-------- 3 -------------\n\n");
     // char *ptr3;
     // ptr3 = get_next_linefd);
     // printf("MAIN_3: %s\n", ptr3);
printf("-------- 4 -------------\n\n");
     // char *ptr4;
     // ptr4 = get_next_line(fd);
     // printf("MAIN_4: %s\n", ptr4);
printf("-------- 5 -------------\n\n");
     // char *ptr5;
     // ptr5 = get_next_line(fd);
     // printf("MAIN_5: %s\n", ptr5);
printf("-------- 6 -------------\n\n");
     // char *ptr6;
     // ptr6 = get_next_line(fd);
     // printf("MAIN_6: %s\n", ptr6);

}