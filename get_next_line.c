/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@wolfsburg.42student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:33:26 by mmensing          #+#    #+#             */
/*   Updated: 2022/06/11 13:14:15 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief      function reallocates mem for temp if including the     
 *             len of temp_ptr(static)
 *             puts content from temp_ptr to temp
 * @param temp 
 * @param BUFFER 
 * @return char* 
 */
char *realloc_temp_outside_loop(char *temp, int BUFFER, char *temp_ptr)
{
     char *new_ptr;
     int i = 0;

     new_ptr = (char *) malloc (BUFFER + ft_strlen(temp_ptr));
     if(!temp || !new_ptr)
     {
          free(new_ptr);
          free(temp);
          return(NULL);
     }
     while (i < ft_strlen(temp_ptr))	//((BUFFER * mem) + ))
     {
          new_ptr[i] = temp_ptr[i];
          i++;
     }
     free(temp);
     return (new_ptr);
}

/**
 * @brief	funcion allocates mem based on strlen of temp + always one BUFFER
 * 		purs old content in new allocated ptr 
 * @param temp 
 * @param BUFFER 
 * @return char* 
 */
char *realloc_temp_inside_loop(char *temp, int BUFFER)
{
	char *new_ptr;
	int i = 0;

	new_ptr = (char *) malloc (ft_strlen(temp) + BUFFER);
	if (!new_ptr)
	{
		free(new_ptr);
		free(temp);
		return (NULL);
	}
	while (i < ft_strlen(temp))
	{
		new_ptr[i] = temp[i];
		i++;
	}
	free(temp);
	return (new_ptr);
}

/**
 * @brief      function puts content in new allocated pointer with new size
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
     else      // if there was min 1 prev call -> BUFF size + len of temp_ptr PLUS reallocating
     {
          temp_ptr = realloc_temp_ptr(temp_ptr, BUFFER_SIZE);
          if (!temp_ptr)
          {
               //free(temp_ptr); -> not free here! already freed in function
               return(NULL);
          }
          //printf("len: %zu\n", ft_strlen(temp_ptr));
     }


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
	temp = "";
     if (ft_strlen(temp_ptr) != 0) //there is something in temp_ptr
          temp = realloc_temp_outside_loop(temp, BUFFER_SIZE, temp_ptr);


     val = read(fd, ptr, BUFFER_SIZE);


     while (val > 0 && ft_strchr(ptr, '\n') == NULL)
	{

		temp = ft_strjoin(temp, ptr);
		temp = realloc_temp_inside_loop(temp, BUFFER_SIZE);
		if(!temp)
		{
			free(ptr);	//?
			return(NULL);
		}
		val = read(fd, ptr, BUFFER_SIZE);

	}
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


	// cut ptr in half and maybe at the and '\n'




     // while (val != 0)
     // {
     //      if (val < 0)   // in case of error in read
     //      {
     //           free(temp);
     //           free(ptr);
     //           return (NULL);
     //      }
     //      if (ft_strlen(temp) == 0)
     //      {
     //           if (ft_strlen(temp_ptr) != 0)
     //           {
     //                temp = realloc_temp_lonely(temp, BUFFER_SIZE, temp_ptr); 
     //                temp = ft_strjoin(temp_ptr, temp);
     //                if(!temp)
     //                {
     //                     free(temp);
     //                     return (NULL);
     //                }
     //           }
     //           temp = ft_memmove(temp, ptr, BUFFER_SIZE);
     //           temp = realloc_temp_lonely(temp, BUFFER_SIZE * 2, temp_ptr);
     //           if(!temp)
     //           {
     //                free(temp);
     //                return (NULL);
     //           }
     //           val = read(fd, ptr, BUFFER_SIZE);
     //      }

     //      else if (ft_strlen(temp_ptr) != 0)
     //      {
     //           printf("later alligator\n");
     //           val = read (fd, ptr, BUFFER_SIZE);
     //      }
     //      mem++;
     // }






     return(temp);
}

int main()
{
     int fd = open("test2.txt", O_RDONLY, 0);

     char *ptr1;
     ptr1 = get_next_line(fd);
     printf("MAIN_1: %s\n", ptr1);

     // char *ptr2;
     // ptr2 = read(fd);
     // printf("MAIN_2: %s\n", ptr2);

     // char *ptr3;
     // ptr3 = read(fd);
     // printf("MAIN_3: %s\n", ptr3);

     // char *ptr4;
     // ptr4 = read(fd);
     // printf("MAIN_4: %s\n", ptr4);

     // char *ptr5;
     // ptr5 = read(fd);
     // printf("MAIN_5: %s\n", ptr5);

     // char *ptr6;
     // ptr6 = read(fd);
     // printf("MAIN_6: %s\n", ptr6);

}