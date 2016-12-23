// --------------------------------
// Auteur : Alexandre l'Heritier
// PcIsola v4.1 : Module fonctions communes pour les modes de jeu.
// Module pour : PcIsola v3.0 et supérieurs
// --------------------------------
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "fonctions_isola.h"
#include <time.h>

string version_pcisola = "4.1";

/**
* Fonction qui permet d'effacer l'historique de la console selon l'OS.
**/
void effacer_console()
{
#ifdef _WIN32
	system("cls");
#elif __unix__
	system("clear");
#endif
}
/**
* Fonction qui permet de faire une pause dans la console selon l'OS. 
**/
void pause_console()
{
#ifdef _WIN32
	cout << endl;
	system("pause.");
#elif __unix__
	cout << endl;
	system("read a");
#endif
}

/**
* Fonction qui verifie si une chaine de caractère est dans la liste.
* @param t le tableau dans lequel faut rechercher.
* @param cherche la chaine de caractère à rechecher..
* @return true si la liste possède la chaine de caractère, false sinon.
**/
bool In(Tab1Dstring t, string cherche)
{
	// Boucle pour parcourir la liste.
	for (int i = 0; i < t.size(); i++)
	{
		// Si la chaine est trouvé, renvoyer true.
		if (t[i] == cherche)
		{
			return true;
		}
	}
	return false;
}

/**
* Fonction qui affiche les déplacements possible de manière carré.
* @param t le tableau à afficher.
**/
void affichage_deplacement_possible(Tab1Dstring t)
{
	// Tableau contenant l'ordre d'affichage des déplacements.
	Tab1Dstring t1 = { "HG", "H", "HD", "G", " ", "D", "BG", "B", "BD" };

	// Boucle qui va afficher les 9 élements.
	for (int i = 0; i < 9; i++)
	{
		// Si le tableau t contient t1[i] alors il est affiché, sinon si on est au milieu du carré, afficher 2 espaces, sinon afficher 1 espace.
		if (In(t, t1[i])) cout << t1[i];
		else if (i == 4) cout << "  ";
		else cout << " ";

		// 1 espace pour séparer les déplacements affichés.
		cout << " ";

		// On met un saut de ligne quand on arrive au bout du carré.
		if (i == 2 || i == 5) cout << endl;
	}
}

/**
* Fonction qui affiche les règles du jeu.
* @param a un string qui permet de déterminer quel mode a été choisi.
**/
void regle(string a)
{
	// Règles à afficher si le jeu classique est choisi.
	if (a == "A" || a == "C" || a == "E" || a == "F")
	{
		cout << "Régle de l'isola classique" << endl;
		cout << "-------------------------------" << endl;
		if (a == "E" || a == "F")
		{
			cout << "Chaque joueur possède un pion. Au début du jeu, les deux pions sont" << endl;
			cout << "placés par les joueurs." << endl;
		}
		else
		{
			cout << "Chaque joueur possède un pion. Au début du jeu, les deux pions sont" << endl;
			cout << "situés au milieu de deux côtés opposés." << endl;
		}
		cout << "A chaque tour, chaque joueur :" << endl;
		cout << "- déplace son pion vers une case libre adjacente ou touchant la case" << endl;
		cout << "  de départ par un coin(comme un roi aux échecs) et" << endl;
		cout << "- détruit ensuite une case du jeu non occupée pour le reste de la partie" << endl;
		cout << "  (dans la version commercialisée, on appuyait avec le doigt sur la case" << endl;
		cout << "  qui se déboitait alors du tablier)." << endl;
		cout << "Le premier joueur qui ne peut plus déplacer son pion - c'est-à-dire qui se" << endl;
		cout << "trouve sur une case qui ne touche plus aucune case libre ni par un côté" << endl;
		cout << "ni par un coin - perd la partie." << endl;
		cout << "Source : Wikipédia" << endl;
	}

	// Règles à afficher si le jeu course est choisi.
	if (a == "B")
	{
		cout << "Régle de l'isola course" << endl;
		cout << "-------------------------------" << endl;
		cout << "Chaque joueur possède un pion. Au début du jeu, les deux pions sont" << endl;
		cout << "situés au milieu de deux côtés opposés." << endl;
		cout << "A chaque tour, chaque joueur :" << endl;
		cout << "- déplace son pion vers une case libre adjacente ou touchant la case" << endl;
		cout << "  de départ par un coin(comme un roi aux échecs) et" << endl;
		cout << "- détruit ensuite une case du jeu non occupée pour le reste de la partie" << endl;
		cout << "  (dans la version commercialisée, on appuyait avec le doigt sur la case" << endl;
		cout << "  qui se déboitait alors du tablier)." << endl;
		cout << "Le premier joueur qui touche le coté de l'adversaire ou qui ne peut plus" << endl;
		cout << "déplacer son pion - c'est-à-dire qui se trouve sur une case qui ne touche" << endl;
		cout << "plus aucune case libre ni par un côté ni par un coin - perd la partie." << endl;
		cout << "Source : Wikipédia" << endl;
	}
	if (a == "D")
	{
		cout << "Régle de l'isola survie" << endl;
		cout << "-------------------------------" << endl;
		cout << "Vous avez un pion, vous devez le déplacer pour éviter de vous faire entourer" << endl;
		cout << "de blocs cassés." << endl;
	}
}

