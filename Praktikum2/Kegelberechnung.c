/****************************************************************
Aufgabe
Autor Maja Rother
Datum 31.10.2017
2.1
Kurzbeschreibung: Wurzelberechnung! 
*****************************************************************/

#include <stdio.h>
#include <math.h>

float PI = 3.14159; // globale Variable

float volumen (float r, float h)
{
    return 1.0/3.0 *PI*r*r*h;
}

float oberflaeche (float r, float h) 
{
    float s = sqrt(r*r+h*h);

    return PI*r*r+PI*r*s;
}

int main(void)
{
    float r;
    float h;

    printf("Bitte geben Sie einen Radius ein: \n");
    scanf("%f", &r);

    printf("Bitte geben Sie eine Höhe ein: \n");
    scanf("%f", &h);

    printf("Radius\t\t\t%7.2f\n", r);
    printf("Höhe\t\t\t%7.2f\n", h);
    printf("Oberfläche\t\t%7.2f\n", oberflaeche(r, h));
    printf("Volumen\t\t\t%7.2f\n", volumen(r, h));

    return 0; 
}

/*
 * 1) write and save your program program.c
 * 2) go to terminal
 * 3) gcc program.c -o program.out
 * 4) ./program.out
 */