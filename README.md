# PcIsola
## Version 5.0
Jeu Isola en C++.
Programme créé pour l'info111. 2eme projet : Jeu Isola.
L1 MPI Semestre 1. Présenté au prof le 15/12/16 à 9:30.

## Changelog :


### v5.0 :

Ajout du mode cavalier :

-Sauvegarde adaptée.

-Main adaptée.

Optimisation : Création de fonctions "deplacement_possible", localement pour les modules "fonctions_isola" et 

"fonctions_spe_jeu_cavalier", sur le modèle du module "fonctions_spe_jeu_ordi".

Correction d'un bug critique de casse_bloc() (boucle qui tourne en boucle).

Bug de save avec deux noms pareil.

Affichage des déplacements refait.

Affichage des differents modes de jeu rangé (Régles ajoutées).

Fonction deplacement_possible de l'IA retiré et remplacé par deplacement_possible générale situé dans fonctions_isola.cpp (donc

adaptation des fonctions de l'IA et de deplacement_possible).

Protection ajouté pour éviter le dépassement de 26 cases dans une ligne, dans toutes les fonctions secondaire.

Placement des pions manuel pour mode survie.

Ajout d'une IA pour le mode Cavalier. Basée en grande partie sur l'IA du mode Classique.


### v4.1 :

Un peu d'optimisation (-100 lignes : Mode normal inclut dans mode classique car les deux sont semblablent, 

création de la fonction position_pion utilisée par plusieurs fonctions.).

Bugs de sauvegarde résolu.

Mode IA vs IA retiré. (Toutes les IA développées ne sont pas adaptable au programme).

Option pour quitter en effacent le fichier temporaire.


### v4.0 :

Fonction affichage_deplacement_possible crée pour afficher les déplacements de manière "carré" (au lieu de tous les déplacements sur la

même ligne).

Mode de jeu normal ajouté (consignes).

Indications à afficher par la fonction main plus précise.

Sauvegarde et sauvegarde temporaire ajoutées, adaptation avec:

-Mode classique.

-Mode course.

-Mode ordi.

-Mode survie.

-Mode normal.

-Mode IA vs IA.


### v3.1 :

Déplacement aléatoire du pion ordi.

Améliorations de l'IA : 

-Protection contre les blocages dans les coins.

Nouvelles fonctions commentées.


### v3.0 :

Programme découpé en modules.

Affichage du tableau finale lorsque qq'un a perdu.

Affichage de la grille corrigé.

Boucle dans main.

Trois modes ajouté :

 -Mode ordi vs joueur.
 
 -Mode survie.
 
 -Mode IA vs IA.


### v2.1 :

Ajout des corrections automatique des minuscules entrés par l'utilisateur.


### v2.0 :

Fonction main() transformé en menu de séléction pour differents mode de jeu.

Deux modes de jeux :

-Jeu classique.

-Jeu course.

Ajout des régles de jeu.

Ajout des commentaires.


### v1.0 (Projet Isola devient PcIsola :-) ) :

Fonction main() refaite complètement pour correspondre aux règles de l'isola.


### v0.6 :

Remplacement des cin par des getline() dans main().

Fonction casse_bloc() corrigé :

-Première ligne = 1 et non 0.

-Condition pour valider l'entrer de l'utilisateur renforcé.

Fonction demande_deplace() corrigé :

-Affichage de la position du pion corrigé.

-Affichage des déplacements possible amélioré.

Fonction affichage() amélioré (indication des lignes et des colonnes).


### v0.5 :

Fonction possibl_deplac() réecrite complètement.


### v0.4.1 :
Correction de la fonction gagner().


### v0.4 :

Corrections dans la fonction casse_bloc().

Fonction gagner() ne fonctionne pas.

Fonction possibl_deplac() ne fonctionne pas.


### v0.3.20 :

Fonction affichage() réduite à sa fonction de base : afficher un tableau.


### v0.3.12 :

Correction de bugs dans la fonction demande_deplace().


### v0.3.11 :

Fonction demande_deplace() refaite de zero.


### v0.3.2 -> v0.3.10 :

Correction de bugs dans demande_deplace().


### v0.3.1 :

Correction de bugs dans demande_deplace().

Fonction affichage() ne fonctionne pas (n'affiche rien).


### v0.3 :

Remplissage des fonctions du scelettes :

-Fonction deplacement découpé en deux fonctions : demande_deplace() et deplacement().

-Création des fonctions char_en_int() et int_en_char().

Création d'une fonction main() provisoire permettant de tester le programme.

pos_dep() renommé en possibl_deplac()


### v0.2 :

Création du scelette provisoire du programme :

-Fonction deplacement() pour déplacer les pions.

-Fonction casse_bloc() pour casser un bloc.

-Fonction de test gagner() et pos_dep().


### v0.1 :

Initialisation du projet Isola.

Création de la fonction initialisation_tableau().

Création de la fonction affichage().
