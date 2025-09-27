#include "../include/grind.h"

// ls > open quest.tsv
// get the next line
// read from the second line onto EOF...

// read n lines
int	log_quests(int n)
{
	int fd = open("./data/quests.tsv", O_RDONLY);
	if (fd == -1)
		return printf("Cannot log quests file.\n") & 0;
	char *line = get_next_line(fd);
	int i = 0;
	if (n != 0)
	{
		while (i < n)
		{
			line = get_next_line(fd);
			printf("%s", line);
			i++;
		}
		return n;
	}

	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	return n;
}
