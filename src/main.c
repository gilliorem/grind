#include "../include/grind.h"
int main()
{
	signal(SIGINT, reset_prompt);
	get_user_prompt();
	return 0;
}
