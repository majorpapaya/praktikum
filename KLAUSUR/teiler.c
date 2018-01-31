/************************************
Datum:
Autor:
Version:
Kurzbeschreibung: Teiler

************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Hilfsfunktion zum Leeren

void flashStandardInput(void) {
	int intCharacter;
		while ((intCharacter = getchar()) != '\n' && intCharacter!=EOF);
}

int main(void) {

	int r = 0, max = 0, min = 0;
	float n1 = 0.0f, n2 = 0.0f;

	printf("Bestimmung der ggt zweier ganzer Zahlen: \n");
	printf("------------------------------------------\n");

	printf("\nBitte geben Sie die erste Zahl ein:");
	while (1 != scanf("%f", &n1) || n1 != (int)n1 || n1 == 0) { //1 != ... ermöglicht speichern der Zahl, Rückgabewert ist gleich 0, wenn der Typ eingegeben wird. || 
		flashStandardInput(); 					//!= (int) selektiert Fließkommazahlen raus.
			printf("Die Eingabe war fehlerhaft!\n");	//|| == 0 selektiert 0 raus
			flashStandardInput();
			printf("Bitte Versuchen Sie es erneut:");
	}
	
	/*der Kopf wird immer durchlaufen, der Rumpf nur, wenn der Returnwert des Kopfes 1 ist. 
	Und der Kopf ist in diesem Fall 1, wenn der Returnwert von scanf ungleich (!=) 1 ist*/

	printf("\nBitte geben Sie die zweite Zahl ein:");
	while (1 != scanf("%f", &n2) || n2 != (int)n2 || n2 == 0) {
		flashStandardInput();
		printf("Die Eingabe war fehlerhaft!\n");
		printf("Bitte Versuchen Sie es erneut:");
	}
	
	//Selektieren des größten und kleinsten Wertes - nicht zwangsläufig nötig!
	/*if (n1 > n2) {
		max = (int)n1;
		min = (int)n2;
	}
	else {
		max = (int)n2;
		min = (int)n1;
	}

	printf("Max: %d und Min: %d", max, min);*/ 


	printf("\nDer ggT von %d und %d ist: ", (int)n1, (int)n2);

	//Bestimmen des ggT. 
	do {
		r = (int)n1 % (int)n2;
		n1 = n2;
		n2 = (float)r;
	} while (r != 0);
	
	printf("%d\n", (int)n1);

	/*do {
		r = max % min;
		max = min;
		min = r;
	} while (r != 0);

	printf("%d\n", max);*/

	return 0;
}
