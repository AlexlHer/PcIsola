// --------------------------------
// Auteur : Alexandre l'Heritier
// PcIsola v3.1 : Module fonction spécifique au mode ordi.
// Module pour : PcIsola v3.1 et supérieurs
// --------------------------------
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <time.h>
#include "fonctions_spe_jeu_ordi.h"
#include "fonctions_isola.h"

// Compteur de tour pour commencer l'aléatoire (alea_dans_tab()).
int tour = 0;

/**
* Fonction qui coupe le "plateau de jeu" en quatre.
* @param tab le tableau de jeu.
* @param numnom le numéro du pion.
* @return l'emplacement du pion (1 ou 2 ou 3 ou 4).
**/
int position_tableau(Tab2Dint tab, int numnom)
{
	//|----------|
	//| 1  |  2  |
	//|----|-----|
	//| 3  |  4  |
	//|----------|
	// Initialisation des variables.
	// x et y la position du pion, z la condition pour que la boucle de verification s'arrete (tout en bas de la fonction).
	// t1 le tableau contenant les déplacements possibles.
	// choix_deplac la cdc contenant le déplacement à renvoyer.
	int x, y = 0;

	// Double boucle qui parcours le tableau 2D.
	for (int i = 0; i < tab.size(); i++)
	{
		for (int j = 0; j < tab[i].size(); j++)
		{
			// Une fois le pion trouvé, mettre sa position dans x et y.
			if (tab[i][j] == numnom)
			{
				x = i + 1;
				y = j + 1;
			}
		}
	}

	// Prend la taille du tableau et la divise par 2 pour avoir les parties.
	int taille_x = (tab.size() / 2);
	int taille_y = (tab[0].size() / 2);

	// Selon l'emplacement du pion, retourne son emplacement.
	if (x > taille_x && y > taille_y) return 4;
	if (x <= taille_x && y > taille_y) return 3;
	if (x <= taille_x && y <= taille_y) return 1;
	if (x > taille_x && y <= taille_y) return 2;
}

/**
* Fonction qui met le ou les positions du chiffre demandé dans un tableau.
* @param tab le tableau dans lequel il faut rechercher x..
* @param x le nombre à rechercher.
* @return le tableau qui contient les emplacements de x.
**/
Tab1Dint comptage_dans_tableau(Tab1Dint tab, int x)
{
	// On crée le tableau qui sera retourné à la fin.
	Tab1Dint fin;

	// Boucle qui parcours le tableau tab et ajoute la position de x dans fin.
	for (int i = 0; i < tab.size(); i++)
	{
		if (tab[i] == x)
		{
			fin.push_back(i);
		}
	}
	return fin;
}

/**
* Fonction qui choisi aléatoirement un élément dans le tableau.
* @param tab le tableau dans lequel il faut choisir un élément.
* @return un élément de la liste choisi aléatoirement.
**/
int alea_dans_tab(Tab1Dint tab)
{
	// Test qui permet de laisser passer 4 tours de jeu avant de choisir aléatoirement. Cela rend l'algorithme plus efficace.
	if (tour > 4)
	{
		// Initialisation du random avec le nombre de seconde depuis le 1 jan. 1975. 
		// Cela permet de ne jamais avoir de nombre identique après deux lancement de programme.
		srand(time(NULL));

		// Prend un nombre aléatoire et fait le modulo taille du tab pour obtenir un nombre entre 0 et taille de tab.
		int a = rand() % tab.size();
		//cout << a << endl;
		return tab[a];
		//return tab[0];
	}
	else
	{
		tour++;
		// Retourne le première élément du tableau.
		return tab[0];
	}
}

