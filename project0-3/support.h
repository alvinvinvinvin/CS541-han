/*
 * [Han Chen]
 * [2/10/2014]
 *
 * [Header of project0-3]
 */
#include <stdio.h>
#include <string.h> // For strlen
#include <stdlib.h> // For strtol and strtod
#include <ctype.h>  // For isdigit
#include <math.h>   // For fmod

/*
 * Max length of the buffer for fgets
 */
int LINELEN = 256;

/*
 * Process all of the instructions in the filename specified.
 *
 * Parameters:
 *   filename: Filename to process
 *
 * Returns:
 *   0 on success
 *  -1 if we cannot open the file
 */
int process_file(char *filename);
/*
 * Determine whether it is valid float number or not.
 *
 * Parameters:
 *   str: the array to traverse every single character to determine
 *
 * Returns:
 *   0 if it is not a valid number
 *   1 if it is a valid number
 */
int is_valid_float(char *str);
/*
 * Method of calculating in defferent operations.
 *
 * Parameters:
 *   num1: the first value in operation
 *   num2: the next value in operation
 *   op: the method of operation
 *
 * Returns:
 *   result if the operation is complete
 *  
 */
double calc(double num1, double num2, char op);
/*
 * function to determine whether the string is a valid operation or not.
 *
 * Parameters:
 *   str: the string to process
 *
 * Returns:
 *   '*' if it is a valid multiplying operation command;
 *   '+' if it is a valid addition operation command;
 *   '-' if it is a valid substraction operation command;
 *   '/' if it is a valid division operation command;
 *   '%' if it is a valid modulus operation command;
 *   '1' if the string does not begin with "op";
 *   '0' if the string begins with "op" but it is not a valid operation command;
 */
char is_op(char *str);
