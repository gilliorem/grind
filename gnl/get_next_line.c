#include "get_next_line.h"

static int	read_file_until_next_line(int fd, char *buf, char **static_buf)
{
	ssize_t bytes_read; 
	ssize_t total_bytes; 
	char	*tmp;
	
	bytes_read = 1;
	total_bytes = 0;
	if (!*static_buf)
	{
		*static_buf = malloc(BUFFER_SIZE + 1);
		*static_buf[0] = '\0';
		if(!*static_buf) 
			return (0);
	}
	if (ft_strchr(*static_buf, '\n') != NULL)
		return (bytes_read);
	total_bytes = ft_strlen(*static_buf);
	while ((ft_strchr(buf, '\n') == NULL) && (bytes_read > 0))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		total_bytes += bytes_read;
		if (bytes_read <= 0)
			return (total_bytes);
		buf[bytes_read] = '\0';
		tmp = ft_strjoin(*static_buf, buf);
		*static_buf = tmp;
	}
	return (bytes_read);
}

static char	*clean_static_buf(char **static_buf)
{
	char	*new_line_ptr;
	char	*new_static;

	new_line_ptr = ft_strchr(*static_buf, '\n');
	new_static = NULL;
	if (new_line_ptr != NULL)
	{
		new_line_ptr++;
		new_static = ft_strdup(new_line_ptr);
	}
	free (*static_buf);
	return (new_static);
}

static char	*extract_line(char *static_buf)
{
	int	i;
	char	*line;

	i = 0;
	if (!static_buf || static_buf[0] == '\0')
		return (NULL);
	while (static_buf[i] != '\n' && static_buf[i])
		i++;
	if (static_buf[i] == '\n')
		i++;
	line = ft_substr(static_buf, 0, i);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*static_buf;
	int		bytes_read;
	
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	else
		buf[0] = '\0';
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buf);
		return (NULL);
	}
	bytes_read = read_file_until_next_line(fd, buf, &static_buf);
	free(buf);
	if (bytes_read == 0 || bytes_read == -1 || !static_buf)
	{
		if (static_buf)
		{
			free(static_buf);
			static_buf = 0;
		}
		return (NULL);
	}
	line = extract_line(static_buf);
	if (!line || line[0] == '\0')
	{
		if (line)
			free(line);
		free (static_buf);
		static_buf = NULL;
		return (NULL);
	}
	static_buf = clean_static_buf(&static_buf);
	return (line);
} 

/*
int	main()
{
	int fd = open("tester/files/41_with_nl", O_RDONLY );
	char *line = NULL;
	//while ((line = get_next_line(fd)))
	for (int i = 0; i < 20; i++)
	{
		line = get_next_line(fd);
		if (line)
		{
			printf("main>>> %s", line);
			free(line);
		}
	}
	return 0;
}
*/
