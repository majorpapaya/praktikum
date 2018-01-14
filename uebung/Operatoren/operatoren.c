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

	int x, y, z;
	float z1, z2;
	x = 42 / 8; /* x hat  dann  den  Wert 5          */
	y = 47 / 8; /* x hat  dann  den  Wert 5          */
				/* Es wird  also  nicht  gerundet! */
	z1 = 42.0 / 8; /* z1 hat  den  Wert  5.25           */
	z2 = 42 / 8; /* z2 hat  den  Wert  5.00           */
	//y = 42 / 0; /*  Laufzeitfehler!                 */

	z = y-- - x;
	printf("x=%d y=%d z=%d\n", x, y, z);

	int a = 3, b = 2, c = 1;
	z = a == (b = c);
	printf("z=%d a=%d b=%d c=%d \n", z, a, b, c);
	z = a == (b = 3);
	printf("z=%d a=%d b=%d c=%d \n", z, a, b, c);

	return 0;
}