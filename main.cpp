// --------------------------------
// Auteur : Alexandre l'Heritier
// PcIsola v4.1
// --------------------------------
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "fonctions_isola.h"
#include "fonctions_spe_jeu_course.h"
#include "fonctions_spe_jeu_ordi.h"

using namespace std;

string version_prog = "4.1";

// Mes raccourcis :
typedef vector<vector<int>> Tab2Dint;


/**
 * Fonction secondaire qui permet de lancer le jeu classique.
**/
void jeu_classique(string type_tab, Tab2Dint tab_de_jeu, int nb_tour, string nom1, string nom2, string gagnant)
{
	// Initialisation des variables.
	// nb_tour permet de compter les tours, taille_tab_x et taille_tab_y contiennent la taille du tableau choisi par l'utilisateur.
	// nom1 est le nom du premier joueur, nom2 est le nom du deuxième joueur, deplace contient le déplacement choisi par l'utilisateur, gagnant contient le nom du gagnant.
	int taille_tab_x = 0, taille_tab_y = 0;
	string deplace;
	Tab2Dint t;

	if (nom1 != " ")
	{
		t = tab_de_jeu;
	}
	else
	{
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
		t = initialisation_tableau(taille_tab_x, taille_tab_y, type_tab);
		cout << endl;
		gagnant = nom2;
	}
	// Tant que personne n'a gagné.
	while (possibl_deplac(t, 2) && possibl_deplac(t, 3))
	{
		if (gagnant == nom2)
		{
			sauvegarde("temp", "classique", t, nb_tour, nom1, nom2, gagnant);
			// On ajoute un tour.
			nb_tour++;

			effacer_console();

			// On affiche le tableau de jeu.
			affichage(t);

			cout << endl << "-------------------------------" << endl;
			cout << "Isola Classique / Tour " << nb_tour << endl;

			// On demande le déplacement au joueur.
			deplace = demande_deplace(t, nom1, 2);

			while (deplace == "S")
			{
				sauvegarde("save", "classique", t, nb_tour, nom1, nom2, gagnant);
				effacer_console();
				cout << "Partie sauvegardée !" << endl;
				pause_console();
				effacer_console();
				affichage(t);
				// On demande le déplacement au joueur.
				deplace = demande_deplace(t, nom1, 2);
			}

			// On déplace le pion selon la demande du joueur.
			t = deplacement(t, 2, deplace);

			effacer_console();
			affichage(t);

			// On demande au joueur de casser un bloc et on le casse.
			t = casse_bloc(t);

			// On rempli gagnant au cas où il gagne.
			gagnant = nom1;

			effacer_console();
		}
		// Au tour du deuxième joueur.
		if (possibl_deplac(t, 2))
		{
			sauvegarde("temp", "classique", t, nb_tour, nom1, nom2, gagnant);
			affichage(t);
			cout << endl << "-------------------------------" << endl;
			cout << "Isola Classique / Tour " << nb_tour << endl;
			deplace = demande_deplace(t, nom2, 3);
			while (deplace == "S")
			{
				sauvegarde("save", "classique", t, nb_tour, nom1, nom2, gagnant);
				effacer_console();
				cout << "Partie sauvegardée !" << endl;
				pause_console();
				effacer_console();
				affichage(t);
				deplace = demande_deplace(t, nom2, 3);
			}
			t = deplacement(t, 3, deplace);
			effacer_console();
			affichage(t);
			t = casse_bloc(t);
			gagnant = nom2;
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
void jeu_course(Tab2Dint tab_de_jeu, int nb_tour, string nom1, string nom2, string gagnant)
{
	// Initialisation des variables.
	// nb_tour permet de compter les tours, taille_tab_x et taille_tab_y contiennent la taille du tableau choisi par l'utilisateur.
	// nom1 est le nom du premier joueur, nom2 est le nom du deuxième joueur, deplace contient le déplacement choisi par l'utilisateur, gagnant contient le nom du gagnant.
	int taille_tab_x = 0, taille_tab_y = 0;
	string deplace;
	Tab2Dint t;

	if (nom1 != " ")
	{
		t = tab_de_jeu;
	}
	else
	{
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
		t = initialisation_tableau(taille_tab_x, taille_tab_y, "normal");
		cout << endl;
		gagnant = nom2;
	}
	// Tant que personne n'a gagné.
	while (gagner(t, 2) && gagner(t, 3) && possibl_deplac(t, 2) && possibl_deplac(t, 3))
	{
		if (gagnant == nom2)
		{
			// On ajoute un tour.
			nb_tour++;
			sauvegarde("temp", "course", t, nb_tour, nom1, nom2, gagnant);
			effacer_console();

			// On affiche le tableau de jeu.
			affichage(t);

			cout << endl << "-------------------------------" << endl;
			cout << "Isola Course / Tour " << nb_tour << endl;

			// On demande le déplacement au joueur.
			deplace = demande_deplace(t, nom1, 2);

			while (deplace == "S")
			{
				sauvegarde("save", "course", t, nb_tour, nom1, nom2, gagnant);
				effacer_console();
				cout << "Partie sauvegardée !" << endl;
				pause_console();
				effacer_console();
				affichage(t);
				// On demande le déplacement au joueur.
				deplace = demande_deplace(t, nom1, 2);
			}

			// On déplace le pion selon la demande du joueur.
			t = deplacement(t, 2, deplace);

			effacer_console();
			affichage(t);

			// On demande au joueur de casser un bloc et on le casse.
			t = casse_bloc(t);

			// On rempli gagnant au cas où il gagne.
			gagnant = nom1;

			effacer_console();
		}
		// Au tour du deuxième joueur.
		if (possibl_deplac(t, 2))
		{
			sauvegarde("temp", "course", t, nb_tour, nom1, nom2, gagnant);
			affichage(t);
			cout << endl << "-------------------------------" << endl;
			cout << "Isola Course / Tour " << nb_tour << endl;
			deplace = demande_deplace(t, nom2, 3);
			while (deplace == "S")
			{
				sauvegarde("save", "course", t, nb_tour, nom1, nom2, gagnant);
				effacer_console();
				cout << "Partie sauvegardée !" << endl;
				pause_console();
				effacer_console();
				affichage(t);
				deplace = demande_deplace(t, nom2, 3);
			}
			t = deplacement(t, 3, deplace);
			effacer_console();
			affichage(t);
			t = casse_bloc(t);
			gagnant = nom2;
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
void jeu_ordi(string type_tab, Tab2Dint tab_de_jeu, int nb_tour, string nom1, string nom2, string gagnant)
{
	// Initialisation des variables.
	// nb_tour permet de compter les tours, taille_tab_x et taille_tab_y contiennent la taille du tableau choisi par l'utilisateur.
	// nom1 est le nom du premier joueur, nom2 est le nom du deuxième joueur, deplace contient le déplacement choisi par l'utilisateur, gagnant contient le nom du gagnant.
	int taille_tab_x = 0, taille_tab_y = 0;
	string deplace;
	Tab2Dint t;

	if (nom1 != " ")
	{
		t = tab_de_jeu;
	}
	else
	{
		// On demande les infos des joueurs.
		cout << "Quelle est votre nom : ";
		getline(cin, nom1);
		cout << endl << "Quelle est la taille du tableau x (Par défaut : 8) : ";
		cin >> taille_tab_x;
		cout << endl << "Quelle est la taille du tableau y (Par défaut : 6) : ";
		cin >> taille_tab_y;

		// On initialise le tableau.
		t = initialisation_tableau(taille_tab_x, taille_tab_y, type_tab);
		cout << endl;
		gagnant = nom2;
	}

	// Tant que personne n'a gagné.
	while (possibl_deplac(t, 2) && possibl_deplac(t, 3))
	{
		if (gagnant == nom2)
		{
			// On ajoute un tour.
			nb_tour++;
			sauvegarde("temp", "ordi", t, nb_tour, nom1, nom2, gagnant);
			effacer_console();

			// On affiche le tableau de jeu.
			affichage(t);

			cout << endl << "-------------------------------" << endl;
			cout << "Isola Ordi / Tour " << nb_tour << endl;

			// On demande le déplacement au joueur.
			deplace = demande_deplace(t, nom1, 2);

			while (deplace == "S")
			{
				sauvegarde("save", "ordi", t, nb_tour, nom1, nom2, gagnant);
				effacer_console();
				cout << "Partie sauvegardée !" << endl;
				pause_console();
				effacer_console();
				affichage(t);
				// On demande le déplacement au joueur.
				deplace = demande_deplace(t, nom1, 2);
			}

			// On déplace le pion selon la demande du joueur.
			t = deplacement(t, 2, deplace);

			effacer_console();
			affichage(t);

			// On demande au joueur de casser un bloc et on le casse.
			t = casse_bloc(t);

			// On rempli gagnant au cas où il gagne.
			gagnant = nom1;

			effacer_console();
		}
		// Au tour du deuxième joueur.
		if (possibl_deplac(t, 2) && possibl_deplac(t, 3))
		{
			sauvegarde("temp", "ordi", t, nb_tour, nom1, nom2, gagnant);
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
			gagnant = nom2;
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
void jeu_survie(Tab2Dint tab_de_jeu, int nb_tour, string nom1, string nom2, string gagnant)
{
	// Initialisation des variables.
	// nb_tour permet de compter les tours, taille_tab_x et taille_tab_y contiennent la taille du tableau choisi par l'utilisateur.
	// nom1 est le nom du premier joueur, nom2 est le nom du deuxième joueur, deplace contient le déplacement choisi par l'utilisateur, gagnant contient le nom du gagnant.
	int taille_tab_x = 0, taille_tab_y = 0;
	string deplace;
	Tab2Dint t;

	if (nom1 != " ")
	{
		t = tab_de_jeu;
	}
	else
	{
		// On demande les infos des joueurs.
		cout << "Quelle est votre nom : ";
		getline(cin, nom1);
		cout << endl << "Quelle est la taille du tableau x (Par défaut : 8) : ";
		cin >> taille_tab_x;
		cout << endl << "Quelle est la taille du tableau y (Par défaut : 6) : ";
		cin >> taille_tab_y;

		// On initialise le tableau.
		t = initialisation_tableau(taille_tab_x, taille_tab_y, "survie");
		cout << endl;
	}
	// Tant que personne n'a gagné.
	while (possibl_deplac(t, 2))
	{
		// On ajoute un tour.
		nb_tour++;
		sauvegarde("temp", "survie", t, nb_tour, nom1, nom2, gagnant);

		effacer_console();

		// On affiche le tableau de jeu.
		affichage(t);

		cout << endl << "-------------------------------" << endl;
		cout << "Isola Survie / Tour " << nb_tour << endl;

		// On demande le déplacement au joueur.
		deplace = demande_deplace(t, nom1, 2);

		while (deplace == "S")
		{
			sauvegarde("save", "survie", t, nb_tour, nom1, nom2, gagnant);
			effacer_console();
			cout << "Partie sauvegardée !" << endl;
			pause_console();
			effacer_console();
			affichage(t);
			// On demande le déplacement au joueur.
			deplace = demande_deplace(t, nom1, 2);
		}

		// On déplace le pion selon la demande du joueur.
		t = deplacement(t, 2, deplace);

		effacer_console();
		affichage(t);
		// On rempli gagnant au cas où il gagne.
		gagnant = nom1;
		effacer_console();

		// Au tour du deuxième joueur.
		if (possibl_deplac(t, 2))
		{
			sauvegarde("temp", "survie", t, nb_tour, nom1, nom2, gagnant);
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
	cout << "Fin" << endl;
	cout << "Vous avez survécu " << nb_tour << " tours !" << endl;
	cout << "Tableau final :" << endl;
	affichage(t);

	pause_console();
}

/**
* Fonction qui permet de restaurer une sauvegarde.
* @param nom_sauvegarde le nom de la sauvegarde.
**/
void restaure_save(string nom_sauvegarde)
{
	// On initialise les variables à remplir.
	string version, type_jeu, nom1, nom2, gagnant;
	int taille_x, taille_y, nb_tour;

	// On ouvre le fichier.
	ifstream fichier(nom_sauvegarde);

	// Le fichier n'existe pas, on ferme le programme.
	if (fichier.fail())
	{
		cout << "Erreur : Le fichier n'existe pas." << endl;
		pause_console();
		exit(0);
	}

	// On explore le fichier jusqu'au début des informations utiles.
	for (int i = 0; i < 10; i++) fichier >> version;

	// On verifie la version de la sauvegarde et on previent si elle est differente de la version du programme.
	if (version != version_prog)
	{
		cout << "Version de la sauvegarde differente de la version de PcIsola";
		pause_console();
	}

	// On lis le fichier et on met dans les variables correspondante.
	fichier >> type_jeu;
	fichier >> taille_x;
	fichier >> taille_y;

	// Créer le double tableau qui sera rempli et renvoyé.
	Tab2Dint t(taille_x);

	// Double boucle qui crée des listes dans chaques cases du double tableau et qui le rempli.
	for (int i = 0; i < taille_x; i++)
	{
		t[i] = Tab1Dint(taille_y);
		for (int j = 0; j < taille_y; j++)
		{
			fichier >> t[i][j];
		}
	}
	fichier >> nb_tour;
	fichier >> nom1;
	fichier >> nom2;
	fichier >> gagnant;

	// On ferme le fichier.
	fichier.close();

	// On ouvre la fonction correspondante à la sauvegarde.
	if (type_jeu == "classique") jeu_classique("normal", t, nb_tour, nom1, nom2, gagnant);
	if (type_jeu == "course") jeu_course(t, nb_tour, nom1, nom2, gagnant);
	if (type_jeu == "ordi") jeu_ordi("ordi", t, nb_tour, nom1, nom2, gagnant);
	if (type_jeu == "survie") jeu_survie(t, nb_tour, nom1, nom2, gagnant);
}

/**
 * Fonction principale qui permet de lancer l'une des fonctions secondaires.
**/
int main()
{
	// Variable qui enregistre le choix de l'utilisateur sur le mode de jeu choisi.
	string choix;

	// Variable pour la boucle.
	int boucle = 0;

	// Affichage d'infos.
	cout << "-------------------------------------------------" << endl;
	cout << "PcIsola v" << version_prog << endl;
	cout << "Pour Info111" << endl;
	cout << "-------------------------------------------------" << endl;

	// On ouvre le fichier temp.
	ifstream fichier_verif("temp_PcIsola.save");

	// On regarde si le fichier existe. Si il existe, on demande à l'utilisateur si il veut utilisé la sauvegarde.
	if (!fichier_verif.fail())
	{
		// Variable pour sauver le choix de l'utilisateur.
		string temp_choix;

		// On demande à l'utilisateur si il veut restaurer la sauvegarde.
		cout << "Un fichier de sauvegarde temporaire a été trouvé." << endl << "Voulez-vous continuer votre partie ? (O/N)" << endl;
		getline(cin, temp_choix);

		// Si oui, on l'ouvre.
		if (temp_choix == "O" || temp_choix == "o")
		{
			restaure_save("temp_PcIsola.save");
			boucle = 1;
		}
	}
	// On ferme le fichier.
	fichier_verif.close();

	while (boucle == 0)
	{
		cout << endl << "Choisir le type de jeu :" << endl;
		cout << "(A) Isola classique avec 2 joueurs." << endl;
		cout << "(B) Isola classique course avec 2 joueurs." << endl;
		cout << "(C) Isola classique avec 1 joueur et 1 ordinateur." << endl;
		cout << "(D) Isola survie." << endl;
		cout << "(E) Isola normal avec 2 joueurs. [Mode de jeu consignes]" << endl;
		cout << "(F) Isola normal avec 1 joueur et 1 ordinateur. [Mode de jeu consignes]" << endl;
		cout << "(G) Isola cavalier avec 2 joueurs. [Mode de jeu consignes]" << endl;
		cout << "(S) Restauration de la sauvegarde.";

		cout << endl << "Votre choix : ";
		getline(cin, choix);
		cout << endl << "-------------------------------" << endl;

		// Converti une chaine de caractère minucule en majuscule.
		choix = verif_maj_min(choix);

		if (choix == "A")
		{
			effacer_console();
			regle(choix);
			pause_console();
			effacer_console();
			jeu_classique("normal", { {} }, 0, " ", " ", " ");
			boucle = 1;
		}
		if (choix == "B")
		{
			effacer_console();
			regle(choix);
			pause_console();
			effacer_console();
			jeu_course({ {} }, 0, " ", " ", " ");
			boucle = 1;
		}
		if (choix == "C")
		{
			effacer_console();
			regle(choix);
			pause_console();
			effacer_console();
			jeu_ordi("normal", { {} }, 0, " ", " ", " ");
			boucle = 1;
		}
		if (choix == "D")
		{
			effacer_console();
			regle(choix);
			pause_console();
			effacer_console();
			jeu_survie({ {} }, 0, " ", " ", " ");
			boucle = 1;
		}
		if (choix == "E")
		{
			effacer_console();
			regle(choix);
			pause_console();
			effacer_console();
			jeu_classique("placement_choisi_par_joueur", { {} }, 0, " ", " ", " ");
			boucle = 1;
		}
		if (choix == "F")
		{
			effacer_console();
			regle(choix);
			pause_console();
			effacer_console();
			jeu_ordi("placement_choisi_par_joueur_ordi", { {} }, 0, " ", " ", " ");
			boucle = 1;
		}
		if (choix == "G")
		{
			effacer_console();
			regle(choix);
			pause_console();
			effacer_console();
			//jeu_cavalier();
			boucle = 1;
		}
		if (choix == "S")
		{
			restaure_save("save_PcIsola.save");
		}
	}
	// Une fois la partie fini, on supprime le fichier temp.
	remove("temp_PcIsola.save");

	return 0;
}

/**
Changelog :

A faire :
-Modes de jeu : Règles du prof : Cavalier.
-Option pour quitter sans fichier temp.

v4.1 :
Un peu d'optimisation (-50 lignes).
Bugs de sauvegarde résolu.
Mode IA vs IA retiré. (Toutes les IA développées ne sont pas adaptable au programme).

v4.0 :
Fonction affichage_deplacement_possible crée pour afficher les déplacements de manière "carré" (au lieu de tous les déplacements sur la même ligne).
Mode de jeu normal ajouté (consignes).
Indications à afficher par la fonction main plus précise.
Sauvegarde et sauvegarde temporaire ajoutées, adaptation avec:
-Mode classique.
-Mode course.
-Mode ordi.
-Mode survie.

v3.1 :
Déplacement aléatoire du pion ordi.
Améliorations de l'IA : 
-Protection contre les blocages dans les coins.
Nouvelles fonctions commentées.

v3.0 :
Programme découpé en modules.
Affichage du tableau finale lorsque qq'un a perdu.
Affichage de la grille corrigé.
Boucle dans main.
Trois modes ajouté :
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
