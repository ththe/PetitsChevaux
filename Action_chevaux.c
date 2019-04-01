#include <stdio.h>
#include <stdlib.h>
#include "Action_chevaux.h"
#include "Affichage.h"
#include "petitchevaux.h"
#include "Verification.h"
#include "Deroulement.h"

void Deplacement(int couleur, chevaux chevaux[], int des){
  int pion;
  printf("Quel pion voulez-vous déplacer ?(Veuillez entrer le numero de cheval que vous voulez déplacer)\n");
  for(int i=1; i<=4;i++){
    if(couleur==1){
      if(chevaux[i-1].position>=0 && pion_sur_le_chemin(chevaux,couleur,des,i-1)!=1){
		printf("Cheval %d\n",i);
      }
    }
    else if(couleur==2){
      if(chevaux[i-1+4].position>=0 && pion_sur_le_chemin(chevaux,couleur,des,i-1+4)!=1){
		printf("Cheval %d\n",i);
      }
    }
    else if(couleur==3){
      if(chevaux[i-1+8].position>=0 && pion_sur_le_chemin(chevaux,couleur,des,i-1+8)!=1){
		printf("Cheval %d\n",i);
      }
    }
    else{
      if(chevaux[i-1+12].position>=0 && pion_sur_le_chemin(chevaux,couleur,des,i-1+12)!=1){
		printf("Cheval %d\n",i);
      }
    }
  }
  scanf("%d",&pion);
  /*D'abord on fait choisir au joueur quel pion veut-il déplacer. La fonction ne propose que ceux qui peuvent être déplacé en regardant si leur 
  position est positive et si il n'y a aucun pion sur le chemin*/
  
  
  if(couleur==1){
    while(pion>4 || pion<1 || chevaux[pion-1].position<0 || pion_sur_le_chemin(chevaux,couleur,des,pion-1)!=0){
      printf("Erreur veuillez choisir un pion existant ou étant déjà sorti\n");
      scanf("%d",&pion);
    }
  }
  else if(couleur==2){
    while(pion>4 || pion<1 || chevaux[pion-1+4].position<0 || pion_sur_le_chemin(chevaux,couleur,des,pion-1+4)!=0){
      printf("Erreur veuillez choisir un pion existant ou étant déjà sorti\n");
      scanf("%d",&pion);
    }
  }
  else if(couleur==3){
    while(pion>4 || pion<1 || chevaux[pion-1+8].position<0 ||  pion_sur_le_chemin(chevaux,couleur,des,pion-1+8)!=0){
      printf("Erreur veuillez choisir un pion existant ou étant déjà sorti\n");
      scanf("%d",&pion);
    }
  }
  else{
    while(pion>4 || pion<1 || chevaux[pion-1+12].position<0 || pion_sur_le_chemin(chevaux,couleur,des,pion-1+12)!=0){
      printf("Erreur veuillez choisir un pion existant ou étant déjà sorti\n");
      scanf("%d",&pion);
    }
  }
/*Puis on vérifie que ce que choisit le joueur est valide*/
  
  /*Enfin on déplace le pion choisit à sa nouvelle position*/
  if(couleur==1){
    if(verif_escalier(chevaux,couleur,pion-1,des)==0){ //On vérifie si le pion n'a pas fini son tour 
      chevaux[pion-1].position=(chevaux[pion-1].position+des)%56; //puis on change la position du pion en rajoutant le dé à cette dernière
	  /*On met pion-1 car le tableau chevaux est remplie de la case 0 à la case 15*/
      collision(chevaux,pion-1); //On regarde si le pion est arrivé sur le pion d'un autre joueur
    }
    else{
      escalier(chevaux,pion-1,couleur,des);//si le pion a fini son tour, on regarde si il peut monter l'escalier
    }
  }
  else if(couleur==2){
    if(verif_escalier(chevaux,couleur,pion-1+4,des)==0){
      chevaux[pion-1+4].position=(chevaux[pion-1+4].position+des)%56;
      collision(chevaux,pion-1+4);
    }
    else{
      escalier(chevaux,pion-1+4,couleur,des);
    }
  }
  else if(couleur==3){
    if(verif_escalier(chevaux,couleur,pion-1+8,des)==0){
      chevaux[pion-1+8].position=(chevaux[pion-1+8].position+des)%56;
      collision(chevaux,pion-1+8);
    }
    else{
      escalier(chevaux,pion-1+8,couleur,des);
    }
  }
  else if(couleur==4){
    if(verif_escalier(chevaux,couleur,pion-1+12,des)==0){
      chevaux[pion-1+12].position=(chevaux[pion-1+12].position+des)%56;
      collision(chevaux,pion-1+12);
    }
    else{
      escalier(chevaux,pion-1+12,couleur,des);
    }
  }
  
}




