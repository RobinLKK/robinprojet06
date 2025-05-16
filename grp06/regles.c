#include <stdio.h>
#include "regles.h"


int somme_chiffres(int n) {
	int somme = 0;
	
	while (n > 0) {
		somme += n % 10;
		n / 10;
	}
	return somme;
	
}

void Affiche_regle(const Regle* regle) {
    switch (regle->type) {
    case REGLE_MULTIPLE:
        printf("Règle : Multiple de %d\n", regle->valeur);
        break;
    case REGLE_PAIRE:
        printf("Règle : Nombre pair\n");
        break;
    case REGLE_IMPAIR:
        printf("Règle : Nombre impair\n");
        break;
    case REGLE_PREMIER:
        printf("Règle : Nombre premier\n");
        break;
    case REGLE_SOMME_CHIFFRES:
        printf("Règle : Somme des chiffres = %d\n", regle->valeur);
        break;
    default:
        printf("Aucune règle\n");
        break;
    }
}