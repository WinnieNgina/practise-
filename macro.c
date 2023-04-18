#include <stdio.h>

// if we uncomment the below line, then the program will print AGE in the output.
#define AGE 18

int main() {
	#ifdef AGE
		printf("Age is %d\n", AGE);
	#else
		printf("Not Defined\n");
	#endif
	
	return 0;
}
