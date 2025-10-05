#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
// delete word
// "hello there"
// ->"hello"

// src "hello there"
// dest []
// go at the last char
// backup until ' '
// mark the end
// write each char in dest
// return dest

char	*join(char const *s1, char const *s2)
{
	char	*str_join;
	size_t	str_join_len;
	int		i;

	str_join_len = strlen(s1) + strlen(s2);
	str_join = (char *)malloc((str_join_len + 1) * sizeof(char));
	if (!str_join)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str_join[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str_join[i + strlen(s1)] = s2[i];
		i++;
	}
	str_join[strlen(s1) + i] = '\0';
	return (str_join);
}

int is_white(char c)
{
    if (c == ' ')
        return 1;
    return 0;
}

char *delete_last_word(char *src)
{
    char *dup_src = src;
    while (*dup_src)
        dup_src++;
    dup_src--;
    while (!is_white(*dup_src))
        dup_src--;
    char *end = dup_src;
    dup_src = src;
    int size = 0;
    while (*dup_src != *end)
    {
        size++;
        dup_src++;
    }
    dup_src = src;
    char *dest;
    dest = malloc(size * sizeof(char) + 1);
    int i = 0;
    while (i < size)
    {
        dest[i] = *dup_src;
        dup_src++;
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char *delete_first_word(char *src)
{
    char *src_dup = src;
    int size = 0;
    int i = 0;
    while (!is_white(src_dup[i]))
    {
        size++;
        i++;
    }
    i = 0;
    char *dest = malloc(size * sizeof(char) + 1);
    while (i < size)
    {
        dest[i] = *src_dup;
        i++;
        src_dup++;
    }
    dest[i] = '\0';
    return dest;
}

int identify_line(char *line, char *id)
{
    if (strstr(line, id))
        return 1;
    return 0;
}

char *append_lines(int fd, char *id)
{
    char *lines;
    lines = strdup("");
    char *line;
    while ((line = get_next_line(fd)))
    {
        if (!identify_line(line, id))
            lines = join(lines, line);
        free(line);
    }
    printf("lines:%s\n",lines);
    return lines;
}

// go implementer ca dans le projet mtn lol
int main()
{
    int fd = open("file", O_RDONLY);
    if (fd == -1)
        return (printf("error file\n") & 0);
    char *lines = append_lines(fd, "RUST");
    close(fd);
    fd = open("file", O_CREAT | O_TRUNC | O_WRONLY);
    write(fd, lines, strlen(lines));
}

