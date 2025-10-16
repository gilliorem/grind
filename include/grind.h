#ifndef TASK_H
# define TASK_H
# include "../libft/libft.h"
# include <stdbool.h> // bool
# include <string.h> // strcat
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <time.h>
# include <signal.h> 
# include <readline/readline.h>
# include <readline/history.h>

typedef enum
{
	CMD_NONE,
	CMD_LS,
	CMD_LOG,
	CMD_RECAP,
	CMD_ADD,
	CMD_COMPLETE,
	CMD_YIELD,
	CMD_HELP,
	CMD_UNKNOWN
} command_name;

typedef	enum
{
	OPT_NONE,
	OPT_INT,
	OPT_STRING,
	OPT_DATE,
} option_type;

typedef enum
{
	CMD,
	OPT
}token_type; 

typedef struct s_option
{
	const char *name;
	option_type type;
}t_context;

typedef struct s_command
{
	const char *name;
	command_name name;
	t_context	context;
}t_command;

typedef struct s_token
{
	token_type type;
	char *str;
	int num;
}t_token;

typedef struct s_task
{
    int id;
    char name[64];
    bool complete;
    struct s_task *next;
}t_task;

typedef struct s_event
{
	time_t time;
	char *type;
	char *id;
	int token;
	bool done;
	char *notes;
}t_event;

/*Time*/
char	*get_current_time();
void	get_deadline_time(int days);
int		get_current_month();

/*File*/
char 	*get_ledger_file();
void	execute_cmd(char **input, t_command commands[], int arg);
int		update_file(char *id);
char	**split_line(char *line);
int		write_line_in_file(char *line);

/*Parser*/
void	reset_prompt(int sig);
command_type	get_cmd(char **input);
context_type	get_context(char **input);
char	*get_arg(char **input);

void	get_user_prompt();
void	handle_words(char **words, t_command commands[]);
void	handle_exit(char *line);
void	parse_cmd(char *cmd);

/* Commands execution */
void	execute_ls(char *context, int n);
int		log_quests(int n);
void	complete_quest(char *context, char *id);
char	*get_quest_values();
int		add_quest(t_command add);


#endif
