#include "word.h"
#include "utils.h"
#include "fileUtils.h"

 /**
 * @brief Cleans up all dynamically allocated memory for the word
 *
 * Cleans up and frees all the dynamically allocated memory
 * In this case ltrs
 *
 * Each pointer in the specific data type is set to NULL after it has been freed.
 *
 * @param passedIn - The void * passed in representing the specific word
 *
 * @warning - The passed in void * passedIn is checked - exit(-99) if NULL
 */
void cleanTypeWord(void * ptr){
    if (ptr == NULL){
        exit(-99);
    }
    Word *word = (Word *)ptr;
    free(word->ltrs);
    word->ltrs = NULL;
}


/**
 * @brief Builds and returns a single word.
 *
 * Reads the initial data from the file and then builds
 * an object of type word.
 *
 * @note The carriage return will be removed when reading from the file
 *
 * @param fin - The FILE * representing the open file
 * @return void * - Representing a word object
 *
 * @warning - The passed in FILE * fin is checked - exit(-99) if NULL
 */
void * buildTypeWord(FILE * fin){
    if (fin == NULL){
        exit(-99);
    }
    char temp[100]; Word *word = (Word *)calloc(1, sizeof(Word));
    word->ltrs = (char *)calloc(100, sizeof(char));
    fgets(temp, 100, fin);
    strip(temp);
    strcpy(word->ltrs, temp);
    word->len = (int)strlen(temp);
    return word;
}


/**
 * @brief Prints the specific word.
 *
 * Format is word - length
 *
 * @param passedIn - The void * passed in representing a specific word
 *
 * @warning - The passed in void * passedIn is checked - exit(-99) if NULL
 */
void printTypeWord(void * passedIn){
    if (passedIn == NULL){
        exit(-99);
    }
    Word *word = (Word *)passedIn;
    printf("%s - %d\n", word->ltrs, word->len);
    cleanTypeWord(word);
}


/**
 * @brief Builds and returns a single word.
 *
 * Reads the initial data from the keyboard by prompting the user.
 * A word object is constructed.
 *
 * @note The carriage return will be removed when reading from the keyboard
 *
 * @return void * - Representing a word object
 *
 */
void * buildTypeWord_Prompt(){
    Word *word = (Word *)calloc(1, sizeof(Word)); char temp[100];
    printf("Enter a word: ");
    fgets(temp, 100, stdin);
    strip(temp);
    word->ltrs = (char *)calloc(100, sizeof(char));
    strcpy(word->ltrs, temp);
    word->len = strlen(temp);
    return word;
}

/**
 * @brief Compares two objects of type word.
 *
 * Words are compared based on the letters (word)
 *
 * @note The passed in items will need to be cast to the appropriate word type.
 *
 * @param p1 - The void * representing an object of type word
 * @param p2 - The void * representing an object of type word
 * @return int - Representing order < 0 indicates p1 is less than p2,
 * > 0 indicates p1 is greater than p2 and == 0 indicates p1 == p2 for contents
 *
 * @warning - The passed in void * p1 is checked - exit(-99) if NULL
 * @warning - The passed in void * p2 is checked - exit(-99) if NULL
 */
int compareWords(const void * p1, const void * p2){
    if (p1 == NULL || p2 == NULL){
        exit(-99);
    }
    Word * w1 = (Word *)p1;
    Word * w2 = (Word *)p2;
    if (strcmp(w1->ltrs, w2->ltrs) < 0){
        return -1;
    }
    else return strcmp(w1->ltrs, w2->ltrs) > 0 ? 1 : 0;
}