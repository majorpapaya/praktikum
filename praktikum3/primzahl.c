/****************************************************************
Aufgabe
Autor Maja Rother
Datum 12.11.2017
3.1
Kurzbeschreibung: Primzahl! 
*****************************************************************/

#include <stdio.h>
#include <math.h>

int main (void)
{
    int lv1;
    int lv2;
    int teiler;
    printf ("Primzahlen:\n");
    for (lv1 = 2, teiler = 0;
        lv1 <= 101;
        lv1 ++, teiler = 0)

        // printf("1:%d\n", lv1);
    {
        for (lv2 = 2;
            lv2 * lv2 <= lv1 && teiler == 0;
            lv2++)
            // printf("1:%d, 2:%d\n", lv1, lv2);
    {
        if (lv1 % lv2 == 0)
            {
                printf("1:%d, 2:%d\n", lv1, lv2);
                teiler = 1;
            } 
        }
    if (teiler == 0)
    {
            printf ("%d",lv1);
            if (lv1 < 101)
            {
                printf (", ");
            }
        } 
    }
    return 0; 
}