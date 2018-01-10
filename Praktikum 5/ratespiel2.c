/****************************************************************
Aufgabe 5.1
Autor Maja Rother
Datum 12.12.2017
Kurzbeschreibung: Ratespiel!
*****************************************************************/

/*// Präprozessordirektiven
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
	int eingabe = 1;

	printf("Ratespiel\n---------\n\n");
	printf("Denke Dir eine Zahl zwischen 1 und 1000 aus.\n\n");
	printf("Bist du bereit? Dr%ccke die Enter-Taste.", 129);
	if (getchar() == '\n') //Erwartet die Enter-Taste als Eingabe.

		while (eingabe == 1) {
			int small = 0; //Die Variablen hier deklarieren, sodass sie bei einem neuen Spiel auf "0" gesetzt werden.
			int big = 1001;
			int erg;
			int count = 1;
			char x;

			while (1) {
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

				if (x != 'k' && x != 'n' && x != 'h') {
					printf("Error!\n");
					break;
				}
				else if (x == 'k') {
					printf("\nSpielende!\n-------\n");
					break; //Verlassen der Schleife
				}
				else if (x == 'h') {
					small = erg;
					count++;
				}
				else if (x == 'n') {
					big = erg;
					count++;
				}
	
			}

			printf("M%cchten Sie eine weitere Runde spielen?\nJa [1]; Nein [0]\n\n", 148);
			printf("Eingabe: ");
			scanf("%d", &eingabe);
			printf("\n");
			if (eingabe == 1) {
				printf("Das Spiel beginnt - denken Sie sich eine neue Zahl aus! Und drücke enter: \n");
				//if (getchar() == '\n') funktioniert hier nicht, wieso!?
			}
		}

	printf("Tsch%css!\n\n", 129);

	return 0;
}*/