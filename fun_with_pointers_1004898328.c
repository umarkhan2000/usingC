#include<stdio.h>
#define MAX_STR_LEN 2048

void stringLength(char *str, int *len)
{
 // This function computes the length of the string
 // at the address in the pointer *str. Once the length
 // has been determined, it updates the length
 // variable OUTSIDE this function whose address is
 // given by the pointer *len
 //
 // Note - the length can not be more than MAX_STR_LEN

 // TO DO:
 // Complete this function!
 // YOU ARE NOT ALLOWED TO USE FUNCTIONS FROM THE STRING LIBRARY
	int counter = 0;
	while(str[counter] != '\0')
	{
		counter++;
	}
	*len = counter;
}

void stringCopy(char *destStr, char *srcStr)
{
 // This function copies the contents of a string whose address
 // is given by the pointer *srcStr to the string whose address
 // is given by the pointer *destStr.
 // Note that the function should never try to copy more than
 // MAX_STR_LEN characters

 // TO DO:
 // Complete this function!
 // YOU ARE NOT ALLOWED TO USE FUNCTIONS IN THE STRING LIBRARY
 for(int i = 0; i < MAX_STR_LEN; i++)
 {
	 destStr[i] = srcStr[i];
 }
 
}

int main()
{
 char string1[MAX_STR_LEN]="To see a world in a grain of sand,";
 char string2[MAX_STR_LEN]="And a heaven in a wild flower.";
 int len1,len2;

 len1=0;
 len2=0;
 printf("%s\n",string1);
 printf("%s\n",string2);

 // DO NOT CHANGE ANYTHING ABOVE THIS LINE for main()
 // In the space below, complete the code for each step

 // 1 - Update len1 and len2 with the length of the
 //     corresponding strings (complete the stringLength()
 //     function for this!)
stringLength(string1, &len1);
stringLength(string2, &len2);


 // DO NOT CHANGE THE PRINT STATEMENTS BELOW
 printf("String 1 is %d characters long\n",len1);
 printf("String 2 is %d characters long\n",len2);

 // 2 - Copy string1 to string2 (after you do this, string2
 //     should contain 'To see a world in a grain of sand,'
 //     complete the function stringCopy() for this part
stringCopy(string2, string1);
 // DO NOT CHANGE ANYTHING BELOW THIS LINE
 printf("%s\n",string1);
 printf("%s\n",string2);

 return 0;

}
