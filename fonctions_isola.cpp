// --------------------------------
// Auteur : Alexandre l'Heritier
// PcIsola v3.0 : Module fonctions communes pour les modes de jeu.
// --------------------------------
#include <iostream>
#include <vector>
#include <string>
#include "fonctions_isola.h"

/**
* Fonction qui affiche les r�gles du jeu.
* @param a un string qui permet de d�terminer quel mode a �t� choisi.
**/
void regle(string a)
{
	// R�gles � afficher si le jeu classique est choisi.
	if (a == "A" || a == "C")
	{
		cout << "R�gle de l'isola classique" << endl;
		cout << "-------------------------------" << endl;
		cout << "Chaque joueur poss�de un pion. Au d�but du jeu, les deux pions sont" << endl;
		cout << "situ�s au milieu de deux c�t�s oppos�s." << endl;
		cout << "A chaque tour, chaque joueur :" << endl;
		cout << "- d�place son pion vers une case libre adjacente ou touchant la case" << endl;
		cout << "  de d�part par un coin(comme un roi aux �checs) et" << endl;
		cout << "- d�truit ensuite une case du jeu non occup�e pour le reste de la partie" << endl;
		cout << "  (dans la version commercialis�e, on appuyait avec le doigt sur la case" << endl;
		cout << "  qui se d�boitait alors du tablier)." << endl;
		cout << "Le premier joueur qui ne peut plus d�placer son pion - c'est-�-dire qui se" << endl;
		cout << "trouve sur une case qui ne touche plus aucune case libre ni par un c�t�" << endl;
		cout << "ni par un coin - perd la partie." << endl;
		cout << "Source : Wikip�dia" << endl;
	}

	// R�gles � afficher si le jeu course est choisi.
	if (a == "B")
	{
		cout << "R�gle de l'isola course" << endl;
		cout << "-------------------------------" << endl;
		cout << "Chaque joueur poss�de un pion. Au d�but du jeu, les deux pions sont" << endl;
		cout << "situ�s au milieu de deux c�t�s oppos�s." << endl;
		cout << "A chaque tour, chaque joueur :" << endl;
		cout << "- d�place son pion vers une case libre adjacente ou touchant la case" << endl;
		cout << "  de d�part par un coin(comme un roi aux �checs) et" << endl;
		cout << "- d�truit ensuite une case du jeu non occup�e pour le reste de la partie" << endl;
		cout << "  (dans la version commercialis�e, on appuyait avec le doigt sur la case" << endl;
		cout << "  qui se d�boitait alors du tablier)." << endl;
		cout << "Le premier joueur qui touche le cot� de l'adversaire ou qui ne peut plus" << endl;
		cout << "d�placer son pion - c'est-�-dire qui se trouve sur une case qui ne touche" << endl;
		cout << "plus aucune case libre ni par un c�t� ni par un coin - perd la partie." << endl;
		cout << "Source : Wikip�dia" << endl;
	}
	if (a == "D")
	{
		cout << "R�gle de l'isola survie" << endl;
		cout << "-------------------------------" << endl;
		cout << "Vous avez un pion, vous devez le d�placer pour �viter de vous faire entourer" << endl;
		cout << "de blocs cass�s." << endl;
	}
}

/**
* Fonction qui permet de convertir une chaine de caract�re minuscule en CC majuscule.
* @param a une chaine de caract�re minuscule et/ou majuscule.
* @return une chaine de caract�re majuscule.
**/
string verif_maj_min(string a)
{
	// Les deux listes contenant les majuscules et les minuscules.
	Tab1Dchar t1 = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	Tab1Dchar t2 = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

	// Boucles qui recherche les minuscules dans la liste et remplace par une majuscule.
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < t2.size(); j++)
		{
			if (a[i] == t2[j])
			{
				a[i] = t1[j];
			}
		}
	}
	return a;
}

