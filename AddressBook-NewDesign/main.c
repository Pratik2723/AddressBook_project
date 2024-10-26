/*
Name : Pratik Jadhav
Date : 19/10/2024
Project Name : AddressBook
Batch : 24021G
Roll No : 24021_332
*/
#include <stdio.h>
#include "contact.h"         //user libreary file

int main() {
    int choice;            //declare a choice
    AddressBook addressBook;     // defined user variable 
    initialize(&addressBook); // Initialize the address book

   //to choose which function to select to run a upto exit
    do {
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {           //using switch to choice to select contact function
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                searchContact(&addressBook);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:
                // printf("Select sort criteria:\n");
                // printf("1. Sort by name\n");
                // printf("2. Sort by phone\n");
                // printf("3. Sort by email\n");
                // printf("Enter your choice: ");
                // int sortChoice;
                // scanf("%d", &sortChoice);
                listContacts(&addressBook);//, sortChoice);
                break;
            case 6:
                printf("Saving and Exiting...\n");
                //saveContactsToFile(&addressBook);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    
       return 0;
}
