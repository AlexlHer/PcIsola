// --------------------------------
// Auteur : Alexandre l'Heritier
// PcIsola v5.0 : Module fonction spécifique au mode ordi cavalier.
// Module pour : PcIsola v5.0 et supérieurs
// --------------------------------
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <time.h>
#include "fonctions_spe_jeu_ordi_cavalier.h"
#include "fonctions_spe_jeu_cavalier.h"
#include "fonctions_spe_jeu_ordi.h"
#include "fonctions_isola.h"

/**
* Fonction qui cherche le déplacement le plus judicieux, là où il y a le moins de blocs cassé.
* @param t le tableau de jeu.
* @param numnom le numéro du pion.
* @return le nombre de déplacement maximum que l'on peut faire sur une casse (la casse en question n'est pas retourné).
*
* Degré de confiance : 100%
* Complexité : n²
**/
int double_verif_cavalier(Tab2Dint t, int numnom)
{
	Tab1Dstring t1, t1temp;
	Tab2Dint ttemp;
	Tab1Dint tailles;

	// t1 contiendera les déplacements possible du pion numnom.
	t1 = deplacement_possible_cavalier(t, numnom, -1);

	// Si t1 contient le déplacement "HG".
	if (In(t1, "HG"))
	{
		// On déplace le pion vers "HG" et on met le tableau de jeu temporaire dans ttemp.
		ttemp = deplacement_cavalier(t, numnom, "HG");

		// On recherche les déplacement possible du pion que l'on a déplacé temporairement.
		t1temp = deplacement_possible_cavalier(ttemp, numnom, -1);

		// Met le nombre de déplacement possible dans tailles.
		tailles.push_back(t1temp.size());
	}
	if (In(t1, "HD"))
	{
		ttemp = deplacement_cavalier(t, numnom, "HD");
		t1temp = deplacement_possible_cavalier(ttemp, numnom, -1);
		tailles.push_back(t1temp.size());
	}
	if (In(t1, "GH"))
	{
		ttemp = deplacement_cavalier(t, numnom, "GH");
		t1temp = deplacement_possible_cavalier(ttemp, numnom, -1);
		tailles.push_back(t1temp.size());
	}
	if (In(t1, "DH"))
	{
		ttemp = deplacement_cavalier(t, numnom, "DH");
		t1temp = deplacement_possible_cavalier(ttemp, numnom, -1);
		tailles.push_back(t1temp.size());
	}
	if (In(t1, "GB"))
	{
		ttemp = deplacement_cavalier(t, numnom, "GB");
		t1temp = deplacement_possible_cavalier(ttemp, numnom, -1);
		tailles.push_back(t1temp.size());
	}
	if (In(t1, "DB"))
	{
		ttemp = deplacement_cavalier(t, numnom, "DB");
		t1temp = deplacement_possible_cavalier(ttemp, numnom, -1);
		tailles.push_back(t1temp.size());
	}
	if (In(t1, "BG"))
	{
		ttemp = deplacement_cavalier(t, numnom, "BG");
		t1temp = deplacement_possible_cavalier(ttemp, numnom, -1);
		tailles.push_back(t1temp.size());
	}
	if (In(t1, "BD"))
	{
		ttemp = deplacement_cavalier(t, numnom, "BD");
		t1temp = deplacement_possible_cavalier(ttemp, numnom, -1);
		tailles.push_back(t1temp.size());
	}
	// Retourne le nombre de déplacement possible maximale du pion.
	//cout << "----====----" << endl << superieur(tailles) << endl;
	//pause_console();
	return superieur(tailles);
}