void sortir_pion(int couleur, chevaux chevaux[]){
  int pion;
  printf("Quel pion voulez-vous sortir ?(Veuillez entrer le numero de cheval que vous voulez sortir)\n");
  for(int i=1; i<=4;i++){
    if(couleur==1){
      if(chevaux[i-1].position<0){
		printf("Cheval %d\n",i);
      }
    }
    else if(couleur==2){
      if(chevaux[i-1+4].position<0){
		printf("Cheval %d\n",i);
      }
    }
    else if(couleur==3){
      if(chevaux[i-1+8].position<0){
		printf("Cheval %d\n",i);
      }
    }
    else{
      if(chevaux[i-1+12].position<0){
		printf("Cheval %d\n",i);
      }
    }
  }
  //On affiche les pions qui peuvent être sorti
  
  scanf("%d",&pion);
  
  if(couleur==1){
    while(pion>4 || pion<1 || chevaux[pion-1].position>=0){
      printf("Erreur veuillez choisir un pion existant ou n'étant pas déjà sorti\n");
      scanf("%d",&pion);
    }
  }
  else if(couleur==2){
    while(pion>4 || pion<1 || chevaux[pion-1+4].position>=0){
      printf("Erreur veuillez choisir un pion existant ou n'étant pas déjà sorti\n");
      scanf("%d",&pion);
    }
  }
  else if(couleur==3){
    while(pion>4 || pion<1 || chevaux[pion-1+8].position>=0){
      printf("Erreur veuillez choisir un pion existant ou n'étant pas déjà sorti\n");
      scanf("%d",&pion);
    }
  }
  else{
    while(pion>4 || pion<1 || chevaux[pion-1+12].position>=0){
      printf("Erreur veuillez choisir un pion existant ou n'étant pas déjà sorti\n");
      scanf("%d",&pion);
    }
  }
  //On vérifie que le pion choisi puisse être sorti
  
  if(couleur==1){
    chevaux[pion-1].position=1;
    collision(chevaux,pion-1);
  }
  else if(couleur==2){
    chevaux[pion-1+4].position=15;
    collision(chevaux,pion-1+4);
  }
  else if(couleur==3){
    chevaux[pion-1+8].position=29;
    collision(chevaux,pion-1+8);
  }
  else{
    chevaux[pion-1+12].position=43;
    collision(chevaux,pion-1+12);
  }
  //On met le pion choisit sur la case départ en fonction de sa couleur
}	
/*Remarque: Peut être nous aurions pu faire les différentes actions des 2 fonctions ci-dessus dans différentes fonctions*/



