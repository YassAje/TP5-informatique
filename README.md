# TP5-informatique
TP 5
Ouverture de fichiers en mode binaire

Exercice 1 : affichage du contenu d’un fichier quelconque

1. Écrivez un programme nommé exo1.c permettant d’afficher le contenu d’un fichier quelconque.
1. Le programme prend comme paramètre d’entrée le nom du fichier que l’on souhaite
analyser.
2. Il doit afficher dans la console la représentation hexadécimale de chaque octet ainsi que le
caractère ASCII correspondant lorsque cet octet correspond à un code ASCII affichable. On
affichera 16 octets par ligne, comme indiqué dans l’exemple ci-dessous.

BMz.......z...l.
................
................
......BGRs......
................
................
................
..........J0.J2.
L6$J3#T:­I/!P8$L
7 L3"N7!L5 O6&Q8

2. Créez un fichier makefile avec une recette exo1 permettant de produire l’exécutable exo1.
3. Testez votre programme avec un fichier texte ainsi qu’avec un fichier exécutable et un fichier
image au format BMP. Commentez.

Exercice 2 : lecture le l’entête d’un fichier BMP

1. Écrivez un programme nommé exo2.c permettant de lire l’entête fichier d’un fichier BMP.
1. Le programme prend comme paramètre d’entrée le nom du fichier BMP que l’on souhaite
analyser.
2. L’entête est contenu dans les 14 premiers octets du fichier BMP. Les deux premiers octets
sont les caractères B et M (0x42 et 0x4D). Ils sont suivis de 3 mots 32 bits (4 octets)
indiquant, dans l’ordre, la taille du fichier en octets, un mot réservé pour des usages futures
(normalement égal à 0) ainsi que la position dans le fichier de l’image proprement dite (les
valeurs RVB des pixels). Attention au boutisme (endianness).
3. On définira pour cela une structure nommé BMP_FILE_HEADER dont on vérifiera la taille
grâce à l’opérateur sizeof. Votre programme doit afficher dans le terminal la taille en octet
de cette structure. Commentez.
4. Le programme doit également vérifier si le fichier passé en paramètre est bien conforme au
format BMP et, le cas échéant, afficher les trois mots 32 bits lus.
2. Créez un fichier makefile avec une recette exo2 permettant de produire l’exécutable exo2.
3. Testez votre programme et vérifiez la cohérence des informations extraites.
4. 
Exercice 3 : Lecture de l’entête image d’un fichier BMP

1. Écrivez un programme nommé exo3.c permettant de lire l’entête image d’un fichier BMP.
1. Le programme prend comme paramètre d’entrée le nom du fichier BMP que l’on souhaite
analyser.
2. L’entête image dont la taille dépend de la version commence immédiatement après l’entête
fichier, c’est-à-dire au 15ème octet. On utilisera la fonction fseek pour commencer la lecture
au bon endroit.
3. On utilisera pour cela la structure BMP_IMAGE_HEADER fournie.
4. Le programme doit lire les données du fichier source et afficher les informations les plus
importantes à savoir la taille de l’entête (renseigne sur la version de l’entête), les dimensions
de l’image en pixels, le nombre de bits par pixel ainsi que la résolution en points par pouce.
Attention, dans le format BMP, la résolution est exprimée en points par mètre (1 pouce =
25,4mm).
2. Créez un fichier makefile avec une recette exo3 permettant de produire l’exécutable exo3.
3. Testez votre programme et vérifiez la cohérence des informations extraites.
