#include <stdio.h>
#include <fcntl.h>

#include "get_next_line_bonus.h"

int main()
{
//	int fd1 = open("file1.txt", O_RDWR);
//	int fd2 = open("file2.txt", O_RDWR);
//	int fd3 = open("file3.txt", O_RDWR);
//	int fd4 = open("file4.txt", O_RDWR);

//	printf("%s", get_next_line(fd1));
//	printf("%s", get_next_line(fd2));
//	printf("%s", get_next_line(fd3));
//	printf("%s", get_next_line(fd4));
//	printf("%s\n", get_next_line(fd1));
//	printf("%s\n", get_next_line(fd2));
//	printf("%s\n", get_next_line(fd3));
	printf("%s", get_next_line(20000000));
}
