#include <stdio.h>
#include <stdlib.h>
#include "grille.h"
#include "regles.h"



// D�placement 

//V�rifie si une case respecte la r�gle du niveau
int deplacement_valide(int valeur_case, int regle);

//Tente de d�placer le joueur selon la direction
int deplacer_joueur(Position* joueur, char direction, int** grille, int taille,int regle);

// Affiche la grille avec la position actuelle du joueur
void afficher_grille_avec_joueur(int** grille, int taille, Position joueur, Position depart, Position arrivee);

//V�rifie si le joueur a atteint la sortie
int a_gagne(Position joueur, Position arrivee);

//V�rifie si une position est en dehors de la grille
int hors_grille(Position pos, int taille);