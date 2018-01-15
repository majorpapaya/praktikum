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
float parallel(float vektor_a[], float vektor_b[], float skalar, int dim);
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
	float a[10];
	float b[10];
	float skalar;
	int dim;
	double dim_temp;
	float vektor_p[10];
	//int check; (check = 0 ||

	//Abfrage der Dimension
	do {
		printf("Bitte geben Sie die Dimension (<= 10) der Vektoren ein: ");
		scanf("%d", &dim_temp);
		flashStandardInput();
	} while (dim_temp <= 1 || dim_temp >= 10 || dim_temp != (int)dim_temp);
	dim = (int)dim_temp;

	// Abfrage der Werte
	printf("Bitte geben Sie den Vektor a ein, der zerlegt werden soll!\n");
	eingabe(a, dim);
	printf("Bitte geben Sie den Vektor b ein, der zerlegt werden soll!\n");
	eingabe(b, dim);

	// Skalarprodukt
	skalar = skalarprodukt(a, b, dim);
	printf("Das Skalarprodukt ist %.2f", skalar);

	//Orthogonale Zerlegung
	printf("Die orthogonale Zerlegung des Vektors a:\n\n");
	ausgabe(a, dim);

	printf("in Bezug auf den Vektor b:\n\n");
	printf("Vektor b:\n");
	ausgabe(b, dim);

	printf("ergibt als parallele Komponente zu b:\n\n");
	vektor_p[10] = parallel(a, b, skalar, dim);
	ausgabe(vektor_p, dim);

	printf("und als orthogonale Komponente zu b:\n\n");
	orthogonal();
	ausgabe()

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

float parallel(float vektor_a[], float vektor_b[], float skalar, int dim) {

	float a_b[10];

	for (int i = 0; i < dim; i++) {
		a_b[i] = (skalar / skalarprodukt(vektor_b, vektor_b, dim)) * vektor_b[i];
	}
	return a_b[10];
}

void orthogonal(float vektor_a[], float vektor_o[], float vektor_p[], int dim) {

	float a_o[10];

	for (int i = 0; i < dim; i++) {
		a_o[i] = vektor_a[i] - vektor_p[i];
	}

	return a_o[10];
}