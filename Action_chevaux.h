#ifndef ACTION_H
#define ACTION_H
#include "petitchevaux.h"

void Deplacement(int couleur, chevaux chevaux[], int des);
void sortir_pion(int joueur, chevaux chevaux[]);
void collision(chevaux chevaux[],int pion);
void escalier(chevaux chevaux[], int pion, int couleur,int des);

#endif
