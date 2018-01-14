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

int main(void) {

	int  teiler = 1;
	int  anzahl = 0;
	for (int zahl = 2; zahl <= 30; zahl++) {
		for (teiler = 1, anzahl = 0; teiler <= zahl; teiler++)
			if (zahl % teiler == 0)  anzahl++; // kein  Block
											   //  noetig
		printf(" Die Zahl %2d hat %2d Teiler\n", zahl, anzahl);
	}

	return 0;
}