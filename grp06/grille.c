#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grille.h"

int** allouer_grille(int taille) {
    int** grille = (int**)malloc(taille * sizeof(int*));
    if (!grille) return NULL;
    for (int i = 0; i < taille; ++i) {
        grille[i] = (int*)malloc(taille * sizeof(int));
        if (!grille[i]) {
            // Libération en cas d'échec partiel
            for (int k = 0; k < i; ++k) free(grille[k]);
            free(grille);
            return NULL;
        }
    }
    return grille;
}

void liberer_grille(int** grille, int taille) {
    for (int i = 0; i < taille; ++i) free(grille[i]);
    free(grille);
}

int charger_grille(const char* nom_fichier, int** grille, int* taille, Position* depart, Position* arrivee) {
    FILE* f = fopen(nom_fichier, "r");
    if (!f) {
        perror("Erreur d'ouverture de fichier");
        return 0;
    }

    /*    // Lecture de la regle
        char ligne[64];
        if (fgets(ligne, sizeof(ligne), f)) {
            char type_str[32] = { 0 };
            int valeur = 0;
            if (sscanf_s(ligne, "%31s %d",type_str, (unsigned int)sizeof(type_str), &valeur) >= 1) {
                if (strcmp(type_str, "REGLE_MULTIPLE") == 0) {
                    regle->type = REGLE_MULTIPLE;
                    regle->valeur = valeur;
                }
                else if (strcmp(type_str, "REGLE_PAIRE") == 0) {
                    regle->type = REGLE_PAIRE;
                }
                else if (strcmp(type_str, "REGLE_IMPAIR") == 0) {
                    regle->type = REGLE_IMPAIR;
                }
                else if (strcmp(type_str, "REGLE_SOMME_CHIFFRES") == 0) {
                    regle->type = REGLE_SOMME_CHIFFRES;
                    regle->valeur = valeur;
                }
                else {
                    // Règle par défaut
                    regle->type = REGLE_AUCUNE;
                }
            }
        }
    */

    char ligne[256];
    int i = 0;
    while (fgets(ligne, sizeof(ligne), f) && i < TAILLE_MAX) {
        int j = 0;
        char* context = NULL; // Contexte pour strtok_s
        char* token = strtok_s(ligne, " \t\r\n", &context);
        while (token && j < TAILLE_MAX) {
            if (strcmp(token, "S") == 0) {
                grille[i][j] = 0;
                depart->x = j;
                depart->y = i;
            }
            else if (strcmp(token, "E") == 0) {
                grille[i][j] = 0;
                arrivee->x = j;
                arrivee->y = i;
            }
            else {
                grille[i][j] = atoi(token);
            }
            j++;
            token = strtok_s(NULL, " \t\r\n", &context);
        }
        i++;
    }
    *taille = i;
    fclose(f);
    return 1;
}
