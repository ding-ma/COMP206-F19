#include <stdio.h>
#include <string.h>

// function that returns reversed word
char *reverseStr(char *str) {
    int len = strlen(str);
    int i = 0;
    while (len > i) { //simple swap function
        char tmp = str[--len];
        str[len] = str[i];
        str[i++] = tmp;
    }
    return str;
}

int main(int argc, char *argv[]) {
    
    if (argc != 3) { // if there are more than 2 arguments, return error msg and terminate program
        printf("Wrong number of arguments. Please input: ./reverse WORD1 WORD2. \n");
        return 1;
    }
    
    char firstWord[100];
    char *pFirstW = firstWord;
    sscanf(argv[1], "%s", firstWord);
    
    char secondWord[100];
    char *pSecondW = secondWord;
    sscanf(argv[2], "%s", secondWord);
    
    int lenStr1 = strlen(firstWord);
    int lenStr2 = strlen(secondWord);
    reverseStr(pFirstW);
    
    for (int i = 0; i < lenStr1; i++) {
        if (pFirstW[i] != pSecondW[i] || lenStr1 != lenStr2) {
            printf("WORD1=%s WORD2=%s - NOT REVERSE", reverseStr(pFirstW), secondWord);
            break;
        }
        if (i + 1 == lenStr1) {
            printf("WORD1=%s WORD2=%s - REVERSE", reverseStr(pFirstW), secondWord);
        }
    }
    
}