/**
* Fonction qui converti un entier en caract�re.
* @param c un entier.
* @return un caract�re.
**/
char int_en_char(int c)
{
	// Tableau contenant les 26 lettres de l'alphabet avec un espace au d�but (permet de raccourcir la fonction affichage().
	Tab1Dchar t = { ' ',  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

	// Si il y a un d�pacement du tableau, renvoyer la derni�re lettre (donc Z).
	if (c >= 28)
	{
		return t[26];
	}
	return t[c + 1];
}

/**
* Fonction qui converti un caract�re en entier.
* @param c un caract�re.
* @return un entier.
**/
int char_en_int(char c)
{
	// Tableau contenant les 26 lettres de l'alphabet.
	Tab1Dchar t = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	Tab1Dchar t2 = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

	// Boucle servant � retrouver la lettre demand�e.
	for (int i = 0; i < t.size(); i++)
	{
		if (t[i] == c || t2[i] == c)
		{
			return i;
		}
	}
}

/**
* Fonction qui cr�e un tableau, place 2 pions sur la premi�re et derni�re ligne et le renvoi.
* @param x le nombre de ligne.
* @param y le nombre de colonne.
* @return le tableau de taille "x" x "y".
**/
Tab2Dint initialisation_tableau(int x, int y, string choix)
{
	// Cr�er le double tableau qui sera rempli et renvoy�.
	Tab2Dint t(x);

	// Double boucle qui cr�e des listes dans chaques cases du double tableau et qui le rempli de 0.
	for (int i = 0; i < x; i++)
	{
		t[i] = Tab1Dint(y);
		for (int j = 0; j < y; j++)
		{
			t[i][j] = 0;
		}
	}

	if (choix == "normal")
	{
		// Place les pions � la moitier de la premi�re et derni�re ligne. (Diviser deux int renvoi un int, temps mieux !)
		t[0][y / 2] = 2;
		t[x - 1][y / 2] = 3;
	}

	if (choix == "survie")
	{
		// Place les pions � la moitier de la premi�re et derni�re ligne. (Diviser deux int renvoi un int, temps mieux !)
		t[x / 2][y / 2] = 2;
	}

	//t = { {0,0,0,0,2,0,0,0,0},{ 0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,1,1,1 },{ 0,0,0,0,0,0,1,1,1 },{ 0,0,0,0,0,0,1,1,0 },{ 0,0,0,0,0,0,1,1,3 } };
	// Retourne le tableau 2D compl�t�.
	return t;
}

/**
* Fonction qui affiche un tableau.
* @param t le tableau � afficher.
**/
void affichage(Tab2Dint t)
{
	// Double boucle qui parcours tout le tableau 2D (Comme le tableau 2D poss�de toujours le m�me nombre de colonne dans chaque ligne, 
	// on peut limiter la deuxi�me boucle grace au nombre de colonne de la premi�re ligne ou limiter avec la taille de la ligne i, cela revient au m�me !).
	for (int i = 0; i < t.size(); i++)
	{
		for (int j = 0; j < t[i].size(); j++)
		{
			// Tests qui permettent de mettre des indications de ligne et de colonne lors de l'affichage (Pour �viter de compliquer 
			// encore plus le code (d�j� que j'aime pas mettre autant de commentaire dans mes programmes), j'ai mis une troisi�me 
			// boucle qui compl�te la premi�re ligne avec les lettres).
			if (i == 0 || j == 0)
			{
				if (i == 0 && j == 0)
				{
					for (int k = 0; k < t[0].size() + 1; k++)
					{
						if (k == 0)
						{
							cout << "  " << int_en_char(k - 1) << " ";
						}
						else
						{
							cout << " " << int_en_char(k - 1) << " ";
						}
					}
					cout << endl;
				}
				// Mettre le num�ro de ligne au d�but de chaques lignes.
				if (j == 0 && i >= 0)
				{
					if (i >= 0 && i < 9)
					{
						cout << "  " << i + 1 << " ";
					}
					else
					{
						cout << " " << i + 1 << " ";
					}
				}
			}
			// Place une case vide ou d�truite ou avec un pion.
			if (t[i][j] == 0)
			{
				cout << "[ ]";
			}
			if (t[i][j] == 1)
			{
				cout << "[X]";
			}
			if (t[i][j] == 2)
			{
				cout << "[1]";
			}
			if (t[i][j] == 3)
			{
				cout << "[2]";
			}
		}
		cout << endl;
	}
}

/**
* Fonction qui affiche les d�placement possible et plusieurs autres informations.
* @param t le tableau contenant le pion � d�placer.
* @param nom le nom du joueur.
* @param numnom le num�ro du pion.
* @return le d�placement � effectuer.
**/
string demande_deplace(Tab2Dint t, string nom, int numnom)
{
	// Initialisation des variables.
	// x et y la position du pion, z la condition pour que la boucle de verification s'arrete (tout en bas de la fonction).
	// t1 le tableau contenant les d�placements possibles.
	// choix_deplac la cdc contenant le d�placement � renvoyer.
	int x, y, z = 0;
	Tab1Dstring t1;
	string choix_deplac;

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
	// Grande serie de test pour trouver les d�placements possibles.
	// Si x != 0 donc si le pion n'est pas sur la premi�re ligne du tableau 2D.
	if (x != 0)
	{
		// Si la case au dessus n'est pas casser ou pas prise par un autre pion, H possible.
		if (t[x - 1][y] == 0)
		{
			t1.push_back("H");
		}
		// Si y != 0 donc si le pion n'est pas sur la premi�re colonne.
		if (y != 0)
		{
			// Si la case au dessus et � gauche n'est pas cass� ou pas prise par un autre pion, HG possible.
			if (t[x - 1][y - 1] == 0)
			{
				t1.push_back("HG");
			}
		}
		// Si y + 1 != taille de la x ligne donc si le pion n'est pas sur la derni�re colonne.
		if (y + 1 != t[x].size())
		{
			// Si la case au dessus et � droite n'est pas cass� ou pas prise par un autre pion, HD possible.
			if (t[x - 1][y + 1] == 0)
			{
				t1.push_back("HD");
			}
		}
	}
	// Si x + 1 != taille des colonnes donc si le pion n'est pas sur la derni�re ligne du tableau 2D.
	if (x + 1 != t.size())
	{
		// Si la case en dessous n'est pas casser ou pas prise par un autre pion, B possible.
		if (t[x + 1][y] == 0)
		{
			t1.push_back("B");
		}
		// Si y != 0 donc si le pion n'est pas sur la premi�re colonne.
		if (y != 0)
		{
			// Si la case en dessous et � gauche n'est pas cass� ou pas prise par un autre pion, BG possible.
			if (t[x + 1][y - 1] == 0)
			{
				t1.push_back("BG");
			}
		}
		// Si y + 1 != taille de la x ligne donc si le pion n'est pas sur la derni�re colonne.
		if (y + 1 != t[x].size())
		{
			// Si la case en dessous et � droite n'est pas cass� ou pas prise par un autre pion, BD possible.
			if (t[x + 1][y + 1] == 0)
			{
				t1.push_back("BD");
			}
		}
	}
	// Si y != 0 donc si le pion d'est pas sur la premi�re colonne.
	if (y != 0)
	{
		// Si la case � gauche est vide alors G possible.
		if (t[x][y - 1] == 0)
		{
			t1.push_back("G");
		}
	}
	// Si y + 1 != taille de la x ligne donc si le pion n'est pas sur la derni�re colonne.
	if (y + 1 != t[x].size())
	{
		// Si la case � droite est vide alors D possible.
		if (t[x][y + 1] == 0)
		{
			t1.push_back("D");
		}
	}

	// Inscription d'infos.
	cout << "-------------------------------" << endl;
	cout << "C'est au tour de " << nom << " ! (Pion n�" << numnom - 1 << ")" << endl;
	cout << "-------------------------------" << endl;
	cout << "Position actuelle du pion : " << x + 1 << "x" << int_en_char(y) << endl;
	cout << "Les d�placements possibles sont : ";

	// Affiche chaque �l�ment du tableau.
	for (int i = 0; i < t1.size(); i++)
	{
		cout << t1[i] << " ";
	}
	cout << endl << "-------------------------------" << endl;

	// Boucle de verification.
	do
	{
		cout << endl << "O� d�placer le pion : ";
		cin >> choix_deplac;

		// Converti une chaine de caract�re minucule en majuscule.
		choix_deplac = verif_maj_min(choix_deplac);

		for (int i = 0; i < t1.size(); i++)
		{
			if (t1[i] == choix_deplac)
			{
				z = 1;
			}
		}
	} while (z != 1);

	return choix_deplac;
}

/**
* Fonction qui effectue le d�placement.
* @param t le tableau contenant le pion � d�placer.
* @param numnom le num�ro du pion.
* @param ou le d�placement � effectuer.
* @return le tableau avec le pion d�plac�.
**/
Tab2Dint deplacement(Tab2Dint t, int numnom, string ou)
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

	// Effectue le d�placement selon la variable ou.
	if (ou == "H")
	{
		t[x - 1][y] = numnom;
	}
	if (ou == "B")
	{
		t[x + 1][y] = numnom;
	}
	if (ou == "G")
	{
		t[x][y - 1] = numnom;
	}
	if (ou == "D")
	{
		t[x][y + 1] = numnom;
	}
	if (ou == "HG")
	{
		t[x - 1][y - 1] = numnom;
	}
	if (ou == "HD")
	{
		t[x - 1][y + 1] = numnom;
	}
	if (ou == "BG")
	{
		t[x + 1][y - 1] = numnom;
	}
	if (ou == "BD")
	{
		t[x + 1][y + 1] = numnom;
	}

	// Met une case vide � l'ancienne case du pion.
	t[x][y] = 0;

	return t;
}

