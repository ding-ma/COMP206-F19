#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
Ding Ma, 260871301
Mairead Maloney, 260867767
*/

int main() {

    char input[100];
    //get environment
    char *data = getenv("QUERY_STRING");
    int goldPieces; //stores the number of goldPieces user has
    printf("Content-Type:text/html\n\n"); 
    printf("<html>");
    
    //if the number of gold pieces is not passed in in the url, set the number of gold pieces to 10 
    if (strstr(data, "gold") == NULL) {
        sscanf(data, "answer=%s", input);
        goldPieces = 10;
        printf("<input type=\"hidden\" name\"gold\" value=\"10\">");
    } else {
    //if number of gold pieces is specified, get and put into goldPieces variable
        sscanf(data, "gold=%d&answer=%s", &goldPieces, input);
    }
    
    /*
    * 
    * The following checks the input of the user. If input is NORTH, SOUTH, EAST or WEST, send user to another website, pass in goldPieces variable
    * If the input is GOLD, send the user to a new page that displays the number of gold pieces they have.
    * If the input is anything else, check if it is the answer to the question. 
    */
    	//NORTH
    if (strcmp(input, "NORTH") == 0) {
        printf("<head><title>North</title></head>");
        printf("<a href=\"https://www.cs.mcgill.ca/~ysavas/cgi-bin/addgold.cgi?gold=%d\">Press HERE to go North</a>",
               goldPieces);
	//SOUTH
    } else if (strcmp(input, "SOUTH") == 0) {
        printf("<head><title>South</title></head>");
        printf("<a href=\"https://www.cs.mcgill.ca/~imeado/cgi-bin/addgold.cgi?gold=%d\">Press HERE to go South</a>",
               goldPieces);
	//EAST
    } else if (strcmp(input, "EAST") == 0) {
        printf("<head><title>East</title></head>");
        printf("<a href=\"https://www.cs.mcgill.ca/~mgoodm10/cgi-bin/addgold.cgi?gold=%d\">Press HERE to go East</a>",
               goldPieces);
	//WEST
    } else if (strcmp(input, "WEST") == 0) {
        printf("<head><title>NWest</title></head>");
        printf("<a href=\"https://www.cs.mcgill.ca/~zgao20/cgi-bin/addgold.cgi?gold=%d\">Press HERE to go West</a>",
               goldPieces);
	
	//GOLD
    } else if (strcmp(input, "GOLD") == 0) {
        printf("<p>You have %d gold </p>", goldPieces);
        printf("<a href=\"https://www.cs.mcgill.ca/~dma24/cgi-bin/addgold.cgi?gold=%d\">Go Back</a>", goldPieces);
    
	//Check answer: if correct, add 10 gold pieces. if wrong, subtract 5
    } else {
        if (strcmp(input, "HelloHi") == 0) {
            goldPieces += 10;  //add 10
		//if number of gold pieces greater than 100, tell user they one the game. otherwise, tell user they answered correctly and display current number of gold pieces.
            if (goldPieces >= 100) {
                printf("<p>You Won the Game!!!</p>");
            } else {
                printf("<head><title>Good Answer</title></head>");
                printf("<p>You Win!</p>");
                printf("<p>You now have %d gold.</p>", goldPieces);
                printf("<a href=\"https://www.cs.mcgill.ca/~dma24/cgi-bin/addgold.cgi?gold=%d\">Go Back</a>",
                       goldPieces);
            }
        } else {
		//if number of gold pieces after subtraction smaller than 0, tell user they lost. otherwise give user current number of gold pieces
            goldPieces -= 5;  //subtract 5
            if (goldPieces <= 0) {
                printf("<p>You Lost</p>");
                printf("<p>Ran out of pieces to play</p>");
                printf("<a href=\"https://www.cs.mcgill.ca/~dma24\">Click here to restart</a>");
            } else {
                printf("<head><title>Wrong Answer</title></head>");
                printf("<p>You Lost</p>");
                printf("<p>You now have %d gold.</p>", goldPieces);
                printf("<a href=\"https://www.cs.mcgill.ca/~dma24/cgi-bin/addgold.cgi?gold=%d\">Go Back</a>",
                       goldPieces);
            }
        }
    }
    
    printf("</html>");
    return 0;
}
