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

int main(void)
{
	double vektor_1[3];
	double vektor_2[3];
	double temp;

	for (int r = 0; r < 2; r++) {
		for (int s = 0; s < 3; s++) {
			printf("Bitte das [%d.] Element für den [%d.] Vektor eingeben!", s + 1, r + 1);
			scanf("%lf", &temp);
			flashStandardInput();
			if (r == 0) {
				vektor_1[s] = temp;
			}
			else vektor_2[s] = temp;
	}

		printf("Das Skalarprodukt ist %lf\n", skalarprodukt(&vektor_1, &vektor_1, 3))

	return 0;
}

	double skalarprodukt(double * vektor1, double * vektor2, int dim) {

	}