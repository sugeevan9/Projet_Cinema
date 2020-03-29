#include <stdio.h>
#include <stdlib.h>
#include "cinema.h"

// GROUPE : SUGEEVAN SUGUNAPARAJAN, NEIL TOFFA

int main()
{


    FILE* fichier=NULL;
    fichier=fopen("baseCinema.txt","r");
    Film *movies=bdd_cinema(fichier);
    int choix=0;

    printf("---------------Bienvenue sur la BDD CINEMA---------------\n\n");

    while(choix!=1,2,3,4,5)
    {

        printf("\nChoissisez entre : \n\n");
        printf("1) Lister les films (Choisir 1)\n2) Lister les realisateurs (Choisir 2)\n3) Rechercher un film(Choisir 3) \n4) Recherche par Annee (Choisir 4)\n5) Quitter (Choisir 5) \n");
        printf("Votre choix: ");
        scanf("%d",&choix);

        switch(choix)
        {

        case 1:
            liste_film(movies);
            break;

        case 2:
            liste_realisateur(movies);
            break;

        case 3:
            recherche_film(movies);
            break;

        case 4:
            listeFilmParAnnee(movies);
            break;

        case 5:
            exit(0);
            break;

        }
    }
}
