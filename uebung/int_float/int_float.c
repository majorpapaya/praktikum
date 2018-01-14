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

	int a = 1, b = 2;
	float x = 4.2, y = 47.11;
	a = a - b; // a-b ist  Ausdruck  vom Typ int
	x = x*y; // x*y ist  Ausdruck  vom Typ  float
	b = x - a; // rechnet mit dem Float wird, gibt aber b als int raus- wie definiert!


	return 0;
}