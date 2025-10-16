#include "../include/grind.h"

void	execute_ls(char *context, int n)
{
	if (context == NULL)
		context = "quests";
	char *data_dir = "./data/";
	char *full_path = ft_strjoin(data_dir, context);
	full_path = ft_strjoin(full_path, ".tsv");
	int fd = open(full_path, O_RDONLY);
	if (fd == -1)
		printf("cannot log %s file.\n", context);
	char *line = get_next_line(fd);
	int i = 0;
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

// get the name of the quest (context)
// open the quest file, look up for the line with the quest ID
// delete that line -> strchr in the line
// append a new line in the ledger file reporting this deletion
// update the wallet balance

void	complete_quest(char *context, char *id)
{
	if (strcmp(context, "quest") != 0)
	{
		printf("Usage: complete quest questName");
		return; 
	}
	if (id == NULL)
	{
		printf("Please provide a quest name.\n");
		return ;
	}
	update_file(id);
}

char *get_quest_values()
{
	char id[30];
	printf("ID:");
	scanf("%s", id);
	char deadline[6];
	printf("DEADLINE:");
	scanf("%s", deadline);
	char gold[6];
	printf("GOLD:");
	scanf("%s", gold);
	char *line = ft_strjoin(id, "\t\t");
	ft_strjoin(line, deadline);
	ft_strjoin(line, "\t\t");
	ft_strjoin(line, gold);
	printf("%s\n", line);
	return (line);
}

int	add_quest(t_command add)
{
	// TODO: Make this two lines a generic functio
	printf("add name:%s\n",add.name);
	if (strcmp(add.name, "add") != 0)
		return printf("Command not found.\n") & 0;
	printf("in add_quest()");
	char *line = get_quest_values();
	write_line_in_file(line);
	return 1;
}

//TODO figure out a better way to use context
void	execute_cmd(char **input, t_command commands[], int n)
{
	command_type cmd = get_cmd(input);
	char error_msg_cmd_none[] = "please enter a valid command.\n";
	char error_msg_cmd_unknown[] = "Command not found.\n";
	switch (cmd)
	{
		case CMD_NONE:
			write(STDERR_FILENO, error_msg_cmd_none, strlen(error_msg_cmd_none));
			return ;
		case CMD_LS:
			execute_ls(input[1], 0);
			return;
		case CMD_COMPLETE:
			complete_quest(input[1], input[2]);
			return;
		case CMD_ADD:
			printf("here\n");
			add_quest(commands[2]);
		default:
			write(STDERR_FILENO, error_msg_cmd_unknown, strlen(error_msg_cmd_unknown));
			return ;
	}
}
