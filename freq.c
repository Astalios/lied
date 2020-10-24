#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*Programme d'analyse fréquentielle
Cela pourrait être utilie d'ajouter une option pour différencier majuscule
et minuscule et prendre en compte les autres caractères*/

void freq(char cipher[])
  {
    char alph[27] = "abcdefghijklmnopqrstuvwxyz";
    int count[27] = {0}; /*stocke le nombre d'apparition de chaque lettre*/
    float freq[27] = {0}; /*stocke la fréquence d'apparition de chaque lettre*/
    int a, b;
    char c;
    int len = strlen(cipher);

		/*compte le nombre d'occurence de chaque lettre en comparant chaque caractères
		 de l'entrée à chaque lettre de l'alphabet*/
    for (a = 0; a < 26; a++)
      {
        for (b = 0; cipher[b] != 0; b++)
          {
            if(cipher[b] == alph[a] || tolower(cipher[b]) == alph[a])
              {
                count[a] = count[a] + 1;
              }
          }
      }

		/*ordonne la list du nombre de chaque lettre et la string de l'alphabet
		par ordre décroissant de nombre d'apparition*/
		for(a = 1; a < 27; a++)
			{
				if(count[a] > count[a-1] && a > 0)
					{
						b = count[a-1];
						c = alph[a-1];
						count[a-1] = count[a];
						alph[a-1] = alph[a];
						count[a] = b;
						alph[a] = c;
						a = a - 2;
					}
			}
		/*détermine la fréquence d'apparition de chaque lettre*/
		for(a = 0; a < 26; a++)
			{
				freq[a] = count[a]*100/len;
			}

    for (a = 0; a < 26; a++)
      {
        printf("%c : %.2f\n", alph[a], freq[a]);
      }
  }

int main(int argc, char *argv[])
  {
  	if(argc == 2)
  		{
  			freq(argv[1]);
  		}
  	else
  		{
  			printf("Wrong input !");
  		}
	return 0;
  }
