#ifndef GRILLE_H
#define GRILLE_H
#include <stdio.h>
#include "regles.h"

#define TAILLE_MAX 100
typedef struct Position {
	int x;
	int y;

}Position;

// Alloue dynamiquement une matrice carrée de taille taille × taille.
int** allouer_grille(int taille);

void liberer_grille(int** grille, int taille);

// Charge une grille depuis un fichier texte (.grid) vers un tableau 2D
int charger_grille(const char* fichier, int** grille, int* taille, Position* depart, Position* arrivee);

//Affichage de la grille (test initial)
//void afficher_grille(int grille[TAILLE_MAX][TAILLE_MAX],int lignes,int colonnes, Position depart, Position arrivee);

#endif 