// header files and user defined libreary files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

// function prototype
int valid_name(char *);
int valid_phone(char *str, AddressBook *addressBook);
int valid_email(char *str, AddressBook *addressBook);
void print_by_name(AddressBook *addressBook, char *str, int n);
void edit_by_name(AddressBook *addressBook, char *str, int n);
void delete_by_name(AddressBook *addressBook, char *str, int n);

// list contact function to print all contact list
void listContacts(AddressBook *addressBook) //, int sortCriteria)
{
    // Sort contacts based on the chosen criteria
    printf("%20s\t%20s\t%20s\n", "Name", "Phone no:", "Email");
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        printf("%20s\t%20s\t%20s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
}

// using initiliase we save the dummy conatct in addressbook
void initialize(AddressBook *addressBook)
{
    addressBook->contactCount = 0;

    populateAddressBook(addressBook);

    // Load contacts from file during initialization (After files)
    // loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook)
{
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS);              // Exit the program
}

// In create contact we save Name,phone number and gmail
void createContact(AddressBook *addressBook)
{
    /* Define the logic to create a Contacts */
    char name[50];
    char phone[50];
    char email[50];

    // Read a name and check the name is valid or not and run a loop upto valid name
    int flag = 1;
    printf("Enter a name : ");
    do
    {

        __fpurge(stdin);
        scanf("%[^\n]s", name);
        flag = valid_name(name); // check the  function  to name is a valid or not and run a upto valid name
        if (flag == 0)
        {
            printf("Reenter a valid name : ");
        }
    } while (flag != 1);
    strcpy(addressBook->contacts[addressBook->contactCount].name, name); // copy this name in addressbook

    printf("Enter a phone : "); // check the phone number is valid or not
    do
    {

        __fpurge(stdin);
        scanf("%[^\n]s", phone);
        flag = valid_phone(phone, addressBook); // function call to check phone number is valid or not
        if (flag == 0)
        {
            printf("Reenter a valid phone no. : ");
        }
    } while (flag != 1);
    strcpy(addressBook->contacts[addressBook->contactCount].phone, phone); // copy this phone number to addressbook

    printf("Enter a Email Id : "); // to run a loop upto valid gmail id
    do
    {

        __fpurge(stdin);
        scanf("%[^\n]s", email);
        flag = valid_email(email, addressBook); // function call to check mail is valid or not
        if (flag == 0)
        {
            printf("Reenter a valid email Id : ");
        }
    } while (flag != 1);
    strcpy(addressBook->contacts[addressBook->contactCount].email, email); // copy this mail to addressbook
    (addressBook->contactCount)++;
}

// In search contact we serach conatact name,phone or gmail wise
void searchContact(AddressBook *addressBook)
{
    /* Define the logic for search */
    printf("Select sort criteria:\n");
    printf("1. Search by name\n");
    printf("2. Search by phone\n");
    printf("3. Search by email\n");
    printf("Enter your choice: ");
    int sortChoice;
    scanf("%d", &sortChoice);
    char temp[25];
    __fpurge(stdin);

    // select a sortchoice  and defined function call to print conatct information
    switch (sortChoice)
    {
    case 1:
        printf("Search a Name wise contact : ");
        scanf("%[^\n]s", temp);
        print_by_name(addressBook, temp, sortChoice);
        break;
    case 2:
        printf("Search a Phone number : ");
        scanf("%[^\n]s", temp);
        print_by_name(addressBook, temp, sortChoice);
        break;
    case 3:
        printf("Search a Email address : ");
        scanf("%[^\n]s", temp);
        print_by_name(addressBook, temp, sortChoice);
        break;
    default:
        printf("Invalid choice");
        break;
    }
}
// in edit contact we modify contact as name or phone or gmail wise

void editContact(AddressBook *addressBook)
{
    /* Define the logic for Editcontact */
    printf("Select Edit criteria:\n");
    printf("1. Edit by name\n");
    printf("2. Edit by phone\n");
    printf("3. Edit by email\n");
    printf("Enter your choice: ");
    int sortChoice;
    scanf("%d", &sortChoice);
    char temp[25];
    __fpurge(stdin);
    // select sort choice and edit contact information
    switch (sortChoice)
    {
    case 1:
        printf("Edit a Name wise contact : ");
        scanf("%[^\n]s", temp);
        edit_by_name(addressBook, temp, sortChoice);
        break;
    case 2:
        printf("Edit a Phone number : ");
        scanf("%[^\n]s", temp);
        edit_by_name(addressBook, temp, sortChoice);
        break;
    case 3:
        printf("Edit a Email address : ");
        scanf("%[^\n]s", temp);
        edit_by_name(addressBook, temp, sortChoice);
        break;
    default:
        printf("Invalid choice");
        break;
    }
}

// in delete contact we can delete conatct information
void deleteContact(AddressBook *addressBook)
{
    /* Define the logic for deletecontact */
    printf("Select Delete criteria:\n");
    printf("1. Delete by name\n");
    printf("2. Delete by phone\n");
    printf("3. Delete by email\n");
    printf("Enter your choice: ");
    int sortChoice;
    scanf("%d", &sortChoice);
    char temp[25];
    __fpurge(stdin);
    // using switch we delete conatct name,numberor gmail wise
    switch (sortChoice)
    {
    case 1:
        printf("Delete a Name wise contact : ");
        scanf("%[^\n]s", temp);
        delete_by_name(addressBook, temp, sortChoice);
        break;
    case 2:
        printf("Delete a Phone number : ");
        scanf("%[^\n]s", temp);
        delete_by_name(addressBook, temp, sortChoice);
        break;
    case 3:
        printf("Delete a Email address : ");
        scanf("%[^\n]s", temp);
        delete_by_name(addressBook, temp, sortChoice);
        break;
    default:
        printf("Invalid choice");
        break;
    }
}
// function defination to check name is valid or not
int valid_name(char *str)
{
    int flag = 1;
    while (*str != '\0') // to run a loopupto null character
    {
        if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z') || *str == ' ') // to check the char is alphabet or space
        {
            str++;
            continue;
        }
        else
        {
            printf("Please Enter a charcter!\n");
            flag = 0;
            break;
        }
    }
    return flag;
}

// In valid phone we check the number is uniqe or 10 digit
int valid_phone(char *str, AddressBook *addressBook)
{
    int flag = 1, i = 0;
    if (strlen(str) == 10) // check the number is 10 digit
    {
        while (str[i] != '\0')
        {
            if (str[i] >= '0' && str[i] <= '9') // check the element is number
            {
                i++;
                continue;
            }
            else
            {
                printf("Please enter a number!\n");
                flag = 0;
                return flag;
            }
        }
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].phone, str))
            {
                continue;
            }
            else
            {
                printf("Please enter Phone number unique!\n");
                flag = 0;
                break;
            }
        }
    }
    else
    {
        printf("Please enter a 10 digit number!\n");
        flag = 0;
    }
    return flag;
}

