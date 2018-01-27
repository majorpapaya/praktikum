/************************************
Datum:
Autor:
Version:
Kurzbeschreibung:

************************************/

#define _CRT_SECURE_NO_WARNINGS
#define DIM 3

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Hilfsfunktion zum Leeren

void flashStandardInput(void) {
	int intCharacter;
		while ((intCharacter = getchar()) != '\n' && intCharacter != EOF);
}

void eingabe(int matrix[3][3]);
void ausgabe(int matrix[DIM][DIM]);
int nullen_zaehlen(int matrix[DIM][DIM]);
void kopieren(int matrix_a[DIM][DIM], int matrix_b[DIM][DIM]);
void multiplizieren(int matrix_a[DIM][DIM], int matrix_b[DIM][DIM], int matrix_c[DIM][DIM]);

int main(void) {

	int matrix[DIM][DIM] = { 0 }, matrix_kopie[DIM][DIM] = {0}, matrix_multi[DIM][DIM];
	int nullen = 0, nullen_alt = 0;

	printf("Test f%cr nilpotente Matrizen der Dimension: %d\n",129, DIM);
	printf("----------------------------------------------------\n\n");

	eingabe(matrix);

	printf("\nDie Matrix:\n\n");
	ausgabe(matrix);

	kopieren(matrix, matrix_kopie);
	//ausgabe(matrix_kopie);


	nullen = nullen_zaehlen(matrix);

	printf("\nEs gibt %d Nullen.\n\n", nullen);

	do {
		nullen_alt = nullen;
		multiplizieren(matrix, matrix_kopie, matrix_multi);
		nullen = nullen_zaehlen(matrix_multi);
		kopieren(matrix_multi, matrix_kopie);
	} while (nullen > nullen_alt);

	ausgabe(matrix_multi);

	if (nullen == (DIM * DIM)) printf("\n\nist nilpotent!\n");
	else printf("\n\nist NICHT nilpotent!\n");
	
	return 0;
}

void eingabe(int matrix [3][3]) {

	for (int r = 0; r < DIM; r++) {
		for (int s = 0; s < DIM; s++) {
			printf("Bitte Elemente [%d][%d] eingeben!", r + 1, s + 1);
			scanf("%d", &matrix[r][s]);
			flashStandardInput();
			while (matrix[r][s] < -1 || matrix[r][s] > 1) {
				printf("\nFehler bei der Eingabe, bitte geben Sie das Element [%d][%d] erneut ein : ", r+1, s+1);
				scanf("%d", &matrix[r][s]);
				flashStandardInput();
			}
		}
	}
}

void ausgabe(int matrix[DIM][DIM]) {

	for (int r = 0; r < DIM; r++) {
		printf(" |");
		for (int s = 0; s < DIM; s++) {
			printf("%3.d", matrix[r][s]);
		}
		printf(" |\n\n");
	}
}

int nullen_zaehlen(int matrix[DIM][DIM]) {

	int count = 0;

	for (int r = 0; r < DIM; r++) {
		for (int s = 0; s < DIM; s++) {
			if (matrix[r][s] == 0) count++;
		}
	}
	return count;
}

void kopieren(int matrix_a[DIM][DIM], int matrix_b [DIM][DIM]) {

	for (int r = 0; r < DIM; r++) {
		for (int s = 0; s < DIM; s++) {
			matrix_b[r][s] = matrix_a[r][s];
		}
	}
}

void multiplizieren(int matrix_a[DIM][DIM], int matrix_b[DIM][DIM], int matrix_c[DIM][DIM]) {

	int s, r, k;

	for (r = 0; r < DIM; r++) {
		for (s = 0; s < DIM; s++) {
			matrix_c[r][s] = 0;
			for (k = 0; k < DIM; k++) {
				matrix_c[r][s] += matrix_a[r][k] * matrix_b[k][s];
			}
		}
	}
}