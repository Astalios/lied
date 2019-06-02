#include <stdio.h>
#include <string.h>

int polybiusDecrypt(char input[], char output[])
	{
		char square[7][7] = {{'a','b','c','d','e'},
												 {'f','g','h','i','k'},
												 {'l','m','n','o','p'},
												 {'q','r','s','t','u'},
												 {'v','w','x','y','z'}};
		int a, b=0;

		for(a = 0; input[a] != '\0'; a + 3)
			{
				output[b] = square[input[a]][input[a+1]];
				b++;
			}
	}

int main(int argc, char *argv[])
	{
		char output[strlen(argv[1]+1)];
		polybiusDecrypt(argv[1], output);
		printf("%s\n", output);
		return 0;
	}

