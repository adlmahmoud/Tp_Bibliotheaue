#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H
#define MAX_LIVRES 10
#define MAX_STR 50

extern char nom_bibliotheque[MAX_STR];
extern int nb_livres_global; 

// --- EXERCICE 1 : Affichage ---
void afficher_infos();

// --- EXERCICE 2 : Ajout ---
void ajouter_livre(char titres[][MAX_STR], int *nb);

// --- EXERCICE 3 : Recherche ---
int rechercher_livre(char titres[][MAX_STR], int nb, char *titre);

// --- EXERCICE 4 : Menu Principal ---
// Nouvelle fonction pour alléger le main
void lancer_app();

// Utilitaire
void vider_buffer();

#endif