/**
* Fonction qui donne les déplacements possible d'un pion.
* @param t le tableau de jeu.
* @param numnom le numéro du pion.
* @return un tableau contenant les déplacements possible.
**/
Tab1Dstring deplacement_possible(Tab2Dint t, int numnom)
{
	// Initialisation des variables.
	// x et y la position du pion, z la condition pour que la boucle de verification s'arrete (tout en bas de la fonction).
	// t1 le tableau contenant les déplacements possibles.
	// choix_deplac la cdc contenant le déplacement à renvoyer.
	int x, y = 0;
	Tab1Dstring t1;

	// Double boucle qui parcours le tableau 2D.
	for (int i = 0; i < t.size(); i++)
	{
		for (int j = 0; j < t[i].size(); j++)
		{
			// Une fois le pion trouvé, mettre sa position dans x et y.
			if (t[i][j] == numnom)
			{
				x = i;
				y = j;
			}
		}
	}
	// Grande serie de test pour trouver les déplacements possibles.
	// Si x != 0 donc si le pion n'est pas sur la première ligne du tableau 2D.
	if (x != 0)
	{
		// Si la case au dessus n'est pas casser ou pas prise par un autre pion, H possible.
		if (t[x - 1][y] == 0)
		{
			t1.push_back("H");
		}
		// Si y != 0 donc si le pion n'est pas sur la première colonne.
		if (y != 0)
		{
			// Si la case au dessus et à gauche n'est pas cassé ou pas prise par un autre pion, HG possible.
			if (t[x - 1][y - 1] == 0)
			{
				t1.push_back("HG");
			}
		}
		// Si y + 1 != taille de la x ligne donc si le pion n'est pas sur la dernière colonne.
		if (y + 1 != t[x].size())
		{
			// Si la case au dessus et à droite n'est pas cassé ou pas prise par un autre pion, HD possible.
			if (t[x - 1][y + 1] == 0)
			{
				t1.push_back("HD");
			}
		}
	}
	// Si x + 1 != taille des colonnes donc si le pion n'est pas sur la dernière ligne du tableau 2D.
	if (x + 1 != t.size())
	{
		// Si la case en dessous n'est pas casser ou pas prise par un autre pion, B possible.
		if (t[x + 1][y] == 0)
		{
			t1.push_back("B");
		}
		// Si y != 0 donc si le pion n'est pas sur la première colonne.
		if (y != 0)
		{
			// Si la case en dessous et à gauche n'est pas cassé ou pas prise par un autre pion, BG possible.
			if (t[x + 1][y - 1] == 0)
			{
				t1.push_back("BG");
			}
		}
		// Si y + 1 != taille de la x ligne donc si le pion n'est pas sur la dernière colonne.
		if (y + 1 != t[x].size())
		{
			// Si la case en dessous et à droite n'est pas cassé ou pas prise par un autre pion, BD possible.
			if (t[x + 1][y + 1] == 0)
			{
				t1.push_back("BD");
			}
		}
	}
	// Si y != 0 donc si le pion d'est pas sur la première colonne.
	if (y != 0)
	{
		// Si la case à gauche est vide alors G possible.
		if (t[x][y - 1] == 0)
		{
			t1.push_back("G");
		}
	}
	// Si y + 1 != taille de la x ligne donc si le pion n'est pas sur la dernière colonne.
	if (y + 1 != t[x].size())
	{
		// Si la case à droite est vide alors D possible.
		if (t[x][y + 1] == 0)
		{
			t1.push_back("D");
		}
	}
	return t1;
}

/**
* Fonction qui donne le nombre le plus grand, contenu dans le tableau.
* @param t le tableau dans lequel rechercher.
* @return le nombre max.
**/
int superieur(Tab1Dint t)
{
	// Contient le nombre max qui sera renvoyé.
	int max = 0;

	// Boucle qui parcours la liste et qui prend le plus grand.
	for (int i = 0; i < t.size(); i++)
	{
		if (t[i] > max)
		{
			t[i] = max;
		}
	}
	return max;
}

