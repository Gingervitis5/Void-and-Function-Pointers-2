/**
 * @file utils.h
 * The utils.h defines the basic menu and strip functions that will be
 * required during the course of the quarter.
 */

#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100


/**
 * @brief Prompts the user for a menu choice.
 *
 * Prompts the user for a menu choice and ensures the value
 * entered by the user is within range.
 *
 * @note The carriage return is removed from the input buffer
 *
 * @return int - Representing the menu choice
 */
int menu();

/**
 * @brief Strinps the \r and \n from the string if they exist.
 *
 * Walks through the character array one character at a time
 * if a '\r' or '\n' are encountered it is changed to a '\0'
 * entered by the user is within range.
 *
 * @param The character array potentially containing a '\r' and/or '\n'
 *
 * @warning - The passed in pointer is checked - exit(-99) if NULL
 */
void strip(char *array);


/**
 * readIndex reads an index from the keyboard and ensures it
 * is between 0 and the total - 1.
 *
 * @param int Representing the total size
 * @return int - Representing the index
 *
 * @warning ensures the carriage return is removed from stdin
 */
int readIndex(int total);

#endif
