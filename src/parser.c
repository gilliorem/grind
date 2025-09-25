#include "../include/grind.h"
// list token

char *tokens[] = {"command", "context", "argument"};
char *commands[] = {"ls", "log", "recap", "help"};
char *contexts[] = {"event", "quest", "yield", "balance", "both"};
char *args[] = {"today", "tomorrow", "week", "urgent", "all"};
// for args, need to implement numbers.

void	reset_prompt(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

int	count_input_elements(char **input)
{
	int i;
	for (i = 0; input[i]; i++);
	printf("Number of elements:%d\n", i);
	return i;
}

char*	get_cmd(char **input)
{
	char *cmd;
	if (!input[0])
		return NULL;
	for (int i = 0; commands[i]; i++)
	{
		if (strcmp(input[0], commands[i]) == 0)
		{
			cmd = input[0];
			printf("element 1 is matching with cmd:%s\n",commands[i]);
			return (cmd);
		}
	}
	char error_msg[] = "please enter a valid command\n";
	write(2, error_msg, strlen(error_msg)); 
	rl_replace_line("", 0);
	return NULL;
}

char*	get_context(char **input)
{
	char *context;
	if (!input[1])
		return NULL;
	for (int i = 0; contexts[i]; i++)
	{
		if (strcmp(input[1], contexts[i]) == 0)
		{
			context = input[1];	
			printf("element 2 is matching with context:%s\n",contexts[i]);
			return (context);
		}
	}
	perror("please enter a valid command\n");
	return NULL;
}

char*	get_args(char **input)
{
	char *arg;
	if (!input[2])
		return (NULL);
	for (int i = 0; args[i]; i++)
	{
		if (strcmp(input[2], args[i]) == 0)
		{
			arg = args[i];
			printf("element 1 is matching with arg:%s\n",arg);
			return (arg);
		}
	}
	perror("please enter a valid argument\n");
	return NULL;
}

char	**get_user_prompt()
{
	char *line;
	char **words;
	while (1)
	{
		line = readline("./grind$ ");
		if (strcmp(line,  "exit") == 0)
			exit(0);
		words = ft_split(line, ' ');
		get_cmd(words);
		add_history(line);
	}
	return words;
}

