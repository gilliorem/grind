#include "../include/task.h"

void	print_events();

char	*get_current_time()
{
	time_t now = time(NULL);
	char *curr_time = ctime(&now);
	return curr_time;
}

void	get_deadlime_time(int days)
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

int	find_current_ledger_file()
{
	char *ledger_dir = "./ledger/";
	int month = get_current_month();
	char *current_month = ft_itoa(month);
	if (month < 10)
	{
		char *new_current_month = ft_strjoin("0", current_month);
		printf("%s\n", new_current_month);
	}
	return 0;
	//char *full_path = strcat(current_month, ledger_dir);
	//printf("%s\n",full_path);
	//int ledger_fd = open(ledger_path)
	
	return 0;
}
