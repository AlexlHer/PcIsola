// --------------------------------
// Auteur : Alexandre l'Heritier
// PcIsola v3.0
// --------------------------------
#include <iostream>
#include <vector>
#include <string>
#include "fonctions_isola.h"
#include "fonctions_spe_jeu_course.h"
#include "fonctions_spe_jeu_ordi.h"
#include "fonctions_spe_jeu_ordi_vs_ordi_1.h"
#include "fonctions_spe_jeu_ordi_vs_ordi_2.h"

using namespace std;

// Mes raccourcis :
typedef vector<vector<int>> Tab2Dint;
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
 * Fonction secondaire qui permet de lancer le jeu classique.
**/
void jeu_classique()
{
	// Initialisation des variables.
	// nb_tour permet de compter les tours, taille_tab_x et taille_tab_y contiennent la taille du tableau choisi par l'utilisateur.
	// nom1 est le nom du premier joueur, nom2 est le nom du deuxième joueur, deplace contient le déplacement choisi par l'utilisateur, gagnant contient le nom du gagnant.
	int nb_tour = 0, taille_tab_x = 0, taille_tab_y = 0;
	string nom1, nom2, deplace, gagnant;

	// On demande les infos des joueurs.
	cout << "Quelle est le nom du premier joueur : ";
	getline(cin, nom1);
	cout << endl << "Quelle est le nom du deuxième joueur : ";
	getline(cin, nom2);
	cout << endl << "Quelle est la taille du tableau x (Par défaut : 8) : ";
	cin >> taille_tab_x;
	cout << endl << "Quelle est la taille du tableau y (Par défaut : 6) : ";
	cin >> taille_tab_y;

	// On initialise le tableau.
	Tab2Dint t = initialisation_tableau(taille_tab_x, taille_tab_y, "normal");
	cout << endl;

	// Tant que personne n'a gagné.
	while (possibl_deplac(t, 2) && possibl_deplac(t, 3))
	{
		// On ajoute un tour.
		nb_tour++;

		// On rempli gagnant au cas où il gagne.
		gagnant = nom1;

		effacer_console();

		// On affiche le tableau de jeu.
		affichage(t);

		cout << endl << "-------------------------------" << endl;
		cout << "Isola Classique / Tour " << nb_tour << endl;

		// On demande le déplacement au joueur.
		deplace = demande_deplace(t, nom1, 2);

		// On déplace le pion selon la demande du joueur.
		t = deplacement(t, 2, deplace);

		effacer_console();
		affichage(t);

		// On demande au joueur de casser un bloc et on le casse.
		t = casse_bloc(t);


		effacer_console();

		// Au tour du deuxième joueur.
		if (possibl_deplac(t, 2))
		{
			gagnant = nom2;
			affichage(t);
			cout << endl << "-------------------------------" << endl;
			cout << "Isola Classique / Tour " << nb_tour << endl;
			deplace = demande_deplace(t, nom2, 3);
			t = deplacement(t, 3, deplace);
			effacer_console();
			affichage(t);
			t = casse_bloc(t);
		}
	}

	effacer_console();

	// On affiche les scores et le vainqueur.
	cout << "Le gagnant est " << gagnant << endl;
	cout << "La partie s'est déroulée en " << nb_tour << " tours." << endl;
	cout << "Tableau final :" << endl;
	affichage(t);

	pause_console();
}

