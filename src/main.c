#include "../include/grind.h"

int main(int arg, char *argv[])
{
	signal(SIGINT, reset_prompt);
	get_user_prompt();
	return 0;
}
