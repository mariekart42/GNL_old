/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@wolfsburg.42student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:33:26 by mmensing          #+#    #+#             */
/*   Updated: 2022/06/10 16:18:58 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief      function reallocates mem for temp if including the     
 *             len of temp_ptr(static)
 * 
 * @param temp 
 * @param BUFFER 
 * @return char* 
 */
char *realloc_temp_lonely(char *temp, int BUFFER, char *temp_ptr)
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
     while (i < ((BUFFER * 2) + ft_strlen(temp_ptr)))
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
          if(! temp_ptr)
          {

               free(temp_ptr);
               return (NULL);
          }
     }
     else      // if there was min 1 prev call -> BUFF size + len of temp_ptr PLUS reallocating
     {
          temp_ptr = realloc_temp_ptr(temp_ptr, BUFFER_SIZE);
          if (temp_ptr == NULL)
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


     // temp stores previouse content of ptr in loop
     char *temp;
     temp = (char *) malloc (BUFFER_SIZE);
     if(!temp)
     {
          free(ptr);
          free(temp);
          return (NULL);
     }
     if (ft_strlen(temp_ptr) == 0)
          printf("YEEE\n");

     val = read(fd, ptr, BUFFER_SIZE);


     //join temp_ptr with temp somewhere

     while (val != 0)
     {
          if (val < 0)   // in case of error in read
          {
               free(temp);
               free(ptr);
               return (NULL);
          }
          if (ft_strlen(temp) == 0)
          {
               if (ft_strlen(temp_ptr) != 0)
               {
                    temp = realloc_temp_lonely(temp, BUFFER_SIZE, temp_ptr); 
                    temp = ft_strjoin(temp_ptr, temp);
                    if(!temp)
                    {
                         free(temp);
                         return (NULL);
                    }
               }
               temp = ft_memmove(temp, ptr, BUFFER_SIZE);
               temp = realloc_temp_lonely(temp, BUFFER_SIZE * 2, temp_ptr);
               if(!temp)
               {
                    free(temp);
                    return (NULL);
               }
               val = read(fd, ptr, BUFFER_SIZE);
          }

          else if (ft_strlen(temp_ptr) != 0)
          {
               printf("later alligator\n");
               val = read (fd, ptr, BUFFER_SIZE);
          }
          mem++;
     }
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