#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

// Consigne 3.2 : Max 10 livres
#define MAX_LIVRES 10
#define MAX_STR 50

// Consigne 3.1 : Variables globales (déclarées "extern" pour être visibles partout)
extern char nom_bibliotheque[MAX_STR];
extern int nb_livres_global; 

// Consigne 3.1 : Afficher infos (sans arguments)
void afficher_infos();

// Consigne 3.2 : Ajouter (avec pointeur)
void ajouter_livre(char titres[][MAX_STR], int *nb);

// Consigne 3.3 : Rechercher (retourne int)
int rechercher_livre(char titres[][MAX_STR], int nb, char *titre);

// Fonction utilitaire pour vider le buffer (Amélioration UX)
void vider_buffer();

#endif