#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

char ft_vigenere(char* phrase, char* increment)
	{	
		char alphabet[27]="abcdefghijklmnopqrstuvwxyz";
		int i=0, j=0, k=0, l=0;
		/*Mise tout au minuscule pour ne pas avoir de problèmes de calcul, optimisable pour faire deux en un ?*/
		for (int min = 0; increment[min]; min++)
			{
				increment[min] = tolower(increment[min]);
			}
		for (int min = 0; phrase[min]; min++)
			{
				phrase[min] = tolower(phrase[min]);
			}
		while(phrase[j] != '\0')
		{
			k = 0;
			i = 0;
			if(alphabet[k] != increment[l])
				while(alphabet[k] != increment[l])
					{
						if(i > 26)
							i = 0;
						k++;
						i++;
					}
			/* Ci dessus, comptage de la distance qui sépare la lettre du début de l'alphabet afin d'appliquer 'i' dans la formule ci dessous, et ensuite l'afficher, et passer au caractère suivant si aucun calcul est nécessaire*/
			if (phrase[j] >= 'a' && phrase[j] <= 'z')
			{
				if (phrase[j] + i >'z')
					phrase[j] = i + phrase[j] - 25;
				else	phrase[j] = phrase[j] + i;
				printf("%c", phrase[j]);
				l++;
				if(increment[l] == '\0')
					l = 0;
			}
			else printf("%c", phrase[j]);
			j++;
		}
		printf("\n");
		return(0);
	}

/*le ft_vigenere_inverse reprend exactement la même chose que le vigenère classique, mais, en changeant des signes dans la partie calculatoire afin d'en faire une soustraction et non une addition pour faire le déchiffrage du message. */
char ft_vigenere_inverse(char* phrase, char* increment)
	{	
		char alphabet[27]="abcdefghijklmnopqrstuvwxyz";
		int i=0, j=0, k=0, l=0;
		for (int min = 0; increment[min]; min++)
			{
				increment[min] = tolower(increment[min]);
			}
		for (int min = 0; phrase[min]; min++)
			{
				phrase[min] = tolower(phrase[min]);
			}
		while(phrase[j] != '\0')
		{
			k = 0;
			i = 0;
			if(alphabet[k] != increment[l])
				while(alphabet[k] != increment[l])
					{
						if(i > 26)
							i = 0;
						k++;
						i++;
					}
			if (phrase[j] >= 'a' && phrase[j] <= 'z')
			{
				if (phrase[j] - i <'a')
					phrase[j] = phrase[j] - i + 25;
				else	phrase[j] = phrase[j] - i;
				printf("%c", phrase[j]);
				l++;
				if(increment[l] == '\0')
					l = 0;
			}
			else printf("%c", phrase[j]);
			j++;
		}
		printf("\n");
		return(0);
	}

/*Main donnant choix au chiffrage ou déchiffrage du vigenère, faiblement sécurisé.*/
int main(int argc, char** argv)
	{
		int choix = 0;
		if ( argc != 3)
		printf("il faut renter deux valeurs,la phrase a chiffrer et la phrase qui sert de clef de chiffrage. \n");
		else 
		{
			//while (choix == 0) 
			printf("1 - Chiffrage \n 2 - Déchiffrage \n Votre choix :");
			scanf("%d", &choix);
			if (choix == 1)
				ft_vigenere(argv[1], argv[2]);
			else if (choix ==2)
				ft_vigenere_inverse(argv[1], argv[2]);
			else 
				printf("veuillez rentrer 1 ou 2");
		}
	}
