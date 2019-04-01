all : Principal

Principal: Affichage.o Verification.o Action_chevaux.o Deroulement.o Principal.o
	gcc -Wall Affichage.o Verification.o Action_chevaux.o Deroulement.o Principal.o -o petit_chevaux

Affichage.o: Affichage.c
	gcc -Wall -c Affichage.c

Verification.o: Verification.c
	gcc -Wall -c Verification.c

Action_chevaux.o: Action_chevaux.c
	gcc -Wall -c Action_chevaux.c

Deroulement.o: Deroulement.c
	gcc -Wall -c Deroulement.c

clean:
	rm *.o
