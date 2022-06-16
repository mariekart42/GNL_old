#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


// defining BUFFERSITE, delete at the and (calling it in the command line)
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

#include <unistd.h>
# include <stddef.h>

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <strings.h>


char *get_next_line(int fd);

void      *ft_calloc (size_t nelem, size_t elsize);
size_t	ft_strlen(const char *str);
void      ft_bzero(void *str, size_t n);
char      *ft_strjoin(char const *s1, char const *s2);
char      *ft_strchr(const char *str, int c);


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

# endif

