/************************************
Datum:
Autor:
Version:
Kurzbeschreibung:

************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ist_schaltjahr(int jahr);
int anzahl_tage_im_monat(int monat, int jahr);
int kalenderJahr(jahr, erster);

int main(void) {

	int jahr = 0;
	int erster = 0;
	double mat[5][5];


	printf("Geben Sie ein Jahr ein : \n");
	scanf("%d", &jahr);

	printf("Welcher Tag ist der 1. Januar?\n ( 1 = Montag, 2 = Dienstag usw.) \n");
	scanf("%d", &erster);

	printf("Kalender\n\n");
	kalenderJahr(jahr, erster);


	return 0;
}

int anzahl_tage_im_monat(int monat, int jahr) {
	int tage = 0;
	switch (monat) {
	case 2: if (ist_schaltjahr(jahr)) tage = 29;
			else tage = 28;
			break;
	case 4:
	case 6:
	case 9:
	case 11: tage = 30;
		break;
	default: tage = 31;
	}
}

int ist_schaltjahr(int jahr) {
	return ((jahr % 4 == 0) && (jahr % 100 != 0)) || (jahr % 400 == 0);
}

int KalenderMonat(int anzahlTage, int erster, int tag) {

	//Spaltenbeschriftung
	printf(" Mo  Di  Mi  Do  Fr  Sa  So\n");
	printf("---------------------------\n");

	//Einrücken des ersten Kalendertags
	printf("%*s", (int)(4 * erster), "");

	//Ausgabe des Kalenders
	for (tag = 1; tag <= anzahlTage; tag = tag + 1) {
		printf("%4d", tag);
		if ((tag + erster) % 7 == 0)
			printf("\n");
	}
	printf("\n");

	return (tag + erster = 1) % 7;
}

int kalenderJahr(jahr, erster) {
	for (int i = 1; i <= 12; i++) {
		printf("Monat %d", i)
			KalenderMonat()
	}
}