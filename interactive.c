#include <stdio.h>
#include <unistd.h>

int main(void)
{
	if (isatty(0))
	{
		printf("Shell is running in interactive mode\n");
	}
	else
	{
		printf("Shell is running in non-interactive mode\n");
	}
	return (0);
}

