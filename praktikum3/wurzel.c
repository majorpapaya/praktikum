/****************************************************************
Aufgabe
Autor Maja Rother
Datum 12.11.2017
3.1
Kurzbeschreibung: Wurzel! 
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
    int h;
    int i;

    printf("Bitte Zahl eingeben, deren Wurzel berechnet werden soll: \n");
        scanf("%d", &h);

    printf("Bitte Anzahl der gültigen Stellen hinter dem Komma eingeben!: \n");
        scanf("%d", &i);

    printf("Die Wurzel von %d ergibt %.*f \n", h, i ,sqrt(h) );

    return 0;
}

