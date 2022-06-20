#include"get_next_line.h"
#include <stdlib.h>

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
	size_t i = 0;
	
	new_ptr = (char *) malloc(ft_strlen(string) + size);

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
	}
	free(string);
	return (new_ptr);
}


char *test_func(char *bier)
{
	char *new_ptr;
	int i = 0;
	char *bla;

	bla = (char *) calloc(10, sizeof(char));
	*bla = '!';
	new_ptr = (char *) calloc(20, sizeof(char));
	while (i < 10)
	{
		new_ptr[i] = bier[i];
		i++;
	}
	new_ptr[i] = '\0';
	bier = ft_strjoin(new_ptr, bla);
	free(bier);
	free(bla);

    return (new_ptr);
}

int main()
{
    char	*test;
	//test = NULL;
	//test = (char *)malloc(10);
	test[0] = 'P';
	//test = "something";
	//test = test_func(test);
    //free(test);
}