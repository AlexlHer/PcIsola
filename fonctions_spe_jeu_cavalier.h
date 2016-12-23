#ifndef FONCTIONS_SPE_JEU_CAVALIER_H_INCLUDED
#define FONCTIONS_SPE_JEU_CAVALIER_H_INCLUDED

using namespace std;

// Mes raccourcis :
typedef vector<char> Tab1Dchar;
typedef vector<string> Tab1Dstring;
typedef vector<int> Tab1Dint;
typedef vector<vector<int>> Tab2Dint;

Tab1Dstring deplacement_possible_cavalier(Tab2Dint t, int x, int y);
string demande_deplace_cavalier(Tab2Dint t, string nom, int numnom);
Tab2Dint deplacement_cavalier(Tab2Dint t, int numnom, string ou);
bool possibl_deplac_cavalier(Tab2Dint t, int numnom);
void affichage_deplacement_possible_cavalier(Tab1Dstring t, int numnom);

#endif //FONCTIONS_SPE_JEU_CAVALIER_H_INCLUDED