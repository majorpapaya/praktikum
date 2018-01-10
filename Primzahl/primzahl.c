/****************************************************************
Aufgabe 1.2
Autor Maja Rother
Datum 12.12.2017
Kurzbeschreibung:
*****************************************************************/

// Präprozessordirektiven
#define _CRT_SECURE_NO_WARNINGS

// Header
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

void flashStandardInput(void);

int main(void)
{
	double prim = 0.0;
	int check = 0;

	printf("Bitte geben Sie eine nat%crliche Zahl ein: ", 129);
	scanf("%lf", &prim);
	flashStandardInput();
	if (prim < 1 || prim != (int)prim){
	printf("FEHLER: Die eingebenene Zahl ist keine natürliche Zahl!");
	}
	else {
		for (int i = 2; i < prim; i++) {
			rest = (int)prim % i;
			}
		/*if (rest == 0) {
			printf("FEHLER: Die eingebenene Zahl ist KEINE Primzahl!");
		}
			else printf("Die eingebenene Zahl ist eine Primzahl!");
		}*/
	return 0;
}

void flashStandardInput(void)
{
	int intCharacter;
	while ((intCharacter = getchar()) != '\n' && intCharacter != EOF);
}

/*Sichere Abfrage!!!
double a = 0.0;
int check = 0;

do {
printf("Bitte geben Sie eine Ganzzahl von 1-10 ein: ");
check = scanf("%lf", &a);
flashStandardInput();
} while (check == 0 || a < 1 || a > 10 || a != (int)a);*/