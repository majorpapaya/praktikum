/****************************************************************
Aufgabe
Autor Maja Rother
Datum 12.11.2017
3.1
Kurzbeschreibung: Exponentialfunktion! 
*****************************************************************/

#include <stdio.h>
#include <math.h>

int fakultaet(int x) {
	if(x > 1) {
		return x * fakultaet(x-1);
	}else {
		return 1;
	}
}

int main(void)
{
    int x;
    float res = 0;
    float prev = 0.1;
    int count = 0;;

    printf("Bitte Zahl eingeben, die den Exponentialwert bestimmt:  \n");
    scanf("%d", &x);

    /*while(prev != res)*/
    for(; prev != res; count++){
        prev = res;
        res = res + (pow(x,count))/(fakultaet(count));

        printf("Res = %f\n", res);
        printf("Pre = %f\n", prev);

        // count++;
    }

    printf("Result hat den Wert: %f\n", res);
    printf("Die Anzahl der Summanden: %d\n", count);

    return 0;
}