/**
* Fonction qui permet de convertir une chaine de caractère minuscule en CC majuscule.
* @param a une chaine de caractère minuscule et/ou majuscule.
* @return une chaine de caractère majuscule.
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
* Fonction qui converti un entier en caractère.
* @param c un entier.
* @return un caractère.
**/
char int_en_char(int c)
{
	// Tableau contenant les 26 lettres de l'alphabet avec un espace au début (permet de raccourcir la fonction affichage().
	Tab1Dchar t = { ' ',  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

	// Si il y a un dépacement du tableau, renvoyer la dernière lettre (donc Z).
	if (c >= 28)
	{
		return t[26];
	}
	return t[c + 1];
}

/**
* Fonction qui converti un caractère en entier.
* @param c un caractère.
* @return un entier.
**/
int char_en_int(char c)
{
	// Tableau contenant les 26 lettres de l'alphabet.
	Tab1Dchar t = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	Tab1Dchar t2 = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

	// Boucle servant à retrouver la lettre demandée.
	for (int i = 0; i < t.size(); i++)
	{
		if (t[i] == c || t2[i] == c)
		{
			return i;
		}
	}
}

/**
* Fonction qui affiche un tableau.
* @param t le tableau à afficher.
**/
void affichage(Tab2Dint t)
{
	// Double boucle qui parcours tout le tableau 2D (Comme le tableau 2D possède toujours le même nombre de colonne dans chaque ligne, 
	// on peut limiter la deuxième boucle grace au nombre de colonne de la première ligne ou limiter avec la taille de la ligne i, cela revient au même !).
	for (int i = 0; i < t.size(); i++)
	{
		for (int j = 0; j < t[i].size(); j++)
		{
			// Tests qui permettent de mettre des indications de ligne et de colonne lors de l'affichage (Pour éviter de compliquer 
			// encore plus le code (déjà que j'aime pas mettre autant de commentaire dans mes programmes), j'ai mis une troisième 
			// boucle qui complète la première ligne avec les lettres).
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
				// Mettre le numéro de ligne au début de chaques lignes.
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
			// Place une case vide ou détruite ou avec un pion.
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
* Fonction qui crée un tableau, place 2 pions sur la première et dernière ligne et le renvoi.
* @param x le nombre de ligne.
* @param y le nombre de colonne.
* @return le tableau de taille "x" x "y".
**/
Tab2Dint initialisation_tableau(int x, int y, string choix)
{
	// Créer le double tableau qui sera rempli et renvoyé.
	Tab2Dint t(x);

	// Double boucle qui crée des listes dans chaques cases du double tableau et qui le rempli de 0.
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
		// Place les pions à la moitier de la première et dernière ligne. (Diviser deux int renvoi un int, temps mieux !)
		t[0][y / 2] = 2;
		t[x - 1][y / 2] = 3;
	}

	if (choix == "survie")
	{
		// Place les pions à la moitier de la première et dernière ligne. (Diviser deux int renvoi un int, temps mieux !)
		t[x / 2][y / 2] = 2;
	}

	if (choix == "placement_choisi_par_joueur")
	{
		int a = 0, arret = 0;
		char b;
		effacer_console();
		do
		{
			// On affiche la grille de jeu.
			affichage(t);
			cout << "Où mettre le pion du premier joueur ?" << endl;
			cout << "Ligne : ";
			cin >> a;
			cout << endl << "Colonne : ";
			cin >> b;
			// On fait -1 car un tableau commence par 0 et pas par 1.
			a--;

			// Tests pour déterminer si la case est disponible.
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
		// On place le pion.
		t[a][char_en_int(b)] = 2;

		// On remet arret en 0.
		arret = 0;
		effacer_console();
		affichage(t);
		do
		{
			cout << "Où mettre le pion du deuxième joueur ?" << endl;
			cout << "Ligne : ";
			cin >> a;
			cout << endl << "Colonne : ";
			cin >> b;
			// On fait -1 car un tableau commence par 0 et pas par 1.
			x--;

			// Tests pour déterminer si la case est disponible.
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
		// On place le pion.
		t[a][char_en_int(b)] = 3;
	}

	if (choix == "placement_choisi_par_joueur_ordi")
	{
		int a = 0, arret = 0, bc = 0;
		char b;
		effacer_console();
		do
		{
			// On affiche la grille de jeu.
			affichage(t);
			cout << "Où mettre votre pion ?" << endl;
			cout << "Ligne : ";
			cin >> a;
			cout << endl << "Colonne : ";
			cin >> b;
			// On fait -1 car un tableau commence par 0 et pas par 1.
			a--;

			// Tests pour déterminer si la case est disponible.
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
		// On place le pion.
		t[a][char_en_int(b)] = 2;

		// On remet arret en 0.
		arret = 0;
		effacer_console();
		affichage(t);
		do
		{
			// Initialisation du random avec le nombre de seconde depuis le 1 jan. 1975. 
			// Cela permet de ne jamais avoir de nombre identique après deux lancement de programme.
			srand(time(NULL));

			// Prend un nombre aléatoire et fait le modulo taille du tab pour obtenir un nombre entre 0 et taille de tab.
			a = rand() % (x-1);
			bc = rand() % (y-1);
			//cout << a << endl;
			//cout << bc << endl;

			// Tests pour déterminer si la case est disponible.
			if (t[a][bc] == 0)
			{
				arret = 1;
			}
		} while (arret != 1);
		// On place le pion.
		t[a][bc] = 3;
	}
	//t = { {0,0,0,0,2,0,0,0,0},{ 0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,1,1,1 },{ 0,0,0,0,0,0,1,1,1 },{ 0,0,0,0,0,0,1,1,0 },{ 0,0,0,0,0,0,1,1,3 } };
	// Retourne le tableau 2D complété.
	return t;
}

/**
* Fonction qui affiche les déplacement possible et plusieurs autres informations.
* @param t le tableau contenant le pion à déplacer.
* @param nom le nom du joueur.
* @param numnom le numéro du pion.
* @return le déplacement à effectuer.
**/
string demande_deplace(Tab2Dint t, string nom, int numnom)
{
	// Initialisation des variables.
	// x et y la position du pion, z la condition pour que la boucle de verification s'arrete (tout en bas de la fonction).
	// t1 le tableau contenant les déplacements possibles.
	// choix_deplac la cdc contenant le déplacement à renvoyer.
	int x, y, z = 0;
	Tab1Dstring t1;
	string choix_deplac;

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

	// Inscription d'infos.
	cout << "-------------------------------" << endl;
	cout << "C'est au tour de " << nom << " ! (Pion n°" << numnom - 1 << ")" << endl;
	cout << "-------------------------------" << endl;
	cout << "Position actuelle du pion : " << x + 1 << "x" << int_en_char(y) << endl;
	cout << "Les déplacements possibles sont : ";

	// Affiche chaque élément du tableau.
	//for (int i = 0; i < t1.size(); i++)
	//{
	//	cout << t1[i] << " ";
	//}
	cout << endl;
	affichage_deplacement_possible(t1);
	cout << endl << "-------------------------------" << endl;
	cout << "Entrer (S) pour sauver la partie." << endl;

	// Boucle de verification.
	do
	{
		cout << endl << "Où déplacer le pion : ";
		cin >> choix_deplac;

		// Converti une chaine de caractère minucule en majuscule.
		choix_deplac = verif_maj_min(choix_deplac);
		if (choix_deplac == "S") return "S";

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
* Fonction qui effectue le déplacement.
* @param t le tableau contenant le pion à déplacer.
* @param numnom le numéro du pion.
* @param ou le déplacement à effectuer.
* @return le tableau avec le pion déplacé.
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
			// Une fois le pion trouvé, mettre sa position dans x et y.
			if (t[i][j] == numnom)
			{
				x = i;
				y = j;
			}
		}
	}

	// Effectue le déplacement selon la variable ou.
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

	// Met une case vide à l'ancienne case du pion.
	t[x][y] = 0;

	return t;
}

/**
* Fonction qui demande quel bloc casser et le casse.
* @param t le tableau.
* @return le tableau avec le bloc cassé.
**/
Tab2Dint casse_bloc(Tab2Dint t)
{
	// Initialisation des variables.
	// a va contenir la ligne où se situe le bloc à casser, arret permettera l'arret de la boucle de verification.
	// b va contenir la colonne où se situe le bloc à casser.
	int a, arret = 0;
	char b;

	// Boucle de verification.
	do
	{
		// Demande de la ligne et de la colonne.
		cout << endl << "-------------------------------" << endl;
		cout << "Dans quelle ligne se situe le bloc à casser : ";
		cin >> a;
		cout << endl << "Dans quelle colonne se situe le bloc à casser : ";
		cin >> b;
		//b = verif_maj_min(b);

		// On fait -1 car un tableau commence par 0 et pas par 1.
		a--;

		// Tests pour déterminer si la casse de la case est possible.
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
* Fonction qui verifie si le déplacement du pion est possible.
* @param t le tableau à verifier.
* @param numnom le numéro du pion.
* @return faux si le pion est bloqué, vrai sinon.
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
			// Une fois le pion trouvé, mettre sa position dans x et y.
			if (t[i][j] == numnom)
			{
				x = i;
				y = j;
			}
		}
	}

	// Très (très) grande série de test pour trouver si il y a encore des déplacements possibles. (Bonne chance !)
	// Si le pion est sur la première ligne.
	if (x == 0)
	{
		// Si le pion est sur la première colonne. (donc dans l'angle haut gauche)
		if (y == 0)
		{
			// On verifie si les 3 cases autour sont cassé, si oui retourne faux.
			if (t[x + 1][y + 1] != 0 && t[x][y + 1] != 0 && t[x + 1][y] != 0)
			{
				return false;
			}
		}

		// Si le pion est sur la dernière colonne. (donc dans l'angle haut droite)
		else if (y + 1 == t[x].size())
		{
			// On verifie si les 3 cases autour sont cassé, si oui retourne faux.
			if (t[x][y - 1] != 0 && t[x + 1][y] != 0 && t[x + 1][y - 1] != 0)
			{
				return false;
			}
		}

		// Si le pion est sur la première ligne mais pas dans un angle.
		else
		{
			// On verifie si les 5 cases autour sont cassé, si oui retourne faux.
			if (t[x][y - 1] != 0 && t[x + 1][y] != 0 && t[x + 1][y + 1] != 0 && t[x][y + 1] != 0 && t[x + 1][y - 1] != 0)
			{
				return false;
			}
		}
	}

	// Si le pion est sur la dernière ligne.
	else if (x + 1 == t.size())
	{
		// Si le pion est sur la première colonne. (donc dans l'angle bas gauche)
		if (y == 0)
		{
			// On verifie si les 3 cases autour sont cassé, si oui retourne faux.
			if (t[x - 1][y] != 0 && t[x - 1][y + 1] != 0 && t[x][y + 1] != 0)
			{
				return false;
			}
		}

		// Si le pion est sur la dernière colonne. (donc dans l'angle bas droite)
		else if (y + 1 == t[x].size())
		{
			// On verifie si les 3 cases autour sont cassé, si oui retourne faux.
			if (t[x][y - 1] != 0 && t[x - 1][y] != 0 && t[x - 1][y - 1] != 0)
			{
				return false;
			}
		}

		// Si le pion est sur la dernière ligne mais pas dans un angle.
		else
		{
			// On verifie si les 5 cases autour sont cassé, si oui retourne faux.
			if (t[x][y - 1] != 0 && t[x - 1][y - 1] != 0 && t[x - 1][y] != 0 && t[x - 1][y + 1] != 0 && t[x][y + 1] != 0)
			{
				return false;
			}
		}
	}

	// Si le pion est sur la première colonne mais pas dans un angle.
	else if (y == 0 && (x != 0 || x + 1 != t.size()))
	{
		// On verifie si les 5 cases autour sont cassé, si oui retourne faux.
		if (t[x - 1][y] != 0 && t[x - 1][y + 1] != 0 && t[x][y + 1] != 0 && t[x + 1][y + 1] != 0 && t[x + 1][y] != 0)
		{
			return false;
		}
	}

	// Si le pion est sur la dernière colonne mais pas dans un angle.
	else if (y + 1 == t[x].size() && (x != 0 || x + 1 != t.size()))
	{
		// On verifie si les 5 cases autour sont cassé, si oui retourne faux.
		if (t[x - 1][y] != 0 && t[x - 1][y - 1] != 0 && t[x][y - 1] != 0 && t[x + 1][y - 1] != 0 && t[x + 1][y] != 0)
		{
			return false;
		}
	}

	// Si le pion n'est pas sur les bors du tableau.
	else
	{
		// On verifie si les 8 cases autour sont cassé, si oui retourne faux.
		if (t[x - 1][y - 1] != 0 && t[x][y - 1] != 0 && t[x + 1][y - 1] != 0 && t[x + 1][y] != 0 && t[x + 1][y + 1] != 0 && t[x][y + 1] != 0 && t[x - 1][y + 1] != 0 && t[x - 1][y] != 0)
		{
			return false;
		}
	}
	// Si le pion peut se déplacer, on returne vrai.
	return true;
}

/**
* Fonction qui créer une sauvegarde du jeu.
* @param type_de_save le type de sauvegarde (temp ou save).
* @param type_de_jeu le type de jeu (survie, ordi...).
* @param tab_de_jeu le tableau de jeu.
* @param nb_tour le nombre de tour.
* @param nom1 le nom du joueur 1.
* @param nom2 le nom du joueur 2.
* @param gagnant le joueur jouant et sauvegardant.
**/
void sauvegarde(string type_de_save, string type_de_jeu, Tab2Dint tab_de_jeu, int nb_tour, string nom1, string nom2, string gagnant)
{
	// On ouvre le fichier demandé.
	if (type_de_save == "save") type_de_save = "save_PcIsola.save";
	else if (type_de_save == "temp") type_de_save = "temp_PcIsola.save";

	// Création du fichier "save_PcIsola.save".
	ofstream fichier(type_de_save);

	// Inscription de toutes les infos dans le fichier.
	fichier << "Fichier de sauvegarde de PcIsola." << endl << "Version de PcIsola : " << version_pcisola << endl << endl;
	fichier << type_de_jeu << endl;
	fichier << tab_de_jeu.size() << " " << tab_de_jeu[0].size() << endl;

	// On note tous les élements du tableau dans le fichier.
	for (int i = 0; i < tab_de_jeu.size(); i++)
	{
		for (int j = 0; j < tab_de_jeu[0].size(); j++)
		{
			fichier << tab_de_jeu[i][j] << " ";
		}
	}
	fichier << endl << nb_tour;
	fichier << endl << nom1 << endl << nom2 << endl << gagnant;

	// On ferme le fichier.
	fichier.close();
}
