// CSC A48 - Exercise 8 - Caesar Cipher Breaker
// Complete where indicated below.
//
// Do not add any additional functions
// and do not leave any print statements
// in your final submission for testing!
//
// (c) F. Estrada, Mar. 2019.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// Do not include any extra libraries!

#define MAX_STR_LEN 2048

void caesar_break(unsigned char message[5][MAX_STR_LEN])
{
  /*
   * This function takes in a message (of 5 lines of text, no more no less)
   * that has been encoded using a correct implementation of the caesar
   * cipher from Exercise 7.
   * The function must decode the message and restore the original text.
   *
   * You do not know the displacement used to encode the message
   * But you do know it's from Marzieh and Paco, so it probably says
   * something about A48
   *
   * The goal of this exercise is to get you to think hard, about the
   * problem, about what needs to be done to solve it, and about
   * different ways you could try to do this. So, if it seems
   * challenging - that's exactly how it should feel :). You're exercising
   * and this is a tough uphill.
   *
   * To help you a bit:
   * - You can re-use code from previous exercises you've solved
   *   (at the very least, you will need a caesar_decipher() function
   *    at some point, but maybe code from other exercises could help?)
   * - You don't have to worry about complexity (but it shouldn't take
   *   mode than a few seconds to run your code)
   *
   * You can solve this if you sit down and consider the problem, think
   * about how caesar cipher works, and what you need to do to break it,
   * as well as how to figure out you broke it.
   *
   * It's problem solving, so please don't ask on Piazza for someone to
   * confirm things for you. It's your task, see to it, make reasonable
   * assumptions, and see my Piazza post on problem solving if you
   * need a reminder of what should be in your mind as you work on this.
   */

  /*** TO DO:
   * Implement this function to decode secret messages!
   */

 int m=0,final=0;


 for(int displacement=1;displacement<256;displacement++){


    for(int i=0;i<5;i++){


        for(int j=0;message[i][j]!='\0';j++){


            if(j-2>=0 && ((message[i][j-2]-displacement)=='A' || (message[i][j-2]-displacement)== 'a')  && (message[i][j-1]-displacement)=='4' && (message[i][j]-displacement)== '8'){


                final =1;
                m=displacement;
                break;



            }else if(j-2>=0 && (message[i][j-2]-displacement)=='B' && (message[i][j-1]-displacement)=='i' && (message[i][j]-displacement)== 'g'){


               final =1;
               m=displacement;
               break;


            }else if(j-2>=0 && (message[i][j-2]-displacement)=='B' && (message[i][j-1]-displacement)=='i' && (message[i][j]-displacement)== 'g'){

               final= 1;
               m=displacement;
               break;


            }else if(j-3>=0 && (message[i][j-3]-displacement)=='c' && (message[i][j-2]-displacement)=='o' && (message[i][j-1]-displacement)== 'm' && (message[i][j]-displacement)=='p'){

               final=1;
               m=displacement;
               break;


            }else if(j-2>=0 && (message[i][j-2]-displacement)=='B' && (message[i][j-1]-displacement)=='S' && (message[i][j]-displacement)== 'T'){


               final =1;
               m=displacement;
               break;


            }else if(j-3>=0 && (message[i][j-3]-displacement)=='q' && (message[i][j-2]-displacement)=='u' && (message[i][j-1]-displacement)== 'i' && (message[i][j]-displacement)=='z'){

              final=1;
              m=displacement;
              break;


            }else if(j- 9 >= 0 && (message[i][j - 9] - displacement) == 'a' && (message[i][j - 8] - displacement) == 's' && (message[i][j - 7] - displacement) == 's' && (message[i][j - 6] - displacement) == 'i' && (message[i][j - 5] - displacement) == 'g' && (message[i][j - 4] - displacement) == 'n' && (message[i][j - 3] - displacement) == 'm' && (message[i][j - 2] - displacement) == 'e' && (message[i][j - 1] - \
               displacement) == 'n' && (message[i][j] - displacement) == 't'){


                  final =1;
                  m=displacement;
                  break;
                }


            if(final==1) break;

        }


        if(final==1) break;



    }


    if(final==1) break;


 }

for(int i=0;i<5;i++){

    for(int j=0;message[i][j] != '\0';j++){


        if((char)(message[i][j] + m) != '\0'){

            message[i][j] = message[i][j] -m;
        }else{

           message[i][j] = message[i][j];


        }


    }




}

}



#ifndef __testing

int main()
{
    unsigned char the_message[5][MAX_STR_LEN]={"Wklv#zhhn#lq#D7;#zh#fryhu#EVW#lpsohphqwdwlrq",
					       "Gr#qrw#irujhw#wr#frpsohwh#|rxu#zhhno|#h{huflvh",
					       "Wkh#txl}#zloo#eh#rq#frpsxwdwlrqdo#frpsoh{lw|",
					       "Vr#gr#qrw#irujhw#Elj#R",
					       "Dqg#vwduw#hduo|#rq#|rxu#dvvljqphqw#5"};

    printf("\n**** Encrypted text lines:\n\n");
    for (int i=0; i<5; i++)
        printf("%s\n",the_message[i]);

    caesar_break(the_message);

    printf("\n**** Decoded text lines (should show the original message!):\n\n");
    for (int i=0; i<5; i++)
        printf("%s\n",the_message[i]);

    return 0;
}

#endif
