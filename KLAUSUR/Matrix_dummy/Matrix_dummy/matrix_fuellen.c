/*
Beschreibung:	Programm zum Befüllen einer Zeichenmatrix
Autor:			[Namen eintragen]
Datum:			19. Januar 2017
*/

// Warnung bezüglich scanf() abschalten
#define _CRT_SECURE_NO_WARNINGS

// Einbinden benötigter Header
#include<stdio.h>
#include<stdlib.h>

// Prototypen
char abfrage(void);
void befuellen(char matrix[5][5], char a, char b, char c);
void ausgabe(char matrix[5][5]);

// Hilfsfunktion um den Eingabepuffer zu leeren
void flashStandardInput(void)
{
	int intCharacter;
	while ((intCharacter = getchar()) != '\n' && intCharacter != EOF);
}


// Beginn der Hauptfunktion

int main(void) {

	// lokale Variablen
	char a = 0, b = 0, c = 0;
	char matrix[5][5];

	// Abfrage
	a = abfrage();
	b = abfrage();
	c = abfrage();

	printf("A: %c, B: %c, C: %c\n", a, b, c);

	//befuellen(matrix, a, b, c);
	for (int r = 0; r < 5; r++) {
		matrix[r][r] = a;
	}

	for (int r = 0; r < 5; r++) {
		matrix[4 - r][r] = a;
	}

	for (int r = 0; r < 5; r++) {
		for (int s = 1; s < 4; s++) {
			matrix[r][s] = b;
		}
	}

	for (int r = 4; r < 5; r++) {
		for (int s = 1; s < 4; s++) {
			matrix[r][s] = b;
		}
	}

	for (int r = 1; r < 4; r++) {
		for (int s = 0; s < 4; s=+4) {
			matrix[r][s] = b;
		}
	}

	for (int r = 1; r < 4; r++) {
		for (int s = 1; s < 4; s++) {
			if (!(matrix[r][s] == a || matrix[r][s] == b))
				matrix[r][s] = c;
		}
	}
	//ausgabe(matrix);

	for (int r = 0; r < 5; r++) {
		printf("|");
		for (int s = 0; s < 5; s++)
			printf("%6.2c", matrix[r][s]);
		printf("|\n");
	}
	return 0;
}

// Implementieren der Prototypen
char abfrage(void) {

	char zeichen;
	// Abfrage
	printf("Bitte geben Sie ein Zeichen ein: ");
	// Befüllen
	scanf("%c", &zeichen);
	flashStandardInput();
	// Ausgabe
	return zeichen;
}

void befuellen(char matrix[5][5], char a, char b, char c) {

	for (int r = 0; r < 5; r++) {
		matrix[r][r] = a;
	}

	for (int r = 0; r < 5; r++) {
		matrix[4 - r][r] = a;
	}

	for (int r = 0; r < 5; r+4) {
		for (int s = 1; s < 4; s++) {
			matrix[r][s] = b;
		}
	}

	for (int r = 1; r < 4; r ++) {
		for (int s = 0; s < 5; s+4) {
			matrix[r][s] = b;
		}
	}

	for (int r = 1; r < 4; r++) {
		for (int s = 1; s < 4; s++) {
			if (!(matrix[r][s] == a || matrix[r][s] == b))
			matrix[r][s] = c;
		}
	}
}

void ausgabe(char matrix[5][5]) {
	
	for (int r = 0; r < 5; r++) {
		printf("|");
		for (int s = 0; s < 5; s++)
			printf("%6.2c", matrix[r][s]);
		printf("|\n");
	}
}