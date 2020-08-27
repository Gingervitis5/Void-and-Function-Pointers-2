#include "utils.h"
#include "fileUtils.h"


int countRecords(FILE * fin, int linesPer)
{
	if(fin == NULL || linesPer < 1)
	{
		perror("Bad params to countRecords\n");
		exit(-99);
	}
	int count = 0;
	char temp[MAX];

	fgets(temp, 100, fin);

	while(!feof(fin))
	{
		count ++;
		fgets(temp, 100, fin);
	}

	if(count == 0 || count % linesPer != 0)
	{
		perror("Bad count in countRecords\n");
		exit(-99);
	}
	
	rewind(fin);

	return count/linesPer;
}


FILE * openInputFile_Prompt()
{
	FILE * fin = NULL;
	char fileName[MAX];
	do
	{
		printf("Please enter the name of the input file ");
		fgets(fileName, MAX, stdin);
		strip(fileName);

		fin = fopen(fileName, "r");

	}while(fin == NULL);

	return fin;
}


