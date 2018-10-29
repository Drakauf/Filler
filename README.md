<h1 align="center">
Filler 
</h1>

<h3 align="center"> Description </h3>
<p>Créez votre joueur pour affronter d’autres étudiants sur le célèbre (ou pas) plateau du Filler. Le principe est simple : deux joueurs s’affrontent sur un plateau, et doivent placer, tour à tour, la pièce que le maître du jeu (fourni sous la forme d’un exécutable Ruby) leur donne, gagnant ainsi des points. La partie s’arrête dès qu’une pièce ne peut plus être placée. Petit projet ludique !</p>

<p><b>Objectif :</b> Créer un champion Filler</p>
<p><b>Langage :</b> C</p>
<p><b>Fonctions autorisées :</b>  write, malloc, free, read, perror, strerror</p>

<h3 align="center"> But du jeu </h3>
• Deux adversaires s’affrontent à tour de rôle.</br>
• L’objectif est de gagner le plus de points en remplissant le plateau de jeu avec le
plus de pièces possible.</br>
• Le plateau est défini par X colonnes et Y lignes. Il fera donc X x Y cases.</br>
• A chaque tour, le programme du joueur actif se voit fournir l’état actuel du plateau
et une pièce à placer.</br>
• La VM représente les pièces posées par un des programmes joueurs avec des charactères
’X’ et celles posées par l’autre avec des charactères ’O’.</br>
• Une pièce est définie par x colonnes et y lignes. Dans chaque pièce, une forme
d’une ou plusieurs cases est représentée avec le charactère ’*’.</br>
• Pour pouvoir poser une pièce, il faut qu’une case de la forme recouvre une case,
et une seule case, d’une forme précédemment posée.</br>
• La forme doit rentrer intégralement dans le plateau.</br>
• Le plateau contient une première forme pour chaque programme joueur pour initier
la partie.</br>
• La partie s’arrête à la première erreur : dès qu’une pièce ne peut plus être posée
ou a été mal posée.</br>
• La VM calcule ensuite le score pour chacun des deux programmes joueurs. Le score
le plus élevé remporte la partie</br>

<h3 align="center"> Le plateau</h3>
Un plateau est donc une grille de deux dimensions avec un nombre de lignes et de
colonnes arbitraires. Pour lancer la partie un plateau initial doit être passée en argument
à la VM. Ce plateau initial doit comporter une forme de départ pour chaque joueur.</br>
Voici un exemple de plateau initial de 14 par 30 :

`Plateau 14 30:`</br>
`012345678901234567890123456789`</br>
`000 ..............................`</br>
`001 ..............................`</br>
`002 ..X...........................`</br>
`003 ..............................`</br>
`004 ..............................`</br>
`005 ..............................`</br>
`006 ..............................`</br>
`007 ..............................`</br>
`008 ..............................`</br>
`009 ..............................`</br>
`010 ..............................`</br>
`011 ...........................O..`</br>
`012 ..............................`</br>
`013 ..............................`</br>

<h3 align="center"> Les piéces</h3>
Les pièces sont générées aléatoirement par la VM. Vous ne pouvez pas prévoir leur
taille ni leur forme avant que la VM ne les transmettent à votre programme. Voiçi quelques
exemples arbitraires de pièces possibles pour vous donner une idée :</br>

`Piece 4 7:`</br>
` ...*... `</br>
` ...*... `</br>
` ...*... `</br>
` ..***.. `</br>

`Piece 4 5:`</br>
` .**..    `</br>
` .***.    `</br>
` ..*..    `</br>
` .....`</br>

`Piece 3 6:`</br>
` .****.`</br>
` **....`</br>
` *.....`</br>

<h3 align="center">Le programme joueur</h3>
Vous comprenez donc maintenant que le but du projet Filler est d’écrire un programme
joueur capable de battre son adversaire. Ce programme joueur est passé en
paramètre à la VM qui se chargera d’exécuter chaque programme joueur, puis de lui
transmettre les informations nécessaires au calcul du prochain coup à chaque tour. A
chaque tour, votre programme joueur devra donc :</br>
• Lire le plateau et les pièces sur l’entrée standard. Ces informations proviennent
bien évidemment de la VM.</br>
• Ecrire sur la sortie standard les coordonnées pour placer la pièce. Le format sera
sous la forme suivante : X Y\n".</br>

Lorsque votre programme joueur lira sur l’entrée standard, pour la première fois, il
lira son numéro de joueur et son nom transmis par la VM au format suivant :</br>
`$$$ exec pPLAYER_NUMBER : [PLAYER_NAME]`</br>
• Si vous êtes le premier joueur, votre programme sera représenté par les caractères ’O’.</br>
• Si vous êtes le second joueur, votre programme sera représenté par les caractères ’X’.</br>



<p> Parsing by <a>asiaux</a> and <a>wgaetan</a></p>
Need to change strat : Now -> surrounding each ennemy char => surrounding ennemy's block.
