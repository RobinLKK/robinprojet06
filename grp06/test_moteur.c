/*#include <stdio.h>
#include "moteur.h"
#include "grille.h"

void test_hors_grille() {
    Position pos1 = {0, 0};
    Position pos2 = {5, 5};
    Position pos3 = {-1, 3};
    Position pos4 = {3, -1};
    int taille = 5;

    printf("Test hors_grille:\n");
    printf("Position (0, 0): %d (attendu: 0)\n", hors_grille(pos1, taille));
    printf("Position (5, 5): %d (attendu: 1)\n", hors_grille(pos2, taille));
    printf("Position (-1, 3): %d (attendu: 1)\n", hors_grille(pos3, taille));
    printf("Position (3, -1): %d (attendu: 1)\n", hors_grille(pos4, taille));
}

void test_deplacement_valide() {
    int valeur1 = 9;
    int valeur2 = 10;
    int regle = 3;

    printf("Test deplacement_valide:\n");
    printf("Valeur 9, règle 3: %d (attendu: 1)\n", deplacement_valide(valeur1, regle));
    printf("Valeur 10, règle 3: %d (attendu: 0)\n", deplacement_valide(valeur2, regle));
}
*/