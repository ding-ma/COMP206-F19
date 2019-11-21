#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <stdbool.h>

/*
 * Name: Ding Ma
 * ID: 260871301
 */
void show(FILE *f) {
    
    // crates a buffer for every kind of entry
    char buffer[100];
    char id[20];
    char name[60];
    char age[10];
    char gpa[10];
    int j = 0;
    int n = 0;
    int i = 0;
    
    while (fgets(buffer, 99, f)) { // gets line by line from the file into the buffer
        
        i = 0;
        if (buffer[0] != '\n') {
            n++;
            
            for (j = 0; buffer[i] != ','; i++) { // like in class, iterates on the buffer until sees comma
                if (buffer[i] != ' ') {
                    id[j] = buffer[i];
                    j++;
                }
            }
            id[j] = '\0'; //adds end of line character to the id (makes life easier after)
            i++; // skips comma
            
            //same thing as before, for name
            for (j = 0; buffer[i] != ','; i++) {
                if (buffer[i] != ' ') {
                    name[j] = buffer[i];
                    j++;
                }
            }
            name[j] = '\0';
            i++;
            
            //same thing as before for age
            for (j = 0; buffer[i] != ','; i++) {
                if (buffer[i] != ' ') {
                    age[j] = buffer[i];
                    j++;
                }
            }
            age[j] = '\0';
            i++;
            
            //iterate on the buffer until sees end of line character, because we know that gpa is the last entry
            for (j = 0; buffer[i] != '\0'; i++) {
                if (buffer[i] != ' ') {
                    gpa[j] = buffer[i];
                    j++;
                }
            }
            gpa[j] = '\0';
            
            // prints the content
            printf("Records %d:  ID= %s NAME=%s AGE=%s GPA=%s", n, id, name, age, gpa);
            
        }
    }
    printf("\n");
    fclose(f);
}

//appends the new entry into the database
void add(char *ID, char *name, char *age, char *GPA) {
    FILE *f = fopen("database.csv", "at");
    fprintf(f, "\n%s, %s, %s, %s", ID, name, age, GPA);
    fclose(f);
}


void delete(FILE *f, char *ID) {
    FILE *temp = fopen("database.tmp", "at"); //creates a temporary file
    
    //like before, we need to search for the id
    char buffer[100]; // buffer needs to be at 100 because we are loading the entire line in.
    char idToDelete[10];
    sprintf(idToDelete, "%s", ID);
    char id[10];
    int j = 0;
    int n = 0;
    int i = 0;
    bool isIDDeleted = false; //check if the id was found or not
    while (fgets(buffer, 100, f)) {
        
        //like before, we are finding the id in the buffer (line by line)
        n++;
        i = 0;
        for (j = 0; buffer[i] != ','; i++) {
            if (buffer[i] != ' ') {
                id[j] = buffer[i];
                j++;
            }
        }
        id[j] = '\0';
        
        //if the id does not match what the user entered, write it to temp file, else, skips and set idDeleted to true
        if (strcmp(id, idToDelete) != 0) {
            fputs(buffer, temp);
        } else {
            isIDDeleted = true;
        }
    }
    //if nothing was found, print the error message
    if (isIDDeleted == false) {
        printf("Name of record to delete is missing. \n");
    } else { //else, close both file and rename .temp file to the new .csv file
        fclose(f);
        fclose(temp);
        remove("database.csv");
        rename("database.tmp", "database.csv");
    }
    
}

//check if the command entered by the user exists
bool isNotCMDValid(char *cmd) {
    char *commands[] = {"SHOW", "DELETE", "ADD"};
    int len = sizeof(commands) / sizeof(commands[0]);
    for (int i = 0; i < len; ++i) {
        if (strcmp(commands[i], cmd) == 0) {
            return false; //if it exist, we can the skip the if condition
        }
    }
    return true; // else, print error
}

int main(int argc, char *argv[]) {
    // opens database file
    FILE *db = fopen("database.csv", "r");
    if (db == NULL) {
        printf("Problem reading the file \n");
        exit(1);
    }
    
    if (argc == 1) { // if argument is 1, error
        printf("You did not provide any arguments. Please enter: ./database CMD OPT1 OPT2 OPT3 OPT4\n");
        return 0;
        
    } else if (isNotCMDValid(argv[1])) { // if more than one, check if the command is valid
        printf("The command you requested is invalid. Please select from one of these: SHOW, DELETE, ADD\n");
    } else {
        if (strcmp(argv[1], "ADD") == 0) { // if it is add, check if there is at least 6 arguments
            if (argc < 6) {
                printf("Missing ID, Name, AGE, and GPA arguments\n");
            } else { // if yes, add the entries into the db
                char *ID = argv[2];
                char *GPA = argv[5];
                add(ID, argv[3], argv[4], GPA);
            }
        } else if (strcmp(argv[1], "DELETE") == 0) { // if cmd is delete, check if there are more than 3 arguments
            if (argc < 3) {
                printf("Name of record to delete is missing\n");
            } else { // if yes, get the id entered and check if it exists in the db.
                char *ID = argv[2];
                delete(db, ID);
            }
        } else if (strcmp(argv[1], "SHOW") == 0) { //show basically displays everything from the db
            show(db);
        }
    }
    return 0;
}