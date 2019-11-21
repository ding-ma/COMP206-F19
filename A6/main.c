#include <stdio.h>
#include "ssv.h"
#include "linked.h"

int main(int argc, char *argv[]) {
    FILE *f = fopen("bankAccounts.ssv", "r");
    if(f == NULL){
        printf("File is invalid, try again");
        return 1;
    }
    int numbEntries = 0; // numbers of entries in file
    char record[100];
    int accountNo;
    float amount;
    while (fgets(record, 99, f)) {
        parse(record, &accountNo, &amount);
        findUpdate(accountNo,amount); //not a call by ref, not using pointer
        numbEntries++;
    }
    
    prettyPrint();
    return 0;
}