/**
 * Fonction secondaire qui permet de lancer le jeu course.
**/
void jeu_course()
{
	// Initialisation des variables.
	// nb_tour permet de compter les tours, taille_tab_x et taille_tab_y contiennent la taille du tableau choisi par l'utilisateur.
	// nom1 est le nom du premier joueur, nom2 est le nom du deuxième joueur, deplace contient le déplacement choisi par l'utilisateur, gagnant contient le nom du gagnant.
	int nb_tour = 0, taille_tab_x = 0, taille_tab_y = 0;
	string nom1, nom2, deplace, gagnant;

	// On demande les infos des joueurs.
	cout << "Quelle est le nom du premier joueur : ";
	getline(cin, nom1);
	cout << endl << "Quelle est le nom du deuxième joueur : ";
	getline(cin, nom2);
	cout << endl << "Quelle est la taille du tableau x (Par défaut : 8) : ";
	cin >> taille_tab_x;
	cout << endl << "Quelle est la taille du tableau y (Par défaut : 6) : ";
	cin >> taille_tab_y;

	// On initialise le tableau.
	Tab2Dint t = initialisation_tableau(taille_tab_x, taille_tab_y, "normal");
	cout << endl;

	// Tant que personne n'a gagné.
	while (gagner(t, 2) && gagner(t, 3) && possibl_deplac(t, 2) && possibl_deplac(t, 3))
	{
		// On ajoute un tour.
		nb_tour++;

		// On rempli gagnant au cas où il gagne.
		gagnant = nom1;

		effacer_console();

		// On affiche le tableau de jeu.
		affichage(t);

		cout << endl << "-------------------------------" << endl;
		cout << "Isola Course / Tour " << nb_tour << endl;

		// On demande le déplacement au joueur.
		deplace = demande_deplace(t, nom1, 2);

		// On déplace le pion selon la demande du joueur.
		t = deplacement(t, 2, deplace);

		effacer_console();
		affichage(t);

		// On demande au joueur de casser un bloc et on le casse.
		t = casse_bloc(t);


		effacer_console();

		// Au tour du deuxième joueur.
		if (possibl_deplac(t, 2))
		{
			gagnant = nom2;
			affichage(t);
			cout << endl << "-------------------------------" << endl;
			cout << "Isola Course / Tour " << nb_tour << endl;
			deplace = demande_deplace(t, nom2, 3);
			t = deplacement(t, 3, deplace);
			effacer_console();
			affichage(t);
			t = casse_bloc(t);
		}
	}

	effacer_console();

	// On affiche les scores et le vainqueur.
	cout << "Le gagnant est " << gagnant << endl;
	cout << "La partie s'est déroulée en " << nb_tour << " tours." << endl;
	cout << "Tableau final :" << endl;
	affichage(t);

	pause_console();
}

/**
* Fonction secondaire qui permet de lancer le jeu ordi.
**/
void jeu_ordi()
{
	// Initialisation des variables.
	// nb_tour permet de compter les tours, taille_tab_x et taille_tab_y contiennent la taille du tableau choisi par l'utilisateur.
	// nom1 est le nom du premier joueur, nom2 est le nom du deuxième joueur, deplace contient le déplacement choisi par l'utilisateur, gagnant contient le nom du gagnant.
	int nb_tour = 0, taille_tab_x = 0, taille_tab_y = 0;
	string nom1, nom2 = "Ordinateur", deplace, gagnant;

	// On demande les infos des joueurs.
	cout << "Quelle est votre nom : ";
	getline(cin, nom1);
	cout << endl << "Quelle est la taille du tableau x (Par défaut : 8) : ";
	cin >> taille_tab_x;
	cout << endl << "Quelle est la taille du tableau y (Par défaut : 6) : ";
	cin >> taille_tab_y;

	// On initialise le tableau.
	Tab2Dint t = initialisation_tableau(taille_tab_x, taille_tab_y, "normal");
	cout << endl;

	// Tant que personne n'a gagné.
	while (possibl_deplac(t, 2) && possibl_deplac(t, 3))
	{
		// On ajoute un tour.
		nb_tour++;

		// On rempli gagnant au cas où il gagne.
		gagnant = nom1;

		effacer_console();

		// On affiche le tableau de jeu.
		affichage(t);

		cout << endl << "-------------------------------" << endl;
		cout << "Isola Ordi / Tour " << nb_tour << endl;

		// On demande le déplacement au joueur.
		deplace = demande_deplace(t, nom1, 2);

		// On déplace le pion selon la demande du joueur.
		t = deplacement(t, 2, deplace);

		effacer_console();
		affichage(t);

		// On demande au joueur de casser un bloc et on le casse.
		t = casse_bloc(t);


		effacer_console();

		// Au tour du deuxième joueur.
		if (possibl_deplac(t, 2) && possibl_deplac(t, 3))
		{
			gagnant = nom2;
			affichage(t);
			cout << endl << "-------------------------------" << endl;
			cout << "Isola Ordi / Tour " << nb_tour << endl;
			deplace = demande_deplace_ordi(t, 3);
			t = deplacement(t, 3, deplace);
			cout << "Déplacement choisi : " << deplace << endl;
			pause_console();
			effacer_console();
			affichage(t);
			cout << endl << "-------------------------------" << endl;
			cout << "Bloc cassé par l'ordi : ";
			t = casse_bloc_ordi(t);
			cout << endl;
			pause_console();
		}
	}

	effacer_console();

	// On affiche les scores et le vainqueur.
	cout << "Le gagnant est " << gagnant << endl;
	cout << "La partie s'est déroulée en " << nb_tour << " tours." << endl;
	cout << "Tableau final :" << endl;
	affichage(t);

	pause_console();
}

