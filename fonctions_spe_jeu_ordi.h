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

#endif //FONCTIONS_SPE_JEU_ORDI_H_INCLUDED