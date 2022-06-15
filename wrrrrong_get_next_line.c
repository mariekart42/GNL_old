/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:33:26 by mmensing          #+#    #+#             */
/*   Updated: 2022/06/13 23:37:29 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
	if (!string)
		return ;
	len = strlen(string)+10;
	i = 0;
	ptr = strdup(string);
	if (!strchr(ptr, '\n'))
		printf(MAG "-> no newline character --\n" RESET);
	printf(YEL"RESULT: "RESET);
	while (i < len)
	{
		if (ptr[i] == '\n')
			printf(GRN"'\\n'"RESET);
		if (ptr[i] == '\0')
			printf(BLU"'\\0'"RESET);
		else
			printf("%c", ptr[i]);
		i++;
	}
	printf(YEL"\n<-------------------------\n\n"RESET);
	//printf("\n\n");
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
 *        ends with '\n'
 * 
 * @param ptr 
 * @return char* 
 */
char *new_line_cutter(char *ptr)
{
     char *new_ptr;
     int i = 0;
	int k = 0;

     if (ptr[0] == '\n')
     {
          new_ptr = (char *) malloc(1);
		if(!new_ptr)
		{
			free(new_ptr);
			return(NULL);
		}
          new_ptr[0] = '\0';		//changed but should be right 
          return (new_ptr);
     }
     while (ptr[i] != '\n')
     {
          
          if (i == ft_strlen(ptr)) // means there is no '\n'
          {
               return(NULL);
          }
          i++;
     }
	//printf("!!i; %d\n",i);
     new_ptr = (char *) malloc(i+1);
	k = i;
     i = 0;
     while (ptr[i] != '\n' && i < k)
     {
          new_ptr[i] = ptr[i];
          i++;
		//printf("iteration: %d\n", i);
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
     
     while (ptr[i] != '\n' && ptr[i] != '\0')		// no leng check needed cause there has to be an '\n'
          i++;
	i++;		// was '\n'

	k = i;
	//printf("ptr; %s\n", ptr +i);
	while (ptr[k] != '\n' && ptr[k] != '\0')
	{
		count++;
		k++;
	}
	new_ptr = (char *) malloc(count);
	if (!new_ptr)
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
	free(temp_ptr);	//?
	free(ptr);
	return (new_ptr);
}



char *func_for_reading(char *temp_ptr, char *temp, int fd)
{
	int val;
	char *ptr;
	
	ptr = (char *) malloc(BUFFER_SIZE);
     if (!ptr)
     {
          free_func(temp_ptr, temp, 0);
          return (NULL);
     }
	val = read(fd, ptr, BUFFER_SIZE);
	while (val > 0)
	{
		if (ft_strchr(ptr, '\n') != NULL)	// there is a '\n'
		{
			temp = ft_strjoin(temp, new_line_cutter(ptr));
			temp[ft_strlen(temp)] = '\n';
			temp_ptr = temp_ptr_content(ptr, temp_ptr);
			return (temp);
		}
	}
	
	
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
	// if(copy_content == 0)
	// 	printf("LEN_PTR: %zu\n\n", ft_strlen(string));
	// if(copy_content == 1)
	// 	printf("LEN_TEMP: %zu\n\n", ft_strlen(string));
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
		//printf("FUNC: %s\n\n", new_ptr);
	}
	free(string);	//?
	return (new_ptr);
}


// /**
//  * @brief function puts content in new allocated pointer with new size
//  * 
//  * @param temp_ptr 
//  * @param BUFFER 
//  * @return char* 
//  */
// char *realloc_temp_ptr(char *temp_ptr, int BUFFER)
// {
//      char *new_ptr;
//      int i = 0;

//      if (!temp_ptr)
//      {
//           free(temp_ptr);
//           return(NULL);
//      }
//      new_ptr = (char *) malloc (BUFFER + ft_strlen(temp_ptr));
//      if (!new_ptr)
//      {
//           free(new_ptr);
//           free(temp_ptr);
//           return(NULL);
//      }
//      while (i < (BUFFER + ft_strlen(temp_ptr)))
//      {
//           new_ptr[i] = temp_ptr[i];
//           i++;
//      }
//      free(temp_ptr);
//      return (new_ptr);
// }


