/****************************************************************
Aufgabe 6.1-6.3
Autor Maja Rother
Datum 19.12.2017
Kurzbeschreibung: Gleichungssysteme
*****************************************************************/

// Präprozessordirektiven
#define _CRT_SECURE_NO_WARNINGS

// Header
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

void flashStandardInput(void);
double determinante(double matrix[3][3], int dimension);
void inverse(double matrix2[3][3], int dimension2, double inv[3][3]);

int main(void) 
{
	int dim;
	double mat[3][3];
	double invmat[3][3];
	double b[3] = { 0 };
	double x[3] = { 0 };

	printf("Programm zur Berechnung der Determinante einer quadratischen Matrix.\n\n");
	printf("Bitte Dimension der Matrix eingeben (1,2 oder 3 Dimensionen)!");
	scanf("%d", &dim);

	for (int r = 0; r < dim; r++) {
		for (int s = 0; s < dim; s++) {
			printf("Bitte Elemente [%d][%d] eingeben!", r + 1, s + 1);
			scanf("%lf", &mat[r][s]);
			flashStandardInput();
		}
	}

	for (int r = 0; r < dim; r++) {
			printf("Bitte Elemente [%d] des inhomogenen Anteils eingeben!", r+1);
			scanf("%lf", &b[r]);
			flashStandardInput();
		}

	printf("\nDie Determinante der Matrix\n\n");
	for (int r = 0; r < dim; r++) {
		printf("|");
		for (int s = 0; s < dim; s++)
			printf("%6.2lf", mat[r][s]);
		printf("|\n");
	}
	double determ = determinante(mat, dim);

	inverse(mat, dim, invmat);

	if (determ == 0) {
		printf("\nist %.0lf. Die Matrix kann nicht invertiert werden.\n", determ);
	}
		else {
			printf("\nist %.2lf.\n\nDie Inverse der Matrix ist\n\n", determ);
				for (int r = 0; r < dim; r++) {
					printf("|");
						for (int s = 0; s < dim; s++)
							printf("%6.2lf", invmat[r][s]);
							printf("|\n");
		}
	}

	if (determ == 0) {
			printf("\nDas Gleichungssystem ist singul%cr und kann nicht eindeutig gel%cst werden!\n", 132, 148);
	}
	else {
		printf("\nDie L%csung des Gleichungssystems\n\n", 148);

		for (int r = 0; r < dim; r++) {
			printf("|");
			for (int s = 0; s < dim; s++) {
				printf("%6.2lf", mat[r][s]);
				printf("|");
			}
			printf("\tx%i %8.2lf\n", r + 1, b[r]);
		}
			printf("\n\nist\n\n");
				for (int r = 0; r < dim; r++) {
					for (int s = 0; s < dim; s++) {
						x[r] += invmat[r][s] * b[s];
					}
					printf("x%i = %.2lf\n", r + 1, x[r]);
				}
	}

	return 0;
}

double determinante(double matrix[3][3], int dimension)
{
	double det;

	switch (dimension) {
	case 1: det = matrix[0][0];
		break;
	case 2: det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
		break;
	case 3: det = matrix[0][0] * matrix[1][1] * matrix[2][2] +
		matrix[0][1] * matrix[1][2] * matrix[2][0] +
		matrix[0][2] * matrix[1][0] * matrix[2][1] -
		matrix[2][0] * matrix[1][1] * matrix[0][2] -
		matrix[2][1] * matrix[1][2] * matrix[0][0] -
		matrix[2][2] * matrix[1][0] * matrix[0][1];
		break;
	}
	return det;
}

void inverse(double matrix2[3][3], int dimension2, double inv[3][3]) 
{
	switch (dimension2) {
	case 1: inv[0][0] = 1.0f / determinante(matrix2,dimension2);
		break;
	case 2: inv[0][0] = +matrix2[1][1] / determinante(matrix2, dimension2);
		inv[0][1] = -matrix2[0][1] / determinante(matrix2, dimension2);
		inv[1][1] = +matrix2[0][0] / determinante(matrix2, dimension2);
		inv[1][0] = -matrix2[1][0] / determinante(matrix2, dimension2);
		break;
	case 3: inv[0][0] = +(matrix2[1][1] * matrix2[2][2] - matrix2[1][2] * matrix2[2][1]) / determinante(matrix2, dimension2);
		inv[0][1] = -(matrix2[0][1] * matrix2[2][2] - matrix2[2][1] * matrix2[0][2]) / determinante(matrix2, dimension2);
		inv[0][2] = +(matrix2[0][1] * matrix2[1][2] - matrix2[1][1] * matrix2[0][2]) / determinante(matrix2, dimension2);
		inv[1][0] = -(matrix2[1][0] * matrix2[2][2] - matrix2[1][2] * matrix2[2][0]) / determinante(matrix2, dimension2);
		inv[1][1] = +(matrix2[0][0] * matrix2[2][2] - matrix2[0][2] * matrix2[2][0]) / determinante(matrix2, dimension2);
		inv[1][2] = -(matrix2[0][0] * matrix2[1][2] - matrix2[1][0] * matrix2[0][2]) / determinante(matrix2, dimension2);
		inv[2][0] = +(matrix2[1][0] * matrix2[2][1] - matrix2[1][1] * matrix2[2][0]) / determinante(matrix2, dimension2);
		inv[2][1] = -(matrix2[0][0] * matrix2[2][1] - matrix2[0][1] * matrix2[2][0]) / determinante(matrix2, dimension2);
		inv[2][2] = +(matrix2[0][0] * matrix2[1][1] - matrix2[0][1] * matrix2[1][0]) / determinante(matrix2, dimension2);
		break;
	}
}

void flashStandardInput(void)
{
	int intCharacter;
	while ((intCharacter = getchar()) != '\n' && intCharacter != EOF);
}