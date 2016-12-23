// --------------------------------
// Auteur : Alexandre l'Heritier
// PcIsola v3.0 : Module fonction spécifique au mode ordi.
// --------------------------------
#include <iostream>
#include <vector>
#include <string>
#include "fonctions_spe_jeu_ordi.h"
#include "fonctions_isola.h"

bool In(Tab1Dstring t, string cherche)
{
	for (int i = 0; i < t.size(); i++)
	{
		if (t[i] == cherche)
		{
			return true;
		}
	}
	return false;
}

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

int superieur(Tab1Dint t)
{
	int max = 0;
	for (int i = 0; i < t.size(); i++)
	{
		if (t[i] > max)
		{
			t[i] = max;
		}
	}
	return max;
}

int double_verif(Tab2Dint t, int numnom)
{
	Tab1Dstring t1, t1temp;
	Tab2Dint ttemp;
	Tab1Dint tailles;
	t1 = deplacement_possible(t, numnom);
	if (In(t1, "H"))
	{
		ttemp = deplacement(t, numnom, "H");
		t1temp = deplacement_possible(ttemp, numnom);
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
	return superieur(tailles);
}

string deduire_deplace(Tab1Dint t)
{
	Tab1Dstring liste = { "H", "B", "G", "D", "HD", "HG", "BD", "BG" };
	string fin = "";
	int temp = 0;
	for (int i = 0; i < t.size(); i++)
	{
		if (t[i] > temp)
		{
			temp = t[i];
			fin = liste[i];
		}
	}
	return fin;
}

string demande_deplace_ordi(Tab2Dint t, int numnom)
{
	int tempH = 0, tempB = 0, tempG = 0, tempD = 0, tempHD = 0, tempHG = 0, tempBD = 0, tempBG = 0;
	Tab1Dstring t1, t1tempH, t1tempB, t1tempG, t1tempD, t1tempHD, t1tempHG, t1tempBD, t1tempBG;
	Tab2Dint ttemp;
	string choix_deplac;
	t1 = deplacement_possible(t, numnom);
	if (In(t1, "H"))
	{
		ttemp = deplacement(t, numnom, "H");
		t1tempH = deplacement_possible(ttemp, numnom);
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
	Tab1Dint fin = { tempH, tempB, tempG, tempD, tempHD, tempHG, tempBD, tempBG };
	//for (int i = 0; i < fin.size(); i++)
	//{
	//	cout << fin[i] << endl;
	//}

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
		for (int i = 0; i < t1.size(); i++)
		{
			cout << t1[i] << " ";
		}
		cout << endl << "-------------------------------" << endl;
	}
	return deduire_deplace(fin);
}

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
	string ou = demande_deplace_ordi(t, 2);
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
	cout << x+2 << " x " << int_en_char(y+1);
	return t;
}