/**
* Fonction qui demande quel bloc casser et le casse.
* @param t le tableau.
* @return le tableau avec le bloc cass�.
**/
Tab2Dint casse_bloc(Tab2Dint t)
{
	// Initialisation des variables.
	// a va contenir la ligne o� se situe le bloc � casser, arret permettera l'arret de la boucle de verification.
	// b va contenir la colonne o� se situe le bloc � casser.
	int a, arret = 0;
	char b;

	// Boucle de verification.
	do
	{
		// Demande de la ligne et de la colonne.
		cout << endl << "-------------------------------" << endl;
		cout << "Dans quelle ligne se situe le bloc � casser : ";
		cin >> a;
		cout << endl << "Dans quelle colonne se situe le bloc � casser : ";
		cin >> b;
		//b = verif_maj_min(b);

		// On fait -1 car un tableau commence par 0 et pas par 1.
		a--;

		// Tests pour d�terminer si la casse de la case est possible.
		if (a < t.size() && a >= 0)
		{
			if (char_en_int(b) < t[a].size() && char_en_int(b) >= 0)
			{
				if (t[a][char_en_int(b)] == 0)
				{
					arret = 1;
				}
			}
		}
	} while (arret != 1);

	// On casse le bloc.
	t[a][char_en_int(b)] = 1;

	return t;
}

