#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

char ft_vigenere(char* phrase, char* increment)
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
