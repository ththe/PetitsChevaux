#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Action_chevaux.h"
#include "Affichage.h"
#include "petitchevaux.h"
#include "Verification.h"
#include "Deroulement.h"


int QuiCquiCommence(){
  int joueur,tmp, b,c;
  char a;
  tmp=0;
  b=0;
  c=0;
  for(joueur=1; joueur<= 4; joueur++){
    printf("Joueur %d, veuillez presser ENTREE pour lancer un dé \n", joueur);
    scanf("%c",&a); 
    b=lancer_des();
    printf("Joueur %d vous avez tiré le nombre %d \n",joueur, b);getchar();
    if(b > c){
      tmp=joueur; //
      c=b;
      printf("Pour l'instant le joueur %d est en tête, il a tire un %d \n", joueur,b);
    }
  }
  return tmp;
}
/*Cette fonction permet de déterminer qui commence: Chaque joueur tire un dés, celui qui tire le plus grand nombre commence, ensuite les tours continuent dans le sens horaire. 
Pour cela la fonction fait tirer à chaque joueur un dé, grâce à la fonction lancer_des, si le dé est plus grand que le dé précédent il est stocké dans la variable c, et le 
numero du joueur sera stocké dans tmp qui sera renvoyé à la fin de la fonction.
*/



int lancer_des (){
  srand(time(NULL));
  return rand()%(6)+1;
}
//Cette fonction tire aléatoirement un nombre entre 1 et 6

int Choix(int joueur){
  int choix;
  printf("Joueur %d quel action voulez vous faire\n(1) Sortir un pion\n(2) Déplacer un pion\n",joueur);
  scanf("%d",&choix);
  while(choix!=1 && choix!=2){
    printf("ERREUR,veuillez choisir quel action voulez vous faire\n(1) Sortir un pion\n(2) Déplacer un pion\n");
    scanf("%d",&choix);
  }
  getchar();
  return choix;
}
/*Cette fonction au joueur de choisir l'action qu'il veut faire entre (1) Sortir un pion ou (2) Déplacer un pion, elle regarde si le choix est valide puis elle renvoie le choix
*/

void action(int joueur, int plateau[][15], chevaux chevaux[]){
  char a;
  int c;
  printf("Joueur %d veuillez tirer un des en appuyant sur ENTREE \n",joueur);
  scanf("%c",&a);
  int des=lancer_des(); //Le joueur tire d'abord un dé grâce à la fonction lancer_des
  printf("Vous avez tiré un %d\n",des);
  if(des==6){ //si il tire un 6
    c=Choix(joueur); // il a le choix de sortir un pion ou de déplacer un pion
    if(c==1 && sorti_possible(joueur,chevaux)){ //si il choisit de sortir un pion et qu'il peut sortir un pion 
      sortir_pion(joueur,chevaux); //il sort le pion
      afficher_plateau(plateau,chevaux); //le plateau s'affiche
      getchar();
      printf("Joueur %d vous avez tirer un 6 vous pouvez rejouer\n",joueur);
      action(joueur,plateau,chevaux); //il peut rejouer donc on re-utilise la fonction 
    }else if(c==2 && deplacement_possible(joueur,chevaux,des)==1){ //sinon si il choisit de déplacer un pion et que le déplacement est possible
      Deplacement(joueur,chevaux,des); //il déplace un pion
      afficher_plateau(plateau,chevaux); //le plateau s'affiche
      getchar();
      printf("Joueur %d vous avez tirer un 6 vous pouvez rejouer\n",joueur);
      action(joueur,plateau,chevaux);//il rejoue
    }
    else{ //sinon si il choisit une action mais que sa réalisation n'est pas possible
      if(c==1 && deplacement_possible(joueur,chevaux,des)==1){ //si il choisit de sortir un pion, et que cela n'est pas possible mais qu'un déplacement est possible
		printf("Sorti de pion impossible mais un déplacement est possible\n"); //on lui indique
		Deplacement(joueur,chevaux,des); //ect..
		afficher_plateau(plateau,chevaux);
		getchar();
		printf("Joueur %d vous avez tirer un 6 vous pouvez rejouer\n",joueur);
		action(joueur,plateau,chevaux);
      }
      else if(c==2 && sorti_possible(joueur,chevaux)){// si il choisit de déplacer un pion, et que cela n'est pas possible mais qu'un pion peut sortir
		printf("Déplacements impossible mais vous pouvez sortir un pion\n");//on lui indique
		sortir_pion(joueur,chevaux); //ect
		afficher_plateau(plateau,chevaux);
		getchar();
		printf("Joueur %d vous avez tirer un 6 vous pouvez rejouer\n",joueur);
		action(joueur,plateau,chevaux);
      }
      else{ //sinon si aucuns déplacement ou sorti de pion n'est possible
		printf("Déplacement impossible\n\n"); //on lui indique et aucune action n'est réalisé
      }
    }
  }
  else if(deplacement_possible(joueur,chevaux,des)==1){ //sinon si il tire un autre nombre que 6 et qu'un déplacement est possible
    Deplacement(joueur,chevaux,des);
    afficher_plateau(plateau,chevaux);
    getchar();
  }
  else{ //sinon si il ne peut rien faire aucune action n'est réalisé
    printf("Déplacement impossible\n\n");
  } 
}	
/* Cette fonction est utilisé à chaque tour du jeu et détermine l'action que va réaliser le joueur en fonction du dé qu'il tire*/