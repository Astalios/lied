#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char atbash(char cipher[], char key[27], char decipher[])
	{
		int a, b;
		int len = strlen(key);

		for (a=0; cipher[a] != '\0'; a++)
			{
				for (b=0; key[b] != '\0'; b++)
					{
						if (cipher[a] == key[b])
							{
								decipher[a] = key[len - b - 1];
							}
						/*if (tolower(cipher[a]) == key[b])
							{
								decipher[a] == toupper(key[b]);
							}*/
					}
				/*if (cipher[a] == '\0')
					{
						decipher[a] == cipher[a];
					}*/
			}
	}

int main(int argc, char *argv[])
	{
		char output[strlen(argv[1])+1];

		atbash(argv[1], "abcdefghijklmnopqrstuvwxyz", output);
		printf("%s\n", output);
		return 0;
	}