void escalier(chevaux chevaux[], int pion, int couleur, int des){
  if(couleur==1){
    if(des==1 && chevaux[pion].position==0){ //si le dé est égale à 1 et que le pion est devant l'échelle
      if(pion_sur_le_chemin_echelle(chevaux,couleur,pion)!=1){ //et si il n'y a personne sur la 1er position de l'échelle
		chevaux[pion].position=57; //alors la position du pion sera la première case de l'échelle
      }
      else{
		chevaux[pion].position=0;//sinon le pion reste devant l'échelle
      }
    }
    else if(des==2 && chevaux[pion].position==57){ //sinon si le dé est égale à 2 et que le pion se trouve en première position de l'échelle
      if(pion_sur_le_chemin_echelle(chevaux,couleur,pion)!=1){//ect...
		chevaux[pion].position=58;
      }
      else{
		chevaux[pion].position=57;
      }
    }	
    else if(des==3 && chevaux[pion].position==58){
      if(pion_sur_le_chemin_echelle(chevaux,couleur,pion)!=1){
		chevaux[pion].position=59;
      }
      else{
		chevaux[pion].position=58;
      }
    }
    else if(des==4 && chevaux[pion].position==59){
      if(pion_sur_le_chemin_echelle(chevaux,couleur,pion)!=1){
		chevaux[pion].position=60;
      }
      else{
		chevaux[pion].position=59;
      }
    }
    else if(des==5 && chevaux[pion].position==60){
      if(pion_sur_le_chemin_echelle(chevaux,couleur,pion)!=1){
		chevaux[pion].position=61;
      }
      else{
		chevaux[pion].position=60;
      }
    }
	
    else if(des==6 && chevaux[pion].position==61){
      if(pion_sur_le_chemin_echelle(chevaux,couleur,pion)!=1){
		chevaux[pion].position=62;
      }
      else{
		chevaux[pion].position=61;
      }
    }
  }
  else if(couleur==2){
    if(des==1 && chevaux[pion].position==14){
      if(pion_sur_le_chemin_echelle(chevaux,couleur,pion)!=1){
		chevaux[pion].position=63;
      }
      else{
		chevaux[pion].position=14;
      }
    }
    else if(des==2 && chevaux[pion].position==63){
      if(pion_sur_le_chemin_echelle(chevaux,couleur,pion)!=1){
		chevaux[pion].position=64;
      }
      else{
		chevaux[pion].position=63;
      }
    }
    else if(des==3 && chevaux[pion].position==64){
      if(pion_sur_le_chemin_echelle(chevaux,couleur,pion)!=1){
		chevaux[pion].position=65;
      }
      else{
		chevaux[pion].position=64;
      }
    }
    else if(des==4 && chevaux[pion].position==65){
      if(pion_sur_le_chemin_echelle(chevaux,couleur,pion)!=1){
		chevaux[pion].position=66;
      }
      else{
		chevaux[pion].position=65;
      }
    }
    else if(des==5 && chevaux[pion].position==66){
      if(pion_sur_le_chemin_echelle(chevaux,couleur,pion)!=1){
		chevaux[pion].position=67;
      }
      else{
		chevaux[pion].position=66;
      }
    }
    else if(des==6 && chevaux[pion].position==67){
      if(pion_sur_le_chemin_echelle(chevaux,couleur,pion)!=1){
		chevaux[pion].position=68;
      }
      else{
		chevaux[pion].position=67;
      }
    }
  } 
  else if(couleur==3){
    if(des==1 && chevaux[pion].position==28){
      if(pion_sur_le_chemin_echelle(chevaux,couleur,pion)!=1){
		chevaux[pion].position=69;
      }
      else{
		chevaux[pion].position=28;
      }
    }
    else if(des==2 && chevaux[pion].position==69){
      if(pion_sur_le_chemin_echelle(chevaux,couleur,pion)!=1){
		chevaux[pion].position=70;
      }
      else{
		chevaux[pion].position=69;
      }
    }
    else if(des==3 && chevaux[pion].position==70){
      if(pion_sur_le_chemin_echelle(chevaux,couleur,pion)!=1){
		chevaux[pion].position=71;
      }
      else{
		chevaux[pion].position=70;
      }
    }
    else if(des==4 && chevaux[pion].position==71){
      if(pion_sur_le_chemin_echelle(chevaux,couleur,pion)!=1){
		chevaux[pion].position=72;
      }
      else{
		chevaux[pion].position=71;
      }
    }
    else if(des==5 && chevaux[pion].position==72){
      if(pion_sur_le_chemin_echelle(chevaux,couleur,pion)!=1){
		chevaux[pion].position=73;
      }
      else{
		chevaux[pion].position=72;
      }
    }
    else if(des==6 && chevaux[pion].position==73){
      if(pion_sur_le_chemin_echelle(chevaux,couleur,pion)!=1){
		chevaux[pion].position=74;
      }
      else{
		chevaux[pion].position=73;
      }    
    }
  }
  else{
    if(des==1 && chevaux[pion].position==42){
      if(pion_sur_le_chemin_echelle(chevaux,couleur,pion)!=1){
		chevaux[pion].position=75;
      }
      else{
		chevaux[pion].position=42;
      }
    }
    else if(des==2 && chevaux[pion].position==75){
      if(pion_sur_le_chemin_echelle(chevaux,couleur,pion)!=1){
		chevaux[pion].position=76;
      }
      else{
		chevaux[pion].position=75;
      }
    }
    else if(des==3 && chevaux[pion].position==76){
      if(pion_sur_le_chemin_echelle(chevaux,couleur,pion)!=1){
		chevaux[pion].position=77;
      }
      else{
		chevaux[pion].position=76;
      }
    }
    else if(des==4 && chevaux[pion].position==77){
      if(pion_sur_le_chemin_echelle(chevaux,couleur,pion)!=1){
		chevaux[pion].position=78;
      }
      else{
		chevaux[pion].position=77;
      }
    }
    else if(des==5 && chevaux[pion].position==78){
      if(pion_sur_le_chemin_echelle(chevaux,couleur,pion)!=1){
		chevaux[pion].position=79;
      }
      else{
		chevaux[pion].position=78;
      }
    }
    else if(des==6 && chevaux[pion].position==79){
      if(pion_sur_le_chemin_echelle(chevaux,couleur,pion)!=1){
		chevaux[pion].position=80;
      }
      else{
		chevaux[pion].position=79;
      }
      
    }
  }
}
/*cette fonction permet de faire avancer les pions sur l'échelle si il tire le bon dé et qu'il n'y a personne devant le pion*/


void collision(chevaux chevaux[],int pion){
  for(int j=0; j<16; j++){
    if(chevaux[pion].couleur!=chevaux[j].couleur && chevaux[pion].position==chevaux[j].position){
      if(chevaux[j].couleur==JAUNE){
		chevaux[j].position=-43;
      }
      else if(chevaux[j].couleur==BLEU){
		chevaux[j].position=-44;
      }
      else if(chevaux[j].couleur==VERT){
		chevaux[j].position=-42;
      }
      else{
		chevaux[j].position=-41;
      }
    }
  }
}
/*Cette fonction permet de voir si un cheval est tombé sur un autre cheval suite à son action, pour cela on compare la position du pion qui vient de jouer avec toutes les autres
si elle est égale et que le pion n'est pas de même couleur, le pion trouvé retourne dans son écurie*/
