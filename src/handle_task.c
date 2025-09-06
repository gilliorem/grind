#include "../include/task.h"
#include "../gnl/get_next_line.h"
void    putchar_fd(int fd, char c)
{
    write(fd, &c, 1);
}

void    write_file(int fd, char *s)
{
    while (*s)
        putchar_fd(fd, *s++);
}

int count_lines()
{
    int lines = 0;
    int fd = open("task", O_RDONLY);
    char *line;
    while ((line = get_next_line(fd)))
    {
        lines++;
        free(line);
    }
    close(fd);
    return lines;
}

t_task    new_task(char *name)
{
    int task_fd = open("task", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (task_fd == -1)
        printf("File error\n");
    t_task new_task;
    printf("New task:");
    scanf("%s", new_task.name);
    strcat(new_task.name, "\n");
    new_task.complete = false;
    write_file(task_fd, new_task.name);
    close(task_fd);
    new_task.id = count_lines();
    printf("%sadded to task list.\n",new_task.name);
    return new_task;
}

void    read_tasks()
{
    int task_fd = open("task", O_RDONLY);
    char *line;
    while ((line = get_next_line(task_fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(task_fd);
}
/*
int main(void)
{
    printf("List tasks [1]\n");
    printf("Create task [2]\n");
    int input;
    scanf("%d", &input);
    if (input == 1)
        read_tasks();
    else if (input == 2)
    {
        char *name = malloc(30);
        new_task(name);
    }
}
*/
