#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

char affine(char* clef, int chiffre_a, int chiffre_b)
	{	
		char alphabet[27]="abcdefghijklmnopqrstuvwxyz";
		int i=0, j=0, k=0, l=0;
		for (int min = 0; clef[min]; min++)
			{
				clef[min] = tolower(clef[min]);
			}
		if (chiffre_a == 2 || chiffre_a == 3 || chiffre_a == 5 || chiffre_a == 7 || chiffre_a == 11 ||  chiffre_a == 13 || chiffre_a == 17 || chiffre_a == 19 || chiffre_a == 23)
		{
		while(clef[j] != '\0')
		{
			k = 0;
			i = 0;
			if(alphabet[k] != clef[j])
				while(alphabet[k] != clef[j])
					{
						if(i > 26)
							i = 0;
						k++;
						i++;
					}
			i = ((chiffre_a * i) + chiffre_b);
			if (clef[j] >= 'a' && clef[j] <= 'z')
			{
				if (clef[j] + i >'z')
					clef[j] = i + clef[j] - 25;
				else	clef[j] = clef[j] + i;
				printf("%c", clef[j]);
			}
			else printf("%c", clef[j]);
			j++;
		}
		printf("\n");
		return(0);
		}
		else printf("le Chiffre A doit etre un nombre premier compris entre 2 et 23 pour que le programme fonctionne");
		return 0;
	}

int main(int argc, char** argv)
	{
		if ( argc != 4)
			printf("il faut rentrer trois valeurs, la clef, le nombre 1, et le nombre 2, \n");
		else 
			affine(argv[1], atoi(argv[2]), atoi(argv[3]));
		return(0);
	}
