#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int polybiusDecrypt(char input[], char output[])
	{
		char square[6][6] = {{'a','b','c','d','e'},
												 {'f','g','h','i','k'},
												 {'l','m','n','o','p'},
												 {'q','r','s','t','u'},
												 {'v','w','x','y','z'}};
		int len = strlen(input);
		int a, b;

		for(a=0, b=0; a < len; a=a+3, b++)
			{
				output[b] = square[input[a]-'0'-1][input[a+1]-'0'-1];
			}
	}

int main(int argc, char *argv[])
	{
		char output[strlen(argv[1]+1)];
		polybiusDecrypt(argv[1], output);
		printf("%s\n", output);
		return 0;
	}

