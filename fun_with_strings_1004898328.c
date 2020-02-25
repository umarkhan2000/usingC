#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void reverse_str(char text[])
{
	char result[strlen(text)];
	
	int begin, end, count;
	
	end = strlen(text) - 1;
	count = strlen(text);

	for(int begin = 0; begin < count; begin++)
	{
		result[begin] = text[end];
		end--;
	}
	
	for(int i = 0; i < strlen(result); i++)
	{
		text[i] = result[i];
	}	
}


void search_and_replace(char text[], char query, char target)
{	
	for(int i = 0; i < strlen(text); i++)
	{
		if (text[i] == query)
		{	
			text[i] = target;
		}
	}
}

int main()
{
	char str_text[32];
	
	strcpy(str_text, "Now I know how to program in C!\0");
	printf("%s \n", str_text);
	
	reverse_str(str_text);	
	printf("%s \n", str_text);
	
	
	search_and_replace(str_text, 'o', 'a');
	printf("%s \n", str_text);
	
	return 0;
}