#include "./words/word.h"
#include "./utils/utils.h"
#include "./utils/fileUtils.h"
#include "./genericArray/genericArray.h"


int main()
{
	FILE * fin = NULL;
	int index, total, choice;

	fin = openInputFile_Prompt();
	total = countRecords(fin, 1);   
	GenericArray * array = fillArray(fin, total, buildTypeWord);
   	fclose(fin);
	printArray(array, total, printTypeWord);

   do
   {
		
	choice = menu();
	switch(choice)
	{
		case 1:	array = addItem(array, &total, buildTypeWord_Prompt);
			printArray(array, total, printTypeWord);
  			break;

		case 2:	array = removeItemByIndex(array, &total, cleanTypeWord);
  			printArray(array, total, printTypeWord);
			break;

		case 3:	array = removeItemByValue(array, &total, buildTypeWord_Prompt, cleanTypeWord, compareWords);
  			printArray(array, total, printTypeWord);
  			break;

		case 4:	sortArray(array, total, compareWords);
  			printArray(array, total, printTypeWord);
  			break;

		default: printf("all done\n");

	}// end switch

   }while(choice != 5);

   cleanArray(array, total, cleanTypeWord);

   return 0;

}// end main
