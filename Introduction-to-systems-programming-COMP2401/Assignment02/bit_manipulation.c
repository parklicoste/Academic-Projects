
/*

File bit_manipulation.c

Purpose :
contains helper functions for manipulating bits


Revisions:
file created: Doron Nussbaum

* /

/************************************************************************/

// INCLUDE FILES

#include "bit_manipulation.h"


/************************************************************************/
//MACROS  / DEFINES


/************************************************************************/
// FUNCTION PROTOTYPES









/*************************************************************************************/
/* purpose: perform circular rotation to the left by numBits

input:
c - the character to be checked
numBits - how many bits need to be rotated

return:
none

*/

void rotateLeft( char *c, int numBits)

{
   // add code 
    *c = *c >> (8-numBits) | *c << numBits;

}



/*************************************************************************************/
/* purpose: perform circular rotation to the right by numBits

input:
c - the character to be checked
numBits - how many bits need to be rotated

return:
none

*/

void rotateRight(char *c, int numBits)

{
    // add code 
    *c = *c>>numBits|*c<<(8-numBits);


}

/*************************************************************************************/

/* purpose: translate the value of by a certain amount

input:
c - the character
key - is the key for the encryption
index - is the index of the character in the array

output:
c - the character

return:
None

Description:
This function translate the value of c by a computed amount.  
The translate can be by adding "amount" to c.

The amount is computed using the the key, the index, and the 
value of *c.
the formula is
 the value of the character + (57 * index + key)

Example 1:
Assume that *c is 65 (0x41), key is 87 and index is 1.

65 + 57 * 1 + 87.


*/
void translateChar(char *c, char key, int index)

{
   /* int p = key;
    int x = 0;
    x = p % 16;
    p /= 16;
    p = p * 10 + x;*/
    char shift_amount = 57*index + key;
    *c = *c + shift_amount;
     if(*c >255)
        *c -= 255;
	// add code 
}



/*************************************************************************************/

/* purpose: rev the translate the value of by a certain amount

Description:
This function translate the value of c by a computed amount.
The translate can be by adding "amount" to c.

The amount is computed using the the key, the index, and the
value of *c.
the formula is
the value of the character - (57 * index + key)

Example 1:
Assume that *c is 65 (0x41), key is 87 and index is 1.  

65 - (57 * 1 + 87).


*/
void revTranslateChar(char *c, char key, int index)

{
   /* int p = key;
    int x = 0;
    x = p % 16;
    p /= 16;
    p = p * 10 + x;*/
    int shift_amount = 57*index + key;
    *c = *c - shift_amount;
     if(*c < 0)
        *c *= -1;

	// add code 


}





/*************************************************************************************/


/*  count the number of bits in a short

input: 
num - a short integer

return
the number of bits that are set to 1 in num



*/
int countBits(char c)

{
    int total = 0;
    for(int i=0;i<8;i++)
    {   
        if ( (c >> i) & 1)
            total++;
    }
    return total; // add code
    
}






/*************************************************************************************/


/* Purpose: encrypt a character

input: 
*c - the character to encrypt
key - the encryption key
index - the index of the character in the array

output:
*c - the encrypted character

return
0 



*/
int encryptChar(char *c, char key, int index)

{

	int numBits = 0;
    int no_of_Bits = countBits(*c);
	numBits = (index + no_of_Bits) % 8;
    translateChar(c, key, index);// translate the character 
	if(no_of_Bits % 2 == 0)// perform circular rotation of the char
        rotateLeft(c,numBits);
    else
        rotateRight(c,numBits);
    
	// xor the char
    *c = *c^key;
	return(0);
    
    
}


/*************************************************************************************/


/* Purpose: decrypt a character

input:
*c - the character to encrypt
key - the encryption key
index - the index of the character in the array

output:
*c - the encrypted character

return
0



*/
int decryptChar(char *c, char key, int index)

{

	int numBits = 0;
	*c = *c^key;// xor the char

    numBits = (index + countBits(*c)) % 8;

    if(countBits(*c) % 2 == 0)// performf circular rotation of the char
        rotateRight(c,numBits);
    else
        rotateLeft(c,numBits);	// perform circular rotation of the char

       revTranslateChar(c,key,index);	// translate the character 

	return(0);


}







