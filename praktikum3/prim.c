/****************************************************************
Aufgabe
Autor Maja Rother
Datum 15.11.2017
Zusatz 3.1
Kurzbeschreibung: Primzahl! 
*****************************************************************/

#include <stdio.h>
#include <math.h>

int main (void)
{
    int x;
    
    printf ("Bitte geben Sie eine Primzahl ein:\n");
    scanf("%d", &x);

    if(x <= 1){
        printf("Das ist keine Primzahl/natürliche Zahl!\n"); // Aussortiere von allen Zahlen <1; FRAGE: Kann man Zeichen ausschließen?
        return 0;
    } 
    
    for(int count = 2; count < x; count++){                 //wichtig, count startet bei 2. Ansonsten alle durch 1 teilbar. und durch 0 nicht erlaubt.
        if(x % count == 0){
            printf("Die Zahl %d ist KEINE Primzahl.\n", x);
            return 0;
        }
    }

    printf("Es ist eine Primzahl\n");
    return 0; 
}

