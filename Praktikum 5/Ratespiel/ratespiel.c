/****************************************************************
Aufgabe 5.1
Autor Maja Rother
Datum 12.12.2017
Kurzbeschreibung:/*
*****************************************************************/

// Präprozessordirektiven
#define _CRT_SECURE_NO_WARNINGS

// Header
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main(void)
{
	int small = 1;
	int big = 1000;
	int erg;
	int count = 1;
	int eingabe = 1;
	char x;
	char k = 'k';
	char h = 'h';
	char n = 'n';

	printf("Ratespiel\n---------\n\n");

	while (eingabe == 1) {
		while (1) {
			printf("%d. Versuch:\n--------\n\n", count);
			erg = (big - small) / 2 + small;
			printf("Ist die ausgedachte Zahl: %d?\n", erg);
			printf("Wenn nicht, ist die ausgedachte Zahl h%cher [h] oder niedriger [n]?\n\n", 148);
			printf("Eingabe: ");
			scanf("%s", &x);

			if (x == k) 
				printf("Spielende!\n-------\n\n");
			if (x == h)
				erg = (big - small) / 2 + small;
			if (x == n)
				erg = (big - small) / 2 + small;
		}
		count++;
	}

	printf("Möchten Sie eine weitere Runde spielen? Ja [1]; Nein [0]");
	printf("Eingabe:");
	scanf("%d", &eingabe);

	return 0;
}