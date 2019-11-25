//
// Created by dingm on 2019-11-21.
// By Mairead Maloney 2019-11-23
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked.h"


struct ACCOUNT *head = NULL;


/**
 * check if the account is in the linked list
 * if it is, update the amount and return true
 * else, return false
 * @param account : account number
 * @param amount : amount to be updated
 * @return : true if the account is in the list, false otherwise
 */
bool isAccountInList(int account, float amount) {
    struct ACCOUNT *temp;
    temp = head;
    bool isAccountUpdated = false;
    while (temp != NULL) {
        //while traversing the linked list, if the node matches the account number, update it with the amount
        if (temp->accountNumber == account) {
            temp->balance += amount;
            isAccountUpdated = true;
        }
        temp = temp->next;
    }
    return isAccountUpdated;
}

/**
 * adds a new account to the head of the account linked list
 * @param head: head of the list / the current node
 * @param account : account number, as an integer, used to identify accounts
 * @param amount : transaction ammount from ssv file, used to update account balance
 */     
struct ACCOUNT* addNode(struct ACCOUNT *head, int account, float amount){
    struct ACCOUNT *temp = (struct ACCOUNT *)malloc((sizeof(struct ACCOUNT)));
    if (temp == NULL){
        return NULL;
    }

    temp->accountNumber = account;
    temp->balance = amount;

    //first node in the list
    if(head == NULL){
        temp->next = NULL;
    }

    //set the next pointer of temp to head, temp becomes head
    else{
        temp->next = head;
    }

    //return temp as new head of the list
    return temp;
}

 /**
 * finds a given node in the linked list of ACCOUNT structs,
 * updates it with new amount value using account
 * or creates it if it was not found
 * @param account : account number, as an integer, used to identify accounts
 * @param amount : transaction ammount from ssv file, used to update account balance
 */
void findUpdate(int account, float amount){
    if (!isAccountInList(account, amount)) {
        head = addNode(head, account, amount);
    }
}


/**
 * prints the linked list of accounts
 * has format ACCOUNT ID: nnnnn BALANCE: $ nnnnnn.nn
 */
void prettyPrint(){
    struct ACCOUNT *temp = head;
    while(temp!= NULL){
        printf("ACCOUNT ID: %-3d BALANCE: $ %f \n", temp->accountNumber, temp->balance);
        temp = temp->next;

    }
}