/**
* Fonction qui verifie si le d�placement du pion est possible.
* @param t le tableau � verifier.
* @param numnom le num�ro du pion.
* @return faux si le pion est bloqu�, vrai sinon.
**/
bool possibl_deplac(Tab2Dint t, int numnom)
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

	// Tr�s (tr�s) grande s�rie de test pour trouver si il y a encore des d�placements possibles. (Bonne chance !)
	// Si le pion est sur la premi�re ligne.
	if (x == 0)
	{
		// Si le pion est sur la premi�re colonne. (donc dans l'angle haut gauche)
		if (y == 0)
		{
			// On verifie si les 3 cases autour sont cass�, si oui retourne faux.
			if (t[x + 1][y + 1] != 0 && t[x][y + 1] != 0 && t[x + 1][y] != 0)
			{
				return false;
			}
		}

		// Si le pion est sur la derni�re colonne. (donc dans l'angle haut droite)
		else if (y + 1 == t[x].size())
		{
			// On verifie si les 3 cases autour sont cass�, si oui retourne faux.
			if (t[x][y - 1] != 0 && t[x + 1][y] != 0 && t[x + 1][y - 1] != 0)
			{
				return false;
			}
		}

		// Si le pion est sur la premi�re ligne mais pas dans un angle.
		else
		{
			// On verifie si les 5 cases autour sont cass�, si oui retourne faux.
			if (t[x][y - 1] != 0 && t[x + 1][y] != 0 && t[x + 1][y + 1] != 0 && t[x][y + 1] != 0 && t[x + 1][y - 1] != 0)
			{
				return false;
			}
		}
	}

	// Si le pion est sur la derni�re ligne.
	else if (x + 1 == t.size())
	{
		// Si le pion est sur la premi�re colonne. (donc dans l'angle bas gauche)
		if (y == 0)
		{
			// On verifie si les 3 cases autour sont cass�, si oui retourne faux.
			if (t[x - 1][y] != 0 && t[x - 1][y + 1] != 0 && t[x][y + 1] != 0)
			{
				return false;
			}
		}

		// Si le pion est sur la derni�re colonne. (donc dans l'angle bas droite)
		else if (y + 1 == t[x].size())
		{
			// On verifie si les 3 cases autour sont cass�, si oui retourne faux.
			if (t[x][y - 1] != 0 && t[x - 1][y] != 0 && t[x - 1][y - 1] != 0)
			{
				return false;
			}
		}

		// Si le pion est sur la derni�re ligne mais pas dans un angle.
		else
		{
			// On verifie si les 5 cases autour sont cass�, si oui retourne faux.
			if (t[x][y - 1] != 0 && t[x - 1][y - 1] != 0 && t[x - 1][y] != 0 && t[x - 1][y + 1] != 0 && t[x][y + 1] != 0)
			{
				return false;
			}
		}
	}

	// Si le pion est sur la premi�re colonne mais pas dans un angle.
	else if (y == 0 && (x != 0 || x + 1 != t.size()))
	{
		// On verifie si les 5 cases autour sont cass�, si oui retourne faux.
		if (t[x - 1][y] != 0 && t[x - 1][y + 1] != 0 && t[x][y + 1] != 0 && t[x + 1][y + 1] != 0 && t[x + 1][y] != 0)
		{
			return false;
		}
	}

	// Si le pion est sur la derni�re colonne mais pas dans un angle.
	else if (y + 1 == t[x].size() && (x != 0 || x + 1 != t.size()))
	{
		// On verifie si les 5 cases autour sont cass�, si oui retourne faux.
		if (t[x - 1][y] != 0 && t[x - 1][y - 1] != 0 && t[x][y - 1] != 0 && t[x + 1][y - 1] != 0 && t[x + 1][y] != 0)
		{
			return false;
		}
	}

	// Si le pion n'est pas sur les bors du tableau.
	else
	{
		// On verifie si les 8 cases autour sont cass�, si oui retourne faux.
		if (t[x - 1][y - 1] != 0 && t[x][y - 1] != 0 && t[x + 1][y - 1] != 0 && t[x + 1][y] != 0 && t[x + 1][y + 1] != 0 && t[x][y + 1] != 0 && t[x - 1][y + 1] != 0 && t[x - 1][y] != 0)
		{
			return false;
		}
	}
	// Si le pion peut se d�placer, on returne vrai.
	return true;
}