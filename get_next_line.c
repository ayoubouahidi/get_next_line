/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouahid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:20:42 by ayouahid          #+#    #+#             */
/*   Updated: 2024/12/28 00:20:44 by ayouahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

// char	*readfile(int fd)
// {
// 	int octreaded;
// 	char *readed;
// 	int i;
// 	char *buff;

// 	buff[0] = "";
// 	i = 0;
// 	// readed = malloc(42);
// 	// while (1)
// 	// {
// 	// 	octreaded = read(fd, readed, BUFFER_SIZE);
// 	// 	if (octreaded <= 0)
// 	// 		break;
// 	// 	if(readed[i] == '\n' || readed[i] == '\0')
// 	// 		readed[i] = '\0';
// 	// 	i++;
// 	// }
// 	// buff = ft_strjoin(buff, readed);
// 	while ()
// 	{
// 		// octreaded = read(fd, readed, BUFFER_SIZE);
// 		// printf("%d\n", octreaded);
// // 
//         // readed[octreaded] = '\0';  // Null-terminate the read data
// 		// printf("%c\n", readed[octreaded	- 1]);
//         // if (octreaded <= 0) {
//             // break;
//         // }
// // 
//         // while (i < octreaded && readed[i] != '\n' )
// 		// {
// 				// buff[i] = readed[i];
// 		        // i++;
//         // }
//     	// Check for newline or end of string
//         // if (readed[i] == '\n' || readed[i] == '\0') 
// 		// {
// 			// printf("i found a new line\n"); 
//         	// break;
//         // }
// 		// 
// 	}
// 	return (buff);	
// 	}	

char	*readfile(int fd, char *buff)
{
	ssize_t octreaded;
	char *readed;
	char *line;

	//buff = ft_strdup("");  
	readed = malloc(BUFFER_SIZE + 1);
	octreaded = read(fd, readed, BUFFER_SIZE);
	readed[BUFFER_SIZE] = '\0';
	buff = ft_strjoin(buff, readed);
	while (octreaded != 0)
	{
		if (ft_strchr(buff, '\n') != 0)
			break;
		octreaded = read(fd, readed, BUFFER_SIZE);
		readed[BUFFER_SIZE] = '\0';
		buff = ft_strjoin(buff, readed);
		// printf("%s\n", buff);
	}
	printf("%s\n", buff);
	return (buff);
	
	// printf("%d\n", ft_strlen(buff));
}

char *get_next_line(int fd)
{
	static char *buff;

	// buff = NULL;
	printf("i am here\n");
	buff = readfile(fd, buff);
	// readfile(fd, buff);
	return (buff);
}

int main()
{
	int fd = open("file.txt", O_RDWR);
	// printf("i am here");
	char *str = get_next_line(fd);
	printf("%s\n", str);
}