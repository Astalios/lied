#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
// le ft_cesar est simple, on lui injecte deux donnees, le texte en premier, et la valeur de decalage, positive ou negative, il gere les majuscules et les minuscules, 
// il gere si on met un nombre trop grand, au dessus de 26, puisque l'on fait le tour de l'alphabet, donc le modulo est de mise si cela arrive.

char ft_cesar(char input[], int increment)
{
	if (increment > 26 || increment < -26)
		increment = increment %= 26;
	for (int i = 0; input[i] != '\0'; i++)
	{
		if (input[i] >= 'A'  && input[i] <= 'Z')
		{
			if (input[i] + increment < 'A')
				input[i] = input[i] + 26 + increment;
			else if (input[i] + increment > 'Z')
				input[i] = input[i] - 26 + increment;
			else
				input[i] = input[i] + increment;
		}
		else if (input[i] >= 'a' && input[i] <= 'z')
		{
			if (input[i] + increment < 'a')
				input[i] = input[i] + 26 + increment;
			else if (input[i] + increment > 'z')
				input[i] = input[i] - 26 + increment;
			else
				input[i] = input[i] +  increment;
		}
		printf("%c", input[i]);
	}
	printf("\n");
	return(0);
}

// Creating main, protected to avoid segfaults and some basic mis-input ( more than two ) a simplifier, à faire : utiliser les ocmmandes de capture clavier, 
// premices de la CLI que j ai en tete la premiere condition ne fonctionne pas
int main(int argc, char** argv)
{
	if (argc > 3)
		printf("il ne faut rentrer que deux valeurs\n" /* ou tappez './cesar --help' pour plus d'informations."*/);
	else if ( argc < 3)
		printf("il faut rentrer deux valeurs\n" /*ou tappez './cesar --help' pour plus d'informations."*/);
	else	
		ft_cesar(argv[1], atoi(argv[2]));

	return(0);
}
