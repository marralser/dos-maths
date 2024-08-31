#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main(){
	int choice;

	clrscr();
	while (1){
	textcolor(YELLOW);
	cprintf("Eelementary Math Training for Young Schoolkids \n\n");
	printf("\n");
	cprintf("What would you like to practice?\n\n");
	printf("\n");
	printf ("1. Additions / Plus - Rechnen\n");
	printf ("2. Subtractions / Minus - Rechnen\n");
	printf ("3. Multiplication / Multiplizieren\n");
	printf ("4. Division / Dividieren\n\n");
	printf ("5. Enough for today, Genug geuebt?\n");
	cprintf ("\nPlease choose / Bitte waehle? ");
	scanf ("%d",&choice);

	switch (choice) {
	case 1:
	system ("addjo.exe");
	break;
	case 2:
	system ("subjo.exe");
	break;
	case 3:
	system ("multijo.exe");
	break;
	case 4:
	system ("divjo.exe");
	break;
	case 5:
	printf ("Vielen Dank fuers ueben, Good Bye!\n");
	exit (0);
	default:
	printf ("Try again / Versuchs nochmal :-)\n");
	}
 printf ("\n Press the ANY Key :-)");
 getch();
 clrscr();
 }
 }

