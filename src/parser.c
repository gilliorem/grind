#include "../include/grind.h"

//TODO: store these in a proper place...
char *tokens[] = {"command", "context", "argument"};
char *commands[] = {"ls", "log",  "add", "complete", "yield","recap", "help"};
char *contexts[] = {"events", "quests", "rewards", "balance", "both"};
char *args[] = {"5", "10", "0", "-1", "today", "tomorrow", "week", "urgent", "all"};
// TODO: for args, need to implement numbers

char **parsed_input[] =  {commands, contexts, args};

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
	printf("e:%d\n", i);
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
	int flag = 1;
	if (!input[2 + 1])
		return (NULL);
	for (int i = 0; input[2 + 1][i]; i++)
	{
		if (!isdigit(input[2 + 1][i]))
		{
			flag = 0;
			break;
		}
	}
	if (flag == 1)
	{
		arg = strdup(input[2+1]);
		return arg;
	}
	for (int i = 0; args[i]; i++)
	{
		if (strcmp(input[2+1], args[i]) == 0)
		{
			arg = args[i];
			return (arg);
		}
	}
	char error_msg[] = "please enter a valid argument\n";
	write(2, error_msg, strlen(error_msg)); 
	return NULL;
}

// lets build a hash table since our input is
// more than one char.
//

void	add_token(t_token token)
{
	char	
}

void	scan_input(char *input)
{
	int i = 0;
	while (input[i])
	{
		switch (input[i])
		{
			case 'l':
				add_token(CMD_LS);

		}
		i++;
	}
}

// this is my `scan function`
void	handle_words(char **words, char *commands[])
{
//	char *cmd = get_cmd(words);
//	char *context = words[1];
	char *arg = words[2];
	int arg_int = atoi(arg);
	int w = count_input_elements(words);
	char error[] = "Please enter correct number of arguments.\n";
	switch (w)
	{
		case 1:
			execute_cmd(words, commands, arg_int);
			break;
		case 2:
			execute_cmd(words, commands, arg_int);
			break;
		case 3:
			execute_cmd(words, commands, arg_int);
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
		handle_words(words, commands);
		handle_exit(line);
	}
}

