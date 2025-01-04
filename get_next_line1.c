/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouahid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:14:54 by ayouahid          #+#    #+#             */
/*   Updated: 2025/01/03 18:14:57 by ayouahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"


char *get_line(char *buff)
{
	char *line;
	int i;

	i = 0;
	line = malloc(ft_strlen(buff) + 2);
	if (!line)
		return (NULL);
	if(buff[i] == '\0')
		return (NULL);
	while (buff[i] != '\n' && buff[i] != '\0')
	{
		line[i] = buff[i];
		i++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';	
}
char *newPointer(char *buff)
{
	int i;
	// char *tmp;
	i = 0;
	while(buff[i] != '\n' && buff[i] != '\0')
		i++;
	// if (buff + i + 1  == NULL)
	// 	return (NULL);
	// printf("ayoub's test : %s\n", buff);
	if (buff[i] == 0)
		buff = ft_strdup(buff + i);
	else
		buff = ft_strdup(buff + i + 1);
	// free(buff);
	return (buff);
}



char *get_next_line(int fd)
{
	static char *buff;
	char readed[BUFFER_SIZE + 1];
	int octreaded;
	char *line;
	int i;

	octreaded = read(fd, readed, BUFFER_SIZE);
	if (octreaded == 0)
	{
		return (NULL);
	}
	readed[BUFFER_SIZE + 1] = '\0';
	buff = ft_strjoin(buff, readed);
	// printf("the buff 0 is : %s\n", buff);
	while (ft_strchr(buff, '\n') == 0)
	{
		octreaded = read(fd, readed, BUFFER_SIZE);
		if (octreaded == 0)
			break;
		readed[BUFFER_SIZE + 1] = '\0';
		buff = ft_strjoin(buff, readed);
	}
		
	// printf("buff is %s\n", buff);
	// line = get_line(buff);
	// partie 2
	// i = 0;
	// line = malloc(ft_strlen(buff) + 2);
	// if (!line)
		// return (NULL);
	// if(buff[i] == '\0')
		// return (NULL);
	// while (buff[i] != '\n' && buff[i] != '\0')
	// {
		// line[i] = buff[i];
		// i++;
	// }
	// line[i] = '\n';
	// line[i + 1] = '\0';

		// printf("the buff is %s\n", buff);

// change the pointer 
// 	int j;
// // 
// 	j = 0;
// 	// printf("the buff is %s\n", buff);
// 	while(buff[j] != '\n' && buff[j] != '\0')
// 		j++;
// 	if (buff[i] == 0)
// 		buff = ft_strdup(buff + i);
// 	else
// 		buff = ft_strdup(buff + i + 1);
// 	// printf("the buff is %s\n", buff);
// 	// free(buff);
	buff = newPointer(buff);
	return (line);

}
