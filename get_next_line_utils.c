/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouahid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:21:29 by ayouahid          #+#    #+#             */
/*   Updated: 2024/12/28 00:21:31 by ayouahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (!(char)c)
		return ((char *)&str[i]);
	return (NULL);
}


static size_t	ft_strlen(const char *a)
{
	int	i;

	i = 0;
	while (a[i] != '\0')
	{
		i++;
	}
	return (i);
}


static size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	lendest;
	size_t	lensrc;
	size_t	ret;

	if (dest == NULL && size == 0)
		return (ft_strlen(src));
	lendest = ft_strlen(dest);
	lensrc = ft_strlen(src);
	ret = lendest + lensrc;
	i = 0;
	if (lendest >= size)
		return (lensrc + size);
	while (src[i] != '\0' && (lendest + 1) < size)
	{
		dest[lendest] = src[i];
		i++;
		lendest++;
	}
	dest[lendest] = '\0';
	return (ret);
}

static size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	char	*s;
	size_t	i;

	s = (char *)src;
	i = 0;
	if (size == 0)
	{
		return (ft_strlen(s));
	}
	else
	{
		while (s[i] != '\0' && i < size - 1)
		{
			dest[i] = s[i];
			i++;
		}
	}
	dest[i] = '\0';
	return (ft_strlen(s));
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	lens1;
	size_t	lens2;
	int i;
	int j;

	j = 0;
	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	newstr = (char *)malloc(sizeof(char) * (lens1 + lens2) + 1);
	if (newstr == NULL)
		return (NULL);
	while (s1[i] != '\0')
		{
			newstr[i] = s1[i];
			i++;
		}
	while (s2[i] != '\0')
	{
		newstr[i + j] = s2[j];
		j++;
	}
	newstr[j + i] = '\0';
	free(s1);
	return (newstr);
}
