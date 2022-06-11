
#include "get_next_line.h"
#include <stdio.h>

#include <stdlib.h>

char *test_func(char *content)
{
	unsigned int i = 0;
	char *ptr;
	ptr = (char *) malloc(20);
	printf("var: %zu\n", strlen(content));
	while (i < strlen(content))
	{
		ptr[i] = content[i];
		i++;
	}
	unsigned int k = 0;
	while (k < strlen(content))
	{
		ptr[i] = content[k];
		i++;
		k++;
	}
	ptr[i] = '\0';
	//free(content);		// when we free here, main has no access to it anymore
	//free(test);			// doesn't have any access -> not working either
	return(ptr);

}

int main()
{
	char *test;
	test = (char *) malloc (20);
	test = "test test";
	printf("test: %s\n", test);
	char *content;
	content = (char *) malloc(20 * sizeof(char));
	content = "bla";
	content = test_func(content);
	printf("bla: %s\n", content);
	free(content);
	// printf("no_bla: %s\n", content);


}