/**
* Fonction secondaire qui permet de lancer le jeu survie.
**/
void jeu_survie()
{
	// Initialisation des variables.
	// nb_tour permet de compter les tours, taille_tab_x et taille_tab_y contiennent la taille du tableau choisi par l'utilisateur.
	// nom1 est le nom du premier joueur, nom2 est le nom du deuxième joueur, deplace contient le déplacement choisi par l'utilisateur, gagnant contient le nom du gagnant.
	int nb_tour = 0, taille_tab_x = 0, taille_tab_y = 0;
	string nom1, nom2 = "o-d-m-s-u", deplace, gagnant;

	// On demande les infos des joueurs.
	cout << "Quelle est votre nom : ";
	getline(cin, nom1);
	cout << endl << "Quelle est la taille du tableau x (Par défaut : 8) : ";
	cin >> taille_tab_x;
	cout << endl << "Quelle est la taille du tableau y (Par défaut : 6) : ";
	cin >> taille_tab_y;

	// On initialise le tableau.
	Tab2Dint t = initialisation_tableau(taille_tab_x, taille_tab_y, "survie");
	cout << endl;

	// Tant que personne n'a gagné.
	while (possibl_deplac(t, 2))
	{
		// On ajoute un tour.
		nb_tour++;

		// On rempli gagnant au cas où il gagne.
		gagnant = nom1;

		effacer_console();

		// On affiche le tableau de jeu.
		affichage(t);

		cout << endl << "-------------------------------" << endl;
		cout << "Isola Survie / Tour " << nb_tour << endl;

		// On demande le déplacement au joueur.
		deplace = demande_deplace(t, nom1, 2);

		// On déplace le pion selon la demande du joueur.
		t = deplacement(t, 2, deplace);

		effacer_console();
		affichage(t);

		effacer_console();

		// Au tour du deuxième joueur.
		if (possibl_deplac(t, 2))
		{
			gagnant = nom2;
			affichage(t);
			cout << endl << "-------------------------------" << endl;
			cout << "Isola Survie / Tour " << nb_tour << endl;
			cout << endl << "-------------------------------" << endl;
			cout << "Bloc cassé par l'ordi : ";
			t = casse_bloc_ordi(t);
			cout << endl;
			pause_console();
		}
	}

	effacer_console();

	// On affiche les scores et le vainqueur.
	if (gagnant == "o-d-m-s-u")
	{
		cout << "Vous avez perdu." << endl;
	}
	else
	{
		cout << "Vous avez gagné !" << endl;
	}
	
	cout << "La partie s'est déroulée en " << nb_tour << " tours." << endl;
	cout << "Tableau final :" << endl;
	affichage(t);

	pause_console();
}

