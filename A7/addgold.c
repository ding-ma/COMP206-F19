#include <stdio.h>
#include <stdlib.h>

/*
Ding Ma, 260871301
Mairead Maloney, 260867767
*/

int main() {
    //open HTML file
    FILE *fp = fopen("index.html", "r");
    char buffer[1000];
    
    int goldpieces;
    //get environment
    char *data = getenv("QUERY_STRING");
    printf("Content-Type:text/html\n\n");
    
    //get number of gold pieces passed in
    sscanf(data, "gold=%d", &goldpieces);
    
    if (fp == NULL) {
        perror("Error opening file");
        return (-1);
    }
    
    int formLineNumber = 12;
    int n = 1;
    //read in index.html file
    while (fgets(buffer, 999, fp)) {
        if (n != formLineNumber) {
	//print html file content to browser
            printf("%s", buffer);
        } else {
	//when at form in html, add in form action and gold input passed in from url to html content being printed to browser
            printf("<form action = \"https://www.cs.mcgill.ca/~dma24/cgi-bin/answer.cgi\" method = get>");
            printf("<input type=\"hidden\" name=\"gold\"value=\"%d\">", goldpieces);
        }
        n++;
    }
    
    return 0;
}
