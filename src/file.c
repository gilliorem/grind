#include "../include/grind.h"

int	find_line_to_delete(int fd, char *id)
{
	int line_to_delete = 1;
	char *line;
	while ((line = get_next_line(fd)))
	{
		if (strstr(line, id))
		{
			printf("line to delete:%d %s\n", line_to_delete, line);
			return line_to_delete;
		}
		line_to_delete++;
	}
	printf("did not find line to delete\n");
	return 0;
}

int	duplicate_file(int fd)
{
	int	fd_dup = fd;
	char *line;
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
	}
	printf("End Of Original File\n");
	printf("fd original:%d\n", fd);
	printf("fd dup:%d\n", fd_dup);
	while ((line = get_next_line(fd_dup)))
	{
		printf("%s", line);
	}
	printf("End Of Duplicated File\n");
	return (fd_dup);
}

void	remove_line(int fd, int dup_fd, int line_to_delete)
{
	return ;
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
