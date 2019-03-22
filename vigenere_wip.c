#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
// le ft_viegenere est simple, on lui injecte deux donnees, le texte en premier, et la valeur de decalage, positive ou negative, il gere les majuscules et les minuscules. 
// input : phrase / increment : clef de chiffrage
char	ft_vigenere(char input[] , char increment[])
	{
		char alphabet[53]="ABCDEFGHIJKLMOPQRSTUVWXYZabcdefghijklmopqrstuvwxyz";
		int m = strlen(alphabet);
		
		int len_input;
		len_input = strlen(input);
		
		char* sortie = malloc(sizeof(char)*strlen(input));

		int len_increment = 0;
		len_increment = strlen(increment);

		char a;
		char b;
		char c;

		int i;
		for ( i = 0; i <= len_input ; i++)
		{
			itoa(a, input[i], 10);
			itoa(b, increment[i % len_increment], 10);
			c = ( a + b) % m; 
			sortie[i] = (sortie[i-1] + atoi(c));
		}
		printf("%d", sortie);
	}

// Creating main, protected to avoid segfaults and some basic mis-input ( more than two ) a simplifier, à faire : utiliser les ocmmandes de capture clavier, 
// premices de la CLI que j ai en tete la premiere condition ne fonctionne pas
int	main(int argc, char** argv)
	{
		if (argc > 3)
			printf("il ne faut rentrer que deux valeurs \n" /* ou tappez './cesar --help' pour plus d'informations."*/);
		else if (argc < 3)
			printf("il faut rentrer deux valeurs \n" /*ou tappez './cesar --help' pour plus d'informations."*/);
		else	
			ft_vigenere(argv[1], argv[2]);
		return(0);
	}
