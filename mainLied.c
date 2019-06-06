#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char ft_cesar(char** input, int increment);
char ft_vigenere(char** phrase, char** increment);
char ft_vigenere_inverse(char** phrase, char** increment); 
char ft_affine(char** clef, int chiffre_a, int chiffre_b);
char substitution(char** cipher, char** key1, char** key2/*, char* decipher[]*/);

int main (int argc, char** argv)
{
	char* 	phrase = malloc(sizeof(&phrase + 2) * 256); //utilisé presque partout. 
	char*	phrase_2 = malloc(sizeof(&phrase_2 + 2) * 256); // utilisé pour clé avec des lettres, 2e phrase
	char*	phrase_3 = malloc(sizeof(&phrase_3 + 2) * 256); // utilisé substitution
	char* 	output = malloc(sizeof(&phrase + 1) * 256); // utilisé substitution
	char*	alphabet="abcdefghijklmnopqrstuvwxyz";
	int 	choix, clef_chiffre_1 = 0, clef_chiffre_2 = 0; // choix 
	printf("Bievenue sur LiED, le but de ce programme est de chiffrer, et de déchiffrer un mot, une phrase, voire plusieurs. \n La liste des chiffrages sont : \n [1] Le Chiffrage César \n [2] Le Chiffrage de Vigenère \n [3] Le Chiffrage Affine \n [4] Le Chiffrage par Substitution \n [5] Le Chiffrage Atbash \n [6] Le Carré de Polybe \n [7] Les conversions \n	Il y a également : \n [8] Analyse Fréquentielle \n ");
	sleep(1);
	printf("\nVeuillez choisir une méthode de chiffrage ou lancer l'analyse fréquentielle : ");
	scanf("%d", &choix); 
	
	switch(choix)
		{
			case 1 : // CESAR
				printf("Le César consiste à faire un décalage de la lettre vers la fin ou vers le début de l'alphabet en fonction de la valeur de décalage. \n Par exemple si l'on applique un decalage de 5 a la lettre 'B', en considérant que la position de 'A' = 0, alors 'B' = 1, donc 1 + 5 = 6. \n La lettre en position 6 est la lettre 'G'. \n De même, il est possible d'y appliquer une valeur negative a la valeur de décalage pour remonter vers le debut de l'alphabet : \n 'Z' = 25; appliquons un décalage de -5 et la lettre obtenue est la lettre 'U'. \n");
				sleep(1);
				printf("Tapez votre phrase : ");
				scanf("%s", &phrase);
				printf("\nTapez la valeur de décalage : ");
				scanf("%d", &clef_chiffre_1);
				printf(" \n ");
				ft_cesar(&phrase, clef_chiffre_1);
				break;
				
			case 2 : // VIGENERE
				choix = 0;
				printf("Le Chiffrage de Vigenère   ");
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
						scanf("%s", &phrase_2);
						printf(" \n ");
						ft_vigenere(&phrase, &phrase_2);
						break;
					}
					else if (choix == 2)
					{
						printf("Tapez votre phrase : ");
						scanf("%s", &phrase);
						printf("\nTapez votre clef de déchiffrage : ");
						scanf("%s", &phrase_2);
						printf(" \n ");
						ft_vigenere_inverse(&phrase, &phrase_2);
						break;
					}
					else printf("\n IL faut rentrer [1] ou [2]");
				}
				break;

			case 3 : // AFFINE
				printf("Infos affine \n");
				sleep(1);
				printf("Tapez votre phrase : ");
				scanf("%s", &phrase);
				printf("\nTapez le premier chiffre, il doit être égal à l'un des nombres premiers a 26 suivants  : \n 1, 3, 7, 11, 15, 17, 19, 21, 23 ou 25 : ");
				scanf("%d", &clef_chiffre_1);
				printf("\n Tapez le deuxième chiffre : ");
				scanf("%d", &clef_chiffre_2);
				ft_affine(&phrase, clef_chiffre_1, clef_chiffre_2);
				break;

			case 4 : // SUBSTITUTION
				choix = 0; 
				printf("Le Chiffrement par substitution consiste à remplacer systématiquemetn dans un texte un signe donné par un autre signe. On utilise donc deux clés de même taille, et on remplace dans le texte les caractères d'une clé par leur équivalent de l'autre clé.\n Notons que le code peux être déchiffré soit par une application de l'analyse fréquentielle ou soit en appliquant la clef de chiffrage pour déchiffrer la phrase.\n");
				sleep(1);
				printf("Veuillez rentrer la phrase à Chiffrer : ");
				scanf("%s", &phrase);
				printf("\nVeuillez rentrer la première clef : ");
				scanf("%s", &phrase_2);
				printf("\nVoulez rentrer la deuxième clef de chiffrage ? \n [1] = oui, [2] = non. ");
				while (choix != 1 || choix != 2)
				{
					scanf("%d", &choix);
					if (choix == 1)
						{
							printf("\nVeuillez rentrer la deuxième clef : ");
							scanf("%s", &phrase_3);
							printf("ça marche ici avant fonction \n ");
							substitution(&phrase, &phrase_2, &phrase_3/*, &output*/);
							printf("ça marche ici après fonction \n ");
							break;
						}
					else if (choix == 2)
					{
							printf("ça marche ici avant fonction \n ");

							substitution(&phrase, &phrase_2, &alphabet/*, &output*/);
							printf("ça marche ici apres fonction \n ");

						break;
					}
					else printf("\n Il faut rentrer [1] = oui ou [2] = non.");
				}
				printf("test ici pour voir \n");
				//printf("%s\n", &output_2);
				break;
			case 5 : // ATBASH

			case 6 : // POLYBE

			case 7 : // CONVERSIONS


			case 8 : // ANALYSE FREQUENTIELLE

			default :
				printf("non");
		}
	return(0);
}	
