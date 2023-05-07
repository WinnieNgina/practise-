#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char** fizzBuzz(int n, int* returnSize)
{
	char **str;
	int index;
	int len;

	str = (char **)malloc (sizeof(char *) *n);
	/*Allocating memory for the string*/
	for (int index = 1; index <= n; index++)
	/*iterate from one to find string value*/
	{
		if (index % 15 == 0)
		{
			len = strlen("FizzBuzz") + 1;
			/*1 for the null terminator in the string*/
			str[index - 1] = (char*)malloc(sizeof(char) * len);
			/*Assign memory for the current string*/
			strcpy(str[index - 1], "FizzBuzz");
			/*Assign value for the current string*/
		}
		else if (index % 3 == 0)
		{
			len = strlen("Fizz") + 1;
			str[index - 1] = (char*)malloc(sizeof(char) * len);
			strcpy(str[index - 1], "Fizz");
		}
		else if (index % 5 == 0)
		{
			len = strlen("Buzz") + 1;
			str[index - 1] = (char*)malloc(sizeof(char) * len);
			strcpy(str[index - 1], "Buzz");
		}
		else
		{
			len = snprintf(NULL, 0, "%d", index) + 1;
			/**
			 * snprintf convert numbers into text
			 * 0 indicates no charachers should be written
			 * snprintf function needs a place to store the text it generates
			 * We pass NULL to have it just convert but not store the str
			 * index is the integer converted to string
			 */
			str[index - 1] = (char*)malloc(sizeof(char) * len);
			sprintf(str[index - 1], "%d", index);
		}
	}
	*returnSize = n;
	return (str);
}
int main(void)
{
	int n;
	int returnSize;
	char** str;

	printf("Enter the value of n: ");
	scanf("%d", &n);
	str = fizzBuzz(n, &returnSize);
	/*print the resulting array*/
	for (int i = 0; i < returnSize; i++)
	{
		printf("%s", str[i]);
		if (i < returnSize - 1)
		{
			printf(", ");
		}
	}
	printf("\n");
	/*Free the allocated memory*/
	for (int i = 0; i < n; i++)
	{
		free(str[i]);
	}
	free(str);
}
