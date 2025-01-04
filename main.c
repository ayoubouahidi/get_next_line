#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>



// read fail
// int main()
// {
// 	char *str;
// 	int fd = open("test.txt", O_RDONLY);
// 	//int i = 0;
// 	close (fd);
// 	// while (1)
// 	// {
// 	// 	str = get_next_line(1);
// 	// 	if (str == NULL)
// 	// 		break ;
// 	// 	else
// 	// 	printf("%s", str);
// 	// 	free(str);
// 	// 	i++;
// 	// }
// 	// printf ("-> %d **", get_next_line(1) == NULL);
// 	str = get_next_line(fd);
// 	write(1,str,1);




// //  while (i < 50)
// //  {
// // 	write (fd, "g", 1);
// // 	i++;
// //  }
// }

int main()
{
	char *str;
	int fd = open("test.txt", O_RDONLY);

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	str = get_next_line(fd);
	printf ("-> %d **", str == NULL);
}
// int main() {
//     char *str;
//     int fd = open("test.txt", O_RDONLY);

//     if (fd == -1) {
//         perror("Error opening file");
//         return 1;
//     }

// 	str = get_next_line(fd);
// 	printf("%s", str);
//     while (str != NULL) {
//         printf("%s", str);
//         free(str);
// 		str = get_next_line(fd);
// 		printf ("-> %d **", str == NULL);
//     }
//     close(fd);
//     return 0;
// }