char *get_next_line(int fd)
{
     int mem = 1;

     // val takes return value from read function
     int val;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
     // temp_ptr stores the content of previouse function callings
	     static char *temp_ptr;
	     // allocating mem depending on if temp_ptr is already used before of not
	     if (temp_ptr == 0)       // if its the first calling -> normal BUFF size
	     {
	          temp_ptr = (char *) malloc (BUFFER_SIZE);
	          if (!temp_ptr)
	          {
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


	     // // ptr has content of .txt file in amount of BUFFERSIZE
	     // char *ptr;
	     // ptr = (char *) malloc(BUFFER_SIZE);
	     // if (!ptr)
	     // {
	     //      free_func(temp_ptr, 0, 0);
	     //      return (NULL);
	     // }

     // temp stores previouse content of ptr in loop -> temp_ptr
     char *temp;
     temp = (char *) ft_calloc (BUFFER_SIZE+1, sizeof(char));
     if(!temp)
     {
		free_func(temp_ptr, 0, 0);
          // free(ptr);
          // free(temp_ptr);
          return (NULL);
     }
	*temp = '\0';		// def do it like this!!
	//printf("TEMP_PTR: %s\n", temp_ptr);
	if (ft_strlen(temp_ptr) != 0)
		temp = ft_strjoin(temp, temp_ptr);
		
		

		

// //_______________________________________________________________________
//      val = read(fd, ptr, BUFFER_SIZE);
// 	printf("TTTEMP_PTR: %s\n", temp_ptr);
// 	//show_new_line(temp_ptr, "TTTTTEMP_PTR");
// 	printf("PPPPPPTR: %s\n", ptr);

// 	//printf("----------- in loop ----------------\n\n");
//      while (val > 0)// && ft_strchr(ptr, '\n') == NULL)
// 	{
// 		printf("loop PTR: %s\n", ptr);
// 		if (ft_strchr(ptr, '\n') != NULL)
// 		{
// 			printf("before temp: %s\n", temp);
// 			printf("ptr: %s\n", ptr);
			
			
// 			temp = ft_strjoin(temp, new_line_cutter(ptr));
// 			temp[ft_strlen(temp)] = '\n';
			
			
// 			printf("temp: %s\n", temp);
			
			
// 		     temp_ptr = temp_ptr_content(ptr, temp_ptr);
			
			
// 			show_new_line(temp_ptr, "TEMP_PTR");
// 			printf("temp_ptr: %s\n", temp_ptr);
// 		     return(temp);
// 		}
// 		//printf("before_TEMP: %s\n", temp);
// 		temp = ft_strjoin(temp, ptr);
// 		//printf("after_TEMP: %s\n", temp);
// 		//temp = reallocate(temp, BUFFER_SIZE, 1);
// 		// if(!temp)
// 		// {
// 		// 	free(ptr);
// 		// 	free(temp_ptr);
// 		// 	return(NULL);
// 		// }
// 		val = read(fd, ptr, BUFFER_SIZE);
	
// 	}
	
// 	//printf("----------- out loop ----------------\n\n");
// 	//printf("val: %d\n", val);
// 	//show_new_line(ptr, "PPPPPPTRRR");
// 	// 	if (val == 0)
// 	// 	{
// 	// 		//show_new_line(temp, "RRRR");
// 	// 		if (ft_strchr(temp, '\n') != NULL)// || ft_strchr(ptr, '\0') != NULL)
// 	// 		{
// 	// 			//printf("TEMP: %s\n", temp);
// 	// //printf(GRN"YEEEEEEE\n"RESET);
// 	// 			printf("befor temp: %s\n", temp);
// 	// 			temp = ft_strjoin(temp, "\n");
// 	// 			printf("ptr: %s\n", ptr);
// 	// 			printf("temp: %s\n", temp);
// 	// 			//printf("temp: %s\n", temp);
// 	// 			//show_new_line(temp, "TEMP");
// 	// 			//free_func(temp_ptr, ptr, 0);
// 	// 			//temp_ptr = temp_ptr_content(ptr, temp_ptr);
// 	// 			printf("temp_ptr: %s\n", temp_ptr);
// 	// 			return (temp);
// 	// 		}
// 	// 		else
// 	// 			printf(RED"NOOOOOO\n"RESET);

// 	// 		if(ft_strlen(temp) != 0)
// 	//           {
// 	//                //free(temp_ptr);
// 	//                return(temp);
// 	//           }
				
// 	// 		return(NULL);
// 	// 		// return vals checke what if there is no '\n' at the end etc
// 	// 	}
//      if (val < 0)   // in case of error in read
//      {
//           free(temp_ptr);
//           free(ptr);
//           return (NULL);
//      }

// 	printf("TEMP: %s\n", temp);
// 	printf("PTR: %s\n", ptr);

// 	//printf("1 temp: %s\n", );
// 	//show_new_line(ptr);
// //_______________________________________________________________________


	printf("before temp_ptr: %s\n", temp_ptr);
	temp = func_for_reading(temp_ptr, temp, fd);
	printf("after temp_ptr: %s\n", temp_ptr);


     // temp = ft_strjoin(temp, new_line_cutter(ptr));
	// temp[ft_strlen(temp)] = '\n';
	// printf("PPPPTR: %s\n", ptr);
	// //show_new_line(ptr, "ptr");
     // temp_ptr = temp_ptr_content(ptr, temp_ptr);
//temp_ptr = temp_ptr_content(ptr, temp_ptr);
	
     // //printf("try: %s\n", try(temp, ptr));

	// // cut ptr in half and maybe at the and '\n'

	// printf("end_func_TEMP_PTR: %s\n", temp_ptr);
//return(temp);
	//return (func_for_reading(temp_ptr, temp, fd));
}

int main()
{
     int fd = open("test2.txt", O_RDONLY);
printf("-------- 1 -------------\n\n");
     char *ptr1;
     ptr1 = get_next_line(fd);
     printf("MAIN_1: %s\n", ptr1);
	show_new_line(ptr1, "main 1");
     //free(ptr1);
printf("-------- 2 -------------\n\n");
     char *ptr2;
     ptr2 = get_next_line(fd);
     printf("MAIN_2: %s\n", ptr2);
	show_new_line(ptr2, "main 2");
     //free(ptr2);
printf("-------- 3 -------------\n\n");
     char *ptr3;
     ptr3 = get_next_line(fd);
     printf("MAIN_3: %s\n", ptr3);
	show_new_line(ptr3, "main 3");
     //free(ptr3);
printf("-------- 4 -------------\n\n");
     char *ptr4;
     ptr4 = get_next_line(fd);
     printf("MAIN_4: %s\n", ptr4);
	show_new_line(ptr4, "main 4");
     //free(ptr4);
printf("-------- 5 -------------\n\n");
     char *ptr5;
     ptr5 = get_next_line(fd);
     printf("MAIN_5: %s\n", ptr5);
     free(ptr5);
printf("-------- 6 -------------\n\n");
     char *ptr6;
     ptr6 = get_next_line(fd);
     printf("MAIN_6: %s\n", ptr6);
	
	
	
	
	
	free(ptr6);
}