#ifndef FONCTIONS_ISOLA_H_INCLUDED
#define FONCTIONS_ISOLA_H_INCLUDED

using namespace std;

// Mes raccourcis :
typedef vector<char> Tab1Dchar;
typedef vector<string> Tab1Dstring;
typedef vector<int> Tab1Dint;
typedef vector<vector<int>> Tab2Dint;

void effacer_console();
void pause_console();
void regle(string a);
string verif_maj_min(string a);
char int_en_char(int c);
int char_en_int(char c);
Tab2Dint initialisation_tableau(int x, int y, string choix);
void affichage(Tab2Dint t);
string demande_deplace(Tab2Dint t, string nom, int numnom);
Tab2Dint deplacement(Tab2Dint t, int numnom, string ou);
Tab2Dint casse_bloc(Tab2Dint t);
bool possibl_deplac(Tab2Dint t, int numnom);
bool In(Tab1Dstring t, string cherche);
void affichage_deplacement_possible(Tab1Dstring t);
void sauvegarde(string type_de_save, string type_de_jeu, Tab2Dint tab_de_jeu, int nb_tour, string nom1, string nom2, string gagnant);

#endif //FONCTIONS_ISOLA_H_INCLUDED
