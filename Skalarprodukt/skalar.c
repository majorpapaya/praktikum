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

double skalarprodukt(double * vektor1, double * vektor2, int dim);
double abstand(double * vektor1, double * vektor2, int dim);
void eingabe(double vektor[]);
void ausgabe(double *vektor);

void flashStandardInput(void)
{
	int intCharacter;
	while ((intCharacter = getchar()) != '\n' && intCharacter != EOF);
}

int main(void)
{
	double vektor_1[3];
	double vektor_2[3];
	int dim = 3;

	printf("\nBitte geben Sie den Vektor a ein, der zerlegt werden soll!\n");
	eingabe(vektor_1);
	printf("\nBitte geben Sie den Vektor b ein, der zerlegt werden soll!\n");
	eingabe(vektor_2);

	printf("\nVektor a:\n");
	ausgabe(vektor_1);
	printf("\nVektor b:\n");
	ausgabe(vektor_2);


	printf("Das Skalarprodukt ist %.2lf\n", skalarprodukt(&vektor_1, &vektor_2, dim));
	printf("\nDer Abstand zwischen den Punktet ist: %.2lf/\n", abstand(&vektor_1, &vektor_2, dim));

	return 0;
}


double abstand(double * vektor1, double * vektor2, int dim) {

	double abstand = 0;

	for (int i = 0; i < dim; i++) {

		abstand -= vektor1[i] * vektor2[i];
	}

	return abstand;
}

	double skalarprodukt(double * vektor1, double * vektor2, int dim) {

		double skalar = 0;

		for (int i = 0; i < dim; i++) {
			skalar += vektor1[i] * vektor2[i];
		}
		
		return skalar;
	}

	void ausgabe(double *vektor) {

		for (int r = 0; r < 3; r++) {
			printf("%.2f\n", vektor[r]);
		}
	}

	void eingabe(double vektor[]) {
		float a;
		int check = 0;

		for (int i = 0; i < 3; i++) {
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