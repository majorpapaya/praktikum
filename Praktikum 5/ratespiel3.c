/****************************************************************
Aufgabe 5.1
Autor Maja Rother
Datum 12.12.2017
Kurzbeschreibung: Ratespiel!
*****************************************************************/

// Präprozessordirektiven
#define _CRT_SECURE_NO_WARNINGS

// Header
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

void flashStandardInput(void)
{
	int intCharacter;
	while ((intCharacter = getchar()) != '\n' && intCharacter != EOF);
}

int main(void)
{
	double eingabe = 1;

	printf("Ratespiel\n---------\n\n");
	printf("Denke Dir eine Zahl zwischen 1 und 1000 aus.\n\n");
	printf("Bist du bereit? Dr%ccke die Enter-Taste.", 129);
	scanf("");
	flashStandardInput();
	/*if (getchar() == '\n') //Erwartet die Enter-Taste als Eingabe.
		flashStandardInput(); // zweimal enter nötig*/

		while (eingabe == 1) {
			int small = 0; //Die Variablen hier deklarieren, sodass sie bei einem neuen Spiel auf "0" gesetzt werden.
			int big = 1001;
			int erg;
			int count = 1;
			char x=0;
			int check = 0;
			//int test = 0;
			do {
				printf("\n%d. Versuch:\n-----------\n\n", count);
				erg = (big + small) / 2; //rundet ab
				if (erg < 1) {
					printf("Der Wert ist zu klein.\n\n");
					break;
				}
				printf("Ist die ausgedachte Zahl: %d?\n", erg);
				printf("Wenn nicht, ist die ausgedachte Zahl h%cher [h] oder niedriger [n]?\n\n", 148);
				printf("Eingabe: ");
				scanf("%c", &x);
				flashStandardInput();

				if (x != 'k' && x != 'n' && x != 'h') { //sofern die Eingabe ungleich k,n oder h ist -> Fehlermeldung
					printf("Fehler! Bitte gebe NUR [n], [h] oder [k] ein!\n");
				}
				/*else if (x == 'k') {
					printf("\nSpielende!\n-------\n");
					break; //Verlassen der Schleife
				}*/
				if (x == 'h') {
					small = erg;
					count++;
				}
				else if (x == 'n') {
					big = erg;
					count++;
				}

			} while (x!='k'); // durchläuft während alles außer k eingebeben wird.

			do {
				printf("M%cchten Sie eine weitere Runde spielen?\nJa [1]; Nein [0]\n\n", 148);
				printf("Eingabe: ");
				check = scanf("%lf", &eingabe);
				flashStandardInput();
				printf("\n");
				if (eingabe == 1) {
					printf("Das Spiel beginnt - denken Sie sich eine neue Zahl aus! \n"); //Und dr%ccke enter: \n", 129);
				}
			} while (check == 0 || eingabe < 0 || eingabe > 1 || eingabe != (int)eingabe);
				// if (getchar() == '\n') { //funktioniert nicht, da eingabe == 1 ist!?
		}

	printf("Tsch%css!\n\n", 129);

	return 0;
}