/**
* Fonction qui cherche le déplacement le plus judicieux, là où il y a le moins de blocs cassé.
* @param t le tableau de jeu.
* @param numnom le numéro du pion.
* @return le nombre de déplacement maximum que l'on peut faire sur une casse (la casse en question n'est pas retourné).
**/
int double_verif(Tab2Dint t, int numnom)
{
	Tab1Dstring t1, t1temp;
	Tab2Dint ttemp;
	Tab1Dint tailles;

	// t1 contiendera les déplacements possible du pion numnom.
	t1 = deplacement_possible(t, numnom);

	// Si t1 contient le déplacement "H".
	if (In(t1, "H"))
	{
		// On déplace le pion vers "H" et on met le tableau de jeu temporaire dans ttemp.
		ttemp = deplacement(t, numnom, "H");

		// On recherche les déplacement possible du pion que l'on a déplacé temporairement.
		t1temp = deplacement_possible(ttemp, numnom);

		// Met le nombre de déplacement possible dans tailles.
		tailles.push_back(t1temp.size());
	}
	if (In(t1, "B"))
	{
		ttemp = deplacement(t, numnom, "B");
		t1temp = deplacement_possible(ttemp, numnom);
		tailles.push_back(t1temp.size());
	}
	if (In(t1, "G"))
	{
		ttemp = deplacement(t, numnom, "G");
		t1temp = deplacement_possible(ttemp, numnom);
		tailles.push_back(t1temp.size());
	}
	if (In(t1, "D"))
	{
		ttemp = deplacement(t, numnom, "D");
		t1temp = deplacement_possible(ttemp, numnom);
		tailles.push_back(t1temp.size());
	}
	if (In(t1, "HG"))
	{
		ttemp = deplacement(t, numnom, "HG");
		t1temp = deplacement_possible(ttemp, numnom);
		tailles.push_back(t1temp.size());
	}
	if (In(t1, "HD"))
	{
		ttemp = deplacement(t, numnom, "HD");
		t1temp = deplacement_possible(ttemp, numnom);
		tailles.push_back(t1temp.size());
	}
	if (In(t1, "BD"))
	{
		ttemp = deplacement(t, numnom, "BD");
		t1temp = deplacement_possible(ttemp, numnom);
		tailles.push_back(t1temp.size());
	}
	if (In(t1, "BG"))
	{
		ttemp = deplacement(t, numnom, "BG");
		t1temp = deplacement_possible(ttemp, numnom);
		tailles.push_back(t1temp.size());
	}

	// Retourne le nombre de déplacement possible maximale du pion.
	return superieur(tailles);
}

/**
* Fonction qui déduit le déplacement du pion à effectuer en choisissant un déplacement avec le plus de possibilité.
* @param t le tableau de jeu.
* @return le déplacement choisi.
**/
string deduire_deplace(Tab1Dint t)
{
	// Liste qui contient l'ordre des déplacements (t contient des nombres et leurs positions correspondent aux positions de liste).
	Tab1Dstring liste = { "H", "B", "G", "D", "HD", "HG", "BD", "BG" };

	// fin contiendera la chaine qui sera renvoyée à la fin.
	string fin = "";

	// Liste les possibilités de déplacement.
	Tab1Dint possibilite;

	int temp = 0;

	// Parcours la liste t et suvegarde la plus grande valeur.
	for (int i = 0; i < t.size(); i++)
	{
		if (t[i] > temp)
		{
			temp = t[i];
		}
	}

	// Regarde les positions des plus grand nombre.
	possibilite = comptage_dans_tableau(t, temp);

	// Prend un déplacement aléatoire parmi les déplacements possible (dans possibilite).
	temp = alea_dans_tab(possibilite);

	// Retrouve le déplacement correspondant avec la liste et le retourne.
	fin = liste[temp];
	return fin;
}

