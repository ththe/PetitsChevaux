#include <stdio.h>
#include <stdlib.h>
#include "Action_chevaux.h"
#include "Affichage.h"
#include "petitchevaux.h"
#include "Verification.h"
#include "Deroulement.h"



int verification_pion(int plateau[][15], chevaux chevaux[], int i, int j){
  int d=0;
  for(couleur_e k=JAUNE; k<=VERT; k++){
    for(numero_e l=UN; l<=QUATRE; l++){
      if(plateau[i][j]==chevaux[k*4+l].position && chevaux[k*4+l].position>=0){
	d=1;
      }
    }
   }
  return d;
}
/*Cette fonction permet de vérifier si il y a un pion a une certaine position du plateau en parcourant les position de tout les chevaux et en les comparant avec le plateau(qui est lui même parcouru par la fonction afficher plateau
, si la position est supérieur ou égale à 0. Cette fonction renvoie 1 si il y a un pion*/


int deplacement_possible(int couleur, chevaux chevaux[],int des){
  int possible=0;
  for(int i=1; i<=4;i++){
    if(couleur==1){
      if(chevaux[i-1].position>=0 && pion_sur_le_chemin(chevaux,couleur,des,i-1)!=1){
	possible=1;
      }
    }
    else if(couleur==2){
      if(chevaux[i-1+4].position>=0 && pion_sur_le_chemin(chevaux,couleur,des,i-1+4)!=1){
	possible=1;
      }
    }
    else if(couleur==3){
      if(chevaux[i-1+8].position>=0 && pion_sur_le_chemin(chevaux,couleur,des,i-1+8)!=1){
	possible=1;
      }
    }
    else{
      if(chevaux[i-1+12].position>=0 && pion_sur_le_chemin(chevaux,couleur,des,i-1+12)!=1){
	possible=1;
      }
    }
  }
  return possible;
}
/*Cette fonction permet de vérifier si un déplacement est possible en renvoyant 1 si la position du cheval est supérieur ou égale à 0 et si il n'y a aucun pion sur le chemin.
Cette fonction vérifie la possibilité du déplacement pour les 4 pions du joueur*/


int sorti_possible(int couleur, chevaux chevaux[]){
  int possible=0;
  for(int i=1; i<=4;i++){
    if(couleur==1){
      if(chevaux[i-1].position<0){
	possible=1;
      }
    }
    else if(couleur==2){
      if(chevaux[i-1+4].position<0){
	possible=1;
      }
    }
    else if(couleur==3){
      if(chevaux[i-1+8].position<0){
	possible=1;
      }
    }
    else{
      if(chevaux[i-1+12].position<0){
	possible=1;
      }
    }
  }
  return possible;
}
/*Cette fonction permet de vérifier si la sortie d'un pion est possible en renvoyant 1 si la position du cheval estinférieur à 0
Cette fonction vérifie la possibilité de sortie pour les 4 pions du joueur*/


