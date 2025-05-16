#include <stdio.h>
#include <stdlib.h>
#include "moteur.h"
#include "grille.h"
#include "regles.h"

int hors_grille(Position pos, int taille) {
	if (pos.x <0 || pos.x >taille || pos.y<0 || pos.y > taille) {

		return 1; // hors de la grille
	}
	else
		return 0; // dans la grille
}
int deplacement_valide(int valeur_case, int regle) {
    return (valeur_case % regle == 0);
}

int deplacer_joueur(Position* joueur, char direction, int** grille, int taille, int regle) {
    Position nouvelle_pos = *joueur;

    if (direction == 'z') nouvelle_pos.y--; // haut
    else if (direction == 's') nouvelle_pos.y++; // bas
    else if (direction == 'q') nouvelle_pos.x--; // gauche
    else if (direction == 'd') nouvelle_pos.x++; // droite
    else return 0; // touche invalide

    if (nouvelle_pos.x < 0 || nouvelle_pos.x>= taille || nouvelle_pos.y < 0 || nouvelle_pos.y>= taille) {
        return 0; // déplacement invalide (hors de la grille utilisée)
    }

    int valeur = grille[nouvelle_pos.y][nouvelle_pos.x];

    // Vérification de la règle du niveau
    if (!deplacement_valide(valeur, regle))
        return 0;

    // Déplacement valide : mise à jour de la position
    *joueur = nouvelle_pos;
    return 1;
}

void afficher_grille_avec_joueur(int** grille, int taille, Position joueur, Position depart, Position arrivee) {
    for (int y = 0; y < taille; y++) {
        for (int x = 0; x < taille; x++) {
            if (x == joueur.x && y == joueur.y) 
                printf(" J "); // J position actuelle du joueur
            else if (x == depart.x && y == depart.y) 
                printf(" S "); // S position de départ
            else if (x == arrivee.x && y == arrivee.y) 
                printf(" E "); // E position d'arrivée          
            else 
                printf("%2d ", grille[y][x]);          
        }
        printf("\n");
    }
}
int a_gagne(Position joueur, Position arrivee) {
    if (joueur.x == arrivee.x && joueur.y == arrivee.y) {
        return 1;
    }
    else
        return 0;
}