/**
* Fonction qui va pouvoir déduire le déplacement du pion ordi.
* @param t le tableau de jeu.
* @param numnom le numéro du pion.
* @return le déplacement que doit effectuer le pion ordi.
**/
string demande_deplace_ordi(Tab2Dint t, int numnom)
{
	// Variables contenant le nombre de déplacement possible selon le déplacement initial choisi.
	int tempH = 0, tempB = 0, tempG = 0, tempD = 0, tempHD = 0, tempHG = 0, tempBD = 0, tempBG = 0;

	// Differants tableau contenant les differants déplacement possible.
	Tab1Dstring t1, t1tempH, t1tempB, t1tempG, t1tempD, t1tempHD, t1tempHG, t1tempBD, t1tempBG;

	// Contient à chaque fois un tableau t temporaire avec un déplacement simulé (permettant de compter le nombre de déplacement possible avec les mêmes fonctions).
	Tab2Dint ttemp;

	// Contient le résultat finale, le déplacement choisi à renvoyer.
	string choix_deplac;

	// On cherche les déplacements initiaux possible à étudier.
	t1 = deplacement_possible(t, numnom);

	// Si t1 contient le déplacement "H".
	if (In(t1, "H"))
	{
		// On déplace le pion vers "H" et on met le tableau de jeu temporaire dans ttemp.
		ttemp = deplacement(t, numnom, "H");

		// On recherche les déplacement possible du pion que l'on a déplacé temporairement.
		t1tempH = deplacement_possible(ttemp, numnom);

		// On utilise double_verif pour une précision accru et on additionne le résultat avec le nombre de déplacement du pion du tableau temporaire.
		tempH = double_verif(ttemp, numnom) + t1tempH.size();
	}
	if (In(t1, "B"))
	{
		ttemp = deplacement(t, numnom, "B");
		t1tempB = deplacement_possible(ttemp, numnom);
		tempB = double_verif(ttemp, numnom) + t1tempB.size();
	}
	if (In(t1, "G"))
	{
		ttemp = deplacement(t, numnom, "G");
		t1tempG = deplacement_possible(ttemp, numnom);
		tempG = double_verif(ttemp, numnom) + t1tempG.size();
	}
	if (In(t1, "D"))
	{
		ttemp = deplacement(t, numnom, "D");
		t1tempD = deplacement_possible(ttemp, numnom);
		tempD = double_verif(ttemp, numnom) + t1tempD.size();
	}
	if (In(t1, "HG"))
	{
		ttemp = deplacement(t, numnom, "HG");
		t1tempHG = deplacement_possible(ttemp, numnom);
		tempHG = double_verif(ttemp, numnom) + t1tempHG.size();
	}
	if (In(t1, "HD"))
	{
		ttemp = deplacement(t, numnom, "HD");
		t1tempHD = deplacement_possible(ttemp, numnom);
		tempHD = double_verif(ttemp, numnom) + t1tempHD.size();
	}
	if (In(t1, "BD"))
	{
		ttemp = deplacement(t, numnom, "BD");
		t1tempBD = deplacement_possible(ttemp, numnom);
		tempBD = double_verif(ttemp, numnom) + t1tempBD.size();
	}
	if (In(t1, "BG"))
	{
		ttemp = deplacement(t, numnom, "BG");
		t1tempBG = deplacement_possible(ttemp, numnom);
		tempBG = double_verif(ttemp, numnom) + t1tempBG.size();
	}

	// Tableau contenant les differants déplacements possible selon le déplacement initial.
	Tab1Dint fin = { tempH, tempB, tempG, tempD, tempHD, tempHG, tempBD, tempBG };

	// Choisi le déplacement le plus approprié selon le nombre de déplacement possible (prend le plus grand).
	choix_deplac = deduire_deplace(fin);

	// Differentes exceptions permettant d'éviter un blocage (le numnom == 3 sert à controler si la fonction sert à déplacer un pion ou à detruire un bloc (voir fonction casse_bloc_ordi).
	// Exception permettant d'éviter le blocage dans les coins, au début de partie.
	if (!In(t1, "H") && !In(t1, "G") && position_tableau(t, numnom) == 4 && numnom == 3)
	{
		if (In(t1, "HG"))
		{
			choix_deplac = "HG";
		}
	}
	if (!In(t1, "H") && !In(t1, "D") && position_tableau(t, numnom) == 3 && numnom == 3)
	{
		if (In(t1, "HD"))
		{
			choix_deplac = "HD";
		}
	}
	if (!In(t1, "B") && !In(t1, "G") && position_tableau(t, numnom) == 2 && numnom == 3)
	{
		if (In(t1, "BG"))
		{
			choix_deplac = "BG";
		}
	}
	if (!In(t1, "B") && !In(t1, "D") && position_tableau(t, numnom) == 1 && numnom == 3)
	{
		if (In(t1, "BD"))
		{
			choix_deplac = "BD";
		}
	}
	
	//for (int i = 0; i < fin.size(); i++)
	//{
	//	cout << fin[i] << endl;
	//}

	// A faire seulement si c'est un déplacement de pion qui est à faire.
	if (numnom == 3)
	{
		// Inscription d'infos.
		int x, y = 0;

		// Double boucle qui parcours le tableau 2D.
		for (int i = 0; i < t.size(); i++)
		{
			for (int j = 0; j < t[i].size(); j++)
			{
				// Une fois le pion trouvé, mettre sa position dans x et y.
				if (t[i][j] == numnom)
				{
					x = i;
					y = j;
				}
			}
		}
		cout << "-------------------------------" << endl;
		cout << "C'est au tour de l'Ordinateur " << " ! (Pion n°" << numnom - 1 << ")" << endl;
		cout << "-------------------------------" << endl;
		cout << "Position actuelle du pion : " << x + 1 << "x" << int_en_char(y) << endl;
		cout << "Les déplacements possibles sont : ";

		// Affiche chaque élément du tableau.
		cout << endl;
		affichage_deplacement_possible(t1);
		cout << endl << "-------------------------------" << endl;
	}
	return choix_deplac;
}

