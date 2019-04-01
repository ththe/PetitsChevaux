#ifndef PROJET_H
#define PROJET_H

typedef enum { JAUNE, BLEU, ROUGE, VERT } couleur_e;
typedef enum {UN, DEUX, TROIS, QUATRE} numero_e;


 typedef struct{
	numero_e numero_cheval;
	couleur_e couleur;
	int position;
} chevaux;



typedef struct{
	couleur_e couleur;
	int numero_joueur;
	chevaux chevaux_plateau[4];
/* les int nous aideront à déterminer le sens de jeu*/
} joueur;

typedef struct{
	int place_cellule[4];
} cellule;



#endif
