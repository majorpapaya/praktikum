/**************************************************************************************
Autor: Ömer Yilmaz
Datum: 26.11.2017
Kurs: Programieren Praktikum 4 (Prof. Dr.-Ing. Sebastian Rohjans)
Aufgabe 4.1
**************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void array_ausgeben(int* pointer, int groesse) {						// Funktion, die ein Array printet
	for (int i = 0; i < groesse; i++) {
		printf("%d", pointer[i]);										// Läuft alle Werte des Array durch und printet es.	
	}
	printf("\n");
}

void verschieben_um_eins_vorne(int* pointer, int groesse) {				// Funktion, um die Zahlen im Array um 1 nach vorne zu verschieben
	int erste_zahl = 0;
	erste_zahl = pointer[0];										// Erste Zahl abspiechern, um es später dem letzten Wert zuweisen zu können
	for (int i = 0; i < groesse; i++) {
		if (i != 9) {
			pointer[i] = pointer[i + 1];								// der i'ten stelle vom Array den i+1'sten Wert zusweisen
		}
		else
		{
			pointer[i] = erste_zahl;									// bei i=9, also letzen Wert wird die erste Zahl zugewiesen
		}
	}
}

void verschieben_um_eins_hinten(int* pointer, int groesse) {			// Funktion, um die Zahlen im Array um 1 nach hinten zu verschieben
	int letzte_zahl = 0;
	letzte_zahl = pointer[9];
	for (int i = groesse - 1; i >= 0; i--) {								// ähnliche vorgehensweise wie bei verschieben_um_eins_vorne, nur verkertherum
		if (i != 0) {
			pointer[i] = pointer[i - 1];
		}
		else
		{
			pointer[i] = letzte_zahl;
		}
	}
}

void tausche(int* a, int* b) {															// Funktion, um 2 Werte in einem Array zu tauschen (mithilfe von Pointern)
	int zwischenspeicher1 = 0;
	int zwischenspeicher2 = 0;

	zwischenspeicher1 = *a;																// Werte von a und b im zwischenspiecher speichern
	zwischenspeicher2 = *b;

	*a = zwischenspeicher2;																// Werte getauscht wieder a und b zuweisen
	*b = zwischenspeicher1;
}

void tausche_unsortierte_zahlennachbarn(int* pointer, int groesse, int anzahl) {		// Funktion, um unsortierte Zahlennachbarn zu tauschen.
	for (int j = 1; j <= anzahl; j++) {													// for Schliefe, um es wiederholt durchzuführen, falls erwünscht ("anzahl")
		for (int i = 0; i < 9; i++) {
			if (pointer[i] > pointer[i + 1]) {											// wenn i'ite stelle größer als die i+1'ste stelle ist, werden die Werte ausgetauscht
				tausche(&pointer[i], &pointer[i + 1]);
			}
		}
	}
}

int main(void) {
	int array1[10] = { 0 };																// erstellen eines Array, mit der Länge/Größe: 10. Die erste Stelle mit 1 füllen, somit werden die restlichen 9 auch mit 0 gefüllt.
	int eingabe = 0;
	int * pointer_a = 0;
	int * pointer_b = 0;

	pointer_a = &array1[1];
	pointer_b = &array1[8];

	for (int i = 1; i <= 10; i++) {														// Eingabe 10 mal widerholen
		printf("Geben Sie die %d.te Zahl ein:", i);
		scanf("%d", &eingabe);
		array1[i - 1] = eingabe;
	}
	array_ausgeben(array1, 10);
	verschieben_um_eins_vorne(array1, 10);
	printf("Nach Vorne verschieben: \n");
	array_ausgeben(array1, 10);
	verschieben_um_eins_hinten(array1, 10);
	printf("Nach hinten verschieben: \n");
	array_ausgeben(array1, 10);
	tausche(pointer_a, pointer_b);
	printf("Tausche zweite und neunte Zahl: \n");
	array_ausgeben(array1, 10);
	tausche_unsortierte_zahlennachbarn(array1, 10, 1);
	printf("Tausche unsortierte Zahlennachbarn: \n");
	array_ausgeben(array1, 10);
	tausche_unsortierte_zahlennachbarn(array1, 10, 9);
	printf("Tausche 9mal unsortierte Zahlennachbarn: \n");
	array_ausgeben(array1, 10);

	return 0;
}