/**
* Fonction qui utilise les fonctions précedantes pour déduire le bloc à casser.
* @param t le tableau de jeu.
* @return le tableau de jeu avec le bloc cassé (renvoi le tableau complet pour respecter le programme de base.
**/
Tab2Dint casse_bloc_ordi(Tab2Dint t)
{
	int x, y = 0;

	// Double boucle qui parcours le tableau 2D.
	for (int i = 0; i < t.size(); i++)
	{
		for (int j = 0; j < t[i].size(); j++)
		{
			// Une fois le pion trouvé, mettre sa position dans x et y.
			if (t[i][j] == 2)
			{
				x = i;
				y = j;
			}
		}
	}

	// Appel de la fonction qui déduit le déplacement du pion pour voir où le joueur pourrai probablement déplacer son pion.
	string ou = demande_deplace_ordi(t, 2);

	// En fonction du déplacement renvoyé, on casse le bloc choisi.
	if (ou == "H")
	{
		t[x - 1][y] = 1;
	}
	if (ou == "B")
	{
		t[x + 1][y] = 1;
	}
	if (ou == "G")
	{
		t[x][y - 1] = 1;
	}
	if (ou == "D")
	{
		t[x][y + 1] = 1;
	}
	if (ou == "HG")
	{
		t[x - 1][y - 1] = 1;
	}
	if (ou == "HD")
	{
		t[x - 1][y + 1] = 1;
	}
	if (ou == "BG")
	{
		t[x + 1][y - 1] = 1;
	}
	if (ou == "BD")
	{
		t[x + 1][y + 1] = 1;
	}

	// Affiche le déplacement choisi (ici car on à acces directement au variable).
	cout << x+2 << " x " << int_en_char(y+1);

	// Retourne le tableau modifié.
	return t;
}
