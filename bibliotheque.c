#include <stdio.h>
#include <string.h>
#include "bibliotheque.h"

// Définition des variables globales
char nom_bibliotheque[MAX_STR] = "Bibliotheque Ynov";
int nb_livres_global = 0;

void vider_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Consigne 3.1 : Utilise les variables globales
void afficher_infos() {
    printf("\n--- INFO ---\n");
    printf("Bienvenue a la %s\n", nom_bibliotheque);
    printf("Nombre de livres en stock : %d / %d\n", nb_livres_global, MAX_LIVRES);
    printf("------------\n");
}

// Consigne 3.2 : Sécuriser et ajouter
void ajouter_livre(char titres[][MAX_STR], int *nb) {
    // 1. Nettoyage du buffer (pour éviter les bugs de touches Entrée)
    vider_buffer(); 

    // 2. Vérifier si c'est plein
    if (*nb >= MAX_LIVRES) {
        printf(" Erreur : La bibliotheque est pleine (Max 10) !\n");
        return;
    }

    printf("Entrez le titre du livre : ");
    // On écrit directement dans la case libre
    fgets(titres[*nb], MAX_STR, stdin);
    titres[*nb][strcspn(titres[*nb], "\n")] = 0; // Enlever le \n

    // On regarde du livre 0 jusqu'au livre actuel (*nb)
    for (int i = 0; i < *nb; i++) {
        // Si le titre qu'on vient de taper (titres[*nb]) existe déjà en position i
        if (strcmp(titres[i], titres[*nb]) == 0) {
            printf(" Erreur : Le livre \"%s\" existe deja !\n", titres[*nb]);
            // On s'arrête là, on n'augmente pas le compteur (*nb)
            // La prochaine fois, on écrasera cette case, donc pas de souci.
            return; 
        }
    }
    // -------------------------------------------

    // Si on arrive ici, c'est que le livre est nouveau !
    (*nb)++; 
    nb_livres_global = *nb;
    printf(" Livre ajoute avec succes !\n");
}

// Consigne 3.3 : Retourne l'index ou -1
int rechercher_livre(char titres[][MAX_STR], int nb, char *titre) {
    for (int i = 0; i < nb; i++) {
        // strcasecmp permet d'ignorer majuscules/minuscules (sur Linux/Mac)
        // Si tu es sur Windows strict, utilise strcmp
        if (strcmp(titres[i], titre) == 0) {
            return i; // On retourne l'index trouvé
        }
    }
    return -1; // Pas trouvé
}