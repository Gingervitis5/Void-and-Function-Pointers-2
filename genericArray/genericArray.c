#include "genericArray.h"
#include "word.h"
#include "../utils/utils.h"


GenericArray * fillArray(FILE * in, int length, void * (*buildType)(FILE * input))
{
	int x;

	GenericArray * array = calloc(length, sizeof(GenericArray));

	for(x = 0; x < length; x++)
		array[x].data = buildType(in);

	return array;
}


void printArray(GenericArray * array, int length, void (*printType)(void *))
{
	int x;
	printf("\n");
	for(x = 0; x < length; x++)
        printType(array[x].data);

	printf("\n");
}


void cleanArray(GenericArray * array, int length, void (*cleanType)(void *))
{
	int x;
	for(x = 0; x < length; x++)
		cleanType(array[x].data);

	free(array);
	array = NULL;

}


void sortArray(GenericArray * array, int length, int (*compar)(const void * v1, const void * v2))
{
	int start, search, min;
	GenericArray temp;

	for(start = 0; start < length - 1; start++)
	{
		min = start;

		for(search = start + 1; search < length; search ++)
			if(compar(array[search].data, array[min].data) < 0)
				min = search;

		temp = array[min];
		array[min] = array[start];
		array[start] = temp;

	}// for start

}// end sortArray


/**
 * The addItem method, adds an item into the array.  It first creates a new array of size length + 1
 * then it copies over all the elements.  After the copy it prompts the user to enter the new item
 * from the command line which it stores in the last element of the array. The old array is freed and
 * the length is updated before the new array is returned.
 *
 * @param array The original array to be copied
 * @param length The total number of elements in the array as a pointer
 * @param function pointer for building the type from the keyboard
 * @return GenericArray * Representing the new array
 */
GenericArray * addItem(GenericArray * array, int *length, void * (*buildType_prompt)()){
    GenericArray *newArray = (GenericArray *)calloc(*length+1, sizeof(GenericArray));
    int x = 0;
    for (x; x < *length; x++){
        newArray[x].data = array[x].data;
    }
    newArray[x].data = buildType_prompt();
    *length = *length+1;
    free(array);
    array = NULL;
    return newArray;
}


/**
 * The removeItemByValue method, removes an item from the array.  It first prompts the user to enter a type
 * via the function pointer buildType_ propmt.  It then check to see if that value is in the array.
 * If not, then an "Item Not Found! No Changes\n" message is displayed and the original array is returned.
 * If the item is in the array, then item is removed using the function
 * pointer cleanType. A new array is made one smaller and the elements except the one being removed
 * are copied.  the local item is freed via cleanType, and the old array is freed and the length is updated.
 * NOTE: What happens if the array is length 0?
 *
 * @param array The original array to be changed
 * @param length The total number of elements in the array as a pointer
 * @param function pointer for creating the type from the keyboard
 * @param function pointer for removing the type
 * @return GenericArray * Representing the new array
 */
GenericArray * removeItemByValue(GenericArray * array, int *length, void * (*buildType_prompt)(), void (*cleanType)(void * ptr), int (*compar)(const void * v1, const void * v2)){
    if (array == NULL){
        exit(-99);
    }
    else if (*length <= 0){
        printf("Array length is 0, no changes made\n");
        return array;
    }
    Word *word = buildType_prompt(); int index = -1;
    int x = 0, y = 1;
    for (x; x < *length; x++){
        if (compar(word, ((Word *)(array[x].data))) == 0){
            cleanType(array[x].data);
            index = x;
        }
    }
    if (index < 0){
        printf("Item Not Found! No Changes\n");
        return array;
    }
    else {
        x = 0; GenericArray *newArray = (GenericArray *)calloc(*length-1, sizeof(GenericArray));
        for (x; x != index; x++, y++){
            newArray[x].data = array[x].data;
        }
        for (y; y < *length; x++, y++){
            newArray[x].data = array[y].data;
        }
        *length = *length - 1;
        free(array); cleanType(word);
        array = NULL;
        return newArray;
    }
}


/**
 * The removeItemByIndex method, removes an item from the array.
 * The method first prompts for an index -- look in utils
 * Then item is removed using the function pointer cleanType.
 * A new array is made one smaller and the elements except the one being removed
 * are copied.  The old array is freed and the length is updated.
 * NOTE: What happens if the array is length 0? Can you actually get here if the length is 0?
 *
 * @param array The original array to be changed
 * @param length The total number of elements in the array as a pointer
 * @param function pointer for removing the type
 * @return GenericArray * Representing the new array
 */
GenericArray * removeItemByIndex(GenericArray * array, int *length, void (*cleanType)(void * ptr)){
    if (*length <= 0){
        printf("Array length is 0. No changes made");
        return array;
    }
    int indexRemove = readIndex(*length);
    return removeItemByIndexPassedIn(array, length, cleanType, indexRemove);
}


/**
 * The removeItemByIndexPassedIn method, would be a private method in Java or an overload method
 * in Java.  The method removes an item from the array.
 * The method first prompts for an index -- look in utils
 * Then item is removed using the function pointer cleanType.
 * A new array is made one smaller and the elements except the one being removed
 * are copied.  The old array is freed and the length is updated.
 * NOTE: What happens if the array is length 0? Can you actually get here if the length is 0?
 *
 * @param array The original array to be changed
 * @param length The total number of elements in the array as a pointer
 * @param function pointer for removing the type
 * @param index The index to remove
 * @return GenericArray * Representing the new array
 */
GenericArray * removeItemByIndexPassedIn(GenericArray * array, int *length, void (*cleanType)(void * ptr), int index){

    GenericArray *newArray = (GenericArray *)calloc(*length-1, sizeof(GenericArray));
    while (index >= *length || index < 0){
        index = readIndex(*length);
    }
    cleanType(array[index].data);
    int x = 0, y = 1;
    for (x; x != index; x++, y++){
        newArray[x].data = array[x].data;
    }
    for (y; y < *length; x++, y++){
        newArray[x].data = array[y].data;
    }
    *length = *length-1;
    free(array);
    array = NULL;
    return newArray;
}


