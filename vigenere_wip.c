#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
// le ft_viegenere est simple, on lui injecte deux donnees, le texte en premier, et la valeur de decalage, positive ou negative, il gere les majuscules et les minuscules. 
char	ft_vigenere(char input[] , char increment[])
	{
		int j=0;
		int i=0;
		for (int k = 0; increment[k]; k++) 
			{
			increment[k] = tolower(increment[k]);
			}
		while ((increment[j] >= 'A' && increment[j] <= 'Z') || (increment[j] >= 'a' && increment[j] <= 'z' ) && input[j] != '\0')
		{
			for (i = 0; input[i] != '\0'; i++)
			{
				if (input[i] >= 'A'  && input[i] <= 'Z')
				{
					if (input[i] + increment[j] < 'A')
						input[i] = (((input[i] + 25 + increment[j]) % 26) + 65);
					else if (input[i] + increment[j] > 'Z')
						input[i] = (((input[i] - 25 + increment[j]) % 26) + 65);
					else input[i] = (((input[i] + increment[j]) % 26) + 65);
				}
				else if (input[i] >= 'a' && input[i] <= 'z')
				{
					if (input[i] + increment[j] < 'a')
						input[i] = (((input[i] + 25 +increment[j]) % 27) + 97);
					else if (input[i] + increment[j] > 'z')
						input[i] = (((input[i] - 25 + increment[j]) % 27) + 97);
					input[i] = (((input[i] + increment[j]) % 27) + 97);
				}
			printf("%c", input[i]);
			j++;
			if (increment[j] == '\0')
			j = 0;
			}
			if (input[i] == '\0')
				break;
		}
		printf("\n");
		return(0);
	}

// Creating main, protected to avoid segfaults and some basic mis-input ( more than two ) a simplifier, à faire : utiliser les ocmmandes de capture clavier, 
// premices de la CLI que j ai en tete la premiere condition ne fonctionne pas
int	main(int argc, char** argv)
	{
		if (argc != 3)
			printf("il ne faut rentrer que deux valeurs \n" /* ou tappez './cesar --help' pour plus d'informations."*/);
		else	
			ft_vigenere(argv[1], argv[2]);
		return(0);
	}
