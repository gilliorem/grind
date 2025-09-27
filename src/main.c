#include "../include/grind.h"

int main(int argc, char *argv[])
{
	signal(SIGINT, reset_prompt);
	char *arg = get_arg(argv);
	printf("arg:%d\n", atoi(arg));
	//get_user_prompt();
	return 0;
}
