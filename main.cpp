// Auteur : Alexandre l'Heritier
// Projet Isola v0.6
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Mes raccourcis :
typedef vector<int> Tab1Dint;
typedef vector<vector<int>> Tab2Dint;
typedef vector<char> Tab1Dchar;
typedef vector<string> Tab1Dstring;

char int_en_char(int c)
{
	Tab1Dchar t = { ' ',  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	return t[c+1];
}

int char_en_int(char c)
{
	Tab1Dchar t = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	for (int i = 0; i < t.size(); i++)
	{
		if (t[i] == c)
		{
			return i;
		}
	}
}

Tab2Dint initialisation_tableau()
{
	Tab2Dint t(6);
	for (int i = 0; i < 6; i++) {
		t[i] = Tab1Dint(8);
		for (int j = 0; j < 8; j++) {
			t[i][j] = 0;
		}
	}
	t[2][0] = 2;
	t[2][7] = 3;
	t = { {0, 0, 2, 0, 0, 0}, { 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 3, 0, 0 } };
	return t;
}

void affichage(Tab2Dint t)
{
	for (int i = 0; i < t.size(); i++)
	{
		for (int j = 0; j < t[i].size(); j++)
		{
			if (i == 0 || j == 0)
			{
				if (i == 0 && j == 0)
				{
					for (int k = 0; k < t[0].size() + 1; k++)
					{
						cout << " " << int_en_char(k - 1) << " ";
					}
					cout << endl;
				}
				if (j == 0 && i >= 0)
				{
					cout << " " << i + 1 << " ";
				}
			}
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

string demande_deplace(Tab2Dint t, string nom, int numnom)
{
	int x, y, z = 0; 
	Tab1Dstring t1;
	string choix_deplac;
	for (int i = 0; i < t.size(); i++)
	{
		for (int j = 0; j < t[i].size(); j++)
		{
			if (t[i][j] == numnom)
			{
				x = i;
				y = j;
			}
		}
	}
	if (x != 0)
	{
		if (t[x - 1][y] == 0)
		{
			t1.push_back("H");
		}
		if (y != 0)
		{
			if (t[x - 1][y - 1] == 0)
			{
				t1.push_back("HG");
			}
		}
		if (y + 1 != t[x].size())
		{
			if (t[x - 1][y + 1] == 0)
			{
				t1.push_back("HD");
			}
		}
	}
	if (x + 1 != t.size())
	{
		if (t[x + 1][y] == 0)
		{
			t1.push_back("B");
		}
		if (y != 0)
		{
			if (t[x + 1][y - 1] == 0)
			{
				t1.push_back("BG");
			}
		}
		if (y + 1 != t[x].size())
		{
			if (t[x + 1][y + 1] == 0)
			{
				t1.push_back("BD");
			}
		}
	}
	if (y != 0)
	{
		if (t[x][y - 1] == 0)
		{
			t1.push_back("G");
		}
	}
	if (y+1 != t[x].size())
	{
		if (t[x][y + 1] == 0)
		{
			t1.push_back("D");
		}
	}
	cout << "C'est au tour de " << nom << " (Jeton n°" << numnom-1 << ")" << endl;
	cout << "Position actuelle du pion : " << x+1 << "x" << int_en_char(y) << endl;
	cout << "Les déplacements disponibles sont : ";
	for (int i = 0; i < t1.size(); i++)
	{
		cout << t1[i] << " ";
	}
	do
	{
		cout << endl << "Votre choix : ";
		cin >> choix_deplac;
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

Tab2Dint deplacement(Tab2Dint t, int numnom, string ou)
{
	int x, y;
	for (int i = 0; i < t.size(); i++)
	{
		for (int j = 0; j < t[i].size(); j++)
		{
			if (t[i][j] == numnom)
			{
				x = i;
				y = j;
			}
		}
	}
	if (ou == "H")
	{
		t[x-1][y] = numnom;
	}
	if (ou == "B")
	{
		t[x+1][y] = numnom;
	}
	if (ou == "G")
	{
		t[x][y-1] = numnom;
	}
	if (ou == "D")
	{
		t[x][y+1] = numnom;
	}
	if (ou == "HG")
	{
		t[x-1][y-1] = numnom;
	}
	if (ou == "HD")
	{
		t[x-1][y+1] = numnom;
	}
	if (ou == "BG")
	{
		t[x+1][y-1] = numnom;
	}
	if (ou == "BD")
	{
		t[x+1][y+1] = numnom;
	}
	t[x][y] = 0;
	return t;
}

Tab2Dint casse_bloc(Tab2Dint t)
{
	int a, arret = 0;
	char b;
	do
	{
		cout << "Dans quelle ligne se situe le bloc à casser : ";
		cin >> a;
		cout << endl << "Dans quelle colonne se situe le bloc à casser : ";
		cin >> b;
		a--;
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
	t[a][char_en_int(b)] = 1;
	return t;
}

bool possibl_deplac(Tab2Dint t, int numnom)
{
	int x, y;
	for (int i = 0; i < t.size(); i++)
	{
		for (int j = 0; j < t[i].size(); j++)
		{
			if (t[i][j] == numnom)
			{
				x = i;
				y = j;
			}
		}
	}
	if (x == 0)
	{
		if (y == 0)
		{
			if (t[x + 1][y + 1] != 0 && t[x][y + 1] != 0 && t[x + 1][y] != 0)
			{
				return false;
			}
		}
		else if (y + 1 == t[x].size())
		{
			if (t[x][y - 1] != 0 && t[x + 1][y] != 0 && t[x + 1][y - 1] != 0)
			{
				return false;
			}
		}
		else
		{
			if (t[x][y - 1] != 0 && t[x + 1][y] != 0 && t[x + 1][y + 1] != 0 && t[x][y + 1] != 0 && t[x + 1][y - 1] != 0)
			{
				return false;
			}
		}
	}
	else if (x + 1 == t.size())
	{
		if (y == 0)
		{
			if (t[x - 1][y] != 0 && t[x - 1][y + 1] != 0 && t[x][y + 1] != 0)
			{
				return false;
			}
		}
		else if (y + 1 == t[x].size())
		{
			if (t[x][y - 1] != 0 && t[x - 1][y] != 0 && t[x - 1][y - 1] != 0)
			{
				return false;
			}
		}
		else
		{
			if (t[x][y - 1] != 0 && t[x - 1][y - 1] != 0 && t[x - 1][y] != 0 && t[x - 1][y + 1] != 0 && t[x][y + 1] != 0)
			{
				return false;
			}
		}
	}
	else if (y == 0 && (x != 0 || x + 1 != t.size()))
	{
		if (t[x - 1][y] != 0 && t[x - 1][y + 1] != 0 && t[x][y + 1] != 0 && t[x + 1][y + 1] != 0 && t[x + 1][y] != 0)
		{
			return false;
		}
	}
	else if (y + 1 == t[x].size() && (x != 0 || x + 1 != t.size()))
	{
		if (t[x - 1][y] != 0 && t[x - 1][y - 1] != 0 && t[x][y - 1] != 0 && t[x + 1][y - 1] != 0 && t[x + 1][y] != 0)
		{
			return false;
		}
	}
	else
	{
		if (t[x - 1][y - 1] != 0 && t[x][y - 1] != 0 && t[x + 1][y - 1] != 0 && t[x + 1][y] != 0 && t[x + 1][y + 1] != 0 && t[x][y + 1] != 0 && t[x - 1][y + 1] != 0 && t[x - 1][y] != 0)
		{
			return false;
		}
	}
	return true;
}

bool gagner(Tab2Dint t, int numnom)
{
	int x, y;
	for (int i = 0; i < t.size(); i++)
	{
		for (int j = 0; j < t[i].size(); j++)
		{
			if (t[i][j] == numnom)
			{
				x = i;
				y = j;
			}
		}
	}
	if (numnom == 2 && x+1 == t.size())
	{
		return false;
	}
	if (numnom == 3 && x == 0)
	{
		return false;
	}
	return true;
}

int main()
{
	string nom1, nom2, deplace;
	Tab2Dint t = initialisation_tableau();
	affichage(t);
	cout << "Quelle est le premier nom : ";
	getline(cin, nom1);
	cout << endl << "Quelle est le deuxième nom : ";
	getline(cin, nom2);
	cout << endl;
	while (gagner(t, 2) && gagner(t, 3) && possibl_deplac(t, 2) && possibl_deplac(t, 3))
	{
		affichage(t);
		deplace = demande_deplace(t, nom1, 2);
		t = deplacement(t, 2, deplace);
		t = casse_bloc(t);
	}
	return 0;
}
/**
Changelog :
v1.0 :
Fonction main() refaite complètement pour correspondre aux règles de l'isola.

v0.6 :
Remplacement des cin par des getline() dans main().
Fonction casse_bloc() corrigé : 
-Première ligne = 1 et non 0.
-Condition pour valider l'entrer de l'utilisateur renforcé.
Fonction demande_deplace() corrigé :
-Affichage de la position du pion corrigé.
-Affichage des déplacements possible amélioré.
Fonction affichage() amélioré (indication des lignes et des colonnes).

v0.5 :
Fonction possibl_deplac() réecrite complètement.

v0.4.1 :
Correction de la fonction gagner().

v0.4 :
Corrections dans la fonction casse_bloc().
Fonction gagner() ne fonctionne pas.
Fonction possibl_deplac() ne fonctionne pas.

v0.3.20 :
Fonction affichage() réduite à sa fonction de base : afficher un tableau.

v0.3.12 : 
Correction de bugs dans la fonction demande_deplace().

v0.3.11 :
Fonction demande_deplace() refaite de zero.

v0.3.2 -> v0.3.10 :
Correction de bugs dans demande_deplace().

v0.3.1 :
Correction de bugs dans demande_deplace().
Fonction affichage() ne fonctionne pas (n'affiche rien).

v0.3 :
Remplissage des fonctions du scelettes :
-Fonction deplacement découpé en deux fonctions : demande_deplace() et deplacement().
-Création des fonctions char_en_int() et int_en_char().
Création d'une fonction main() provisoire permettant de tester le programme.
pos_dep() renommé en possibl_deplac()

v0.2 :
Création du scelette provisoire du programme :
-Fonction deplacement() pour déplacer les pions.
-Fonction casse_bloc() pour casser un bloc.
-Fonction de test gagner() et pos_dep().

v0.1 :
Initialisation du projet Isola.
Création de la fonction initialisation_tableau().
Création de la fonction affichage().

**/