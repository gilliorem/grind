#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#  ifndef BUFFER_SIZE
#   define BUFFER_SIZE 64
# endif

# include <stdio.h>
# include <errno.h> // to print the error message
# include <stdlib.h> // malloc
# include <unistd.h> // file functions
# include <fcntl.h> // file descriptors
# include <sys/stat.h> // O_MODE (READ, WRITE ...)
# include <sys/types.h>
//
char	*ft_strchr(const char *s, int c);
ssize_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char *s);
char	*get_next_line(int fd);

#endif
