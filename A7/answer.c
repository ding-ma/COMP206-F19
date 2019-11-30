#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    char *data = getenv("QUERY_STRING");
    /*
    * Compile this way: gcc answer.c -o answer.cgi
    * make sure answer.c is in ~/public_html/cgi-bin
    */
    printf("Content-Type:text/html\n\n");
    printf("<html>");
    
    sscanf(data, "answer=%s", input);
    
    if (strcmp(input, "NORTH") == 0) {
        printf("<head><title>North</title></head>");
        printf("<a href=\"https://www.cs.mcgill.ca/~ysavas/\">Press HERE to go North</a>");
    } else if (strcmp(input, "SOUTH") == 0) {
        printf("<head><title>North</title></head>");
        printf("<a href=\"https://www.cs.mcgill.ca/~imeado/\">Press HERE to go South</a>");
    } else if (strcmp(input, "EAST") == 0) {
        printf("<head><title>North</title></head>");
        printf("<a href=\"https://www.cs.mcgill.ca/~mgoodm10/\">Press HERE to go East</a>");
    } else if (strcmp(input, "WEST") == 0) {
        printf("<head><title>North</title></head>");
        printf("<a href=\"https://www.cs.mcgill.ca/~zgao20/\">Press HERE to go West</a>");
    } else if (strcmp(input, "GOLD") == 0) {
    //todo, check gold from URL
    } else {
        if (strcmp(input, "HelloHi") == 0) {
            printf("<head><title>Good Answer</title></head>");
            printf("<p>You Win</p>");
            printf("<a href=\"https://www.cs.mcgill.ca/~dma24/\">Go Back</a>");
        } else {
            printf("<head><title>Wrong Answer</title></head>");
            printf("You Lost");
        }
    }
    
    printf("</html>");
    return 0;
}
