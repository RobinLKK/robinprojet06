#include <stdio.h>
#include <stdlib.h>
#include "grille.h"
#include "regles.h"



// Déplacement 

//Vérifie si une case respecte la règle du niveau
int deplacement_valide(int valeur_case, int regle);

//Tente de déplacer le joueur selon la direction
int deplacer_joueur(Position* joueur, char direction, int** grille, int taille,int regle);

// Affiche la grille avec la position actuelle du joueur
void afficher_grille_avec_joueur(int** grille, int taille, Position joueur, Position depart, Position arrivee);

//Vérifie si le joueur a atteint la sortie
int a_gagne(Position joueur, Position arrivee);

//Vérifie si une position est en dehors de la grille
int hors_grille(Position pos, int taille);