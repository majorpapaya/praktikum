#include <stdio.h>

int main (void) 
{
   int i;

   printf ("dezimale Zahl angeben: ");
   scanf ("%d", &i); 

   printf ("dezimal %d in hexadezimaler Darstellung: 0x%x\n", i, i);
   printf ("dezimal %d in oktaler Darstellung      : 0%o\n", i, i);

   printf ("hexadezimale Zahl (ohne 0x) eingeben: ");
   scanf ("%x", &i); 

   printf ("hexadezimal 0x%x in dezimaler Darstellung: %d\n", i, i);
   printf ("hexadezimal 0x%x in oktaler Darstellung  : 0%o\n", i, i);

   printf ("oktale Zahl (ohne 0) eingeben: ");
   scanf ("%o", &i); 
   
   printf ("oktal 0%o in dezimaler Darstellung    : %d\n", i, i);
   printf ("oktal 0%o in hexadezimaler Darstellung: 0x%x\n", i, i);

   return 0;
}