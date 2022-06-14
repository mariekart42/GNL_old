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
	//printf("\n\n");
}

int main()
{
	// char *string_yes;
	// string_yes = (char *) malloc (20);
	char string_yes[20] = {'y', 'e', 's', '\n', 'p', '\0', 'P'};
	char string_no[20] = {'N', 'a', 'h', 'h', 'h'};

	show_new_line(string_yes, "YES");
	show_new_line(string_no, "NO");

	printf("\\0mm\n");
	// char *string_no;
	// string_no = (char *) malloc (20); 
}