#include "get_next_line.h"


// void	show_new_line(char *string, char *content)
// {
// 	int		len;
// 	int		i;
// 	char		*ptr;

// 	printf(YEL"\n------------------------->\n"RESET);
// 	printf("-> %s\n", content);
// 	if (!string)
// 		return ;
// 	len = strlen(string);
// 	i = 0;
// 	ptr = strdup(string);
// 	if (!strchr(ptr, '\n'))
// 		printf(MAG "-> no newline character --\n" RESET);
// 	printf(YEL"RESULT: "RESET);
// 	while (i < len)
// 	{
// 		if (ptr[i] == '\n')
// 			printf(GRN"'\\n'"RESET);
// 		if(ptr[i] == '\0')
// 			printf(BLU"'\\0'"RESET);
// 		else
// 			printf("%c", ptr[i]);
// 		i++;
// 	}
// 	printf(YEL"\n<-------------------------\n\n"RESET);
// 	//printf("\n\n");
// }


int main()
{
	char *test;
	test = (char *) malloc(5);
	//test = "test";
	test[0] = 't';
	test[1] = 'e';
	test[2] = 's';
	test[3] = 't';
	test[4] = 0;
	//char *test;

	// test = "test";

	// printf("LEN:%zu\n", ft_strlen(test));
	// printf("ttt: %s\n", test);
	//test[ft_strlen(test)-1] = '\0';

	test[2] = 'n';

	//show_new_line(test, "TEST");
}