// --------------------------------
// Auteur : Alexandre l'Heritier
// PcIsola v3.0 : Module fonction sp�cifique au mode course.
// --------------------------------
#include <iostream>
#include <vector>
#include "fonctions_spe_jeu_course.h"

/**
* Fonction qui verifie si le pion du joueur touche la zone de l'adversaire (pour Isola course).
* @param t le tableau � verifier.
* @param numnom le num�ro du pion.
* @return faux si le pion est dans la zone de l'adversaire, vrai sinon.
**/
bool gagner(Tab2Dint t, int numnom)
{
	// Initialisation des variables.
	// x et y la position du pion.
	int x, y;

	// Double boucle qui parcours le tableau 2D.
	for (int i = 0; i < t.size(); i++)
	{
		for (int j = 0; j < t[i].size(); j++)
		{
			// Une fois le pion trouv�, mettre sa position dans x et y.
			if (t[i][j] == numnom)
			{
				x = i;
				y = j;
			}
		}
	}

	// Si le pion se situe sur la zone ennemi, retourne faux.
	if (numnom == 2 && x + 1 == t.size())
	{
		return false;
	}
	if (numnom == 3 && x == 0)
	{
		return false;
	}

	return true;
}