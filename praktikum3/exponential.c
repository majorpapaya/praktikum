/****************************************************************
Aufgabe
Autor Maja Rother
Datum 12.11.2017
3.1
Kurzbeschreibung: Exponentialfunktion! 
*****************************************************************/

#include <stdio.h>
#include <math.h>

/*
float square( float r)
{
    return sqrt(h);
}
*/
int main(void)
{
    double h;


    printf("Bitte Zahl eingeben, die den Exponentialwert bestimmt:  \n");
        scanf("%lf", &h);

    int x = 1;
    int count = 0;
    float ex = 0;
    int nfakultaet = 1;
    int dx = 1;

    if (h > 10){
        printf("Die Zahl ist zu groß! Lass uns eher 10 nehmen.");
        h = 10;
    }

    while (dx < h) {

        ex = ex + dx;
        count++;
        nfakultaet = nfakultaet * count;
        dx = pow(x,count)/nfakultaet;
        // if count = 0, use 1.
        // if count = 1, use x
        // otherwise, x^count / numbers 1 - count

    }

    printf("%f\n", ex);

    

    return 0;
}