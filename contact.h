#ifndef CONTACT_H
#define CONTACT_H

typedef struct Contact_data  //structure to store contacts individually.
{
    char Name[50];  //store name of the contact.
    char Mobile_number[11];    //store mobile number of the contact.
    char Mail_ID[50];  //store mail id of the contact.
} Contacts;  //nickname for the structure.

typedef struct AddressBook_Data  
{
    Contacts contact_details[100];  //array to store multiple contacts.
    int contact_count;  //store total number of contact counts.
} AddressBook;

/* Function declarations */
// void init_intitalization(AddressBook *);
int create_contact(AddressBook *);
void list_contacts(AddressBook *);
int search_contacts(AddressBook *,int index[],int search_again);
int edit_contact(AddressBook *);
int delete_contact(AddressBook *,int index[]);
int save_contacts(AddressBook *);
int load_file_data(AddressBook *);
// int save_contacts(AddressBook *);

#endif // CONTACT_H
       // CONTACT_H