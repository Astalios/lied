#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char substitution (char cipher[], char key1[27], char key2[27], char decipher[])
  {
    int a, b, c;

    for (a=0; cipher[a] != 0; a++) /*Boucle déplaçant dans le texte en entrée*/
      {
      	c = 0;
        for(b=0; key1[b] != 0 && c == 0; b++) /*Boucle se déplaçant dans les clés*/
          {
            if(cipher[a] == key1[b])
            /*Si le caractère du texte correspond au caractère de la première clé,
             le caractère associé de la seconde clé est ajouté à la sortie*/
              {
                decipher[a] = key2[b];
                c = 1;	/*Stoppe la boucle pour passer au caractère suivant du texte.*/
              }
             else if(tolower(cipher[a]) == key1[b])
             /*Prise en charge des majuscules.
             Il faudrait une option pour le désactiver si la clée comprends les majs*/
             	{
             		decipher[a] = toupper(key2[b]);
             		c = 1;
             	}
          }
        if(c == 0)
        /*Prise en charge des caractères spéciaux.
        Si le caractère du texte en entrée ne correspond à aucun
        caractère de la clé, il est mis tel quel en sortie.
        Cela permet de s'assurer que le texte en sortie soit complet.*/
          {
             		decipher[a] = cipher[a];
             		c = 1;
          }
      }
    decipher[a] = '\0'; /*Permet de s'assurer que la string est bien terminée*/
  }


int main(int argc, char *argv[])
  {

		if(argc == 3 && strlen(argv[2]) == 26)
			{
    		char output[strlen(argv[1])+1];
    		substitution(argv[1], argv[2], "abcdefghijklmnopqrstuvwxyz", output);
    		printf("%s\n", output);
    		return 0;
			}
		else if(argc == 4 && strlen(argv[2]) == strlen(argv[3]))
			{
    		char output[strlen(argv[1])+1];
    		substitution(argv[1], argv[2], argv[3], output);
    		printf("%s\n", output);
    		return 0;
    	}
    else
    	{
				printf("Wrong input !\n");
				return 1;
    	}

  }
