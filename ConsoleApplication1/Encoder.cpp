/**Assessment for AG Leader | Alphanumeric Encoder program

  @Company
	AG Leader

  @File Name
	Encoder.c

  @Date Created
	10/24/21

  @Written by
	Edward Arteaga
 *
  @Summary
 * This is a program that will encode alphanumeric characters to unique cyrillic 
 * characters. This will also provide the decoding table after the encoding completes.
 
  @Description
 * This program is composed of an AVL tree to allow for faster iteration when encoding 
 * an alphanumeric entry. If anything other than an alphanumeric entry is inputted by the 
 * user, it will not convert it. The program first populates the tree with the decoded / encoded
 * pairs. Next, it asks the user for entry. It then encodes the entry using the tree 
 * and outputs the encoded result. Finally, it will output the complete decoding table for 
 * the user's reference. 
 */
 /* ************************************************************************** */


/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#include <iostream>
#include <fcntl.h>
#include <io.h>
#include "Header.h"

/******************************************************************************/
/* Define Statements                                                           */
/******************************************************************************/

#define MAX_INPUT_LEN 256

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

//parameterized contructor
node* newNode(char deco, wchar_t enco) {
	//a single node tree is created and returned
	node* root = new node();
	root->decoded = deco;
	root->encoded = enco;
	root->height = 1;//leaf height
	root->Left = NULL;
	root->Right = NULL;
	
	return(root);
}

//function to insert node into tree 
node* insert(node* root, char deco, wchar_t enco) {
	if (root == NULL) {
		return (newNode(deco, enco));
	}

	if (deco < root->decoded)
		root->Left = insert(root->Left, deco, enco);
	else if (deco > root->decoded)
		root->Right = insert(root->Right, deco, enco);
	else
		return root;

	root->height = Max(Height(root->Left), Height(root->Right)) + 1;

	int balance = getBalance(root);

	if (balance > 1 && deco < root->Left->decoded)
		return singleRotationRight(root);
	if (balance < -1 && deco > root->Right->decoded)
		return singleRotationLeft(root);
	if (balance > 1 && deco > root->Left->decoded) {
		root->Left = singleRotationLeft(root->Left);
		return singleRotationRight(root);
	}
	if (balance < -1 && deco < root->Right->decoded) {
		root->Right = singleRotationRight(root->Right);
		return singleRotationLeft(root);
	}

	return root;
}

//function to perform a rotation between a n1 node and its right child (only called if n1->Right exists)
node* singleRotationRight(node* n1) {
	node* n2 = n1->Left;
	node* p2 = n2->Right;

	n2->Right = n1;
	n1->Left = p2;

	n1->height = Max(Height(n1->Left), Height(n1->Right)) + 1;
	n2->height = Max(Height(n2->Left), Height(n2->Right)) + 1;

	return n2;
}

//function to perform a rotation between a n2 node and its left child (only called if n2->Left exists)
node* singleRotationLeft(node* n2) {
	node* n1 = n2->Right;
	node* p2 = n1->Left;

	n1->Left = n2;
	n2->Right = p2;

	n2->height = Max(Height(n2->Left), Height(n2->Right)) + 1;
	n1->height = Max(Height(n1->Left), Height(n1->Right)) + 1;

	return n1;
}

//function that returns the greater value of 2 characters
int Max(int Left, int Right) {
	return Left > Right ? Left : Right;
}

//function to return node's height
int Height(node* root) {
	if (root == NULL)
		return 0l;
	else
		return root->height;
}

//Get balance of N
int getBalance(node *N) {
	if (N == NULL)
		return 0;
	return Height(N->Left) - Height(N->Right);
}

//function to encode characters
wchar_t findEncode(node* root, char deco) {
	if (root == NULL)
		return NULL;
	if (deco < root->decoded)
		return findEncode(root->Left, deco);
	else if (deco > root->decoded)
		return findEncode(root->Right, deco);
	else
		return root->encoded;
}

