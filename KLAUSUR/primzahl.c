/********************************************
2. Aufgabe Laborprüfung Programmieren 1
Name: [eintragen]
Matrikelnummer: [eintragen]
Datum: 04. Juli 2017
Dieses Programm prüft, ob es sich um einer
Zahl um eine Primzahl handelt. Anschließend
werden alle Primzahlen bis zur eingegebenen
Zahl ausgegeben. Dann werden die Primfaktoren
der eingegebenen Zahl ermittelt. Sie werden
dann einmal kanonisch mit und ohne
Exponentenschreibweise ausgegeben.
*********************************************/
// ########## Präprozessordirektiven ##########
#define _CRT_SECURE_NO_WARNINGS
// ########## Header ##########
#include<stdio.h>
#include<math.h>
// ########## Prototypen ##########
int pruefe_prim(int zahl);
void alle_prim(int zahl);
void prim_zerlegung(int zahl);
void prim_expo(int zahl);
void flashStandardInput(void);

// ########## Hauptfunktion ##########
int main(void) {
	
	double eingabe;
	int check;

	// Abfrage einer natürlichen Zahl
	do {
		check = 0;
		eingabe = 0;
		// a) wiederholung 1P, sichere eingabe 2P
		printf("Bitte geben Sie eine natuerliche Zahl ein: ");
		check = scanf("%lf", &eingabe);
		flashStandardInput();
		if ((eingabe < 1) || (eingabe - (int)eingabe != 0) || (check == 0))
			printf("Fehlerhafte Eingabe!\n");
	} while ((eingabe < 1) || (eingabe - (int)eingabe != 0) || (check ==0));

		// Funktionsaufruf zum Prüfen, ob es sich um eine Primzahl handelt inkl. entsprechender Ausgabe
		// b) sonderfälle (1, 2) 1P, ausgabe 1P, korrektheit 3P
		if (pruefe_prim((int)eingabe)) printf("Es handelt sich bei %d um EINE Primzahl.\n\n", (int)eingabe);
		else printf("\nEs handelt sich bei %d um KEINE Primzahl.\n\n", (int)eingabe);
	// Funktionsaufruf zur Berechnung und Ausgabe aller Primzahlen bis zu eingegebenen Zahl
		// c) sonderfälle (1, 2) 1P, ausgabe 1P, korrektheit 2P
		alle_prim((int)eingabe);
	// Funktionsaufruf zur Berechnung und Ausgabe aller Primfaktoren der eingegebenen Zahl
		// d) sonderfälle (1, 2) 1P, ausgabe 1P, korrektheit 3P
		prim_zerlegung((int)eingabe);
	// Funktionsaufruf zur Berechnung und Ausgabe in Exponentenschreibweise aller Primfaktoren der eingegebenen Zahl
		// e) sonderfälle (1, 2) 1P, ausgabe 1P, nur ^1 2P, alle 4P
		prim_expo((int)eingabe);

		return 0;
}
// ########## Weitere Funktionen ##########
// Funktion zur Prüfung auf Primzahl
int pruefe_prim(int zahl) {
	int n;
	if (zahl == 1) return 0;
	if (zahl == 2) return 1;

	for (n = (int)sqrt(zahl); n > 2; n--) {
		if (zahl%n == 0) return 0;
	}
	return 1;
}

// Funktion zur Ausgabe aller Primzahlen bis zu einer Zahl
void alle_prim(int zahl) {
	int i;
	printf("Folgende Primzahlen liegen zwischen 0 und %d: ", zahl);
	for (i = 1; i < zahl; i++) {
		if (pruefe_prim(i)) printf("%d ", i);
	}
	if (zahl < 3) printf("keine");
	printf("\n\n");
}

// Funktion zur Berechnung und Ausgabe aller Primfaktoren einer Zahl
void prim_zerlegung(int zahl) {
	int i;
	int tmp = zahl;
	printf("Folgende Zerlegung in Primfaktoren ergibt sich:");
	if (zahl == 1) {
		printf(" nicht moeglich\n\n");
		return;
	}
	for (i = 1; i <= zahl; i++) {
		if (pruefe_prim(i)) {
			if (zahl % i == 0) {
				printf(" %d *", i);
				zahl = zahl / i;
				i = 1;
			}
		}
	}
	printf("\b= %d\n\n", tmp);
}

// Funktion zur Berechnung und Ausgabe in Exponentenschreibweise aller Primfaktoren einer Zahl
void prim_expo(int zahl) {
	int faktoren[100] = { 0 };
	int i, j = 0, k, zaehler = 1;
	int tmp = zahl;
	printf("Folgende Zerlegung in Primfaktoren in Exponentenschreibweise ergibt sich : ");
		if (zahl == 1) {
			printf(" nicht moeglich\n\n");
			return;
		}
	for (i = 1; i <= zahl; i++) {
		if (pruefe_prim(i)) {
			if (zahl % i == 0) {
				faktoren[j] = i;
				j++;
				if (j == 99) {
					printf("Die Zerlegung ueberschreitet die maximale Anzahl(100) von Faktoren!");
						return;
				}
				zahl = zahl / i;
				i = 1;
			}
		}
	}
	for (k = 0; k < 99; k++) {
		if (faktoren[k] == faktoren[k + 1]) zaehler++;
		else {
			printf(" %d^%d *", faktoren[k], zaehler);
			zaehler = 1;
		}
	}
	printf("\b= %d\n\n", tmp);
}

// Funktion zur Leerung des Eingabepuffers
void flashStandardInput(void)
{
	int intCharacter;
	while ((intCharacter = getchar()) != '\n' && intCharacter != EOF);
}