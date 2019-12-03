#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("index.html", "r");
    char buffer[1000];
    
   // char gold[3];
    int goldpieces;
    char *data = getenv("QUERY_STRING");
    
    printf("Content-Type:text/html\n\n");
    
    printf("%s", data);
    sscanf(data, "gold=%d", &goldpieces);
 //   int goldpieces = atoi(gold);
    
    if (fp == NULL) {
        perror("Error opening file");
        return (-1);
    }
    
    int formLineNumber =12;
    int n =1;
    while (fgets(buffer, 999, fp)) {
        if(n != formLineNumber){
            printf("%s",buffer);
        } else{
            printf("<form action = \"https://www.cs.mcgill.ca/~dma24/cgi-bin/answer.cgi\" method = get>");
            printf("<input type=\"hidden\" name=\"gold\"value=\"%d\">", goldpieces);
        }
        n++;
    }

    return 0;
}
