#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * randomPasswordGeneration - Function to randomly generates password
 * @n: password length
 */
void randomPasswordGeneration(int n)
{
	/*Initialize counter*/
	int i = 0;
	int randomizer = 0;
  
    /**
     * Seed the random-number generator
     * with current time so that the
     * numbers will be different every time
     */
	srand((unsigned int)(time(NULL)));
	/*Array of numbers*/
	char numbers[] = "0123456789";
	/*Array of lowercase alphabets*/
	char letter[] = "abcdefghijklmnoqprstuvwyzx";
	/*Array of capital alphabets*/
	char LETTER[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";
	/*Array of all the special symbols*/
	char symbols[] = "!@#$^&*?";
	/*Stores the random password*/
	char password[n];

	randomizer = rand() % 4;

	for (i = 0; i < n; i++)
	{
		if (randomizer == 1)
		{
			password[i] = numbers[rand() % 10];
			randomizer = rand() % 4;
			printf("%c", password[i]);
		}
		else if (randomizer == 2)
		{
			password[i] = symbols[rand() % 8];
			randomizer = rand() % 4;
			printf("%c", password[i]);
		}
		else if (randomizer == 3)
		{
			password[i] = LETTER[rand() % 26];
			randomizer = rand() % 4;
			printf("%c", password[i]);
		}
		else
		{
			password[i] = letter[rand() % 26];
			randomizer = rand() % 4;
			printf("%c", password[i]);
		}
	}
	printf("\n");
}
  
/**
 * Entry point of the program
 * Return: 0 on success
 */
int main(void)
{
	/* Length of the password to be generated*/
	int N = 10;
	/*Function Call*/
	randomPasswordGeneration(N);
	return (0);
}
