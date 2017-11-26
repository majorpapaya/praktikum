#include <stdio.h>
#include <math.h>

void array_ausgeben(int *array, int groesse) {
     for(int i = 0; i < groesse; i++) {
        printf("%d ", array[i]);
     }
}

void array_vorne(int *array, int groesse) {
    
    int erstezahl = array[0];

    for(int i = 0; i < groesse; i++) {
        array[i] = array[i + 1];
    }

    array[groesse-1] = erstezahl;
}

int main(void)
{
    const int A = 10;
    int zahlen[A], i, x, c;

    for(i = 0; i < A; i++) {
        printf("Geben Sie die %d. Zahlen ein: ", i+1);
        scanf("%d", &x);
    
        zahlen[i] = x;
    }

    array_ausgeben(zahlen, A);
    array_vorne(zahlen, A);

    printf("\nNach vorne verschieben:\n");

    array_ausgeben(zahlen, A);

   return 0;
}