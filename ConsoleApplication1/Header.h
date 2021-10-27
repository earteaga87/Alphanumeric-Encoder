#pragma once
#ifndef FUNCTIONS_H
#define	FUNCTIONS_h

/**Assessment for AG Leader | Alphanumeric Encoder program

  @Company
	AG Leader

  @File Name
	Header.c

  @Date Created
	10/24/21

  @Written by
	Edward Arteaga
 *
  @Summary
 * This is the header file that includes the function declarations and class definitions
 * for the Alphanumeric Encoder program (Encoder.c).

  @Description
 *
 */
 /* ************************************************************************** */


/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#include <stdint.h>

/******************************************************************************/
/* Class Definitions                                                          */
/******************************************************************************/

class node {
public:
	char decoded;
	wchar_t encoded;
	int height;
	node* Left;
	node* Right;
};

/******************************************************************************/
/* Function Declarations                                                      */
/******************************************************************************/

node* newNode(char, wchar_t);//parameterized constructor
node* insert(node*, char, wchar_t);//function to insert node into tree 
static node* singleRotationRight(node*);//function to perform a rotation between a n1 node and its right child (only called if n1->Right exists)
static node* singleRotationLeft(node*);//function to perform a rotation between a n2 node and its left child (only called if n2->Left exists)
void freeTree(node*); //function to free all memory used by AVL tree
wchar_t findEncode(node*, char);//function to encode characters
int Height(node*);//function to return node's height
int getBalance(node*);//get balance of N
int Max(int, int);//function that returns the greater value of 2 integers 


#endif
/* *****************************************************************************
     End of File
    */
