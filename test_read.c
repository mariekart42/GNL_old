#include "get_next_line.h"

void read_func(int fd)
{
	int val;
	char *ptr;
	int BUFFER = 20;

	ptr = (char *) malloc (60);

	val = read(fd, ptr, BUFFER);
	printf("val: %d\n", val);
}

int main()
{
	int fd;

	fd = open("test.txt", O_RDONLY);
	read_func(fd);
}

// CONCLUSION:
// val is 0 if nothing else is left
// e.g. BUFFER 10
// .txt has 2 character
// -> val will be 2
// after next call, val will be 0