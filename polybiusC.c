#include <stdio.h>
#include <string.h>
#include <ctype.h>

int polybiusC(char input[], char output[])
	{
		char square[6][6] = {"abcde","fghik","lmnop","qrstu","vwxyz"};
		int a, b, c, d;

		for (a=0; input[a] != 0; a++)
			{
				d = 0;
				for (b=0; b < 6 && d == 0; b++)
					{
						for (c=0; c < 6 && d == 0; c++)
							{
								if (input[a] == square[b][c] || tolower(input[a]) == square[b][c])
									{
										output[a*3] = b + '0' + 1;
										output[a*3+1] = c + '0' +1;
										output[a*3+2] = ' ';
										d++;
									}
							}
					}
			}

		output[a*3+1] = '\0';
	}

int main(int argc, char *argv[])
	{
		int a, b=0;
		for (a=0; argv[1][a] != 0; a++)
			{
				if (!((argv[1][a] >= 'a' && argv[1][a] <= 'z') || (argv[1][a] >= 'A' && argv[1][a] <= 'Z')))
					{
						b = 1;
					}
			}

		if (argc == 2 && b == 0)
			{
				char output[strlen(argv[1])*3+1];
				polybiusC(argv[1], output);
				printf("%s\n", output);
				return 0;
			}
		else
			{
				printf("Wrong input !\n");
				return 1;
			}
	}

