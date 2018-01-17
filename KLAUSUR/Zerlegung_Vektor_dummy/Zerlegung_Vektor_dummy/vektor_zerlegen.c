/*
Beschreibung:	Programm zur orthogonalen Zerlegung eines Vektors
Autor:			[Namen eintragen]
Datum:			19. Januar 2017
*/

// Präprozessordirektiven
#define _CRT_SECURE_NO_WARNINGS
#define DIM 10

// Einbinden benötigter Header
#include<stdio.h>
#include<stdlib.h>

// Prototypen
float skalarprodukt(float vektor_a[], float vektor_b[], int dim);
void parallel(float vektor_a[], float vektor_b[], float vektor_p[], int dim, float skalar);
void orthogonal(float vektor_a[], float vektor_o[], float vektor_p[], int dim);
void eingabe(float vektor[], int dim);
void ausgabe(float vektor[], int dim);

// Hilfsfunktion um den Eingabepuffer zu leeren
void flashStandardInput(void)
{
	int intCharacter;
	while ((intCharacter = getchar()) != '\n' && intCharacter != EOF);
}


// Beginn der Hauptfunktion
int main(void) {
	// Lokale Variablen
	float vektor_a[10] = { 0 }, vektor_b[10] = { 0 }, vektor_parallel[10] = { 0 }, vektor_orthogonal[10] = {0};
	float skalar;
	int dim = 0, check = 0;
	double dim_temp;
	float vektor_p[10];
	//int check; (check = 0 ||

	//Abfrage der Dimension
	do {
		printf("Bitte geben Sie die Dimension (<= 10) der Vektoren ein: ");
		check = scanf("%lf", &dim_temp);
		flashStandardInput();
	} while (check == 0 || dim_temp < 1 || dim_temp >= 10 || dim_temp != (int)dim_temp);
	dim = (int)dim_temp;

	// Abfrage der Werte
	printf("\nBitte geben Sie den Vektor a ein, der zerlegt werden soll!\n");
	eingabe(vektor_a, dim);
	printf("\nBitte geben Sie den Vektor b ein, der zerlegt werden soll!\n");
	eingabe(vektor_b, dim);

	// Skalarprodukt
	skalar = skalarprodukt(vektor_a, vektor_b, dim);
	if (skalar == 0) {
		printf("\nIn Richtung eines Nullvektors kann nicht zerlegt werden!\n");
		return 0;
	}
	//printf("\nDas Skalarprodukt ist %.2f", skalar);

	//Orthogonale Zerlegung
	printf("Die orthogonale Zerlegung des Vektors a:\n\n");
	ausgabe(vektor_a, dim);

	printf("\nin Bezug auf den Vektor b:\n\n");
	ausgabe(vektor_b, dim);

	printf("\nergibt als parallele Komponente zu b:\n\n");
	parallel(vektor_a, vektor_b, vektor_parallel, dim, skalar);
	ausgabe(vektor_parallel, dim);

	printf("\nund als orthogonale Komponente zu b:\n\n");
	orthogonal(vektor_a, vektor_orthogonal, vektor_parallel, dim);
	ausgabe(vektor_orthogonal, dim);

	return 0;
}

// Beginn der weiteren Funktionen

void eingabe(float vektor[], int dim) {
	float a;
	int check = 0;

		for (int i = 0; i < dim; i++) {
			do {
			printf("Bitte geben Sie die %d.te Komponente ein:", i + 1); //Abfrage der 10 Indexe des Arrays
			check = scanf("%f", &a);
			flashStandardInput();
			if (check == 0)
				printf("Fehler!"); //Funktioniert noch nicht!
			else
				vektor[i] = a;
		} while (check == 0);
	}
}

//Ausgabe der einzelnen Komponenten
void ausgabe(float vektor[], int dim) {

	for (int r = 0; r < dim; r++) {
		printf("%.2f\n", vektor[r]);
	}
}

float skalarprodukt(float vektor_a[], float vektor_b[], int dim) {
	float skalar = 0;

	for (int i = 0; i < dim; i++) {
		skalar += vektor_a[i] * vektor_b[i];
	}

	return skalar;
}

void parallel(float vektor_a[], float vektor_b[], float vektor_p[], int dim, float skalar) {

	for (int i = 0; i < dim; i++) {
		vektor_p[i] = (skalar / skalarprodukt(vektor_b, vektor_b, dim)) * vektor_b[i];
	}
}

void orthogonal(float vektor_a[], float vektor_o[], float vektor_p[], int dim) {

	for (int i = 0; i < dim; i++) {
		vektor_o[i] = vektor_a[i] - vektor_p[i];
	}
}