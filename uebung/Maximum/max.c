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

int maximumVonDrei(int a, int b, int c);
int maximumVonDrei_2(int a, int b, int c);
int maximumVonDrei_3(int a, int b, int c);

int main(void) {

	int a = 10, b = 3, c = 5;

	printf("Das Maximum ist %d\n", maximumVonDrei(a, b, c));
	printf("Das Maximum ist %d\n", maximumVonDrei_2(a, b, c));
	printf("Das Maximum ist %d\n", maximumVonDrei_3(a, b, c));

	return 0;
}

int maximumVonDrei(int a, int b, int c) {
	int max;

	if (a < b) {
		if (b < c) max = c;
		else max = b;
	}
	if (a > b) {
		if (a > c) max = a;
	}

	return max;
}

int maximumVonDrei_2(int a, int b, int c) {
	int max;

	if (a > b) max = a;
	else max = b;
	if (max < c) max = c;

	return max;
}

int maximumVonDrei_3(int a, int b, int c) {
	int max;

	if (a > b && a > c) max = a;
	else if (b > c) max = b;
	else max = c;

	return max;
}