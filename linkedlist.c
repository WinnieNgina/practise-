#include <stdio.h>
#include <stdlib.h>
typedef struct winnie
{
	char data;
	struct winnie *next_node;
}winnie;
int main( )
{  /* Initialize nodes */
	winnie *head ;
	winnie *one = malloc(sizeof(winnie));
	winnie *two = malloc(sizeof(winnie));
	winnie *three = malloc(sizeof(winnie));
	winnie *four= malloc(sizeof(winnie));
	winnie *five = malloc(sizeof(winnie));
	winnie *six= malloc(sizeof(winnie));
	winnie *seven = malloc(sizeof(winnie));
	winnie *eight = malloc(sizeof(winnie));
	winnie *nine = malloc(sizeof(winnie));
	winnie *ten= malloc(sizeof(winnie));
    
/* Assign data values */
	one->data = 'H';
	two->data = 'E';
	three->data = 'L';
	four ->data = 'L';
	five ->data = 'O';
	six ->data = 'W';
	seven ->data = 'O';
	eight ->data = 'R';
	nine ->data = 'L';
	ten ->data = 'D';
    
	head = one; // save address of the first node in head
 
   /* Connect nodes */
	one->next_node = two;
	two->next_node = three;
	three->next_node = four;
	four->next_node = five;
	five->next_node = six;
	six->next_node = seven;
	seven->next_node = eight;
	eight->next_node = nine;
	nine->next_node = ten;
	ten->next_node = NULL;
    
	printf("%c%c%c%c%c %c%c%c%c%c\n", one->data, two->data, three->data, four->data, five ->data, six ->data,seven ->data, eight ->data, nine ->data, ten ->data);
	printf("The address of Node 1 which is the head node of this list is :%p\n",head);
	printf("The address of the next node is : %p\n", one->next_node);
	printf("The address of the next node is : %p\n", two-> next_node);
	printf("The address of the next node is : %p\n", three->next_node);
	printf("The address of the next node is : %p\n", four-> next_node);
	printf("The address of the next node is : %p\n", five-> next_node);
	printf("The address of the next node is : %p\n", six-> next_node);
	printf("The address of the next node is : %p\n", seven-> next_node);
	printf("The address of the next node is : %p\n", nine-> next_node);
	 printf("The address of the next node is : %p\n", ten-> next_node);
	printf("\n");
 
return 0 ;
}

