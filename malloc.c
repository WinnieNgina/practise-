#include <stdio.h>
#include <stdlib.h>
int main ()
{
	int i;
	int n;
	int *ptr;

	printf("Enter the number of integers: ");
	scanf("%d", &n); /*n represent number of elements*/
	ptr = malloc(sizeof(int) * n);
	if (ptr == NULL)
	{
		printf("memory not available");
		return (1);
	}
	for (i = 0; i < n; i++) /*i is the base address and helps us loop through the pointer*/
	{
		printf ("Enter an integer: ");
		scanf("%d", ptr + i);
	}
	for (i = 0; i < n; i++)
		printf("%d", *(ptr + i)); /* dereferencing the pointer to print the integers*/
	return(0);
}
