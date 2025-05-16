/*#include <stdio.h>
#include "solver.h"

// Fonction pour initialiser la grille avec des valeurs aléatoires
void initialiserGrille(Case grille[TAILLE_GRILLE][TAILLE_GRILLE]) {
    for (int i = 0; i < TAILLE_GRILLE; i++) {
        for (int j = 0; j < TAILLE_GRILLE; j++) {
            grille[i][j].valeur = rand() % 100 + 1; // Valeurs entre 1 et 100
            grille[i][j].visitee = 0;
        }
    }
}

// Fonction pour afficher la grille
void afficherGrille(Case grille[TAILLE_GRILLE][TAILLE_GRILLE]) {
    for (int i = 0; i < TAILLE_GRILLE; i++) {
        for (int j = 0; j < TAILLE_GRILLE; j++) {
            printf("%d ", grille[i][j].valeur);
        }
        printf("\\n");
    }
}

// Fonction pour résoudre la grille selon les règles du jeu
int resoudreGrille(Case grille[TAILLE_GRILLE][TAILLE_GRILLE], int x, int y) {
    // Exemple de règle : déplacement si la valeur est un multiple de 3
    if (grille[x][y].valeur % 3 == 0) {
        grille[x][y].visitee = 1;
        // Logique pour continuer la résolution
        // ...
        return 1; // Retourne 1 si la case est visitée
    }
    return 0; // Retourne 0 si la case ne peut pas être visitée
}
*/