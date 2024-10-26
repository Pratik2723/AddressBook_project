#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100
//defined a struct variable in this sturct we can store name,phone and gmail
typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;
//defined a struct we can store nested struct contact and contactcount
typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

//defined user defined function
void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);//, int sortCriteria);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);

#endif
