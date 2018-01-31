/****************************************************************
Aufgabe
Autor Maja Rother
Datum 21.11.2017
X.X
Kurzbeschreibung: Übung - Mathematische Formeln! 
*****************************************************************/

#include <stdio.h>
#include <math.h>

#define MAX 10

void flashStandardInput(void);
int teilen_for(int a, int b);
int teilen_while(int ersteZahl, int zweiteZahl);
int teilen_do_while(int ersteZahl, int zweiteZahl);
void ausgabe(int array[2][MAX], int anzahl);

int main(void)
{
    
    double a = 0.0, b = 0.0, wahl = 0, anzahlRechnung = 0;
    int check = 0, ergebnis = 0, anzahl = 0, versuche[2][MAX] = {0};

    do {
        printf("Wie viele Rechnungen möchten Sie durchführen?");
        check = scanf("%lf", &anzahlRechnung);
        flashStandardInput();
    } while(check == 0 || anzahlRechnung <= 0 || anzahlRechnung > MAX || anzahlRechnung != (int)anzahlRechnung);

    for (int i = 0; i < anzahlRechnung; i++) {
        do {
            printf("Geben Sie die erste Ganzzahl ein: \n");
            check = scanf("%lf", &a);
            flashStandardInput();
        } while (check == 0 || a <= 0 || a != (int)a);

        do { 
            printf("Geben Sie die zweite Ganzzahl ein: \n");
            check = scanf("%lf", &b);
            flashStandardInput();
        } while (check == 0 || b <= 0 || b !=(int)b);

        do {
            printf("Wie soll die Berechnung durchgeführt werden?\n[1=for; 2=while; 3=do while]");
            check = scanf("%lf", &wahl);
            flashStandardInput();
            
        } while (check == 0 || wahl <= 0 || wahl > 3 || wahl !=(int)wahl);

        switch ((int)wahl) {
        case 1: printf("\nDas Ergebnis lautet %i\n", ergebnis = teilen_for((int)a, (int)b));
            break;
        case 2: printf("\nDas Ergebnis lautet %i\n", ergebnis = teilen_while((int)a, (int)b));
            break;
        case 3: printf("\nDas Ergebnis lautet %i\n", ergebnis = teilen_do_while((int)a, (int)b));
            break;
        default: printf("Fehler!\n"); // Fall der eigentlich nie eintreffen dürfte!
            return -1;
        }
        versuche[0][i] = (int)wahl;
        versuche[1][i] = (int)ergebnis;
    }

    ausgabe(versuche, anzahlRechnung);

    return 0;
}

// Hilfsfunktion um den Eingabepuffer zu leeren
void flashStandardInput(void)
{
	int intCharacter;
	while ((intCharacter = getchar()) != '\n' && intCharacter != EOF);
}

int teilen_for(int ersteZahl, int zweiteZahl) {
    int anzahl;

    for (anzahl = 0; ersteZahl % zweiteZahl == 0; anzahl++)
       ersteZahl = ersteZahl / zweiteZahl;

    return anzahl;
}

int teilen_while(int ersteZahl, int zweiteZahl){
    int anzahl = 0;

    while (ersteZahl % zweiteZahl == 0){
        ersteZahl = ersteZahl / zweiteZahl;
        anzahl++;
    }
    return anzahl;
}

int teilen_do_while(int ersteZahl, int zweiteZahl){
    int anzahl = 0;

    if (ersteZahl % zweiteZahl == 0){
        do {
            ersteZahl = ersteZahl / zweiteZahl;
            anzahl++;
        } while (ersteZahl % zweiteZahl == 0);
    }
    else {
        return 0;
    }

    return anzahl;
}

void ausgabe(int array[2][MAX], int eintraege){
   
   printf("\n\n###############################\n\n");
   printf("Zusammenfassung der Rechnung:\n");
   for(int i = 0; i < 2; i++){
        for(int j = 0; j < eintraege; j++){
            printf("%5d", array[i][j]);
        }
        printf("\n");
    }

    printf("\n\n###############################\n");

}