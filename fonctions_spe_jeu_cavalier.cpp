// --------------------------------
// Auteur : Alexandre l'Heritier
// PcIsola v5.0 : Module fonction spécifique au mode cavalier.
// Module pour : PcIsola v5.0 et supérieurs
// --------------------------------
#include <iostream>
#include <vector>
#include <string>
#include "fonctions_spe_jeu_cavalier.h"
#include "fonctions_isola.h"

/**
* Fonction qui affiche les déplacements possible de manière carré.
* @param t le tableau à afficher.
*
* Degré de confiance : 95% (Afichage qui peut etre perturbé quand il y a une case qui manque)
* Complexité : n (la taille du tableau t)
**/
void affichage_deplacement_possible_cavalier(Tab1Dstring t, int numnom)
{
	// Tableau contenant l'ordre d'affichage des déplacements.
	cout << endl << "[  ]";
	if (In(t, "HG")) cout << "[HG]";
	else cout << "[  ]";
	cout << "[ ]";
	if (In(t, "HD")) cout << "[HD]";
	else cout << "[  ]";
	cout << "[  ]" << endl;
	if (In(t, "GH")) cout << "[GH]";
	else cout << "[  ]";
	cout << "[  ][ ][  ]";
	if (In(t, "DH")) cout << "[DH]";
	else cout << "[  ]";
	cout << endl;
	cout << "[  ][  ][" << numnom-1 << "][  ][  ]" << endl;
	if (In(t, "GB")) cout << "[GB]";
	else cout << "[  ]";
	cout << "[  ][ ][  ]";
	if (In(t, "DB")) cout << "[DB]";
	else cout << "[  ]";
	cout << endl;
	cout << "[  ]";
	if (In(t, "BG")) cout << "[BG]";
	else cout << "[  ]";
	cout << "[ ]";
	if (In(t, "BD")) cout << "[BD]";
	else cout << "[  ]";
	cout << "[  ]" << endl;
}

/**
* Fonction qui détermine les déplacements possible d'un pion.
* @param t le tableau de jeu.
* @param x la ligne du pion.
* @param y la colonne du pion.
* @return le tableau de de déplacement possible.
*
* Degré de confiance : 90% (Certains déplacements ne sont pas pris en compte lors de rares position du pion).
* Complexité : 37
**/
Tab1Dstring deplacement_possible_cavalier(Tab2Dint t, int x, int y)
{
	// Permet d'adapter la fonction pour l'IA cavalier.
	if (y == -1)
	{
		Tab1Dint t2 = position_pion(t, x);
		x = t2[0], y = t2[1];
	}
	Tab1Dstring t1;
	// Grande serie de test pour trouver les déplacements possibles.
	// Si x != 0 donc si le pion n'est pas sur la première ligne du tableau 2D.
	if (x != 0)
	{
		// Si y >= 2 donc si le pion n'est pas sur les trois premières colonnes.
		if (y >= 2)
		{
			// Si les cases en L sont libre, on peut faire le déplacement.
			if (t[x - 1][y - 2] == 0 && t[x][y - 2] == 0 && t[x][y - 1] == 0)
			{
				t1.push_back("GH");
			}
			// Si x != 1 donc si le pion n'est pas sur la deuxième ligne.
			if (x != 1)
			{
				// Si les cases en L sont libre, on peut faire le déplacement.
				if (t[x - 2][y - 1] == 0 && t[x - 2][y] == 0 && t[x - 1][y] == 0)
				{
					t1.push_back("HG");
				}
			}
		}
		// Si le pion n'est pas sur les trois dernières colonnes.
		if (y + 2 < t[x].size())
		{
			// Si les cases en L sont libre, on peut faire le déplacement.
			if (t[x - 1][y + 2] == 0 && t[x][y + 2] == 0 && t[x][y + 1] == 0)
			{
				t1.push_back("DH");
			}
			// Si x != 1 donc si le pion n'est pas sur la deuxième ligne.
			if (x != 1)
			{
				// Si les cases en L sont libre, on peut faire le déplacement.
				if (t[x - 2][y + 1] == 0 && t[x - 2][y] == 0 && t[x - 1][y] == 0)
				{
					t1.push_back("HD");
				}
			}
		}
	}
	// Si le pion n'est pas sur la dernière ligne.
	if (x + 1 < t.size())
	{
		// Si y >= 2 donc si le pion n'est pas sur les trois premières colonnes.
		if (y >= 2)
		{
			// Si les cases en L sont libre, on peut faire le déplacement.
			if (t[x + 1][y - 2] == 0 && t[x][y - 2] == 0 && t[x][y - 1] == 0)
			{
				t1.push_back("GB");
			}
			// Si le pion n'est pas sur les trois dernières colonnes.
			if (x + 2 < t.size())
			{
				// Si les cases en L sont libre, on peut faire le déplacement.
				if (t[x + 2][y - 1] == 0 && t[x + 2][y] == 0 && t[x + 1][y] == 0)
				{
					t1.push_back("BG");
				}
			}
		}
		// Si le pion n'est pas sur les trois dernières colonnes.
		if (y + 2 < t[x].size())
		{
			// Si les cases en L sont libre, on peut faire le déplacement.
			if (t[x + 1][y + 2] == 0 && t[x][y + 2] == 0 && t[x][y + 1] == 0)
			{
				t1.push_back("DB");
			}
			// Si le pion n'est pas sur les trois dernières colonnes.
			if (x + 2 < t.size())
			{
				// Si les cases en L sont libre, on peut faire le déplacement.
				if (t[x + 2][y + 1] == 0 && t[x + 2][y] == 0 && t[x + 1][y] == 0)
				{
					t1.push_back("BD");
				}
			}
		}
	}
	return t1;
}

