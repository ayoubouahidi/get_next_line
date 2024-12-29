#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// int main()
// {
// 	char *str;
// 	int fd = open("test.txt", O_RDONLY);

// 	while (1)
// 	{
// 		str = get_next_line(fd);
// 		if (str == NULL)
// 			break ;
// 		printf("%s", str);
// 		// free(str);
// 		// str = NULL;
// 	}
// }

int main()
{
	char *str;
	int fd = open("test.txt", O_RDONLY);

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));

}