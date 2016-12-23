#ifndef FONCTIONS_SPE_JEU_ORDI_H_INCLUDED
#define FONCTIONS_SPE_JEU_ORDI_H_INCLUDED

using namespace std;

// Mes raccourcis :
typedef vector<char> Tab1Dchar;
typedef vector<string> Tab1Dstring;
typedef vector<int> Tab1Dint;
typedef vector<vector<int>> Tab2Dint;

string demande_deplace_ordi(Tab2Dint t, int numnom);
Tab2Dint casse_bloc_ordi(Tab2Dint t);
int superieur(Tab1Dint t);
int position_tableau(Tab2Dint tab, int numnom);
Tab1Dint comptage_dans_tableau(Tab1Dint tab, int x);
int alea_dans_tab(Tab1Dint tab);


#endif //FONCTIONS_SPE_JEU_ORDI_H_INCLUDED
