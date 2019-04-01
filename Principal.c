#include <stdio.h>
#include <stdlib.h>
#include "Action_chevaux.h"
#include "Affichage.h"
#include "petitchevaux.h"
#include "Verification.h"
#include "Deroulement.h"



/**fonction principale*/
int main(){
  int j,i,nb_j,tour;
  chevaux chevaux[16]; //Le tableau chevaux sert à stocker les données des différents chevaux
  /*char ch_coul[][8]={"Jaune","Bleu","Rouge","Vert"};
  char ch_num[][8]={"un","deux","trois","quatre"};*/
  int plateau[15][15]={{-3,-3,-3,-3,-3,-3,13,14,15,-44,-4,-4,-4,-4,-4},
		       {-3,-3,-3,-3,-3,-3,12,63,16,-4,-4,-4,-4,-4,-4},
		       {-3,-3,-3,-3,-3,-3,11,64,17,-4,-4,-4,-4,-4,-4},
		       {-3,-3,-3,-3,-3,-3,10,65,18,-4,-4,-4,-4,-4,-4},
		       {-3,-3,-3,-3,-3,-3,9,66,19,-4,-4,-4,-4,-4,-4},
		       {-43,-3,-3,-3,-3,-3,8,67,20,-4,-4,-4,-4,-4,-4},
		       {1,2,3,4,5,6,7,68,21,22,23,24,25,26,27},
		       {0,57,58,59,60,61,62,81,74,73,72,71,70,69,28},
		       {55,54,53,52,51,50,49,80,35,34,33,32,31,30,29},
		       {-2,-2,-2,-2,-2,-2,48,79,36,-1,-1,-1,-1,-1,-41},
		       {-2,-2,-2,-2,-2,-2,47,78,37,-1,-1,-1,-1,-1,-1},
		       {-2,-2,-2,-2,-2,-2,46,77,38,-1,-1,-1,-1,-1,-1},
		       {-2,-2,-2,-2,-2,-2,45,76,39,-1,-1,-1,-1,-1,-1},
		       {-2,-2,-2,-2,-2,-2,44,75,40,-1,-1,-1,-1,-1,-1},
		       {-2,-2,-2,-2,-2,-42,43,42,41,-1,-1,-1,-1,-1,-1}};
/*Le tableau plateau contient des valeurs, les pions ont des position égalent à ces valeurs */


  for(couleur_e a=JAUNE; a<=VERT; a++){
    for(numero_e b=UN; b<=QUATRE; b++){
      chevaux[a*4+b].numero_cheval=b;
      chevaux[a*4+b].couleur=a;
      if(a==JAUNE){
		chevaux[a*4+b].position=-43;
      }
      else if(a==BLEU){
		chevaux[a*4+b].position=-44;
      }
      else if(a==VERT){
		chevaux[a*4+b].position=-42;
      }
      else{
		chevaux[a*4+b].position=-41;
      }
    }
  }
  //on initialise les positions, les numeros et les couleurs de chaque chevaux.


  afficher_plateau(plateau,chevaux);
  printf("Nous allons maintenant décider qui va jouer le premier \n");
  int joueur=QuiCquiCommence(); //On détermine le joueur qui commence.
  printf("Le joueur %d commence\n", joueur);

  tour=1;
  while(verification_fin(chevaux,joueur)==0){ /*tant que la vérification de fin de partie n'est pas = 1 la partie continue. REMARQUE: il faut attendre que tout les autres joueurs
  après que le joueur est fini de mettre ses pions sur son échelle pour que la boucle while se ferme*/
    printf("\n---------------- TOUR %d ----------------\n",tour);//indique le numéro du tour (ne sert pas vraiment)
    printf("C'est le tour du joueur %d \n", joueur); //indique le joueur qui jouer
    action(joueur,plateau,chevaux); 
    joueur=joueur%4+1;//passe au joueur suivant à la fin de l'action
    tour++;
  }
  printf("Bravo au joueur %d qui remporte la partie \n",joueur);
 
}
