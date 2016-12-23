// --------------------------------
// Auteur : Alexandre l'Heritier
// PcIsola v5.0 : Module fonction sp�cifique au mode ordi cavalier.
// Module pour : PcIsola v5.0 et sup�rieurs
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
* Fonction qui cherche le d�placement le plus judicieux, l� o� il y a le moins de blocs cass�.
* @param t le tableau de jeu.
* @param numnom le num�ro du pion.
* @return le nombre de d�placement maximum que l'on peut faire sur une casse (la casse en question n'est pas retourn�).
*
* Degr� de confiance : 100%
* Complexit� : n�
**/
int double_verif_cavalier(Tab2Dint t, int numnom)
{
	Tab1Dstring t1, t1temp;
	Tab2Dint ttemp;
	Tab1Dint tailles;

	// t1 contiendera les d�placements possible du pion numnom.
	t1 = deplacement_possible_cavalier(t, numnom, -1);

	// Si t1 contient le d�placement "HG".
	if (In(t1, "HG"))
	{
		// On d�place le pion vers "HG" et on met le tableau de jeu temporaire dans ttemp.
		ttemp = deplacement_cavalier(t, numnom, "HG");

		// On recherche les d�placement possible du pion que l'on a d�plac� temporairement.
		t1temp = deplacement_possible_cavalier(ttemp, numnom, -1);

		// Met le nombre de d�placement possible dans tailles.
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
	// Retourne le nombre de d�placement possible maximale du pion.
	//cout << "----====----" << endl << superieur(tailles) << endl;
	//pause_console();
	return superieur(tailles);
}

/**
* Fonction qui d�duit le d�placement du pion � effectuer en choisissant un d�placement avec le plus de possibilit�.
* @param t le tableau de jeu.
* @return le d�placement choisi.
*
* Degr� de confiance : 100%
* Complexit� : n
**/
string deduire_deplace_cavalier(Tab1Dint t)
{
	// Liste qui contient l'ordre des d�placements (t contient des nombres et leurs positions correspondent aux positions de liste).
	Tab1Dstring liste = { "HG", "HD", "GH", "DH", "GB", "DB", "BG", "BD" };

	// fin contiendera la chaine qui sera renvoy�e � la fin.
	string fin = "";

	// Liste les possibilit�s de d�placement.
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

	// Prend un d�placement al�atoire parmi les d�placements possible (dans possibilite).
	temp = alea_dans_tab(possibilite);

	// Retrouve le d�placement correspondant avec la liste et le retourne.
	fin = liste[temp];
	return fin;
}

/**
* Fonction qui va pouvoir d�duire le d�placement du pion ordi.
* @param t le tableau de jeu.
* @param numnom le num�ro du pion.
* @return le d�placement que doit effectuer le pion ordi.
*
* Degr� de confiance : 100%
* Complexit� : n�
**/
string demande_deplace_ordi_cavalier(Tab2Dint t, int numnom)
{
	// Variables contenant le nombre de d�placement possible selon le d�placement initial choisi.
	int tempHG = 0, tempHD = 0, tempGH = 0, tempDH = 0, tempGB = 0, tempDB = 0, tempBG = 0, tempBD = 0;

	// Differants tableau contenant les differants d�placement possible.
	Tab1Dstring t1, t1tempHG, t1tempHD, t1tempGH, t1tempDH, t1tempGB, t1tempDB, t1tempBG, t1tempBD;

	// Contient � chaque fois un tableau t temporaire avec un d�placement simul� (permettant de compter le nombre de d�placement possible avec les m�mes fonctions).
	Tab2Dint ttemp;

	// Contient le r�sultat finale, le d�placement choisi � renvoyer.
	string choix_deplac;
	// On cherche les d�placements initiaux possible � �tudier.
	t1 = deplacement_possible_cavalier(t, numnom, -1);

	// Si t1 contient le d�placement "HG".
	if (In(t1, "HG"))
	{
		// On d�place le pion vers "HG" et on met le tableau de jeu temporaire dans ttemp.
		ttemp = deplacement_cavalier(t, numnom, "HG");

		// On recherche les d�placement possible du pion que l'on a d�plac� temporairement.
		t1tempHG = deplacement_possible_cavalier(ttemp, numnom, -1);

		// On utilise double_verif pour une pr�cision accru et on additionne le r�sultat avec le nombre de d�placement du pion du tableau temporaire.
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

	// Tableau contenant les differants d�placements possible selon le d�placement initial.
	Tab1Dint fin = { tempHG, tempHD, tempGH, tempDH, tempGB, tempDB, tempBG, tempBD };

	// Choisi le d�placement le plus appropri� selon le nombre de d�placement possible (prend le plus grand).
	choix_deplac = deduire_deplace_cavalier(fin);

	//for (int i = 0; i < fin.size(); i++)
	//{
	//	cout << fin[i] << endl;
	//}

	// A faire seulement si c'est un d�placement de pion qui est � faire.
	if (numnom == 3)
	{
		// On recup�re la position du pion numnom et on l'a met dans x et y.
		Tab1Dint t2 = position_pion(t, numnom);
		int x = t2[0], y = t2[1];

		cout << "-------------------------------" << endl;
		cout << "C'est au tour de l'Ordinateur " << " ! (Pion n�" << numnom - 1 << ")" << endl;
		cout << "-------------------------------" << endl;
		cout << "Position actuelle du pion : " << x + 1 << "x" << int_en_char(y) << endl;
		cout << "Les d�placements possibles sont : ";

		// Affiche chaque �l�ment du tableau.
		cout << endl;
		affichage_deplacement_possible_cavalier(t1, numnom);
		cout << endl << "-------------------------------" << endl;
	}
	return choix_deplac;
}

/**
* Fonction qui utilise les fonctions pr�cedantes pour d�duire le bloc � casser.
* @param t le tableau de jeu.
* @return le tableau de jeu avec le bloc cass� (renvoi le tableau complet pour respecter le programme de base.
*
* Degr� de confiance : 100%
* Complexit� : n�
**/
Tab2Dint casse_bloc_ordi_cavalier(Tab2Dint t)
{
	// On recup�re la position du pion de l'ordi et on l'a met dans x et y.
	Tab1Dint t1 = position_pion(t, 2);
	int x = t1[0], y = t1[1];

	// Appel de la fonction qui d�duit le d�placement du pion pour voir o� le joueur pourrai probablement d�placer son pion.
	string ou = demande_deplace_ordi_cavalier(t, 2);

	// En fonction du d�placement renvoy�, on casse le bloc choisi.
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

	// Affiche le d�placement choisi (ici car on � acces directement au variable).
	cout << x + 2 << " x " << int_en_char(y + 1);

	// Retourne le tableau modifi�.
	return t;
}