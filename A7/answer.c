#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
   // char *gold; //assumes 10 gold, otherwise it will be over written by the sscanf
    char *data = getenv("QUERY_STRING");
    int goldPieces;
    /*
    * Compile this way: gcc answer.c -o answer.cgi
    * make sure answer.c is in ~/public_html/cgi-bin
    */
    printf("Content-Type:text/html\n\n");
    printf("<html>");
    // sscanf(data,"answer=%s=gold=%s",input,gold);
    
    if (strstr(data, "gold") == NULL) {
        sscanf(data, "answer=%s", input);
        goldPieces =10;
        printf("<input type=\"hidden\" name\"gold\" value=\"10\">");
    } else {
        sscanf(data, "gold=%d&answer=%s",  &goldPieces,input);
    }
    
  //  goldPieces = atoi(gold);
    printf("<p>raw data: %s</p>", data);
    printf("<p>string input: %s</p>",input);
  //  printf("<p>%s</p>",gold);
    printf("<p>gold: %d</p>",goldPieces);
    
    if (strcmp(input, "NORTH") == 0) {
        printf("<head><title>North</title></head>");
        printf("<a href=\"https://www.cs.mcgill.ca/~ysavas/cgi-bin/addgold.cgi?gold=%d\">Press HERE to go North</a>",
               goldPieces);
    } else if (strcmp(input, "SOUTH") == 0) {
        printf("<head><title>South</title></head>");
        printf("<a href=\"https://www.cs.mcgill.ca/~imeado/cgi-bin/addgold.cgi?gold=%d\">Press HERE to go South</a>",
               goldPieces);
    } else if (strcmp(input, "EAST") == 0) {
        printf("<head><title>East</title></head>");
        printf("<a href=\"https://www.cs.mcgill.ca/~mgoodm10/cgi-bin/addgold.cgi?gold=%d\">Press HERE to go East</a>",
               goldPieces);
    } else if (strcmp(input, "WEST") == 0) {
        printf("<head><title>NWest</title></head>");
        printf("<a href=\"https://www.cs.mcgill.ca/~zgao20/cgi-bin/addgold.cgi?gold=%d\">Press HERE to go West</a>",
               goldPieces);
    } else if (strcmp(input, "GOLD") == 0) {
        printf("<p>You have %d gold </p>", goldPieces);
        printf("<a href=\"https://www.cs.mcgill.ca/~dma24/cgi-bin/addgold.cgi?gold=%d\">Go Back</a>", goldPieces);
    } else {
        if (strcmp(input, "HelloHi") == 0) {
            goldPieces+=10;
            if (goldPieces>= 100) {
                printf("<p>You Won the Game!!!</p>");
            } else {
                //add 10
                printf("<head><title>Good Answer</title></head>");
                printf("<p>You Win</p>");
                printf("<a href=\"https://www.cs.mcgill.ca/~dma24/cgi-bin/addgold.cgi?gold=%d\">Go Back</a>",
                       goldPieces);
            }
        } else {
            goldPieces-=5;
            if (goldPieces<= 0) {
                printf("<p>You Lost</p>");
                printf("<p>Ran out of pieces to play</p>");
            } else {    //substract 5
                printf("<head><title>Wrong Answer</title></head>");
                printf("<p>You Lost</p>");
                printf("<a href=\"https://www.cs.mcgill.ca/~dma24/cgi-bin/addgold.cgi?gold=%d\">Go Back</a>",
                       goldPieces);
            }
        }
    }
    
    printf("</html>");
    return 0;
}
