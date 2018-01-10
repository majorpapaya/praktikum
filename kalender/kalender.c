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
//int kalenderJahr(jahr, erster);

int main(void) {

	int jahr = 0;
	int erster = 0;
	int anzahl_tage = 0;


	printf("Geben Sie ein Jahr ein : \n\n");
	scanf("%d", &jahr);

	printf("\nWelcher Tag ist der 1. Januar?\n( 1 = Montag, 2 = Dienstag usw.) \n\n");
	scanf("%d", &erster);

	printf("\nKalender\n");
	for (int i = 1; i <= 12; i++) {
		printf("\nMonat %d\n\n", i);
		
	anzahl_tage = anzahl_tage_im_monat(i, jahr);
	printf("Anzahl der Tag sind: %d\n\n", anzahl_tage);

	erster = KalenderMonat(anzahl_tage, erster);
	
	}
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
	return tage;
}

int ist_schaltjahr(int jahr) {
	return ((jahr % 4 == 0) && (jahr % 100 != 0)) || (jahr % 400 == 0);
}

int KalenderMonat(int anzahlTage, int erster) {

	long tag;
	//Spaltenbeschriftung
	printf("  Mo  Di  Mi  Do  Fr  Sa  So\n");
	printf("---------------------------\n");

	//Einrücken des ersten Kalendertags
	for (int i = 1; i < erster; i++) { //printf("%*s", 4 * erster, "");
		printf("    ");
	}
	//Ausgabe des Kalenders
	for (tag = 1; tag <= anzahlTage; tag = tag + 1) {
		printf("%4i", tag);
		if (erster > 6) {
			erster = 0;
			printf("\n");
		}
		erster++;
	}
	printf("\n");
	return erster;
}

/*int kalenderJahr(jahr, erster) {
	for (int i = 1; i <= 12; i++) {
		printf("Monat %d", i)
			KalenderMonat()
	}
}*/