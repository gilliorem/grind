#include "../include/grind.h"

void	print_events(); // ?

/* need to move to the time module time.c */
char	*get_current_time() 
{
	
	time_t now = time(NULL); // returns number of seconds since 1/1/1970
	printf("sec since 1/1/70: %ld\n", now); // 1758784912
	char *curr_time = ctime(&now); 
	return curr_time;
}

void	get_deadline_time(int days)
{
	time_t now = time(NULL);
	time_t deadline = now + (days * (24 * 3600));
	char *deadline_s = ctime(&deadline);
	printf("deadline:%s\n",deadline_s);
}
// ./ledger/09-2025.tsv
int	get_current_month()
{
	time_t now = time(NULL);
	struct tm local_month;
	localtime_r(&now, &local_month);
	//month 0 from 11; I set it to 1 to 12.
	int month_11 = local_month.tm_mon;
	int month_12 = month_11 + 1;
	return month_12;
}

char	*get_ledger_file()
{
	char *ledger_dir = "./ledger/";
	int month = get_current_month();
	char *current_month = ft_itoa(month);
	char *new_current_month = strdup(current_month);
	if (month < 10)
	{
		new_current_month = ft_strjoin("0", new_current_month);
		printf("%s\n", new_current_month);
	}
	char *full_path = ft_strjoin(ledger_dir, new_current_month);
	printf("%s\n",full_path);
	int ledger_fd = open(full_path, O_RDONLY);
	return 0;
}
