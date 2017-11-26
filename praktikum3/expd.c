/****************************************************************
Aufgabe
Autor Maja Rother
Datum 12.11.2017
3.2
Kurzbeschreibung: Exponentialfunktion! 
*****************************************************************/

#include <stdio.h>
#include <math.h>

double fakultaet(int x) {
	if(x > 1) {
		return x * fakultaet(x-1);
	} else {
		return 1;
	}
}

int main(void)
{
    int x;
    double res = 0;
    double prev = 0.1;
    int count = 0;

    printf("Bitte Zahl eingeben, die den Exponentialwert bestimmt:  \n");
    scanf("%d", &x);

    for(; prev != res; count++){
        prev = res;
        res = res + (pow(x,count))/(fakultaet(count));

        if (prev == res) {
            break;
        }

        printf("Pre = %.20lf\n", prev);
        printf("Res = %.20lf\n", res);
        printf("\n\n");

    }

    printf("Result hat den Wert: %f\n", res);
    printf("Die Anzahl der Summanden: %d\n", count);

    return 0;
}

