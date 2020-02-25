// CSC A48 - Exercise 6 - Using black-listed keywords to reject SPAM

#include<stdio.h>
#include<stdlib.h>
// DO NOT ADD ANY EXTRA LIBRARIES

#define MAX_STR_LEN 1024
#define BLACK_LIST_SIZE 10

int get_length_query(char query[MAX_STR_LEN])
{
	int sum = 0;
	
	for(int i = 0; query[i] != '\0'; i++)
	{
		sum++;
	}
	return sum;
}

int get_length_source(char source_string[MAX_STR_LEN])
{
	int sum = 0;
	
	
	for(int i = 0; source_string[i] != '\0'; i++)
	{
		sum++;
	}
	
	return sum;
}

int find_substring(char source_string[MAX_STR_LEN], char query[MAX_STR_LEN])
{
   // This function determines whether a query string is present anywhere within
   // the source_string. If the query string is found, it returns 1, otherwise it
   // returns 0

   // TO DO: Implement this function!
   int result = 0;
   
   int length_query = get_length_query(query);
   int length_source = get_length_source(source_string);

   int temp1 = 0;
   int temp2 = 0;
   
  while(source_string[temp1] != '\0'){

    if(source_string[temp1] == query[0]){


       for(int m = 0; m<length_query;  m++){


          if(source_string[temp1 + m +1] == query[m+1]){

            temp2++;

          }
       }
    }
    temp1++;


  }

	if(temp2 == length_query -1 || temp2 == length_query){


		result = 1;

	}
   return result;		
}

int filter_message(char message_header[MAX_STR_LEN], char black_list[BLACK_LIST_SIZE][MAX_STR_LEN])
{
   // This function takes the header of an incoming email, and uses a black list to
   // determine whether to accept or reject the email. A message is rejected if any
   // of the black-listed keywords appear in the header.
   // The function returns 1 if the message should be rejected,
   //                      0 if the message should be accepted.

  // TO DO: Implement this function!
  
  int i = 0;
  int j = 0;
  int result = 0;

  for(i;i<10;i++){

    if(find_substring(message_header,black_list[i]) == 1){

        j++;
    }

  }

  if(j > 0){

    result = 1;
  }

 return result;
}

#ifndef __testing

int main()
{
    // Initialize black-list - normally, we'd read it from file but we haven't
    // done files in C yet! keep in mind we will  test your program on a different
    // black list, so test carefully!
    char black_list[BLACK_LIST_SIZE][MAX_STR_LEN]={"IMPORTANT",\
						   "ad",\
						   "online",\
						   "scam",\
						   "password",\
						   "account",\
						   "free",\
						   "profile",\
						   "dating",\
						   "prescription"
    };
    
    // Test our filter
    if (filter_message("This is a harmless email",black_list))
    {
        printf("Rejected!\n");
    }
    else
    {
        printf("Accepted\n");
    }

    if (filter_message("This is a scam! please send me to the inbox!",black_list))
    {
        printf("Rejected!\n");
    }
    else
    {
        printf("Accepted\n");
    }
    if (filter_message("How about some free online prescriptions?",black_list))
    {
        printf("Rejected!\n");
    }
    else
    {
        printf("Accepted\n");
    }
    if (filter_message("Give us your password!",black_list))
    {
        printf("Rejected!\n");
    }
    else
    {
        printf("Accepted\n");
    }
    if (filter_message("A48 assignment IMPORTANT! PLEASE READ! ",black_list))
    {
        printf("Rejected!\n");
    }
    else
    {
        printf("Accepted\n");
    }
    if (filter_message("Some funny pictures of cats",black_list))
    {
        printf("Rejected!\n");
    }
    else
    {
        printf("Accepted\n");
    }
    if (filter_message("Your bank account statement is ready",black_list))
    {
        printf("Rejected!\n");
    }
    else
    {
        printf("Accepted\n");
    }

    // Of course, any accepted messages would be passed on to an email system that keeps messages
    // organized using (you guessed it!) a linked list ;)

    return 0;
}
#endif