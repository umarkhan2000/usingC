#include<stdio.h>
#include<stdlib.h>

void solveMagicSquare(int square[6][6])
{
 // This function receives an array of size 6x6
 // that corresponds to a magic square.
 // It then finds any entries with value -1
 // (which means they are not known),
 // and figures out what their value should
 // be to solve the magic square.
 //
 // Conditions:
 // You can not hard-code the value of the rows
 // and columns in the magic square - because
 // we will test this with a *different* magic
 // square than the one in this starter code
 //
 // Your function has to (somehow) figure out
 // what the sum of the rows and columns should be,
 // and then figure out for each entry whose
 // value is -1, what its value is to correctly
 // complete the magic square.
 //
 // This is about problem solving - you don't
 // need any fancy pointer management or anything
 // like that. Just plain old C with a 2D array
 // and a bit of thinking.
 //
 // As a reminder. 2D arrays in C are indexed as
 // array[i][j] - gives you the element at row i,
 // column j

 //////////////////////////////////////
 // TO DO: Complete this function
 //////////////////////////////////////
 
	int i, j, k, x, occur;
	int rowSum, colSum;
	
	int constant = 0;
	for (x=0; x<6; x++)
	{
		for (i=0; i<6; i++)
		{
			rowSum=0;
			colSum=0;
			occur=0;
			for (j=0; j<6; j++)
			{
				if(square[i][j] != -1)
				{
					rowSum = square[i][j] + rowSum; // calculating the sum of the current row
				} else if (square[i][j] == -1) // if -1 occurs in row add to occur
				{
					occur++;
					k = j;
				}
			}

			if (occur == 0){
				constant = rowSum;
			}
			if (occur == 1) // trying to check if the row only has one occur of -1 and then assigning its value
			{
				// value is basically 111 - the sum of the row calculated above divided by the occur
				square[i][k] = constant-rowSum;		
			} 

		}
	
		for (j=0; j<6; j++)
		{
			rowSum=0;
			colSum=0;
			occur=0;
			for (i=0; i<6; i++)
			{
				if(square[i][j] != -1)
				{
					colSum = square[i][j] + colSum; // sum of current column
				} else if (square[i][j] == -1) // if -1 occurs in row add to occur
				{
					occur++;
					k = i;	
				}
			}
			if (occur == 0){
				constant = colSum;
			}
		
			if (occur == 1) // trying to check if the row only has one occur of -1 and then assigning its value
			{
				// value is basically 111 - the sum of the row calculated above divided by the occur
				square[k][j] = constant-colSum;		
			} 
		}
	}	
}


// DO NOT MODIFY ANYTHING BELOW THIS LINE!
// (we mean it! the auto-checker won't be happy)
void printMagicSquare(int square[6][6])
{
   // Prints out the contents of a magic square 6x6

   int i,j,sum;

   for (i=0; i<6; i++)
   {
       sum=0;
       for (j=0; j<6; j++)
       {
           printf("%03d, ",square[i][j]);
           sum=sum+square[i][j];
       }
       printf(" : %03d\n",sum);
   }

   printf("---------------------------\n");

   for (j=0; j<6; j++)
   {
       sum=0;
       for (i=0; i<6; i++)
       {
	   sum=sum+square[i][j];
       }
       printf("%03d, ",sum);
   }
   printf("\n");
}

#ifndef __testing   // This is a compiler directive - used by the auto-checker to enable/disable this part of the code
int main()
{
    int magic[6][6]={{32,29,4,1,24,21},{30,-1,2,3,-1,23},{12,9,17,20,28,25},{10,11,18,-1,26,27},{13,-1,36,33,5,8},{14,15,34,35,6,-1}};

    printMagicSquare(magic);
    printf("Solving Magic Square!\n");
    solveMagicSquare(magic);
    printMagicSquare(magic);

    return 0;
}
#endif
