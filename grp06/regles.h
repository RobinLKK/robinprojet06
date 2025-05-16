#ifndef REGLES_H
#define REGLES_H
#include <stdio.h>
#include "grille.h"

typedef enum {
	REGLE_MULTIPLE,
	REGLE_PAIRE,
	REGLE_IMPAIR,
	REGLE_PREMIER,
	REGLE_SOMME_CHIFFRES,
	REGLE_AUCUNE,
	//ajout d'autres regles ici

}TypeRegle;

typedef struct Regle {
	TypeRegle type;
	int valeur;
}Regle;

// Affichage de la regle
void Affiche_regle(const Regle* regle);

// Fais la somme des valeurs parcourues lorsque le type de regle est somme...
int somme_chiffres(int n);
#endif // REGLES_H

