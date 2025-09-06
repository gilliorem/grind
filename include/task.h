#ifndef TASK_H
# define TASK_H
# include <stdbool.h> // bool
# include <string.h> // strcat
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_task
{
    int id;
    char name[64];
    bool complete;
    struct s_task *next;
}t_task;


#endif

