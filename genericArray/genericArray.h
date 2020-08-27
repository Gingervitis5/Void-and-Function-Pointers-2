/**
 * @file genericArray.h
 * A Generic Array file for holding a basic structure and the method headers that are written in a very
 * generic fashion
 */
#ifndef GENERICARRAY_H
#define GENERICARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * The name generic array structure that simply holds a void pointer<br>
 */
struct generic_array
{
	/**
	 * The void pointer for the data
	 */
	void * data;
};


/**
 * My style is to create a generic named structure and then typedef to a more usable name
 */
typedef struct generic_array GenericArray;


/**
 * The fillArray method, fills the array by reading a record from the file.
 *
 * @param in Representing the input stream
 * @param length The total number of elements in the array
 * @param function pointer for building the type
 * @return GenericArray * Representing the filled array
 */
GenericArray * fillArray(FILE * in, int length, void * (*buildType)(FILE * input));


/**
 * The printArray method.  The point of this method is to:<br>
 * The method loops thru each element of the array and simply calls the appropriate print method and prints the contents to the stream
 *
 * @param array Representing the GenericArray as a 1D pointer
 * @param length A pointer back to main for the length of the array
 * @param function pointer for print the contents of the void pointer -- note the function pointer is passed the void * data
 */
void printArray(GenericArray * array, int length, void (*printType)(void *));


/**
 * The cleanArray method.  The point of this method is to:<br>
 * The method loops thru each element of the array and simply calls the appropriate clean method and frees any dynamically allocated memory<br>
 * Each element of the appropriate type should be set to NULL if it is a pointer<br>
 * Once the for loop completes the array itself is freed.
 *
 * @param array Representing the GenericArray as a 1D pointer
 * @param length A pointer back to main for the length of the array
 * @param function pointer for cleaning the contents of the void pointer -- note the function pointer is passed the void * data
 */
void cleanArray(GenericArray * array, int length, void (*cleanType)(void *));


/**
 * The sortArray method uses the selectionSort to sort the array
 *
 * @param array Representing the GenericArray as a 1D pointer
 * @param length A pointer back to main for the length of the array
 * @param function pointer for comparing the data from the line if(compar(array[search], array[min]) < 0)
 */
void sortArray(GenericArray * array, int length, int (*compar)(const void * v1, const void * v2));


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
GenericArray * addItem(GenericArray * array, int *length, void * (*buildType_prompt)());


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
GenericArray * removeItemByValue(GenericArray * array, int *length, void * (*buildType_prompt)(), void (*cleanType)(void * ptr), int (*compar)(const void * v1, const void * v2));


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
GenericArray * removeItemByIndex(GenericArray * array, int *length, void (*cleanType)(void * ptr));


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
GenericArray * removeItemByIndexPassedIn(GenericArray * array, int *length, void (*cleanType)(void * ptr), int index);



#endif
