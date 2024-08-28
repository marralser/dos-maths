#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define MAX_JOKE_LENGTH 255
#define MAX_JOKES 100

int countJokes(char *filename) {
    FILE *file;
    int count = 0;
    char line[MAX_JOKE_LENGTH];

    if ((file = fopen(filename, "r")) == NULL) {
        printf("Could not open jokes file.\n");
        return 0;
    }

    while (fgets(line, MAX_JOKE_LENGTH, file) != NULL) {
	if (line[0] != '\n') {
            count++;
        }
    }

    fclose(file);
    return count;
}

void displayRandomJoke(char *filename, int totalJokes) {
    FILE *file;
    int jokeNum, currentLine = 0;
    char line[MAX_JOKE_LENGTH];

    if ((file = fopen(filename, "r")) == NULL) {
        printf("Could not open jokes file.\n");
        return;
    }

    jokeNum = rand() % totalJokes + 1;

    while (fgets(line, MAX_JOKE_LENGTH, file) != NULL) {
        currentLine++;
        if (currentLine == jokeNum) {
            printf("%s", line);
            break;
        }
    }

    fclose(file);
}

int main() {
    int num1, num2, num3, answer, totalJokes, score = 0, round  = 1, target = 10;
    char again = 'n';
    char filename[] = "jokes.txt";

    srand((unsigned)time(NULL));

    totalJokes = countJokes(filename);
    if (totalJokes == 0) {
        printf("No jokes found. Please check the jokes.txt file.\n");
	return 1;
    }

    clrscr();
    textcolor(YELLOW);
    cprintf("Willkommen zum Dividieren - Quiz !\n");
    printf("\nFÅr jede richtige Antwort sag ich dir einen Witz \noder einen FunFact.\n\n");
    printf("\nWie viele Punkte moechtest du erreichen (Vorschlag: 10)? ");
    scanf("%d", &target);
    while (score < target ) {
	num1 = (rand() % (10 - 2 + 1)) + 2 ;
	num2 = (rand() % (10 - 2 + 1)) + 2;
	num3 = num1 * num2;
	printf("\n\nRunde %d.\n\nWas ergibt %d geteilt durch %d? ", round, num3, num2);
	round = round + 1;
	scanf("%d", &answer);

	if (answer == num1) {
	    textcolor(YELLOW);
	    score = score +1;
	    printf("\n");
	    cprintf("\nToll! Great job. Deine Punktezahl ist nun %d.", score);
	    printf("\n");
	    cprintf("Dafuer gibts nun einen FunFact oder Witz : \n\n");
	    printf("\n");
	    displayRandomJoke(filename, totalJokes);
	} else {
	    textcolor(RED);
	    cprintf("\nOh nein. Das war nicht ganz richtig. Eigentlich ist die Antwort %d.\n", num1);
	    textcolor(YELLOW);
	}

	printf("\n");
	cprintf("\nDu hast jetzt %d Punkte gesammelt. Dir fehlen noch %d Punkte.", score, target - score);
	fflush(stdin);

    };
    printf ("\n");
    textcolor(GREEN);
    cprintf("\nDanke fuers öben.");
    printf("\n");
    cprintf("Du hast insgesamt %d Runden gespielt, und davon %d Punkte gesammelt.\n Bis bald! \n", round -1, score);

    return 0;
}