/**
* Fonction secondaire qui permet de lancer le jeu ordi.
**/
void jeu_ordi_vs_ordi()
{
	// Initialisation des variables.
	// nb_tour permet de compter les tours, taille_tab_x et taille_tab_y contiennent la taille du tableau choisi par l'utilisateur.
	// nom1 est le nom du premier joueur, nom2 est le nom du deuxième joueur, deplace contient le déplacement choisi par l'utilisateur, gagnant contient le nom du gagnant.
	int nb_tour = 0, taille_tab_x = 0, taille_tab_y = 0;
	string nom1 = "Ordinateur 1", nom2 = "Ordinateur 2", deplace, gagnant;

	// On demande les infos des joueurs.
	cout << endl << "Quelle est la taille du tableau x (Par défaut : 8) : ";
	cin >> taille_tab_x;
	cout << endl << "Quelle est la taille du tableau y (Par défaut : 6) : ";
	cin >> taille_tab_y;

	// On initialise le tableau.
	Tab2Dint t = initialisation_tableau(taille_tab_x, taille_tab_y, "normal");
	cout << endl;

	// Tant que personne n'a gagné.
	while (possibl_deplac(t, 2) && possibl_deplac(t, 3))
	{
		// On ajoute un tour.
		nb_tour++;

		// On rempli gagnant au cas où il gagne.
		gagnant = nom1;

		effacer_console();

		// On affiche le tableau de jeu.
		affichage(t);

		cout << endl << "-------------------------------" << endl;
		cout << "Isola Ordi / Tour " << nb_tour << endl;

		// On demande le déplacement au joueur.
		deplace = demande_deplace_ordi_1(t, 2);

		// On déplace le pion selon la demande du joueur.
		t = deplacement(t, 2, deplace);
		cout << "Déplacement choisi : " << deplace << endl;
		pause_console();
		effacer_console();
		affichage(t);
		cout << endl << "-------------------------------" << endl;
		cout << "Bloc cassé par l'ordi : ";

		// On demande au joueur de casser un bloc et on le casse.
		t = casse_bloc_ordi_1(t, 2);
		cout << endl;
		pause_console();
		effacer_console();

		// Au tour du deuxième joueur.
		if (possibl_deplac(t, 2) && possibl_deplac(t, 3))
		{
			gagnant = nom2;
			affichage(t);
			cout << endl << "-------------------------------" << endl;
			cout << "Isola Ordi / Tour " << nb_tour << endl;
			deplace = demande_deplace_ordi_2(t, 3);
			t = deplacement(t, 3, deplace);
			cout << "Déplacement choisi : " << deplace << endl;
			pause_console();
			effacer_console();
			affichage(t);
			cout << endl << "-------------------------------" << endl;
			cout << "Bloc cassé par l'ordi : ";
			t = casse_bloc_ordi_2(t, 3);
			cout << endl;
			pause_console();
		}
	}

	effacer_console();

	// On affiche les scores et le vainqueur.
	cout << "Le gagnant est " << gagnant << endl;
	cout << "La partie s'est déroulée en " << nb_tour << " tours." << endl;
	cout << "Tableau final :" << endl;
	affichage(t);

	pause_console();
}

/**
 * Fonction principale qui permet de lancer l'une des fonctions secondaires.
**/
int main()
{
	// Variable qui enregistre le choix de l'utilisateur sur le mode de jeu choisi.
	string choix;
	int boucle = 0;
	cout << "-------------------------------------------------" << endl;
	cout << "PcIsola v3.0" << endl;
	cout << "Pour Info111" << endl;
	cout << "-------------------------------------------------" << endl;
	while (boucle == 0)
	{
		cout << endl << "Choisir le type de jeu :" << endl;
		cout << "(A) Isola classique." << endl;
		cout << "(B) Isola course." << endl;
		cout << "(C) Isola ordinateur." << endl;
		cout << "(D) Isola survie." << endl;
		cout << "(E) Isola IA vs IA." << endl;

		cout << endl << "Votre choix : ";
		getline(cin, choix);
		cout << endl << "-------------------------------" << endl;

		// Converti une chaine de caractère minucule en majuscule.
		choix = verif_maj_min(choix);

		if (choix == "A")
		{
			regle(choix);
			pause_console();
			effacer_console();
			jeu_classique();
			boucle = 1;
		}
		if (choix == "B")
		{
			regle(choix);
			pause_console();
			effacer_console();
			jeu_course();
			boucle = 1;
		}
		if (choix == "C")
		{
			regle(choix);
			pause_console();
			effacer_console();
			jeu_ordi();
			boucle = 1;
		}
		if (choix == "D")
		{
			regle(choix);
			pause_console();
			effacer_console();
			jeu_survie();
			boucle = 1;
		}
		if (choix == "E")
		{
			regle(choix);
			pause_console();
			effacer_console();
			jeu_ordi_vs_ordi();
			boucle = 1;
		}
	}
	return 0;
}

/**
Changelog :

A faire :
-Mode avec vies avec respawn ou on veut dans le plateau.
-Couleur des pions.

v3.0 :
Programme découpé en modules.
Affichage du tableau finale lorsque qq'un a perdu.
Affichage de la grille corrigé.
Boucle dans main.
Troix modes ajouté :
 -Mode ordi vs joueur.
 -Mode survie.
 -Mode IA vs IA.

v2.1 :
Ajout des corrections automatique des minuscules entrés par l'utilisateur.

v2.0 :
Fonction main() transformé en menu de séléction pour differents mode de jeu.
Deux modes de jeux :
-Jeu classique.
-Jeu course.
Ajout des régles de jeu.
Ajout des commentaires.

v1.0 (Projet Isola devient PcIsola :-) ) :
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
