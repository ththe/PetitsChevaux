#include <stdio.h>
#include <stdlib.h>
#include "Action_chevaux.h"
#include "Affichage.h"
#include "petitchevaux.h"
#include "Verification.h"
#include "Deroulement.h"



void afficher_chevaux(int plateau[][15], chevaux chevaux[],int i, int j){
  for(couleur_e k=JAUNE; k<=VERT; k++){ 
    for(numero_e l=UN; l<=QUATRE; l++){
      if(plateau[i][j]==chevaux[k*4+l].position && chevaux[k*4+l].position>=0){
	if(chevaux[k*4+l].couleur==JAUNE){ //JAUNE
	  printf("\033[43m");
	  printf("%d",l+1);
	  printf("\033[00m");
	}
	else if(chevaux[k*4+l].couleur==BLEU){ //BLEU
	  printf("\033[44m");
	  printf("%d",l+1);
	  printf("\033[00m");
	}
	else if(chevaux[k*4+l].couleur==ROUGE){ //ROUGE
	  printf("\033[41m");
	  printf("%d",l+1);
	  printf("\033[00m");
	}
	else{	//VERT
	  printf("\033[42m");
	  printf("%d",l+1);
	  printf("\033[00m");
	}	
      }
    }
  }
}
/* Cette fonction parcours tout les chevaux, si leur position est supérieur ou égale à 0 et que cette position correspond à une position du plateau rentrée en paramêtre alors la fonction
affiche le pions, son numéro et sa couleur.
*/


void afficher_plateau(int plateau[][15], chevaux chevaux[]){
  for(int i=0;i<15;i++){
    for(int j=0;j<15;j++){
      if(plateau[i][j]==-3 || plateau[i][j]==-43 || (i==7 && j<=6 && j>0) && verification_pion(plateau,chevaux,i,j)!=1){ /* toutes les cases ayant pour valeur -3 représente l'écurie 
	  Jaune*/
		printf("\033[43m");
		printf(" ");
		printf(" "); //Nous avons choisi de mettre 2 espaces pour que le plateau soit carré et soit plus beau
		printf("\033[00m");
      }
      else if(plateau[i][j]==-4 || plateau[i][j]==-44  || (j==7 && i<=6 && i>0)&& verification_pion(plateau,chevaux,i,j)!=1 ){  /* toutes les cases ayant pour valeur -4 représente l'écurie 
	  Bleu*/
		printf("\033[44m");
		printf(" ");
		printf(" ");
		printf("\033[00m");
      }
      else if(plateau[i][j]==-2 || plateau[i][j]==-42 || (j==7 && i>=8 && i<14) && verification_pion(plateau,chevaux,i,j)!=1){  /* toutes les cases ayant pour valeur -2 représente l'écurie 
	  Vert*/
		printf("\033[42m");
		printf(" ");
		printf(" ");
		printf("\033[00m");
      }
      else if(plateau[i][j]==-1 || plateau[i][j]==-41 || (i==7 && j>=8 && j<14) && verification_pion(plateau,chevaux,i,j)!=1){ /* toutes les cases ayant pour valeur -2 représente l'écurie 
	  Rouge*/
		printf("\033[41m");
		printf(" ");
		printf(" ");
		printf("\033[00m");
      } 
	  else{
		if(verification_pion(plateau,chevaux,i,j)==1){ /*sinon on vérifie si il y a un pion sur la case*/
			afficher_chevaux(plateau,chevaux,i,j); //si il y en a un on l'affiche
			printf(" ");//on rajoute un espace pour que le plateau reste carré
		}
		else{ //si il y a rien on affiche deux espaces sans couleur
			printf(" ");
			printf(" ");
		}
      }
    }
    printf("\n");
  }
}
/* Cette fonction permet d'afficher le plateau.
*/