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
    if (*nb >= MAX_LIVRES) {
        printf("Erreur : La bibliotheque est pleine (Max 10) !\n");
        return;
    }

    printf("Entrez le titre du livre : ");
    // UX : Utilisation de fgets pour accepter les espaces (ex: "Harry Potter")
    vider_buffer(); // On nettoie avant de lire
    fgets(titres[*nb], MAX_STR, stdin);
    
    // Petite astuce UX : enlever le retour à la ligne que fgets ajoute
    titres[*nb][strcspn(titres[*nb], "\n")] = 0;

    (*nb)++; // On met à jour le compteur via le pointeur
    nb_livres_global = *nb; // On met à jour la globale aussi pour l'affichage
    printf("Livre ajoute avec succes !\n");
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