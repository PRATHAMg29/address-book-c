#include <stdio.h>  //include the header files
#include "contact.h"  //include user-defined header file
#include "animation.h"  //include user-defined header file
#define RED       "\033[31m"  //define a macro name for colors
#define RESET     "\033[0m"
#define GREEN     "\033[32m"
#define BBLUE     "\033[94m"
#define BCYAN     "\033[96m"
#define BMAGENTA  "\033[95m"
#define ORANGE    "\033[38;5;208m"
/* Structure declaration */

int main()
{
    /* Variable and structre defintion */
    int option;
    AddressBook addressbook;  //declare a variable.
    addressbook.contact_count = 0;  //initialize contact count with 0.
    int index[100];
    load_file_data(&addressbook);  //load the data from a .csv file
    if(addressbook.contact_count == 0)  //if there are no contacts then print no contacts available.
        printf("No contacts found.\n");
    while(1)
    {
        printf(BCYAN "\nAddress book menu" RESET "\n"); /* Give a prompt message for a user */
        printf("1.Add contact\n2.Search contact\n3.Edit contact\n4.Delete contact\n5.Display contact\n6.Save\n7.Save and exit\n");
        printf("--------------------\n");
        printf("Enter the option : ");
        if(scanf(" %d", &option) != 1);  //read i/p from the user and check if the opiton entered by user is an integer or not.
        {
            getchar();
        }
        printf("--------------------\n");
        switch (option)
        {
        case 1:
        {
            create_contact(&addressbook);  //if user chooses 1, then call create contact function.
            printf("--------------------\n");
            // printf("count is : %d\n",addressbook.contact_count);
            break;
        }
        case 2:
        {
            // printf("Search Contact menu : \n1.Name \n2.Mobile number\n3.Mail ID\n4. Exit\nEnter the option:"); /* Providing menu */
            search_contacts(&addressbook,index,1);  //if user chooses 2, then call search contact function.
            printf("--------------------\n");
            break;
        }
        case 3:
        {
            // printf("Edit Contact menu : \n1.Name \n2.Mobile number\n3.Mail ID\n4.Exit\nEnter the option : "); /* Providing menu */
            edit_contact(&addressbook);  //if user chooses 3, then call edit_contact function.
            printf("--------------------\n");
            break;
        }
        case 4:
        {
            // printf("Delete Contact menu : \n1.Name \n2.Mobile number\n3.Mail ID\n4.Exit\nEnter the option : "); /* Providing menu */
            delete_contact(&addressbook,index);  //if user chooses 4, then call delete_contact function.
            printf("--------------------\n");
            break;
        }
        case 5:
        {
            // printf("List Contacts:\n");
            if(addressbook.contact_count == 0)  //check if contact count is 0. if yes, then print and break.
            {
                printf("There are no contacts to display.\nCreate a contact to display.\n");
                printf("--------------------\n");
                break;
            }
            list_contacts(&addressbook);    //if user chooses 5 and above condition becomes false , then call list_contact function.
            printf("-----------------------------------------------------------------\n");
            break;
        }
        case 6:
        {
            save_contacts(&addressbook);  //if user chooses 6, then call save_contact function.
            loading_animation("Saving contacts.....");
            printf(GREEN "Contacts saved successfully." RESET "\n");  //print in green color
            printf("--------------------\n");
            break;
        }
        case 7:
        {
            save_contacts(&addressbook);  //if user chooses 7, then call save_contact function and exit from the program.
            loading_animation("Saving and exiting.....");
            return 0;
        }
        default:
        {
            printf(ORANGE "Invalid option. Please choose from the above options." RESET "\n");  //if user enters any other input then print invalid.
            printf("--------------------\n");
            break;
        }
        }
    }
}