/**
* Fonction qui affiche les déplacements possibles et plusieurs autres informations. Pour cavalier uniquement.
* @param t le tableau contenant le pion à déplacer.
* @param nom le nom du joueur.
* @param numnom le numéro du pion.
* @return le déplacement à effectuer.
*
* Degré de confiance : 100%
* Complexité : n
**/
string demande_deplace_cavalier(Tab2Dint t, string nom, int numnom)
{
	// Initialisation des variables.
	// x et y la position du pion, z la condition pour que la boucle de verification s'arrete (tout en bas de la fonction).
	// t1 le tableau contenant les déplacements possibles.
	// choix_deplac la cdc contenant le déplacement à renvoyer.
	int z = 0;
	Tab1Dstring t1;
	string choix_deplac;

	// On recupère la position du pion numnom et on l'a met dans x et y.
	Tab1Dint t2 = position_pion(t, numnom);
	int x = t2[0], y = t2[1];

	t1 = deplacement_possible_cavalier(t, x, y);

	// Inscription d'infos.
	cout << "-------------------------------" << endl;
	cout << "C'est au tour de " << nom << " ! (Pion n°" << numnom - 1 << ")" << endl;
	cout << "-------------------------------" << endl;
	cout << "Position actuelle du pion : " << x + 1 << "x" << int_en_char(y) << endl;
	cout << "Les déplacements possibles sont : ";

	cout << endl;
	affichage_deplacement_possible_cavalier(t1, numnom);
	cout << endl << "-------------------------------" << endl;
	cout << "Entrer (S) pour sauver la partie." << endl;
	cout << "Entrer (Q) pour quitter PcIsola." << endl;

	// Boucle de verification.
	do
	{
		cout << endl << "Où déplacer le pion : ";
		cin >> choix_deplac;

		// Converti une chaine de caractère minucule en majuscule.
		choix_deplac = verif_maj_min(choix_deplac);
		if (choix_deplac == "S") return "S";
		if (choix_deplac == "Q") return "Q";

		if (In(t1, choix_deplac))
		{
			z = 1;
		}
	} while (z != 1);

	return choix_deplac;
}

/**
* Fonction qui effectue le déplacement. Pour cavalier uniquement.
* @param t le tableau contenant le pion à déplacer.
* @param numnom le numéro du pion.
* @param ou le déplacement à effectuer.
* @return le tableau avec le pion déplacé.
*
* Degré de confiance : 100%
* Complexité : n²
**/
Tab2Dint deplacement_cavalier(Tab2Dint t, int numnom, string ou)
{
	// On recupère la position du pion numnom et on l'a met dans x et y.
	Tab1Dint t1 = position_pion(t, numnom);
	int x = t1[0], y = t1[1];

	// Effectue le déplacement selon la variable ou.
	if (ou == "HG")
	{
		t[x - 2][y - 1] = numnom;
	}
	if (ou == "HD")
	{
		t[x - 2][y + 1] = numnom;
	}
	if (ou == "GH")
	{
		t[x - 1][y - 2] = numnom;
	}
	if (ou == "DH")
	{
		t[x - 1][y + 2] = numnom;
	}
	if (ou == "GB")
	{
		t[x + 1][y - 2] = numnom;
	}
	if (ou == "DB")
	{
		t[x + 1][y + 2] = numnom;
	}
	if (ou == "BG")
	{
		t[x + 2][y - 1] = numnom;
	}
	if (ou == "BD")
	{
		t[x + 2][y + 1] = numnom;
	}

	// Met une case vide à l'ancienne case du pion.
	t[x][y] = 0;

	return t;
}

/**
* Fonction qui verifie si le déplacement du pion est possible. Pour cavalier uniquement.
* @param t le tableau à verifier.
* @param numnom le numéro du pion.
* @return faux si le pion est bloqué, vrai sinon.
*
* Degré de confiance : 90%
* Complexité : n²
**/
bool possibl_deplac_cavalier(Tab2Dint t, int numnom)
{
	Tab1Dstring t1;
	// On recupère la position du pion numnom et on l'a met dans x et y.
	Tab1Dint t2 = position_pion(t, numnom);
	int x = t2[0], y = t2[1];

	t1 = deplacement_possible_cavalier(t, x, y);

	if (t1.size() == 0)
		return false;

	// Si le pion peut se déplacer, on returne vrai.
	return true;
}