/**
* Fonction qui déduit le déplacement du pion à effectuer en choisissant un déplacement avec le plus de possibilité.
* @param t le tableau de jeu.
* @return le déplacement choisi.
*
* Degré de confiance : 100%
* Complexité : n
**/
string deduire_deplace_cavalier(Tab1Dint t)
{
	// Liste qui contient l'ordre des déplacements (t contient des nombres et leurs positions correspondent aux positions de liste).
	Tab1Dstring liste = { "HG", "HD", "GH", "DH", "GB", "DB", "BG", "BD" };

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
*
* Degré de confiance : 100%
* Complexité : n²
**/
string demande_deplace_ordi_cavalier(Tab2Dint t, int numnom)
{
	// Variables contenant le nombre de déplacement possible selon le déplacement initial choisi.
	int tempHG = 0, tempHD = 0, tempGH = 0, tempDH = 0, tempGB = 0, tempDB = 0, tempBG = 0, tempBD = 0;

	// Differants tableau contenant les differants déplacement possible.
	Tab1Dstring t1, t1tempHG, t1tempHD, t1tempGH, t1tempDH, t1tempGB, t1tempDB, t1tempBG, t1tempBD;

	// Contient à chaque fois un tableau t temporaire avec un déplacement simulé (permettant de compter le nombre de déplacement possible avec les mêmes fonctions).
	Tab2Dint ttemp;

	// Contient le résultat finale, le déplacement choisi à renvoyer.
	string choix_deplac;
	// On cherche les déplacements initiaux possible à étudier.
	t1 = deplacement_possible_cavalier(t, numnom, -1);

	// Si t1 contient le déplacement "HG".
	if (In(t1, "HG"))
	{
		// On déplace le pion vers "HG" et on met le tableau de jeu temporaire dans ttemp.
		ttemp = deplacement_cavalier(t, numnom, "HG");

		// On recherche les déplacement possible du pion que l'on a déplacé temporairement.
		t1tempHG = deplacement_possible_cavalier(ttemp, numnom, -1);

		// On utilise double_verif pour une précision accru et on additionne le résultat avec le nombre de déplacement du pion du tableau temporaire.
		tempHG = double_verif_cavalier(ttemp, numnom) + t1tempHG.size();
	}
	if (In(t1, "HD"))
	{
		ttemp = deplacement_cavalier(t, numnom, "HD");
		t1tempHD = deplacement_possible_cavalier(ttemp, numnom, -1);
		tempHD = double_verif_cavalier(ttemp, numnom) + t1tempHD.size();
	}
	if (In(t1, "GH"))
	{
		ttemp = deplacement_cavalier(t, numnom, "GH");
		t1tempGH = deplacement_possible_cavalier(ttemp, numnom, -1);
		tempGH = double_verif_cavalier(ttemp, numnom) + t1tempGH.size();
	}
	if (In(t1, "DH"))
	{
		ttemp = deplacement_cavalier(t, numnom, "DH");
		t1tempDH = deplacement_possible_cavalier(ttemp, numnom, -1);
		tempDH = double_verif_cavalier(ttemp, numnom) + t1tempDH.size();
	}
	if (In(t1, "GB"))
	{
		ttemp = deplacement_cavalier(t, numnom, "GB");
		t1tempGB = deplacement_possible_cavalier(ttemp, numnom, -1);
		tempGB = double_verif_cavalier(ttemp, numnom) + t1tempGB.size();
	}
	if (In(t1, "DB"))
	{
		ttemp = deplacement_cavalier(t, numnom, "DB");
		t1tempDB = deplacement_possible_cavalier(ttemp, numnom, -1);
		tempDB = double_verif_cavalier(ttemp, numnom) + t1tempDB.size();
	}
	if (In(t1, "BG"))
	{
		ttemp = deplacement_cavalier(t, numnom, "BG");
		t1tempBG = deplacement_possible_cavalier(ttemp, numnom, -1);
		tempBG = double_verif_cavalier(ttemp, numnom) + t1tempBG.size();
	}
	if (In(t1, "BD"))
	{
		ttemp = deplacement_cavalier(t, numnom, "BD");
		t1tempBD = deplacement_possible_cavalier(ttemp, numnom, -1);
		tempBD = double_verif_cavalier(ttemp, numnom) + t1tempBD.size();
	}

	// Tableau contenant les differants déplacements possible selon le déplacement initial.
	Tab1Dint fin = { tempHG, tempHD, tempGH, tempDH, tempGB, tempDB, tempBG, tempBD };

	// Choisi le déplacement le plus approprié selon le nombre de déplacement possible (prend le plus grand).
	choix_deplac = deduire_deplace_cavalier(fin);

	//for (int i = 0; i < fin.size(); i++)
	//{
	//	cout << fin[i] << endl;
	//}

	// A faire seulement si c'est un déplacement de pion qui est à faire.
	if (numnom == 3)
	{
		// On recupère la position du pion numnom et on l'a met dans x et y.
		Tab1Dint t2 = position_pion(t, numnom);
		int x = t2[0], y = t2[1];

		cout << "-------------------------------" << endl;
		cout << "C'est au tour de l'Ordinateur " << " ! (Pion n°" << numnom - 1 << ")" << endl;
		cout << "-------------------------------" << endl;
		cout << "Position actuelle du pion : " << x + 1 << "x" << int_en_char(y) << endl;
		cout << "Les déplacements possibles sont : ";

		// Affiche chaque élément du tableau.
		cout << endl;
		affichage_deplacement_possible_cavalier(t1, numnom);
		cout << endl << "-------------------------------" << endl;
	}
	return choix_deplac;
}

/**
* Fonction qui utilise les fonctions précedantes pour déduire le bloc à casser.
* @param t le tableau de jeu.
* @return le tableau de jeu avec le bloc cassé (renvoi le tableau complet pour respecter le programme de base.
*
* Degré de confiance : 100%
* Complexité : n²
**/
Tab2Dint casse_bloc_ordi_cavalier(Tab2Dint t)
{
	// On recupère la position du pion de l'ordi et on l'a met dans x et y.
	Tab1Dint t1 = position_pion(t, 2);
	int x = t1[0], y = t1[1];

	// Appel de la fonction qui déduit le déplacement du pion pour voir où le joueur pourrai probablement déplacer son pion.
	string ou = demande_deplace_ordi_cavalier(t, 2);

	// En fonction du déplacement renvoyé, on casse le bloc choisi.
	if (ou == "HG" || ou == "HD")
	{
		t[x - 1][y] = 1;
	}
	if (ou == "GH" || ou == "GB")
	{
		t[x][y - 1] = 1;
	}
	if (ou == "DH" || ou == "DB")
	{
		t[x][y + 1] = 1;
	}
	if (ou == "BG" || ou == "BD")
	{
		t[x + 1][y] = 1;
	}

	// Affiche le déplacement choisi (ici car on à acces directement au variable).
	cout << x + 2 << " x " << int_en_char(y + 1);

	// Retourne le tableau modifié.
	return t;
}