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
} CommandType;

typedef enum
{
	CTX_NONE,
	CTX_QUEST,
	CTX_YIELD,
	CTX_DESIRE,
} ContextType;

typedef	enum
{
	ARG_NONE,
	ARG_INT,
	ARG_STRING,
	ARG_DATE,
}ArgType;

typedef enum
{
	CMD,
	CTX,
	ARG
}Token_type; 

typedef struct s_command
{
	const char *name;
	CommandType type;
}t_command;

/* Need to identify the type of the token (int/char/char* ...)*/
typedef struct s_token
{
	Token_type type;
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
/*Parser*/
void	reset_prompt(int sig);
CommandType	get_cmd(char **input);
char	*get_context(char **input);
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
