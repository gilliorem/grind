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

#endif
