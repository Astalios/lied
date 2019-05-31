#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char atbash(char cipher[], char key[27], char decipher[])
	{
		int a, b, c;
		int len = strlen(key);

		for (a=0; cipher[a] != '\0'; a++)
			{
				c = 0;
				for (b=0; key[b]!= '\0' && c == 0; b++)
					{
						if (cipher[a] == key[b])
							{
								decipher[a] = key[len - b - 1];
								c = 1;
							}
						/*if (tolower(cipher[a]) == key[b])
							{
								decipher[a] == toupper(key[b]);
							}*/
					}
				/*if (c = 0)
					{
						decipher[a] == cipher[a];
					}*/
			}
		decipher[a] = '\0';
	}

int main(int argc, char *argv[])
	{
		if(argc == 2)
			{
				char output[strlen(argv[1])+1];
				atbash(argv[1], "abcdefghijklmnopqrstuvwxyz", output);
				printf("%s\n", output);
				return 0;
			}
		else if(argc == 3)
			{
				char output[strlen(argv[1])+1];
				atbash(argv[1], argv[2], output);
				printf("%s\n", output);
				return 0;
			}
		else
			{
				printf("Wrong input !\n");
				return 1;
			}
	}
