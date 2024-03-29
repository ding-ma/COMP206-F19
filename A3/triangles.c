#include <stdio.h>
#include <math.h>
/*
 * Name: Ding Ma
 * ID: 260871301
 */


int main(int argc, char *argv[]) { // int argc, char *argv[]
    int intUsrEntry;
    int rowCounter, starCounter, spaceCounter; // initiation of variables
    float userEntry;
    if (argc == 1) { // if the number of command line argument is 1, prompt the user to enter a number
        printf("Please enter a number: \n");
        scanf("%f", &userEntry); // scans the entry into the address of variable size
    }
    if (argc == 2) { // if there are 2 arguments, take whatever number is on the command line
        sscanf(argv[1], "%f", &userEntry);
    }
    intUsrEntry = userEntry;
    if (argc > 2 || intUsrEntry <0 || intUsrEntry !=userEntry) { // if there are more than 2 arguments, return error msg and terminate program
        printf("An incorrect triangle size was inputted. The size must be greater than 0 and an integer number. Syntax: ./triangles SIZE \n");
        return -1;
    }

    for (rowCounter = 1; rowCounter <= intUsrEntry; ++rowCounter) { // outer loop to keep track of the number of rows (represented by the number of stars)

        for (spaceCounter = 0; spaceCounter < intUsrEntry - rowCounter; spaceCounter++) // inner loop to keep track of number of spaces to insert before
            printf(" ");

        for (starCounter = 1; starCounter <= rowCounter; ++starCounter) // inner loop to keep track of number of stars
            printf("*");

        printf("\n"); // once all are printed, print new line
    }
    return 0;
}