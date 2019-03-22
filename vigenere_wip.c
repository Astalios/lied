#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
// A modifier , faire en sorte que ce soit un vrai vigenere, car a + a = m  au lieu de a + a = b 
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
						input[i] = (((input[i] + 25 + increment[j]) % 27) + 65);
					else if (input[i] + increment[j] > 'Z')
						input[i] = (((input[i] - 25 + increment[j]) % 27) + 65);
					else input[i] = (((input[i] + increment[j]) % 27) + 65);
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
int	main(int argc, char** argv)
	{
		if (argc != 3)
			printf("il faut rentrer deux valeurs \n");
		else	
			ft_vigenere(argv[1], argv[2]);
		return(0);
	}
