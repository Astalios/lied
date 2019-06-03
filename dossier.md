# LIED Is Encrypting Decrypting

https://github.com/Astalios/lied

## 1. Présentation du projet

Notre objectif était de créer une boite à outils pour faciliter la résolution d’énigmes, notament des ARGs (Alternate Reality Game). Pour cela, nous voulions créer un ensemble de programmes permettant de chiffrer et déchiffrer du texte, le décodage de massages étant un grand classique des jeux d'énigmes. Nous avons donc sélectionné un ensemble de chiffrements simples et communs qui sont fréquemment utilisés dans des énigmes et les avons transcrits en programmes.


Pour le choix du language, nous avons tout d’abord hésité entre le C et le python pour écrire notre programme,les deux langages semblant adaptés, et Simon ayant des bases en C, et Thomas en python. Notre projet impliquait de faire de la programmation impérative, donc les deux languages étaient envisageables.
Le C est plus difficile à prendre en main, étant un language de bas niveau, mais le fait qu'il soit un language compilé en rends l'exécution plus rapide (ce qui n'a pas beaucoup d'importance au vue de la taille du projet). Au contraire, le python est plus facile à prendre en main étant un language de haut niveau, ce qui permet d'être plus productif, mais est plus lent étant un language interprété.
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

	Le chiffrement par substitution consiste à remplacer systématiquement dans un texte un signe donné par un autre signe. On utilise donc deux clés de même taille, et on remplace dans le texte les caractères d'une clé par leur équivalent de l'autre clé. 

	Exemple :
	```
	abcdefghijklmnopqrstuvwxyz
	tbjkndfgaicvyopwsxqmhzleru
	```
	
	Le code peut ensuit être décodé soit en réappliquant la clé, soit par cryptanalyse fréquentielle.

- Code César:

	Le code César consiste à remplacer les caractères selon un décallage dans une chaine. On assigna à chaque caractère un chiffre, puis on additionne ou soustrait une constante à chaque caractère du texte. 
	
	Exemple avec +3 :
	```
	abcdefghijklmnopqrstuvwxyz
	xyzabcdefghijklmnopqrstuvw
	```
	
	Le code peut être décodé en appliquant l'opposé de la constante, que se retrouve facilement par analyse de fréquence.

- Chiffre de Vigenère :

	Le Chiffrement de Blaise Vigenère fonctionne de manière plus élaborée qu'un chiffrement par substitution ou qu'un chiffrement César. La clef est une chaîne de caractères, et on additionne la valeur position de la lettre a chiffrer avec la lettre de la clé, et on avance jusqu'à la fin de la chaîne de caractères a chiffrer, on répéteras souvent plusieurs fois la clé de chiffrage jusqu'au bout.

	Exemple : 
	```
	phrase:		Vigenere
	cle:			cleclecl
	resultat:		xtkgyitp

	```
	L'utilisation d'une analyse fréquentielle sur le résultat en sera difficile vu la particularité du chiffrage a donner plusieurs réponses différentes pour une lettre à codée donnée.


- Atbash :

	L'atbash consiste à remplacer chaque caractère d'un texte par son opposé dans une chaine. Par exemple, pour l'alphabet, on a a -> z, b -> y, etc..

	Exemple :
	```
	abcdefghijklmnopqrstuvwxyz
	zyxwvutsrqponmlkjihgfedcba
	```
	
	Etant donné que l'atbash est basiquement un chiffrement par substitution, il est tout aussi simple à cryptanalyser.

- Chiffrement affine :

	Le principe du chiffrage Affine est d'appliquer une fonction affine  **f(x) = m\*x+p** en commençant donc par A en position 0 et Z en position 25, et donc x est une valeur comprise entre 0 et 25. Par exemple on cherche a encoder le mot 'affine', avec comme valeur m = 3 et p = 5, bien sûr si la valeur dépasse largement 25, on applique un modulo 26 sur le résultat obtenu et le résultat obtenu sera la lettre qui correspond a cette valeur de position.
	Seulement, il faut que la valeur du chiffre qui se multiplie à 'x' soit égale a une des valeures premières a 26 sinon on se retrouverais avec des chiffrages de lettre qui donneraient la même lettre, donc le message perdrait de son intérêt vu qu'il devient complètement faux.
 
	Exemple avec les deux premières lettres :
	```
	Mot / Phrase : Affine
	Position de 'A' dans l'alphabet : 0
	Position de 'F' dans l'alphabet : 5 

	f(a) = 3*0+5 = 5 = lettre'f'
	f(f) = 3*5+5 = 20 = lettre 'u'
	```

- Carré de Polybe :



- Analyse fréquentielle :

	L'analyse fréquentielle consiste à déterminer la fréquence d'apparition de chaque caractère dans un texte. Elle permet, en connaissant les fréquences d'apparition de chaque lettre dans la langue supposée du texte, de facilement décoder un texte codé par un code simple si le texte est assez long.


- Conversions :
	
	Programme permettant de réaliser diverses conversions pouvant se révéler utiles, notament entre le binaire, l'héxadécimal et le décimal, et entre les valeurs numériques et l'ASCII. Ce programme n'est pas encore fait.


