#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100
 
 
typedef struct {
    char name[50]; 
    char phone[11];
    char email[50];
} Contact;
 
typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

void initialize(AddressBook *addressBook);
void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);
void saveAndExit(AddressBook *addressBook);
int name_validation(AddressBook *addressBook,char *name);
int phone_validation(AddressBook *addressBook,char *phone);
int mail_validation(AddressBook *addressBook,char *mail);
void whatsappContact(AddressBook *addressBook);

#endif
