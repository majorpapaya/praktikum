/****************************************************************
Aufgabe
Autor Maja Rother
Datum 21.11.2017
X.X
Kurzbeschreibung: Übung - Mathematische Formeln! 
*****************************************************************/

#include <stdio.h>
#include <math.h>

const double PI = 3.1415;

int main(void)
{

int x = 42;
double f;

// printf("Gib eine Zahl ein: \n");
// scanf("%d", &x);

f = 12.3 / (4.5*x + cos(34.0 * PI / 180.0)) + pow(3.0, -x) - 7.4e5;

printf("Die Lösung ist %.5lf\n", f);

    return 0;
}