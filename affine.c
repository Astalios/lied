#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
// principe du chiffrage affine : voir wikipedia et le site dcode pour plus d'informations. 
// le chiffrage affine necessite une phrase, et de deux chiffres, le premier sera le coefficient, et le deuxieme sera l'addition, 
//la est le principe du chiffrage affine.  
char ft_affine(char* clef, int coef, int ordonne)
	{	
		char alphabet[27]="abcdefghijklmnopqrstuvwxyz";
		int i, j=0;
		char l;
		for (int min = 0; clef[min]; ++min) // mise de la chaine de charactere en minuscules afin d'uniformiser la casse de la chaine de char.
			{
				clef[min] = tolower(clef[min]);
			}
		//if (chiffre_a == 1 || chiffre_a == 3 || chiffre_a == 5 || chiffre_a == 7 || chiffre_a == 11 ||  chiffre_a == 15 || chiffre_a == 17 || chiffre_a == 19 || chiffre_a == 21 || chiffre_a == 23 || chiffre_a == 25) // verification que le chiffre_a est premier avec 26, si il ne l'est pas il retourne une erreur.
		if(coef % 2 != 0 && coef % 13 != 0)
		{
			while(clef[j] != '\0')
			{
				i = 0;
				while (alphabet[i] != clef[j] && i < 26) // boucle de comptage de l'alphabet : a = 0 / z = 25
				{
					++i;
				}
				if(i < 26)
				{
					l = (char) (((coef * i + ordonne) % 26) + 'a');
					clef[j] = l;
				}
				printf("%c",clef[j]);
				++j;
			}
			printf("\n");
		}
		else
			printf("le Chiffre A doit etre un nombre premier avec 26 ( le nombre total de lettres dans l'alphabet francais et anglais, ");
		return (0);
	}
/* faible sécurisation du main, truc rapide pour compenser le mainLied défectueux.*/
int main(int argc, char** argv)
		{
		if ( argc != 4)
			printf("il faut rentrer trois valeurs, la clef, le nombre 1, et le nombre 2, \n");
		else 
			ft_affine(argv[1], atoi(argv[2]), atoi(argv[3]));
		return(0);
		}
