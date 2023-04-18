#include <stdio.h>
int mul (int a, int b) {return (a*b); }
int mod (int a, int b) {return (a%b); }
int div (int a, int b) {return (a/b); }
int main()
{
	int mul_res;
	int mod_res;
	int div_res;

	int (*ptr)(int,int) = &mul;
	int (*ptr1)(int,int) = &div;
	int (*ptr2)(int,int) = &mod;

	mul_res=ptr(20,30);
	div_res=ptr1(40,5);
	mod_res=ptr2(60,80);

	printf("Multiplication: %d\n", mul_res);
	printf("Division: %d\n", div_res);
	printf("Modulus: %d\n", mod_res);
	return 0;
}
