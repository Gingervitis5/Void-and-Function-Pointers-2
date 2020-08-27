#include "utils.h"

void strip(char *array)
{
	if(array == NULL)
	{
		perror("array is null");
		exit(-99);
	}// end if

	int len = strlen(array), x = 0;
   
	while(array[x] != '\0' && x < len)
	{
	  if(array[x] == '\r')
		 array[x] = '\0';

	  else if(array[x] == '\n')
		 array[x] = '\0';

	  x++;

	}// end while
   
}// end strip



int menu()
{
	int num;
	
	do
	{
		printf("Please choose from the following\n");
		printf("1) Add New Item to the Array\n");
		printf("2) Remove Item by Index\n");
		printf("3) Remove Item by Value\n");
		printf("4) Sort the Array\n");
		printf("5) Quit\n");
		printf("Choice --> ");
		scanf("%d", &num);
	}while(num < 1 || num > 5);

	while(fgetc(stdin) != '\n');
   
	return num;
}// end menu


int readIndex(int total)
{
	int num;

	do
	{
		printf("Please enter an index ");
		scanf("%d", &num);

	}while(num < 0 || num >= total);

	while(fgetc(stdin) != '\n') ;

	return num;
}// end readIndex