## 3. Objectifs, les choses qui fonctionnent, et d'autre non, où sont donc les limites ?

#### Objectifs :

Les objets dans le projet LiED sont tous fonctionnels pour la majorité des cas, soit non fonctionnels pour une limitation technique du language. 
Ce qui fonctionne pleinement sont donc les programme de (dé)chiffrage, vu qu'ils sont le point central de notre projet, si ils n'étaient pas fonctionnels, celà s'avérerais problématique. 
La fonction du programme est donc simple, et remplie : elle chiffre et elle déchiffre ce qu'on lui demande, la liste étant proposée ci dessus.

#### Limites et échecs :

Néamoins ce qui ne fonctionne pas pour des raisons techniques dues aux utilisations de fonctions telles que la fonction **scanf** qui limite par exemple la prise de mots par le clavier a un seul mot et se bloque dès que cette fonction rencontre ce qu'on appelle un WhiteSpace, c'est a dire littéralement, un espace blanc, un espace blanc est un espace où il n y a aucun caractère visible, telle que l'espace ' ', la tabulation '	' et le retour à la ligne. 
L'une des limites majeures dans la conception de notre petit programme et de notre projet sont souvent le temps parce qu'obligé de se dévouer à d'autres matières, et surtout a nos connaissances, bien souvent dans le language de programmation en question.


## Conclusion Thomas


C'est un projet sur lequel il a été très intéressant de travailler, et que je continuerai à améliorer par la suite. Il m'a permis d'apprendre beaucoup, notamment en C, puisque j'ai débuté le language sur ce projet. C'est un language très intéressant, qui permet (ou plutôt qui oblige) de comprendre plus en détail le fonctionnement de programme, notamment au niveau de la gestion de la mémoire.
Cependant, je pense que ce n'étais pas un bon choix de language, et que nous aurions mieux fait de réaliser ce projet en python. Nous aurions perdu moins de temps et nous aurions pu faire plus d'outils. Ce projet m'a également permis d'apprendre à utiliser gdb (GNU Debugger), qui s'est révélé d'une aide précieuse pour identifier la source de certains problème. J'ai aussi pû utiliser git pour la première fois.

Il y a beaucoup de choses que je voudrai faire pour améliorer le programme. Tout d'abbord, implémenter de nouveaux outils. De nouvelles méthode de codage, tout d'abbord, mais également plus d'outils de cryptanalyse, comme le calcul de l'indice de coincidence. Je voudrais également apprendre à utiliser les librairies permettant de gérer les options (comme getopt) pour permettre de désactiver le traitement des majuscules comme minuscules, et peut-être aussi pour ajouter une option de brute force.
De plus, Simon a fait un main regroupant les programmes demandant après execution le programme à utiliser, là où j'imaginais plutôt que le programme ne soit pas interactif, et que toutes les informations soient passées en ligne de commande. Je ferrais donc surement un fork du programme pour modifier le main.
Enfin, je voudrais que l'on implémente la possibilité de prendre le contenu d'un fichier en entrée, et de stocker la sortie dans un autre fichier. Pour cela, il faudra que je me renseigne sur les entrées et sorties standard du système (stdin et stdout), et sur le fontionnement des pipes et des redirections (|, < et > sous bash).

En conclusion, LIED sera un outil très utile pour résoudre les énigmes de certains jeux auxquels je joue, et même si il est loin d'être parfait, je pense qu'il pourra beaucoup nous aider.


## Conclusion Simon 

Sur ce projet, j'ai littéralement décrassé le peu de bases de C que j'ai pu acquérir lors de mes stages en informatique et en développement sur ce language, le réel progrès ici c'est d'avoir renforcé cette base simple mais pourtant cruciale dans la maitrîse, la modification des chaînes de caractères, tout en ayant un oeil vigilant sur le fonctionnement en interne d'un programme. 
J'admet cependant que les prises en main de ce language est complexe et difficile, pour Thomas comme pour Moi, on a énormément pris du temps a lire la documentation et a expérimenter, corriger des erreurs et son algorythme pour que ce dernier corresponde à la logique de ce language.
	
Le côté le plus enrichissant reste tout de même le coeur du projet, réaliser des programmes de chiffrage, apprendre comment ils fonctionnent sur le papier, puis les réécrir dans un language machine, je pense sincèrement que si on aurait eu encore plus de temps pour avancer dans notre projet, je l'aurais fait a coeur joie, j'ai encore une multitude de chiffrage de plus en plus complexe a insérer, que ce soit pour un défi, même si ces derniers ne serviront sans doute pas a résoudre des énigmes, mais c'est les objectifs qui font avancer.J'pense que mes gros objectifs seraient de reproduire la machinerie enigma, très largement répendue par les soldats nazis pendant la seconde Guerre Mondiale et existant en versions différentes.

LIED est, à notre échelle, un gros projet qui aura nécessité du temps et pas mal de patience pour arriver a nos fins, il est certainement loin d'être parfait, puisqu'il est très certaiment possible de l'améliorer en tout point, mais je pense que l'on peut être fier de notre travail, et on espère qu'il corresponde aux attente des futurs utilisateurs qui ont besoin de déchiffrer ou de chiffrer une phrase.
