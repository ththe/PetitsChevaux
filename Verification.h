#ifndef VERIFICATION_H
#define VERIFICATION_H

int verification_pion(int plateau[][15], chevaux chevaux[], int i, int j);
int deplacement_possible(int couleur, chevaux chevaux[], int des);
int sorti_possible(int couleur, chevaux chevaux[]);
int verification_fin(chevaux chevaux[], int joueur);
int pion_sur_le_chemin(chevaux chevaux[],int joueur, int des, int pion);
int verif_escalier(chevaux chevaux[],int joueur, int pion, int des);
int pion_sur_le_chemin_echelle(chevaux chevaux[],int joueur,int pion);

#endif