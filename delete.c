#include<stdio.h>  //include the required header files.
#include<ctype.h>
#include<string.h>
#include "contact.h"
#include "animation.h"
#define RED       "\033[31m"  //define macros for colors.
#define RESET     "\033[0m"
#define GREEN     "\033[32m"
#define BBLUE     "\033[94m"
#define BCYAN     "\033[96m"
#define BMAGENTA  "\033[95m"
#define ORANGE    "\033[38;5;208m"
#define BROWN     "\033[38;5;94m"
#define SALMON    "\033[38;5;209m"
#define TEAL      "\033[38;5;37m"
#define LIME      "\033[38;5;118m"

//function prototypes.
int contact_delete(AddressBook *addressbook,int index[],int real);
int delete_contact(AddressBook *addressbook, int index[])  //function for deleting a contact.
{
    retry:  //label for goto.
    if(addressbook->contact_count == 0)  //check if address book is empty.
    {
        printf("There are no contacts to delete.\n");  //if yes, then inform the user and exit from the function.
        return 0;
    }
    printf(BMAGENTA "Search the contact you want to delete." RESET "\n");   //prompt the user to search the contact to delete.
    index[addressbook->contact_count];  //array to store indexes.
    int num = search_contacts(addressbook,index,0);  //call the search contacts function and return number of matches.
    if(num==0)  //check if no matching were found.if not, then exit from the function.
    {
        return 0;
    }
    again:  //label used for goto.
    printf(TEAL "Select the index you want to delete." RESET "\nEnter the option : ");  //ask user which matched contact to delete.
    int n;  //variable for user's option.
    if(scanf("%d",&n) != 1)  //check if input is integer
    {
        getchar();
    }
    printf("--------------------\n");
    if(n<1 || n>addressbook->contact_count)  //check if option entered is out of range. if yes, then print error message.
    {
        printf(ORANGE "Invalid input." RESET "\n");
        goto again;  //go back to the label.
    }
    int real=index[n-1];   //convert the displayed index into real contacts index.
    printf(LIME "Are you sure you want to delete this contact." RESET "\n");  //ask the user to confirm if he/she wants to delete this contact again.
    printf("1. YES\n2. NO\nEnter the option : ");  
    int choice;  //variable for option by user.
    if(scanf("%d",&choice) != 1)  //check if input is integer.
    {
        getchar();
    }
    printf("--------------------\n");
    if(choice == 1)  //if user confirms he/she wants to delete the contact, call the delete contact function.
    {
        contact_delete(addressbook,index,real);
        printf("Do you want to delete any other contact.\n");  //prompt user if he wants to delete any other contact.
        printf("1.YES\n2.NO\nEnter the option : ");
        int n;
        scanf("%d",&n);  //read the input from the user.
        if(n==1)  //if yes then go back to the label, else exit from function.
            goto retry;
    }
    else if(choice == 2)  //if user chooses NO, then go back to the label if user wants to delete any other contact.
    {
        goto retry;
    }
    else
    {
        return 0;
    }
}

int contact_delete(AddressBook *addressbook,int index[],int real)  //function to delete contact.
{
    for(int i=real;i<addressbook->contact_count-1;i++)  //run loop from the index of contact to be deleted upto 1 contact before. shifting property. overwrite the contact with the next contact.
    {
        strcpy(addressbook->contact_details[i].Name , addressbook->contact_details[i+1].Name); //copy next contact name into current position.
        strcpy(addressbook->contact_details[i].Mobile_number , addressbook->contact_details[i+1].Mobile_number); //copy next contact mobile number into current position.
        strcpy(addressbook->contact_details[i].Mail_ID , addressbook->contact_details[i+1].Mail_ID);  //copy next contact mail id into current position.
    }
    addressbook->contact_count--;  //reduce total count count after deleting.
    loading_animation("Deleting contacts.....");
    printf(GREEN "Contact deleted successfully." RESET "\n");   //display successfull deletion message in GREEN color.
}