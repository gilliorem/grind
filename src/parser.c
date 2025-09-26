#include "../include/grind.h"
// list token

//TODO: store these in a proper place...
char *tokens[] = {"command", "context", "argument"};
char *commands[] = {"ls", "log",  "add", "complete", "yield","recap", "help"};
char *contexts[] = {"event", "quest", "desire", "balance", "both"};
char *args[] = {"today", "tomorrow", "week", "urgent", "all"};

char **parsed_input[] =  {commands, contexts, args};
// for args, need to implement *numbers.*

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
			printf("valid cmd is: %s\n",cmd);
			return (cmd);
		}
	}
	char error_msg[] = "please enter a valid command.\n";
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
	char error_msg[] = "please enter a valid context\n";
	write(2, error_msg, strlen(error_msg)); 
	return NULL;
}

char*	get_arg(char **input)
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
	char error_msg[] = "please enter a valid argument\n";
	write(2, error_msg, strlen(error_msg)); 
	return NULL;
}

void	handle_words(char **words, char *commands[])
{
	char *cmd;
	char *context;
	char *arg;
	int w = count_input_elements(words);
	char error[] = "Please enter correct number of arguments.\n";
	switch (w)
	{
		case 1:
			cmd = get_cmd(words);
			if (!cmd)
				execute_cmd(words, commands);
			break;
		case 2:
			cmd = get_cmd(words);
			context = get_context(words);
			break;
		case 3:
			cmd = get_cmd(words);
			context = get_context(words);
			arg = get_arg(words);
			break;
		default:
			write(STDERR_FILENO, error, strlen(error));
			return ;
	}
}

void	handle_exit(char *line)
{
	if (strcmp(line, "exit") == 0)
		exit(0);
}

void	get_user_prompt()
{
	char *line;
	char **words;
	while (1)
	{
		line = readline("./grind$ ");
		words = ft_split(line, ' ');
		add_history(line);
		handle_words(words);
		handle_exit(line);
	}
}

