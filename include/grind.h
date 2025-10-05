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
} command_type;

typedef enum
{
	CTX_NONE,
	CTX_QUEST,
	CTX_QUESTS,
	CTX_LEDGER,
	CTX_YIELD,
	CTX_REWARDS,
	CTX_BALANCE,
	CTX_UNKNOWN,
} context_type;

typedef	enum
{
	ARG_NONE,
	ARG_INT,
	ARG_STRING,
	ARG_DATE,
}arg_type;

typedef enum
{
	CMD,
	CTX,
	ARG
}token_type; 

typedef struct s_context
{
	const char *name;
	context_type type;
}t_context;
/* Need to identify the type of the token (int/char/char* ...)*/
typedef struct s_command
{
	const char *name;
	command_type type;
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
int	get_current_month();
/*File*/
char 	*get_ledger_file();
int	find_line_to_delete(int fd, char *id);
int	duplicate_file(int fd);
void	remove_line(int fd, int fd_dup, int line_to_delete);

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

void	execute_cmd(char **input, t_command commands[], int arg);



#endif
