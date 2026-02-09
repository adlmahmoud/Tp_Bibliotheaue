#include <stdio.h>
#include <string.h>
#include <strings.h> // Pour strncasecmp
#include <ctype.h>
#include "../inc/bibliotheque.h" 

/**
 * FICHIER : src/bibliotheque.c
 * Contient l'implémentation des fonctions du TP1
 */

char nom_bibliotheque[MAX_STR] = "Bibliotheque Ynov";
int nb_livres_global = 0;

void vider_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * EXERCICE 1 : Affiche le nom de la bibliothèque et le nombre de livres.
 * Utilise les variables globales.
 */
void afficher_infos() {
    printf("\n--- INFO ---\n");
    printf("Bienvenue a la %s\n", nom_bibliotheque);
    printf("Livres : %d / %d\n", nb_livres_global, MAX_LIVRES);
    printf("------------\n");
}

/**
 * EXERCICE 2 : Ajoute un livre dans le tableau.
 * Vérifie si la bibliothèque est pleine et gère les doublons.
 */
void ajouter_livre(char titres[][MAX_STR], int *nb) {
    vider_buffer(); 
    if (*nb >= MAX_LIVRES) {
        printf(" Erreur : Plein !\n");
        return;
    }

    printf("Titre du livre : ");
    fgets(titres[*nb], MAX_STR, stdin);
    titres[*nb][strcspn(titres[*nb], "\n")] = 0;

    // Vérification doublon
    for (int i = 0; i < *nb; i++) {
        if (strcmp(titres[i], titres[*nb]) == 0) {
            printf(" Deja existant !\n");
            return; 
        }
    }

    (*nb)++; 
    nb_livres_global = *nb;
    printf("✅ Ajoute !\n");
}

/**
 * EXERCICE 3 : Recherche un livre (Insensible à la casse, début du mot).
 * Retourne 1 si trouvé, 0 sinon.
 */
int rechercher_livre(char titres[][MAX_STR], int nb, char *titre) {
    int longueur = strlen(titre);
    int trouve = 0;

    printf("\n Resultats :\n");
    for (int i = 0; i < nb; i++) {
        if (strncasecmp(titres[i], titre, longueur) == 0) {
            printf(" %s (Index %d)\n", titres[i], i);
            trouve = 1;
        }
    }
    return trouve;
}

/**
 * EXERCICE 4 : Gestion du Menu Principal.
 * Contient la boucle principale du programme.
 */
void lancer_app() {
    char titres[MAX_LIVRES][MAX_STR];
    int nb_livres = 0;
    int choix;
    char recherche[MAX_STR];

    do {
        printf("\n=== MENU ===\n1. Infos | 2. Ajouter | 3. Chercher | 4. Quitter\nChoix : ");
        scanf("%d", &choix);

            switch (choix) {
            case 1:
                afficher_infos();
                printf("- Liste des livres -\n");
                if (nb_livres == 0) {
                    printf("(Aucun livre pour l'instant)\n");
                } else {
                    for (int i = 0; i < nb_livres; i++) {
                        printf("%d. %s\n", i + 1, titres[i]);
                    }
                }
                break;
            case 2:
                ajouter_livre(titres, &nb_livres);
                break;
            case 3:
                printf("Recherche : ");
                vider_buffer();
                fgets(recherche, MAX_STR, stdin);
                recherche[strcspn(recherche, "\n")] = 0;
                if (rechercher_livre(titres, nb_livres, recherche) == 0) {
                    printf(" Introuvable.\n");
                }
                break;
            case 4: printf("Au revoir.\n"); break;
            default: printf("Option invalide.\n");
        }
    } while (choix != 4);
}
