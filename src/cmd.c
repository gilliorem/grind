#include "../include/grind.h"

// context is basically the file name.
// arg is, in this case most likely the number of lines to print.

//char *commands[] = {"ls", "log",  "add", "complete", "yield","recap", "help"};

// ls (without context and arg: log quests.tsv)

void	cmd_ls(char *cmd, char *context, int n)
{
	char *data_dir = "./data/";
	char *full_path = ft_strjoin(data_dir, context);
	full_path = ft_strjoin(full_path, ".tsv");
	int fd = open(full_path, O_RDONLY);
	if (fd == -1)
		printf("cannot log %s file.\n", context);
	char *line = get_next_line(fd);
	int i = 0;
	printf("n:%d\n",n);
	if (n > 0)
	{
		while (i < n)
		{
			line = get_next_line(fd);
			printf("%s", line);
			i++;
		}
		return ;
	}
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
}

void	execute_cmd(char **input, char *commands[], int n)
{
	char *cmd = get_cmd(input);
	char *context = get_context(input);
	char *arg = get_arg(input);
	int int_arg = 0;
	if (n == 3)
	{
		if (isdigit(arg[0]))
		{
			int_arg = atoi(arg);
			if (strcmp(cmd, commands[0]) == 0)
				cmd_ls(cmd, context, atoi(arg));
		}
		else
		{
			if (strcmp(cmd, commands[0]) == 0)
				cmd_ls(cmd, context,  -1);
		}
		//TODO each cmd
	}
}
