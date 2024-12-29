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
char *newPointer(char *buff)
{
	int i;

	i = 0;
	while(buff[i] != '\n' && buff[i] != '\0')
		i++;
	// if (buff + i + 1  == NULL)
	// 	return (NULL);
	// printf("ayoub's test : %s\n", buff);
	buff = ft_strdup(buff + i + 1);
	return (buff);
}

char *get_line(char *buff)
{
	char *line;
	int i;

	i = 0;
	line = malloc(ft_strlen(buff) + 2);
	while (buff[i] != '\n' && buff[i] != '\0')
	{
		line[i] = buff[i];
		i++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';
		// printf("i am here\n");
	return (line);
}

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
	return (buff);
	
	// printf("%d\n", ft_strlen(buff));
}

char *get_next_line(int fd)
{
	static char *buff;
	char *line;

	// buff = NULL;
	buff = readfile(fd, buff);
	line = get_line(buff);
	// printf("%s\n",line);
	buff = newPointer(buff);

	// readfile(fd, buff);
	return (line);
}

int main()
{
	int fd = open("file.txt", O_RDWR);
	// printf("i am here");
	char *str = get_next_line(fd);
	char *str1 = get_next_line(fd);
	char *str2 = get_next_line(fd);
	// printf("str : %s\n", str);
	printf("str 1: %s\n", str2);
}