//
// Created by dingm on 2019-11-21.
// By Mairead Maloney 2019-11-23
#include <stdio.h>
#include <stdlib.h>
#include "linked.h"


struct ACCOUNT *head = NULL;


/**
 * takes a given account: if account balance does not equal the amount,
 * @param head: head of the list / the current node
 * @param account : account number, as an integer, used to identify accounts
 * @param amnt : transaction ammount from ssv file, used to update account balance
 */
void update(struct ACCOUNT *current, float amount){
    if(current->balance == amount){
        return;
    }
    else{
        current->balance += amount;
        return;
    }
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
 * goes through linked list starting at head, returns node containing the account number
 * @param head: head of the list / the current node
 * @param account : account number, as an integer, used to identify accounts
 * @param amount : transaction ammount from ssv file, used to update account balance
 * @return: returns a struct of type ACCOUNT, that will take the place at the head of the account list
 */
struct ACCOUNT* findNode(struct ACCOUNT *head, int account, float amount){
    // Base case
    if (head == NULL){
        return addNode(head, account, amount);

    }
    // If account number is present in current node, return that node
    if (head->accountNumber == account){
        return head;
    }

    // Recur for remaining list
    return findNode(head->next, account, amount);
}

 /**
 * finds a given node in the linked list of ACCOUNT structs,
 * updates it with new amount value using account
 * or creates it if it was not found
 * @param account : account number, as an integer, used to identify accounts
 * @param amount : transaction ammount from ssv file, used to update account balance
 */
void findUpdate(int account, float amount){
    struct ACCOUNT *node = (struct ACCOUNT *)malloc((sizeof(struct ACCOUNT)));
    node = findNode(head,account,amount);
    update(node, amount);
}


/**
 * prints the linked list of accounts
 * has format ACCOUNT ID: nnnnn BALANCE: $ nnnnnn.nn
 */
void prettyPrint(){
    struct ACCOUNT *temp = head;
    while(temp!= NULL){
        printf("ACCOUNT ID: %d BALANCE: $ %f \n", temp->accountNumber, temp->balance);
        temp = temp->next;

    }
    //
}
