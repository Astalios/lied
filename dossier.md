#LIED Is Encrypting Decrypting

##1. Présentation du projet

Notre objectif était de créer une boite à outils pour faciliter la résolution d’énigmes. Pour cela, nous voulions créer un ensemble de programmes permettant de crypter et décrypter du texte. Nous avons donc sélectionné un ensemble de chiffrements simples communs qui sont fréquemment utilisés dans des énigmes et les avons transcrits en programmes.

Nous avons tout d’abord hésité entre le C et le python pour écrire notre programme,les deux langages semblant adaptés, et Simon ayant des bases en C, et Thomas en python. Au final, nous avons opté pour le C car nous voulions apprendre le langage.

Notre programme étant à la base une bibliothèque de programmes plus petits, nous nous sommes organisé en se répartissant les codes à implanter. 
Notre code est organisé en sous programmes pour chaque codage, reliés entre eux par un main commun.
Nous avons utilisé git pour organiser travail.

Nous avons rencontré plusieurs problèmes. Tout d’abord, il a fallu que Thomas apprenne le C, puisqu’il ne connaissait pas le langage. Ensuite, certains codes ont été compliqués à implémenter car ils demandaient un niveau en maths que nous n’avons pas.

Notre programme est sous licence libre (licence MIT), car nous sommes tous deux des adeptes du logiciel libre, et que notre code étant disponible sur internet, il nous semblait évident de le distribuer sous licence libre.

Nous pourrions améliorer notre programme en implémentant d’autres méthodes de chiffrement, et en polissant l’implémentation des codes déjà implémentés. Nous aurions par exemple aimé pouvoir implémenter Enigma, mais nous n’avons pas eu le temps et cela aurait sans doute été très difficile.

##2. Les différents programmes

-Substitution :

	Le chiffrement par constitution consiste à remplacer systématiquement dans un texte un signe donné par un autre signe. On utilise donc deux clés de même taille, et on remplace dans le texte les caractères d'une clé par leur équivalent de l'autre clé. Le code peut ensuit être décodé soit en réappliquant la clé, soit par analyse fréquentielle.

	```
	abcdefghijklmnopqrstuvwxyz
	tbjkndfgaicvyopwsxqmhzleru
	```

-Code César:

	Le code César consiste à remplacer les caractères selon un décallage dans une chaine. On assigna à chaque caractère un chiffre, puis on additionne ou soustrait une constante à chaque caractère du texte. Le code peut être décodé en appliquant l'opposé de la constante, que se retrouve facilement par analyse de fréquence.

-Chiffre de Vigenère :



-Atbash :

	L'atbash consiste à remplacer chaque caractère d'un texte par son opposé dans une chaine. Par exemple, pour l'alphabet, on a a -> z, b -> y, etc..

	```
	abcdefghijklmnopqrstuvwxyz
	zyxwvutsrqponmlkjihgfedcba
	```

-Chiffrement affine :



-Carré de polybe :



-Analyse fréquentielle :

	L'analyse fréquentielle consiste à déterminer la fréquence d'apparition de chaque caractère dans un texte. Elle permet, en connaissant les fréquences d'apparition de chaque lettre d0ans la langue supposée du texte, de facilement décoder un texte codé par un code simple si le texte est assez long.

-Morse :

-Conversions :

##3. Code commenté

