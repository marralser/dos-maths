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
    cprintf("Welcome to the Dividing - Practice !\n");
    printf("\nFor each right answer you'll get a joke \nor learn a FunFact.\n\n");
    printf("\nHow many points would you like to achieve today (e.g. 10)? ");
    scanf("%d", &target);
    while (score < target ) {
	num1 = (rand() % (10 - 3 + 1)) + 3 ;
	num2 = (rand() % (10 - 3 + 1)) + 3;
	num3 = num1 * num2;
	printf("\n\nRound %d.\n\nWhat is %d divided by %d? ", round, num3, num2);
	round = round + 1;
	scanf("%d", &answer);

	if (answer == num1) {
	    textcolor(YELLOW);
	    score = score +1;
	    printf("\n");
	    cprintf("\nToll! Great job. You have now %d points.", score);
	    printf("\n");
	    cprintf("Here is your FunFact or joke : \n\n");
	    printf("\n");
	    displayRandomJoke(filename, totalJokes);
	} else {
	    textcolor(RED);
	    cprintf("\nOh no. This wasn't fully correct. The answer would have been %d.\n", num1);
	    textcolor(YELLOW);
	}

	printf("\n");
	cprintf("\nYou have now collected %d points. You lack %d points towards your goal.", score, target - score);
	fflush(stdin);

    };
    printf ("\n");
    textcolor(GREEN);
    cprintf("\nGoal Achieved. Thanks for practicing with me!.");
    printf("\n");
    cprintf("You have played %d rounds, and collected %d points.\n Well done and Bis bald! \n", round -1, score);

    return 0;
}