int verification_fin(chevaux chevaux[], int couleur){
  int verif=0;
  if(couleur==1){
    if(chevaux[0].position==59 || chevaux[1].position==59 || chevaux[2].position==59 || chevaux[3].position==59){
		if(chevaux[0].position==60 || chevaux[1].position==60 || chevaux[2].position==60 || chevaux[3].position==60){
			if(chevaux[0].position==61 || chevaux[1].position==61 || chevaux[2].position==61 || chevaux[3].position==61){
				if(chevaux[0].position==62 || chevaux[1].position==62 || chevaux[2].position==62 || chevaux[3].position==62){
					verif=1;
				}
			}
		}
    }
  }
  else if(couleur==2){
    if(chevaux[4].position==65 || chevaux[5].position==65 || chevaux[6].position==65 || chevaux[7].position==65){
		if(chevaux[4].position==66 || chevaux[5].position==66 || chevaux[6].position==66 || chevaux[7].position==66){
			if(chevaux[4].position==67 || chevaux[5].position==67 || chevaux[6].position==67 || chevaux[7].position==67){
				if(chevaux[4].position==68 || chevaux[5].position==68 || chevaux[6].position==68 || chevaux[7].position==68){
					verif=1;
				}
			}
		}
    }
  }
  else if(couleur==3){
    if(chevaux[8].position==71 || chevaux[9].position==71 || chevaux[10].position==71 || chevaux[11].position==71){
		if(chevaux[8].position==72 || chevaux[9].position==72 || chevaux[10].position==72 || chevaux[11].position==72){
			if(chevaux[8].position==73 || chevaux[9].position==73 || chevaux[10].position==73 || chevaux[11].position==73){
				if(chevaux[8].position==74 || chevaux[9].position==74 || chevaux[10].position==74 || chevaux[11].position==74){
					verif=1;
				}
			}	
		}
    }
  }
  else{
    if(chevaux[12].position==77 || chevaux[13].position==77 || chevaux[14].position==77 || chevaux[15].position==77){
		if(chevaux[12].position==78 || chevaux[13].position==78 || chevaux[14].position==78 || chevaux[15].position==78){
			if(chevaux[12].position==79 || chevaux[13].position==79 || chevaux[14].position==79 || chevaux[15].position==79){
				if(chevaux[12].position==80 || chevaux[13].position==80 || chevaux[14].position==80 || chevaux[15].position==80){
					verif=1;
				}
			}
		}
	}
  }
  return verif;
}
/* Cette fonction permet de vérifier si les 4 pions d'un joueur sont sur les dernières cases de l'échelle. Pour cela la fonction vérifie si il y a d'abord un cheval sur la 3e case,
puis si il y en a un sur la 4e, puis la 5e et enfin la 6e. Si ces 4 conditions sont remplies la fonction renvoie 1
Le jeu ne s'arrête pas tant que cette fonction ne renvoie pas 1.*/


int verif_escalier(chevaux chevaux[],int joueur, int pion, int des){
  int stop=0;
  for(int i=chevaux[pion].position; i<=(chevaux[pion].position+des); i++){
    if(joueur==1){
      if(i%56==0){
		chevaux[pion].position=0;
		stop=1;
      }
    }
    else if(joueur==2){
      if(i%56==14){
		chevaux[pion].position=14;
		stop=1;
      }
    }
    else if(joueur==3){
      if(i%56==28){
		chevaux[pion].position=28;
		stop=1;
      }
    }
    else{
      if(i%56==42){
		chevaux[pion].position=42;
		stop=1;
      }
    }
  }

  if(chevaux[pion].position>=57 && chevaux[pion].position<=80){
    stop=1;
  }
  return stop;
}
/*Cette fonction permet de vérifier si un pion a fini son tour du plateau et doit alors s'arreter devant son échelle. Pour cela, elle vérifie si le pion que le joueur à choisi 
de jouer passe par la case devant l'échelle en parcourant les positions où va passer le pion. 
Elle permet aussi de vérifier si le pion est dans l'échelle et doit alors s'arreter à moins d'avoir fait le bon dé. 
*/

int pion_sur_le_chemin(chevaux chevaux[],int joueur, int des, int pion){
  int impossible=0;
  for(int i=chevaux[pion].position+1; i<(chevaux[pion].position+des); i++){
    for(int j=0; j<16; j++){
      if(i%56==chevaux[j].position && chevaux[pion].couleur!=chevaux[j].couleur){
		impossible=1;
      }
    }
  }
  return impossible;
}
/*Cette fonction permet de vérifier si il y a un pion sur le chemin d'un pion donné, en fonction d'un dé donné. Pour cela elle parcoure les positions où va passer le pion,
et les comparent avec les position de tout les autres pions. Si la position est la même, et la couleur est différente alors la fonction renvoie 1. */

int pion_sur_le_chemin_echelle(chevaux chevaux[],int joueur,int pion){
  int impossible=0;
  for(int j=0; j<16; j++){
    if((chevaux[pion].position+1)%56==chevaux[j].position%56){
      impossible=1;
    }
  } 
  return impossible;
}
/*Cette fonction permet de vérifier si il y a un pion sur le chemin d'un pion donné, en fonction d'un dé donné. Pour cela elle parcoure les positions où va passer le pion,
et les comparent avec les position de tout les autres pions. Si la position est la même alors la fonction renvoie 1.
Cette fonction ne sert que dans l'échelle car les couleurs seront forcement les mêmes */