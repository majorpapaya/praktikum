/************************************
Datum: 06.01.
Autor: Maja Rother
Version: Zusatz 5.1
Kurzbeschreibung: Römische Zahlen

************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void flashStandardInput(void);
int tausender(int numbers);
int hunderter(int numbers);
int zehner(int numbers);
int einer(int numbers);

int main(void) {

	double number = 0.0;
	int num = 0;
	int check = 0;
	int temp;
	double eingabe = 1.0;

	while (eingabe == 1.0) {

		int pruef = 0;

		do {
			printf("Bitte geben Sie eine Ganzzahl zwischen 1-3000 ein: ");
			check = scanf("%lf", &number);
			flashStandardInput();
		} while (check == 0 || number < 1 || number > 3000 || number != (int)number);

		num = number;
		temp = num / 1000;
		tausender(temp);

		num = num % 1000;
		temp = num / 100;
		hunderter(temp);

		num = num % 100;
		temp = num / 10;
		zehner(temp);

		num = num % 10;
		temp = num / 1;
		einer(temp);

		eingabe = 0;

		do {
			printf("\nM%cchtest du noch einmal spielen? 1 = Ja, 0 = Nein\n", 148);
			pruef = scanf("%lf", &eingabe);
			flashStandardInput();
		} while (pruef == 0 || eingabe < 0 || eingabe > 1 || eingabe != (int)eingabe);
	}
	return 0;
}

void flashStandardInput(void)
{
	int intCharacter;
	while ((intCharacter = getchar()) != '\n' && intCharacter != EOF);
}

int tausender(int numbers) {
	//printf("%.2lf", temp);
	for (int i = 0; i < numbers; i++) {
		printf("M");
	}
	return 0;
}

int hunderter(int numbers) {
	switch (numbers) {
	case 1: printf("C");
		break;
	case 2: printf("CC");
		break;
	case 3: printf("CCC");
		break;
	case 4: printf("CD");
		break;
	case 5: printf("D");
		break;
	case 6: printf("DC");
		break;
	case 7: printf("DCC");
		break;
	case 8: printf("DCC");
		break;
	case 9: printf("DCCC");
		break;
	}
}

int zehner(int numbers) {
	if (numbers == 9) {
		printf("XC");
	}
	else if (numbers >= 5) {
		printf("L");
		for (int i = 0; i < numbers -5; i++) {
			printf("X");
		}
	}
	else if (numbers == 4) {
		printf("XL");
	}
	else {
		for (int i = 0; i < numbers; i++) printf("X");
	}
}

int einer(int numbers) {
	if (numbers <= 3) {
		for (int i = 0; i < numbers; i++) printf("I");
	}
	else if (numbers >= 5) {
		printf("V");
		for (int i = 0; i < numbers - 5; i++) {
			printf("I");
		}
	}
	else if (numbers == 4) printf("IV");
	else if (numbers == 9) printf("IX"); 
}