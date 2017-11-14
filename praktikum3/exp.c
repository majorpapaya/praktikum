/****************************************************************
Aufgabe
Autor Maja Rother
Datum 12.11.2017
3.1
Kurzbeschreibung: Exponentialfunktion! 
*****************************************************************/

#include <stdio.h>
#include <math.h>

/*int fakultaet(int x) {
	if(x > 1) {
		return x * fakultaet(x-1);
	}else {
		return 1;
	}
}*/

int main(void)
{
    int x;
    double res;
    /*double res = 0;*/

    printf("Bitte Zahl eingeben, die den Exponentialwert bestimmt:  \n");
    scanf("%d", &x);

    for(int count = 0; count <= 10; count++ ) {

        res = exp(x);
        /*res = res + (pow(x,count))/(fakultaet(count));*/

    }
    printf("%lf\n", res);
    /*printf("%lf\n", res);*/

    return 0;
}