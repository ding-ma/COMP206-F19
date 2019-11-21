//
// Created by dingm on 2019-11-21.
//

#ifndef COMP206_A6_LINKED_H
#define COMP206_A6_LINKED_H

struct ACCOUNT {
    int accountNumber;
    float balance;
    struct ACCOUNT *next;
};

void findUpdate(int account, float amount);
void prettyPrint();

#endif //COMP206_A6_LINKED_H
