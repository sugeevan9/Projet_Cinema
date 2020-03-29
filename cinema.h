#ifndef CINEMA_H_INCLUDED
#define CINEMA_H_INCLUDED

typedef struct S_Realisateur //Structure Realisateur regroupant ses caracteristiques
{
    char nom_realisateur[30];
    char date_de_naissance[20];
    char lieu_naissance[30];

} Realisateur;


typedef struct S_Acteurs
{
    char nom_acteur_principal[50];

} Acteur;


// STRUCTURE FILM REGROUPANT SES CARACTERISTIQUES (NOM,GENRE,DUREE,...)
typedef struct Film
{
    char nom_film[30];
    char genre[30];
    char *movies;

    int annee_sortie;
    int duree_minute;

    Realisateur caracteristique_realisateur; // De type 'Realisateur' qui regroupe les infos du realisateur
    Acteur caracteristique_acteur;          // De type 'Acteur' qui regroupe les infos du acteur


} Film;


Film *bdd_cinema(FILE *fichier);
void liste_film(Film *movies);
void liste_realisateur(Film *movies);
void recherche_film(Film *movies);
void listeFilmParAnnee(Film *movies);


#endif // CINEMA_H_INCLUDED
