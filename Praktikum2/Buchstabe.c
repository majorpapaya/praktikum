/****************************************************************
   Aufgabe
Autor Maja Rother
Datum 23.10.2017
2.1
Kurzbeschreibung: Buchstabe! *****************************************************************/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
char str;

printf("Enter a letter: ");                                                                                                                                                                
scanf("%c", str);  

printf(tolower(str));

return 0; 

}

/*
 * 1) write and save your program program.c
 * 2) go to terminal
 * 3) gcc program.c -o program.out
 * 4) terminal: ./program.out
 */