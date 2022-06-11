#include "get_next_line.h"

int main()
{
     int BUFF = 10;
     char *null;
     char *not_null;
     char *sth;
     char *join1;
     char *join2;

     not_null = (char *) malloc(BUFF);
     if(!not_null)
          return(0);
     join2 = (char *) malloc(BUFF);
     if(!join2)
          return(0);
     join1 = (char *) malloc(BUFF);
     if(!join1)
          return(0);
     null = (char *) malloc(BUFF);
     if(!null)
          return(0);
     sth = (char *) malloc(BUFF);
     if(!sth)
          return(0);

     null = NULL;
     not_null = "";
     sth = "kacke";

     join1 = ft_strjoin(null, sth);
     join2 = ft_strjoin(not_null, sth);

     printf("\nnull_should be 'kacke':     %s\n", join1);
     printf("not_null_should be 'kacke': %s\n\n", join2);
}

// CONCLUSION:
// if join gets an pointer thet is NULL (also if malloced)
// it will always return NULL
// -> pointer has to be "" when it's supposed to be empty