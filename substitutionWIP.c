#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char substitution (char cipher[], char key[27], char *decipher)
  {
    char alph[27] = "abcdefghijklmnopqrstuvwxyz";
    int a, b;

    for (a=0; cipher[a] != 0; a++)
      {
        for(b=0; key[b] != 0; b++)
          {
            if(cipher[a] == key[b])
              {
                decipher[a] = alph[b];
              }
          }
      }

  }


int main(int argc, char *argv[])
  {
    char decipher[sizeof(argv[1])];
    substitution(argv[1], argv[2], decipher);
    printf("%s\n", decipher);
  }
