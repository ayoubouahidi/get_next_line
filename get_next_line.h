# ifndef GET_NEXT_LINE_H 
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE  1
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>

char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *a);
char	*ft_substr(char const *s, unsigned int start, size_t len);
// char *get_next_line(int fd);
char *get_next_line(int fd);

# endif
