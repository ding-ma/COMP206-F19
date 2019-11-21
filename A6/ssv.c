//
// Created by dingm on 2019-11-21.
//
#include <stdio.h>
#include "ssv.h"

/**
 * parses line by line the ssv file
 * @param record : line of the ssv file
 * @param acct : account number, first entry of the ssv file
 * @param amnt : transaction amount, second entry of ssv file
 */
void parse(char record[], int *acct, float *amnt){
    /*
     * sscanf parses the record into the account and amnt variable
     * since they are pointer, it is a call by reference and it returns to main the account number and transaction amount
     */
    
    sscanf(record, "%d %f", acct , amnt);
}
