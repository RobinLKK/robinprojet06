#include <stdio.h>
#include <stdlib.h>
#include "grille.h"
#include "moteur.h"
#include "regles.h"

int main() {
    int taille;
    Position depart, arrivee, joueur;
    char direction;
    int regle = 3;
    taille = TAILLE_MAX;

    int** grille = allouer_grille(taille);
    if (!grille) {
        printf("Erreur d'allocation de la grille.\n");
        return 1;
    }
    if (charger_grille("C:\\Users\\glono\\source\\repos\\2025-grp06-TheBigBangISEN\\grp06\\x64\\Debug\\ressources\\level1.grid", grille, &taille, &depart, &arrivee)) {
        joueur = depart; // Le joueur commence sur la case de départ

        printf("Depart : (%d, %d)\n", depart.x, depart.y);
        printf("Arrivee : (%d, %d)\n", arrivee.x, arrivee.y);

        while (!a_gagne(joueur, arrivee)) {
            printf("\n");
            afficher_grille_avec_joueur(grille, taille, joueur, depart, arrivee);

            printf("Entrez une direction (z=haut, s=bas, q=gauche, d=droite) : ");
            scanf_s(" %c", &direction, 1);

            if (deplacer_joueur(&joueur, direction, grille, taille, regle)) {
                printf("Deplacement reussi !\n");
            }
            else {
                printf("Deplacement impossible.\n");
                // condition de perte ici:
            }
        }

        afficher_grille_avec_joueur(grille, taille, joueur, depart, arrivee);
        printf("Felicitations, vous avez atteint l'arrivee !\n");
    }
    else {
        printf("Erreur de chargement de la grille.\n");
    }

    liberer_grille(grille, taille);

    return 0;
}