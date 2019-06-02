#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char ft_cesar(char** input, int increment);
char ft_vigenere(char** phrase, char** increment);
char ft_vigenere_inverse(char** phrase, char** increment); 



int main (int argc, char** argv)
{
	char* 	phrase = malloc(sizeof(&phrase + 2) * 256);
	char*	phrase_vigenere = malloc(sizeof(&phrase_vigenere + 2) * 256); 
	int 	choix, clef_chiffre = 0, chiffre_1 = 0, chiffre_2 = 0;
	printf("Bievenue sur LiED, le but de ce programme est de chiffrer, et de déchiffrer un mot, une phrase, voire plusieurs. \n La liste des chiffrages sont : \n [1] Le Chiffrage César \n [2] Le Chiffrage de Vigenère \n [3] Le Chiffrage Affine \n [4] Le Chiffrage par Substitution \n [5] Le Chiffrage Atbash \n [6] Le Carré de Polybe \n [7] Le Chiffrage Morse \n [8] Les conversions \n	Il y a également : \n [9] Analyse Fréquentielle \n ");
	sleep(1);
	printf("\nVeuillez choisir une méthode de chiffrage ou lancer l'analyse fréquentielle : ");
	scanf("%d", &choix); 
	
	switch(choix)
		{
			case 1 :
				printf("Le César consiste à faire un décalage de la lettre vers la fin ou vers le début de l'alphabet en fonction de la valeur de décalage. \n Par exemple si l'on applique un decalage de 5 a la lettre 'B', en considérant que la position de 'A' = 0, alors 'B' = 1, donc 1 + 5 = 6. \n La lettre en position 6 est la lettre 'G'. \n De même, il est possible d'y appliquer une valeur negative a la valeur de décalage pour remonter vers le debut de l'alphabet : \n 'Z' = 25; appliquons un décalage de -5 et la lettre obtenue est la lettre 'U'. \n");
				sleep(1);
				printf("Tapez votre phrase : ");
				scanf("%s", &phrase);
				printf("\nTapez la valeur de décalage : ");
				scanf("%d", &clef_chiffre);
				printf(" \n ");
				ft_cesar(&phrase, clef_chiffre);
				break;
				
			case 2 :
				choix = 0;
				printf("infos vigenere....");
				sleep(1);
				while (choix != 1 || choix != 2)
				{
					printf("[1] Pour Chiffrer avec le Vigenère \n [2] Pour déchiffrer le Vigenère \n Choix : ");
					scanf("%d", &choix);
					if (choix == 1)
					{
						printf("Tapez votre phrase : ");
						scanf("%s", &phrase);
						printf("\nTapez votre clef de chiffrage : ");
						scanf("%s", &phrase_vigenere);
						printf(" \n ");
						ft_vigenere(&phrase, &phrase_vigenere);
						break;
					}
					else if (choix == 2)
					{
						printf("Tapez votre phrase : ");
						scanf("%s", &phrase);
						printf("\nTapez votre clef de déchiffrage : ");
						scanf("%s", &phrase_vigenere);
						printf(" \n ");
						ft_vigenere_inverse(&phrase, &phrase_vigenere);
						break;
					}
					else printf("\n IL faut rentrer [1] ou [2]");
				}
				break;

			case 3 :

			case 4 :

			case 5 :

			case 6 :

			case 7 : 

			case 8 : 

			case 9 : 

			default :
				printf("non");
		}
	return(0);
}	
