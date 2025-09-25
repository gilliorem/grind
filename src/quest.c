#include "../include/grind.h"

// ls > open quest.tsv
// get the next line
// read from the second line onto EOF...

int	log_quests()
{
	int fd = open("./data/quests.tsv", O_RDONLY);
	if (fd == -1)
		return printf("Cannot log quests file.\n") & 0;
	// we jump the first line
	char *line = get_next_line(fd);

	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	return 1;
}
