#include <stdio.h>
#include <string.h>  
#include "bibliotheque.h"

int main() {
    char titres[MAX_LIVRES][MAX_STR];
    int nb_livres = 0;
    int choix;
    char recherche[MAX_STR];

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Afficher les informations\n");
        printf("2. Ajouter un livre\n");
        printf("3. Rechercher un livre\n");
        printf("4. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                afficher_infos();
                // Bonus : On affiche la liste aussi pour vérifier
                for(int i=0; i<nb_livres; i++) printf("- %s\n", titres[i]);
                break;
            
            case 2:
                ajouter_livre(titres, &nb_livres);
                break;
            
            case 3:
                printf("Titre a chercher : ");
                vider_buffer();
                fgets(recherche, MAX_STR, stdin);
                recherche[strcspn(recherche, "\n")] = 0; // Enlever le \n

                int resultat = rechercher_livre(titres, nb_livres, recherche);
                
                if (resultat != -1) {
                    printf("Livre trouve a l'emplacement %d !\n", resultat);
                } else {
                    printf("Livre introuvable.\n");
                }
                break;
            
            case 4:
                printf("Au revoir !\n");
                break;
            
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 4);

    return 0;
}