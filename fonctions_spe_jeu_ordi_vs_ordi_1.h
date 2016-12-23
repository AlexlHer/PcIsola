#ifndef FONCTIONS_SPE_JEU_ORDI_VS_ORDI_1_H_INCLUDED
#define FONCTIONS_SPE_JEU_ORDI_VS_ORDI_1_H_INCLUDED

using namespace std;

// Mes raccourcis :
typedef vector<char> Tab1Dchar;
typedef vector<string> Tab1Dstring;
typedef vector<int> Tab1Dint;
typedef vector<vector<int>> Tab2Dint;

string demande_deplace_ordi_1(Tab2Dint t, int numnom);
Tab2Dint casse_bloc_ordi_1(Tab2Dint t, int numnom);

#endif //FONCTIONS_SPE_JEU_ORDI_VS_ORDI_1_H_INCLUDED