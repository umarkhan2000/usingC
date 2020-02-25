// CSC A48 - Exercise 7 - Caesar Cipher
// Complete where indicated below.
//
// Do not add any additional functions
// and do not leave any print statements
// in your final submission for testing!
//
// F. Estrada, Feb 2019.

#include<stdio.h>
#include<stdlib.h>

#define MAX_STR_LEN 2048

void caesar_cipher(unsigned char plaintext[MAX_STR_LEN], int displacement)
{
 // This function encodes the input text in plaintext[] using the caesar
 // cipher process with the specified displacement.
 //
 // The function must ensure that the 'end-of-string' delimiter is preserved,
 // and that no other character can become the 'end-of-string'. 
 // 
 // You want to make sure you understand what values can be stored in each
 // entry of the plaintext[] string, and you'll want to look at an ASCII table
 // to check that your function does the right thing.
 //
 // *** TEST your code with multiple input strings, and verify it works in 
 //     every case! if you get incomplete because your function failed our
 //     tests it means you did not test carefully enough.
 
 // TO DO: Implement this function
 
 int i = 0;
 

 
 while(plaintext[i] != '\0')
 {
	
	 if(plaintext[i] + displacement == (char)0)
	 {
		plaintext[i] += displacement + 1;
	 }
	 
	 plaintext[i] += displacement;	 
	 i++;
 }
    
}

void caesar_decipher(unsigned char cryptotext[MAX_STR_LEN],int displacement)
{
 // This function reverses the encryption process and returns the original
 // text given the encrypted string and the displacement used to encode it.
 // 
 // The function has the same constraints as 'caesar_cipher()', that is, it
 // must respect the 'end-of-string' delimiter, and ensure no other
 // character becomes 'end-of-string' after decoding.
 //
 // Be smart about how you implement this function!
    
 // TO DO: Implement this function
     int i = 0;
 
 while(cryptotext[i] != '\0')
 {
	 cryptotext[i] -= displacement;
	 i++;
 }
}

#ifndef __testing

int main()
{
    
    unsigned char a_passage[5][MAX_STR_LEN]={"When did A48 world begin and how? \n",
                                             "What's it all about and why? \n",
                                             "Where will the whole thing end, and when? \n",
                                             "And I copied all the answers too, \n",
                                             " --- Robert Clairmont\n"};
 
    printf("**** Original input text lines:\n\n");
    for (int i=0; i<5; i++)
        printf("%s",a_passage[i]);

    // Encode the input test lines
    caesar_cipher(&a_passage[0][0],15);
    caesar_cipher(&a_passage[1][0],122);
    caesar_cipher(&a_passage[2][0],-175);
    caesar_cipher(&a_passage[3][0],22);
    caesar_cipher(&a_passage[4][0],-17);

    printf("\n**** Encrypted text lines:\n\n");
    for (int i=0; i<5; i++)
        printf("%s",a_passage[i]);

    // Decode the encrypted strings
    caesar_decipher(&a_passage[0][0],15);
    caesar_decipher(&a_passage[1][0],122);
    caesar_decipher(&a_passage[2][0],-175);
    caesar_decipher(&a_passage[3][0],22);
    caesar_decipher(&a_passage[4][0],-17);

    printf("\n**** Decoded text lines (should be identical to original input!):\n\n");
    for (int i=0; i<5; i++)
        printf("%s",a_passage[i]);
    
    return 0;
    
}

#endif