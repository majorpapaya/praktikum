/****************************************************************
Aufgabe 4.1
Autor Maja Rother
Datum 28.11.2017
Kurzbeschreibung: Array_Operationen
*****************************************************************/

// Präprozessordirektiven
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10

// Header
#include <stdio.h>
#include <stdlib.h>
#include<math.h>



void ausgabe(int *pointer, int size) {		//Ausgabe der 10-Werte
	for (int j = 0; j < size; j++) {
		printf("%d ", pointer[j]);
	}
}

void nach_vorne(int *pointer, int size) {	//Verschiebung der Werte nach vorne, erste Zahl wird letzte Zahl [0] -> [9]
	int erstezahl = pointer[0];

	for (int j = 0; j < size - 1; j++) {
		pointer[j] = pointer[j + 1];
	}
	pointer[size - 1] = erstezahl;
}

void nach_hinten(int *pointer, int size) {		//Verschiebung der Werte nach hinten, letzte Zahl wird erste Zahl [9] -> [0]
	int letztezahl = pointer[size - 1];

	for (int j = size - 1; j > 0; j--) {
		pointer[j] = pointer[j - 1];
	}
	pointer[0] = letztezahl;
}

void tausche(int * a, int * b) {
	int perm1 = *a;		// Zwischenspeicher von Pointer a
	*a = *b;			// Übergabe der 1. Zahl mit der zweiten 
	*b = perm1;			// Übergabe des Zwischenspeichers an den zweiten Pointer
}

int main(void)
{
	int array[SIZE];
	int x;

	for (int i = 0; i < SIZE; i++) {
		printf("Geben Sie die %d.te Zahl ein:", i + 1); //Abfrage der 10 Indexe des Arrays
		scanf("%d", &x);

		array[i] = x;
	}

	ausgabe(array, SIZE);
	nach_vorne(array, SIZE);	//Verweis auf Funktion
	printf("\nNach vorne verschieben:\n");
	ausgabe(array, SIZE);		//Ausgabe über die Funktion ausgabe
	nach_hinten(array, SIZE);
	printf("\nNach hinten verschieben:\n");
	ausgabe(array, SIZE);
	tausche(&array[1], &array[8]);
	printf("\nTausche zweite und neunte Zahl:\n");
	ausgabe(array, SIZE);
	printf("\nTausche unsortierte Zahlennachbarn:\n");
	for (int i = 0; i < 9; i = i + 1) {
		if (array[i] > array[i + 1])
			tausche(&array[i], &array[i + 1]);
	}
	for (int k = 0; k < SIZE; k++) {
		printf("%d ", array[k]);
	}
	//ausgabe(array, 10);
	printf("\nTausche 9mal unsortierte Zahlennachbarn:\n");
	for (int j = 0; j < 9; j = j + 1) {
		for (int i = 0; i < 9; i = i + 1) {
			if (array[i] > array[i + 1])
				tausche(&array[i], &array[i + 1]);
		}
	}
	ausgabe(array, SIZE);

	return 0;
}