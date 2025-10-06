#include "../include/grind.h"

static int	identify_line(char *line, char *id)
{
	if (strstr(line, id))
		return 1;
	return 0;
}

static char *append_new_lines(int fd, char *id)
{
	char *lines;
	lines = strdup("");
	char *line;
	while ((line = get_next_line(fd)))
	{
		if (!identify_line(line, id))
			lines = ft_strjoin(lines, line);
		free (line);
	}
	printf("lines:%s\n", lines);
	return lines;
}

int	update_file(char *id)
{
	int fd = open("./data/quests.tsv", O_RDONLY);
	if (fd == -1)
		return printf("error file\n") & 0;
	char *lines = append_new_lines(fd, id);
	close (fd);
	fd = open("./data/quests.tsv", O_CREAT | O_TRUNC | O_WRONLY);
	write(fd, lines, strlen(lines));
	return 1;
}

int	write_line_in_file(char *line)
{
	int	fd = open("./data/quests.tsv", O_APPEND | O_WRONLY);
	if (fd == -1)
		return printf("file error\n") & 0;
	if (!line)
		return 0;
    write(fd, line, strlen(line));
	write(fd, "\n", 1);
	close(fd);
	return 1;
}

/*
int main()
{
    FILE *fileptr1, *fileptr2;
    char filename[40];
    char ch;
    int delete_line, temp = 1;

    printf("Enter file name: ");
    scanf("%s", filename);
    //open file in read mode
    fileptr1 = fopen(filename, "r");
    ch = getc(fileptr1);
 `  while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(fileptr1);
    }
    //rewind
    rewind(fileptr1);
    printf(" \n Enter line number of the line to be deleted:");
    scanf("%d", &delete_line);
    //open new file in write mode
    fileptr2 = fopen("replica.c", "w");
    ch = getc(fileptr1);
    while (ch != EOF)
    {
        ch = getc(fileptr1);
        if (ch == '\n')
            temp++;
            //except the line to be deleted
            if (temp != delete_line)
            {
                //copy all lines in file replica.c
                putc(ch, fileptr2);
            }
    }
    fclose(fileptr1);
    fclose(fileptr2);
    remove(filename);
    //rename the file replica.c to original name
    rename("replica.c", filename);
    printf("\n The contents of file after being modified are as follows:\n");
    fileptr1 = fopen(filename, "r");
    ch = getc(fileptr1);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(fileptr1);
    }
    fclose(fileptr1);
    return 0;
}
*/
