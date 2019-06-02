# LIED Is Encrypting Decrypting

https://github.com/Astalios/lied

## 1. Présentation du projet

Notre objectif était de créer une boite à outils pour faciliter la résolution d’énigmes, notament des ARGs (Alternate Reality Game). Pour cela, nous voulions créer un ensemble de programmes permettant de crypter et décrypter du texte, le décodage de massages étant un grand classique des jeux d'énigmes. Nous avons donc sélectionné un ensemble de chiffrements simples et communs qui sont fréquemment utilisés dans des énigmes et les avons transcrits en programmes.


Pour le choix du language, nous avons tout d’abord hésité entre le C et le python pour écrire notre programme,les deux langages semblant adaptés, et Simon ayant des bases en C, et Thomas en python. Notre projet impliquait de faire de la programmation impérative, donc les deux languages étaient envisageables.
Le C est plus difficile à prendre en main, étant un language de bas niveau, mais le fait qu'il soit un language compilé en rends l'exécution plus rapide (ce qui n'a pas beaucoups d'importance au vu de la taille du projet). Au contraire, le python est plus facile à prendre en main étant un language de haut niveau, ce qui permet d'être plus productif, mais est plus lent étant un language interprété.
Au final, nous avons opté pour le C car Simon le maitrisait déjà et voulait s'améliorer, et Thomas voulait l'apprendre.


Notre programme étant à la base une bibliothèque de programmes plus petits, nous nous sommes organisé en se répartissant les différents chiffrements et outils à implanter. Notre code est organisé en sous programmes pour chaque outil, reliés entre eux par un main commun.
Pour organiser notre travail, nous avons décidé d'utiliser le logiciel de gestion de version git (et plus précisemment github), ce qui nous a permi de facilement travailler chacun de notre côté, sans avoir à constament s'échanger le code écrit par mail ou par clé usb.


Notre programme est sous license libre (license MIT), car nous sommes tous deux des adeptes du logiciel libre, et que notre code étant disponible sur internet, il nous semblait évident de le distribuer librement, afin que n'importe qui puisse l'utiliser, l'adapter à ses besoins, et le redistribuer librement. Un autre avantage est que si quelqu'un de plus expérimenté que nous s'intéresse à notre programme, il pourra nous aider à l'améliorer.
De plus, même si il semble peu probable que cela arrive, c'est avant tout une question de principe, en effet, nous pensons qu'il n'est pas acceptable de distribuer du code propriétaire, car l'utilisateur n'a aucun moyen de savoir ce que le programme fait, et doit donc entièrement faire confiance au créateur du programme qui peut exécuter du code malicieux à son insu. C'est impossible avec un logiciel libre, tout le monde pouvant étudier le code pour en déterminer le fonctionnement.
Enfin, nous pensons que les logiciels (et les outils en général), doivent être libres, 


Nous avons rencontré plusieurs problèmes. Tout d’abord, il a fallu que Thomas apprenne le C, puisqu’il ne connaissait pas le langage. Ensuite, certains codes ont été compliqués à implémenter car ils demandaient un niveau en maths que nous n’avons pas.


Nous pourrions améliorer notre programme en implémentant d’autres méthodes de chiffrement, et en polissant l’implémentation des codes déjà implémentés. Nous aurions par exemple aimé pouvoir implémenter Enigma, mais nous n’avons pas eu le temps et cela aurait sans doute été très difficile.

## 2. Les différents programmes

- Substitution :

	Le chiffrement par constitution consiste à remplacer systématiquement dans un texte un signe donné par un autre signe. On utilise donc deux clés de même taille, et on remplace dans le texte les caractères d'une clé par leur équivalent de l'autre clé. Le code peut ensuit être décodé soit en réappliquant la clé, soit par analyse fréquentielle.

	```
	abcdefghijklmnopqrstuvwxyz
	tbjkndfgaicvyopwsxqmhzleru
	```

- Code César:

	Le code César consiste à remplacer les caractères selon un décallage dans une chaine. On assigna à chaque caractère un chiffre, puis on additionne ou soustrait une constante à chaque caractère du texte. Le code peut être décodé en appliquant l'opposé de la constante, que se retrouve facilement par analyse de fréquence.

- Chiffre de Vigenère :



- Atbash :

	L'atbash consiste à remplacer chaque caractère d'un texte par son opposé dans une chaine. Par exemple, pour l'alphabet, on a a -> z, b -> y, etc..

	```
	abcdefghijklmnopqrstuvwxyz
	zyxwvutsrqponmlkjihgfedcba
	```

- Chiffrement affine :



- Carré de polybe :



- Analyse fréquentielle :

	L'analyse fréquentielle consiste à déterminer la fréquence d'apparition de chaque caractère dans un texte. Elle permet, en connaissant les fréquences d'apparition de chaque lettre d0ans la langue supposée du texte, de facilement décoder un texte codé par un code simple si le texte est assez long.

- Conversions :

## 3. Code commenté

## Conclusion Thomas


C'est un projet sur lequel il a été très intéressant de travailler, et que je continuerai à améliorer par la suite. Il m'a permis d'apprendre beaucoup, notamment en C, puisque j'ai débuté le language sur ce projet. C'est un language très intéressant, qui permet (ou plutôt qui oblige) de comprendre plus en détail le fonctionnement de programme, notamment au niveau de la gestion de la mémoire.
Cependant, je pense que e n'était pas un bon choix de language, et que nous aurions mieux fait de réaliser ce projet en python. Nous aurions perdu moins de temps et nous aurions pu faire plus d'outils. Ce projet m'a également permi d'apprendre à utiliser gdb (GNU Debugger), qui s'est révélé d'une aide précieuse pour identifier la source de certains problème. J'ai aussi pû utiliser git pour la première fois.

Il y a beaucoup de choses que je voudrai faire pour améliorer le programme. Tout d'abbord, implémenter de nouveaux outils. De nouvelles méthode de codage, tout d'abbord, mais également plus d'outils de cryptanalyse, comme le calcul de l'indice de coincidence. Je voudrais également apprendre à utiliser les librairies permettant de gérer les options (comme getopt) pour permettre de désactiver le traitement des majuscules comme minuscules, et peut-être aussi pour ajouter une option de brute force.
De plus, Simon a fait un main regroupant les programmes demandant après execution le programme à utiliser, là où j'imajinais plutôt que le programme ne soit pas intéractif, et que toutes les informations soient passées en ligne de commande. Je ferrait donc surement un fork du programme pour modifier le main.
Enfin, je voudrai que l'on implémente la possibilité de prendre le contenu d'un fichier en entrée, et de stocker la sortie dans un autre fichier. Pour cela, il faudra que je me renseigne sur les entrées et sorties standard du système (stdin et stdout), et sur le fontionnement des pipes et des redirections (|, < et > sous bash).

En conclusion, LIED sera un outil très utile pour résoudre les énigmes de certains jeux auxquels je joue, et même si il est loin d'être parfait, je pense qu'il pourra beaucoups nous aider.