int valid_email(char *str, AddressBook *addressBook)
{
    int flag = 1;
    char *str1 = ".com";
    char *ch = "@";
    char *at_ptr = strstr(str, ch);       // pointer to the first '@'
    char *dotcom_ptr = strstr(str, str1); // pointer to ".com"

    // Ensure both '@' and ".com" are present and '.com' is at the end
    if (at_ptr && dotcom_ptr && (dotcom_ptr == str + strlen(str) - 4))
    {
        // Check if the first character is '@'
        if (str[0] == '@')
        {
            return 0;
        }

        // Check the characters before '@' (only alphanumeric allowed)
        int i = 0;
        while (str[i] != '@')
        {
            if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9'))
            {
                i++;
            }
            else
            {
                return 0;
            }
        }

        // Check the characters between '@' and '.com' (only alphabets allowed)
        at_ptr++; // move past '@'
        while (at_ptr < dotcom_ptr)
        {
            if (*at_ptr < 'a' || *at_ptr > 'z')
            {
                return 0;
            }
            at_ptr++;
        }

        // Ensure the email is unique in the addressBook
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].email, str) == 0)
            {
                flag = 0; // email already exists
                break;
            }
        }
    }
    else
    {
        flag = 0; // '@' or ".com" is missing, or ".com" is not at the end
    }

    return flag;
}

