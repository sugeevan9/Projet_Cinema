#include <stdlib.h>
#include <stdio.h>
#include "cinema.h"
#define TAILLE 5
#include <string.h>

// Fonction permmettant d'ouvrir le fichier baseCinema, de le lire et stocker les informations dans un tableau de structure 'movies'

Film *bdd_cinema(FILE *fichier)
{

    char carac[200];
    int i= 0;
    Film *movies=NULL;
    movies=malloc(sizeof(Film)*TAILLE);

    if (fichier != NULL)
    {

        while(fgets(carac,200,fichier)!= NULL)
        {

            char *token=strtok(carac,".");// Prend la chaine de caractere jusqu'au '.'
            strcpy(movies[i].nom_film,token);   // la copie dans la rubrique dédiée, ici dans le nom du film


            token=strtok(NULL,".");
            movies[i].annee_sortie=atoi(token); //la fonction atoi permet de convertir un string en entier (int)


            token=strtok(NULL,".");
            strcpy(movies[i].caracteristique_realisateur.nom_realisateur,token);


            token=strtok(NULL,".");
            strcpy(movies[i].caracteristique_realisateur.date_de_naissance,token);


            token=strtok(NULL,".");
            strcpy(movies[i].caracteristique_realisateur.lieu_naissance,token);


            token=strtok(NULL,".");
            strcpy(movies[i].caracteristique_acteur.nom_acteur_principal,token);


            token=strtok(NULL,".");
            movies[i].duree_minute=atoi(token);


            token=strtok(NULL,".");
            strcpy(movies[i].genre,token);

            i++;
        }
    }
    fclose(fichier);


    return movies;
}

 // FONCTION PERMETTANT DE LISTER LES FILMS
void liste_film(Film *movies)
{

    int i;
    printf("---------------Voici la liste des films---------------  :\n\n ");
    printf("===Fiche FILM===\n\n");

    for(i=0; i<TAILLE; i++)
    {
        printf("Nom du film %d: %s (%d)\nRealisateur: %s\nActeurs: %s\nDuree (en min): %d\nGenre: %s",i,movies[i].nom_film,movies[i].annee_sortie,movies[i].caracteristique_realisateur.nom_realisateur,movies[i].caracteristique_acteur.nom_acteur_principal,movies[i].duree_minute,movies[i].genre);
        printf("\n\n");
    }


}
 // FONCTION PERMETTANT DE LISTER LES REALISATEURS

void liste_realisateur(Film *movies)
{
    int i;

    printf("\n\nListe des realisateurs dans votre BDD :\n\n");
    printf("===Fiche REALISATEUR===\n\n");

    for(i=0; i<TAILLE; i++)
        {
        printf("- Nom du realisateur %d: %s\n",i,movies[i].caracteristique_realisateur.nom_realisateur);
        printf("- Date de naissance : %s\n",movies[i].caracteristique_realisateur.date_de_naissance);
        printf("- Lieu de naissance : %s\n\n",movies[i].caracteristique_realisateur.lieu_naissance);

        }

}

 // FONCTION PERMETTANT DE RECHERCHER UN FILM

void recherche_film(Film *movies)
{
    int i=0;
    char film_rechercher[30];
    int trouve=0;

    printf("\nQuel film recherchez-vous ?\n");
    printf("Film à rechercher (1ere lettre du film en majuscule): ");
    scanf("%s",film_rechercher);


    while(trouve==0 && i<TAILLE)    //Tant qu'il n'a pas ete trouvé et que la taille n'est pas dépassée
    {
        if(strcmp(movies[i].nom_film,film_rechercher)==0) //Si identique
        {
            printf("\nNom du film : %s (%d)\nRealisateur: %s\nActeurs: %s\nDuree (en min): %d\nGenre: %s",movies[i].nom_film,movies[i].annee_sortie,movies[i].caracteristique_realisateur.nom_realisateur,movies[i].caracteristique_acteur.nom_acteur_principal,movies[i].duree_minute,movies[i].genre);
            printf("\n\n");
            trouve=1;
        }
        i++;

    }
    if(trouve==0)
    {
        printf("\nFilm non referencé dans la BDD Cinema\n");
    }

}

 // FONCTION PERMETTANT DE LISTER LES FILMS D'UNE ANNEE PRECISE
void listeFilmParAnnee(Film *movies)
{
    int i=0;
    int choix=0;
    int trouve=0;

    printf("\nQuel annee recherchez-vous ?\n");
    printf("Film des annees X a rechercher : ");
    scanf("%d",&choix);


    while(i<TAILLE)
    {
        if(movies[i].annee_sortie==choix)
        {
            printf("\nNom du film : %s (%d)\nRealisateur: %s\nActeurs: %s\nDuree (en min): %d\nGenre: %s",movies[i].nom_film,movies[i].annee_sortie,movies[i].caracteristique_realisateur.nom_realisateur,movies[i].caracteristique_acteur.nom_acteur_principal,movies[i].duree_minute,movies[i].genre);
            printf("\n\n");
            trouve=1;
        }
        i++;
    }

    if(trouve==0)
    {
        printf("\nAucun film de cette annee dans la BDD Cinema\n");
    }

}
