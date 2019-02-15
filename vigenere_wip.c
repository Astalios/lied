#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
// le ft_viegenere est simple, on lui injecte deux donnees, le texte en premier, et la valeur de decalage, positive ou negative, il gere les majuscules et les minuscules. 

char	ft_strcpr(char khey[] , int i)
	{
		char abc[53]="ABCDEFGHIJKLMOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
		int j=0;
		int k=0;
		while (khey[i] != abc[j])
		{
			if (k > 26)
				k = 1;
			j++;
			k++;
		}	
		return(k); 
	}

char	ft_vigenere(char input[] , char increment[])
	{
		int j=0;
		while ((increment[j] >= 'A' && increment[j] <= 'Z') || (increment[j] >= 'a' && increment[j] <= 'z' ) && increment[j] != '\0')
		{
			for (int i = 0; input[i] != '\0'; i++)
			{
				if (input[i] >= 'A'  && input[i] <= 'Z')
				{
					if (input[i] + increment[j] < 'A')
						input[i] = input[i] + 25 + increment[j];
					else if (input[i] + increment[j] > 'Z')
						input[i] = input[i] - 25 + increment[j];
					else input[i] = input[i] + increment[j];
				}
				else if (input[i] >= 'a' && input[i] <= 'z')
				{
					if (input[i] + increment[j] < 'a')
						input[i] = input[i] + 25 + increment[j];
					else if (input[i] + increment[j] > 'z')
						input[i] = input[i] - 25 + increment[j];
					else input[i] = input[i] + increment[j];
				}
			printf("%c", input[i]);
			j++;
			if (increment[j] == '\0')
				j = 0;
			}
		}
		printf("\n");
		return(0);
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