// this is a function defination to print a conatct details name or phone number or gmail wise
void print_by_name(AddressBook *addressBook, char *str, int n)
{
    int flag = 1;
    if (n == 1)
    {
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].name, str) == 0)
            {
                flag = 0;
                printf("%20s\t%20s\t%20s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
            }
        }
        if (flag)
        {
            printf("\nContact cannot found\n");
        }
    }
    else if (n == 2)
    {
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].phone, str) == 0)
            {
                flag = 0;
                printf("%20s\t%20s\t%20s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
            }
        }
        if (flag)
        {
            printf("\nContact cannot found\n");
        }
    }
    else if (n == 3)
    {
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].email, str) == 0)
            {
                flag = 0;
                printf("%20s\t%20s\t%20s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
            }
        }
        if (flag)
        {
            printf("\nContact cannot found\n");
        }
    }
}
// In edit contact we can edit contact name ,phone number or gmail wise
void edit_by_name(AddressBook *addressBook, char *str, int n)
{
    int arr[10];
    int arr_size = 0;
    int flag = 1;
    if (n == 1)
    {
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].name, str) == 0)
            {
                flag = 0;
                arr[arr_size++] = i;
                printf("%d %20s\t%20s\t%20s\n", arr_size, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
            }
        }
        if (flag)
        {
            printf("\nContact cannot found\n");
            return;
        }
        if (arr_size > 1)
        {
            int index;
            printf("Enter a index and Edit name : ");
            scanf("%d", &index);
            if (index > arr_size)
            {
                printf("Invalid Choice");
            }
            else
            {
                char name[50];
                int flag = 1;
                printf("Enter a name : ");
                do
                {

                    __fpurge(stdin);
                    scanf("%[^\n]s", name);
                    flag = valid_name(name);
                    if (flag == 0)
                    {
                        printf("Reenter a valid name : ");
                    }
                } while (flag != 1);

                strcpy(addressBook->contacts[arr[index - 1]].name, name);
            }
        }
        else
        {
            char name[50];
            int flag = 1;
            printf("Enter a name : ");
            do
            {

                __fpurge(stdin);
                scanf("%[^\n]s", name);
                flag = valid_name(name);
                if (flag == 0)
                {
                    printf("Reenter a valid name : ");
                }
            } while (flag != 1);

            strcpy(addressBook->contacts[arr[arr_size - 1]].name, name);
        }
    }
    else if (n == 2)
    {
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].phone, str) == 0)
            {
                flag = 0;
                arr_size = i;
                printf("%20s\t%20s\t%20s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
            }
        }
        if (flag)
        {
            printf("\nContact cannot found\n");
            return;
        }

        char phone[50];
        // _fpurge(stdin);
        int flag = 1;
        printf("Enter a Phone No. : ");
        do
        {

            __fpurge(stdin);
            scanf("%[^\n]s", phone);
            flag = valid_phone(phone, addressBook);
            if (flag == 0)
            {
                printf("Reenter a valid Phone No. : ");
            }
        } while (flag != 1);
        strcpy(addressBook->contacts[arr_size].phone, phone);
    }
    else if (n == 3)
    {
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].email, str) == 0)
            {
                flag = 0;
                arr_size = i;
                printf("%20s\t%20s\t%20s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
            }
        }
        if (flag)
        {
            printf("\nContact cannot found\n");
            return;
        }

        char email[50];
        // _fpurge(stdin);
        printf("Enter a Email : ");

        int flag = 1;
        // printf("Enter a name : ");
        do
        {

            __fpurge(stdin);
            scanf("%[^\n]s", email);
            flag = valid_email(email, addressBook);
            if (flag == 0)
            {
                printf("Reenter a valid name : ");
            }
        } while (flag != 1);
        strcpy(addressBook->contacts[arr_size].email, email);
    }
}
// In delete conatct function defination we can delete contact using name or number or gmail wise
void delete_by_name(AddressBook *addressBook, char *str, int n)
{
    int arr[10];
    int arr_size = 0;
    int flag = 0;
    if (n == 1)
    {
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].name, str) == 0)
            {
                flag = 1;
                arr[arr_size++] = i;
                printf("%d %20s\t%20s\t%20s\n", arr_size, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
            }
        }

        if (flag)
        {

            if (arr_size > 1)
            {
                int index;
                printf("Enter a index and Delete name : ");
                scanf("%d", &index);
                if (arr_size < index)
                {
                    printf("Invalid choice");
                }
                else
                {
                    for (int i = arr[index - 1]; i < addressBook->contactCount - 1; i++)
                    {
                        addressBook->contacts[i] = addressBook->contacts[i + 1];
                    }
                    addressBook->contactCount--;
                }
            }
            else
            {
                for (int i = arr[arr_size - 1]; i < addressBook->contactCount - 1; i++)
                {
                    addressBook->contacts[i] = addressBook->contacts[i + 1];
                }
                addressBook->contactCount--;
            }
            
        }
        else
        {
            printf("\nContact is not found\n");
        }
    }
    else if (n == 2)
    {
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].phone, str) == 0)
            {
                flag = 1;
                arr_size = i;
                printf("%20s\t%20s\t%20s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
            }
        }

        if (flag)
        {

            for (int i = arr_size; i < addressBook->contactCount - 1; i++)
            {
                addressBook->contacts[i] = addressBook->contacts[i + 1];
            }
            addressBook->contactCount--;
        }
        else
        {
            printf("\nContact is not found\n");
        }
    }
    else if (n == 3)
    {
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].email, str) == 0)
            {
                flag = 1;
                arr_size = i;
                printf("%20s\t%20s\t%20s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
            }
        }

        if (flag)
        {

            for (int i = arr_size; i < addressBook->contactCount - 1; i++)
            {
                addressBook->contacts[i] = addressBook->contacts[i + 1];
            }
            addressBook->contactCount--;
        }
        else
        {
            printf("\nContact is not found\n");
        }
    }
}