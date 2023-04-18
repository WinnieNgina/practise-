#include <stdio.h>
int main(void)
{
	int length;
	int width;

	printf("Enter the length: ");
	scanf("%d", &length);
	printf("Enter the width: ");
	scanf("%d", &width);
	printf("The area of the triangle %d \n", length * width);
	return (0);
}
