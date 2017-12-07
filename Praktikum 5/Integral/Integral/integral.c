/************************************
Datum:
Autor: Maja Rother
Version:
Kurzbeschreibung: Integral

************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x) { //Gegebene Funktion
	return 4 - x*x;
}

//Teilaufgabe a
double flaeche(double von, double bis) {
	double zeta = ((bis - von) / 2)+ von;	//Bestimmung von zeta
	double b = (bis - von); //Bestimmung der Breite b
	return f(zeta) * b; //Bestimmung der Fläche
}

//Teilaufgabe b
double integral(double von, double bis, int anzahl) {
	double breite = (bis - von) / anzahl;
	double erg = 0;
	double zbis = von + breite;
	double zvon = von;

	for (int i = 1; i <= anzahl; i++) {
		double z = ((zbis - zvon) / 2) + zvon;
		erg = erg + (f(z) * breite);
		zvon = zbis;
		zbis = zvon + breite;
	}
	return erg;
}

//Teilaufgabe c
double integral_trapez(double von, double bis, int n) {
	if (n == 0) {
		return 0;
	}
	else {
		double h = (bis - von) / n;
		double zwischenwert = 0;
		//double I;

		for (int k = 1; k <= n - 1; k++) {
			zwischenwert = zwischenwert + f(von + k*h);
		}
		return h / 2 * (f(von) + f(bis) + 2 * zwischenwert);
	}
}

int main(void) {

	double a = 0.0;
	double b = 1.0;
	double c = 5.0;
	int anz = 5;
	double flae;
	double inte;
	double trapez;

	// Teilaufgabe a
	flae = flaeche(a, b);
	printf("Die Fl%cche eines Rechtecks betr%cgt: %.2lf\n\n", 132, 132, flae);

	inte = integral(a, c, anz);
	printf("Das Integral von dem Intervall %.2lf und %.2lf ist: %.2lf\n\n", a,c, inte);

	trapez = integral_trapez(a, c, anz);
	printf("Das Integral nach der Trapezformel hat den Wert: %.2lf\n\n", trapez);

	return 0;
}