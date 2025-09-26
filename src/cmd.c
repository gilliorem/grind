#include "../include/grind.h"

// context is basically the file name.
// arg is, in this case most likely the number of lines to print.
void	cmd_log(char *cmd, char *context, int arg)
{
	char *data_dir = "./data/";
	char *full_path = ft_strjoin(data_dir, context);
	full_path = ft_strjoin(full_path, ".tsv");
	printf("full path:%s\n",full_path);
	return ;
	int fd = open("./data/quests.tsv", O_RDONLY);
	fd = open(full_path, O_RDONLY);
	if (fd == -1)
		printf("cannot log %s file.\n", context);
	char *line = get_next_line(fd);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
}

void	execute_cmd(char **input, char *commands[])
{
	char *cmd = get_cmd(input);
	if (strcmp(cmd, commands[0]) == 0)
		cmd_log(cmd, NULL, 0);	
}