//free all memory used by AVL tree
void freeTree(node* root) {
	if (root != NULL) {
		freeTree(root->Left);
		freeTree(root->Right);
		free(root);
	}
}

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/
int main() {
	node *root = NULL;//create new tree
	//populate a tree containing the cyrillic symbols
	root = insert(root, 'a', L'\u0401');
	root = insert(root, 'b', L'\u0402');
	root = insert(root, 'c', L'\u0403');
	root = insert(root, 'd', L'\u0404');
	root = insert(root, 'e', L'\u0409');
	root = insert(root, 'f', L'\u0413');
	root = insert(root, 'g', L'\u0411');
	root = insert(root, 'h', L'\u0416');
	root = insert(root, 'i', L'\u20A4');
	root = insert(root, 'j', L'\u0417');
	root = insert(root, 'k', L'\u0419');
	root = insert(root, 'l', L'\u041B');
	root = insert(root, 'm', L'\u0424');
	root = insert(root, 'n', L'\u0426');
	root = insert(root, 'o', L'\u042A');
	root = insert(root, 'p', L'\u042B');
	root = insert(root, 'q', L'\u042D');
	root = insert(root, 'r', L'\u042E');
	root = insert(root, 's', L'\u042F');
	root = insert(root, 't', L'\u0386');
	root = insert(root, 'u', L'\u0434');
	root = insert(root, 'v', L'\u0451');
	root = insert(root, 'w', L'\u0452');
	root = insert(root, 'x', L'\u0453');
	root = insert(root, 'y', L'\u0454');
	root = insert(root, 'z', L'\u0459');
	root = insert(root, 'A', L'\u045A');
	root = insert(root, 'B', L'\u045B');
	root = insert(root, 'C', L'\u045C');
	root = insert(root, 'D', L'\u045D');
	root = insert(root, 'E', L'\u045E');
	root = insert(root, 'F', L'\u045F');
	root = insert(root, 'G', L'\u0126');
	root = insert(root, 'H', L'\u0152');
	root = insert(root, 'I', L'\u0388');
	root = insert(root, 'J', L'\u03B8');
	root = insert(root, 'K', L'\u03BB');
	root = insert(root, 'L', L'\u03BC');
	root = insert(root, 'M', L'\u03BE');
	root = insert(root, 'N', L'\u03C2');
	root = insert(root, 'O', L'\u0218');
	root = insert(root, 'P', L'\u021A');
	root = insert(root, 'Q', L'\u0110');
	root = insert(root, 'R', L'\u00DE');
	root = insert(root, 'S', L'\u00E6');
	root = insert(root, 'T', L'\u0111');
	root = insert(root, 'U', L'\u0118');
	root = insert(root, 'V', L'\u011D');
	root = insert(root, 'W', L'\u0167');
	root = insert(root, 'X', L'\u01C2');
	root = insert(root, 'Y', L'\u0259');
	root = insert(root, 'Z', L'\u025A');
	root = insert(root, '0', L'\u025E');
	root = insert(root, '1', L'\u025F');
	root = insert(root, '2', L'\u0260');
	root = insert(root, '3', L'\u0263');
	root = insert(root, '4', L'\u0268');
	root = insert(root, '5', L'\u0294');
	root = insert(root, '6', L'\u0295');
	root = insert(root, '7', L'\u02A4');
	root = insert(root, '8', L'\u02A1');
	root = insert(root, '9', L'\u02A2');

	char inputSeq[MAX_INPUT_LEN] = {}; //user input will be stored here

	//ask user for input to be encoded
	std::cout << "Enter an arbitrary sequence of alphanumeric characters (only alphanumeric characters will be converted):\n";
	std::cin.getline(inputSeq, MAX_INPUT_LEN);

	//change output mode so cyrillic characters are displayed
	int result;
	result = _setmode(_fileno(stdout), _O_U16TEXT);
	if (result == -1)
		perror("Cannot set mode");

	//encode the user's input & print the encoding
	int i = 0;
	while (inputSeq[i] != '\0') {
		if (iswalnum(inputSeq[i]))
			wprintf(L"%c", findEncode(root, inputSeq[i]));
		else
			wprintf(L"%c", inputSeq[i]);
		i++;
	}

	//display the decoding table
	wprintf(L"\n\n\u058D\u058D\u058D\u058D\u058D\u058D\u058D\u058D\u058D\u058D\u058D\u058D\u058D\u058D\u058D\u058D\u058D\u058D\u058D\u058D\u058D\u058D\u058D\u058D DECODING TABLE \u058D\u058D\u058D\u058D\u058D\u058D\u058D\u058D\u058D\u058D\u058D\u058D\u058D\u058D\u058D\u058D\u058D\u058D\u058D\u058D\u058D\u058D\u058D\u058D\n");
	wprintf(L"\u250C\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2510\n");
	wprintf(L"| a = \u0401 | b = \u0402 | c = \u0403 | d = \u0404 | e = \u0409 | f = \u0413 | g = \u0411 | h = \u0416 |\n");
	wprintf(L"| i = \u20A4 | j = \u0417 | k = \u0419 | l = \u041B | m = \u0424 | n = \u0426 | o = \u042A | p = \u042B |\n");
	wprintf(L"| q = \u042D | r = \u042E | s = \u042F | t = \u0386 | u = \u0434 | v = \u0451 | w = \u0452 | x = \u0453 |\n");
	wprintf(L"| y = \u0454 | z = \u0459 | A = \u045A | B = \u045B | C = \u045C | D = \u045D | E = \u045E | F = \u045F |\n");
	wprintf(L"| G = \u0126 | H = \u0152 | I = \u0388 | J = \u03B8 | K = \u03BB | L = \u03BC | M = \u03BE | N = \u03C2 |\n");
	wprintf(L"| O = \u0218 | P = \u021A | Q = \u0110 | R = \u00DE | S = \u00E6 | T = \u0111 | U = \u0118 | V = \u011D |\n");
	wprintf(L"| W = \u0167 | X = \u01C2 | Y = \u0259 | Z = \u025A | 0 = \u025E | 1 = \u025F | 2 = \u0260 | 3 = \u0263 |\n");
	wprintf(L"| 4 = \u0268 | 5 = \u0294 | 6 = \u0295 | 7 = \u02A4 | 8 = \u02A1 | 9 = \u02A2 |               |\n");
	wprintf(L"\u2514\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2518\n");

	freeTree(root);//free memory
	return 0;
}
/******************************************************************************
	End of File
*/