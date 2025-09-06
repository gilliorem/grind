#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	target;

	target = c;
	while (*s)
	{
		if (*s == target)
			return ((char *)s);
		s++;
	}
	if (target == '\0')
		return ((char *)s);
	return (NULL);
}

ssize_t	ft_strlen(const char *s)
{
	ssize_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str_join;
	ssize_t	str_join_len;
	ssize_t		i;

	str_join_len = ft_strlen(s1) + ft_strlen(s2);
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
		str_join[i + ft_strlen(s1)] = s2[i];
		i++;
	}
	str_join[ft_strlen(s1) + i] = '\0';
	free(s1);
	return (str_join);
}

char	*ft_strdup(char *s)
{
	char	*dup_src;
	size_t	s_len;
	size_t	i;

	s_len = 0;
	i = 0;
	s_len = ft_strlen(s);
	if (s_len == 0)
		return (NULL);
	dup_src = malloc(sizeof(char) * (s_len + 1));
	if (!dup_src)
		return (NULL);
	while (i < s_len)
	{
		dup_src[i] = s[i];
		i++;
	}
	dup_src[s_len] = '\0';
	return (dup_src);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	subs_len;
	size_t	i;
	size_t	j;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	i = 0;
	j = 0;
	subs_len = ft_strlen(s) - start;
	if (subs_len > len)
		subs_len = len;
	substr = (char *)malloc((subs_len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (s[start + i] && i < len)
	{
		substr[j] = s[start + i];
		i++;
		j++;
	}
	substr[j] = '\0';
	return (substr);
}
