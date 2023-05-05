#include <stdio.h>
/**
 * main - Entry point of the program
 * Return: 0on sucess
 */
int main (void)
{
	char c;

	printf("Enter one char: ");
	scanf("%c", &c);

	if (c == 'y' || c == 'Y')
	{
		printf("Agreed.\n");
	}
	else if (c == 'n' || c == 'N')
	{
		printf("Disagreed.\n");
	}
	else
	{
		printf("Not a valid option\n");
	}
	return (0);
}
