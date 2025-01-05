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
	// char *str;
	// int fd = open("test.txt", O_RDONLY);

	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// str = get_next_line(fd);
	// printf ("-> %d **", str == NULL);

	char *str;
	int fd = open("test.txt", O_RDONLY);
	int fd1 = open("file.txt", O_RDONLY);

	int i = 0;

	while (1)
	{
		str = get_next_line(fd);
		char *str1 = get_next_line(fd1);
		if (str == NULL || str1 == NULL)
			break ;
		else
		printf("%s", str);
		printf("%s", str1);
		free(str);
		free(str1);
		i++;
	}


	// char *str1;
	// while ((str1 = get_next_line(fd1)) != NULL)
	// {
	// 	printf("%s", str1);
	// 	free(str1);
	// }

	
	// printf("%s", str1);
	// printf ("-> %d **", get_next_line(1) == NULL);
	// str = get_next_line(fd);
	// write(1,str,1);


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

// int main()
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	int i = 0;
// 	while (1)
// 	{
// 		char *str = get_next_line(fd);
// 		if (str == NULL)
// 			break ;
// 		else
// 		printf("%s", str);
// 		free(str);
// 		i++;
// 	}
// }