#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*Fonctionne en grande partie comme la substitution*/

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
								/*La taille de la clé (l'alphabet dans le plupart des cas) moins la
								position dans la clé permet de donner la position du caractère inverse dans la clé.
								Moins 1 pour le byte \0 qui termine la clé*/
								c = 1;
							}
						else if(tolower(cipher[a]) == key[b])
							{
								decipher[a] = toupper(key[len - b - 1]);
								c = 1;
							}
					}
				if (c == 0)
					{
						decipher[a] = cipher[a];
						c = 1;
					}
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
