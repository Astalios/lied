#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void freq(char cipher[])
  {
    char alph[53] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int freq[27] = {0};
    int a, b, c;

    for (a = 0; a < 26; a++)
      {
        for (b = 0; cipher[b] != 0; b++)
          {
            if(cipher[b] == alph[a] || cipher[b] == alph[a + 26])
              {
                freq[a] = freq[a] + 1;
              }
          }
      }

    for (c = 0; c < 26; c++)
      {
        printf("%c : %d \n", alph[c], freq[c]);
      }
  }

void main(int argc, char *argv[])
  {
    freq(argv[1]);
  }