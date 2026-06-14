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
int check_valid_name(char *temp_name);
int check_valid_phone(AddressBook *addressbook, char *temp_phone);
int check_valid_email(AddressBook *addressbook, char *temp_email);

// int search_contacts(AddressBook *addressbook,int index[]);

int edit_name(AddressBook *addressbook,char *new_name,int real_index);
int edit_phone(AddressBook *addressbook,char *new_phone,int real_index);
int edit_email(AddressBook *addressbook,char *new_email, int real_index);


int edit_contact(AddressBook *addressbook)  //function to edit contact.
{
    retry:  //label for goto.
    int index[addressbook->contact_count];  //array to store indexes.
    if(addressbook->contact_count == 0)  //check if address book is empty.
    {
        printf("There are no contacts to edit.\n");  //if yes, then inform the user and exit from the function.
        return 0;
    }
    printf(BMAGENTA "Search the contact you want to edit." RESET "\n");  //prompt the user to search the contact to edit.
    int count = search_contacts(addressbook,index,0);  //call the search contacts function and return number of matches.
    if(count == 0)  //check if no matching were found.if not, then exit from the function.
    {
        return 0;
    }
    printf("--------------------\n");
    again:  //label used for goto.
    printf(TEAL "Select the contact which you want to edit." RESET "\nEnter the option : ");  //ask user which matched contact to edit.
    int num;  //variable for user's option.
    if(scanf("%d",&num) != 1)  //check if input is integer
    {
        getchar();
    }
    if(num<1 || num>addressbook->contact_count)  //check if option entered is out of range. if yes, then print error message.
    {
        printf(ORANGE "Invalid selection." RESET "\n");
        goto again;  //go back to the label.
    }
    printf("--------------------\n");
    int real_index = index[num - 1];  //convert the displayed index into real contacts index.
    invalid:  //label for goto.
    int choice;
    printf(LIME "Choose what to edit for the contact : " RESET "\n1.Name \n2.Mobile number\n3.Mail ID\n4.Exit\nEnter the option : ");  //display edit options menu.
    if(scanf("%d",&choice) != 1)  //check if input is integer or not.
    {
        getchar();
    }
    char new_name[50], new_phone[11],new_email[50];  //declare strings for new contacts.
    switch(choice)
    {
        case 1:
        {
            edit_name(addressbook,new_name,real_index);  //if user enters 1, call the edit name function.
            loading_animation("Editing contact name.....");
            printf("--------------------\n");
            printf(GREEN "Contact name edited successfully." RESET "\n");  //once done display that editing is successfull.
            printf("Do you want to edit any other contact.\n");  //prompt user if he wants to edit any other contact.
            printf("1.YES\n2.NO\nEnter the option : ");
            int n;
            scanf("%d",&n);  //read the input from the user.
            if(n==1)  //if yes then go back to the label else exit from function.
                goto retry;
            break;
        }
        case 2:
        {
            edit_phone(addressbook,new_phone,real_index);  //if user enters 2, call the edit phone function.
            loading_animation("Editing contact Mobile number.....");
            printf("--------------------\n");
            printf(GREEN "Contact Mobile number edited successfully." RESET "\n");  //once done display that editing is successfull.
            printf("Do you want to edit any other contact.\n");  //prompt user if he wants to edit any other contact.
            printf("1.YES\n2.NO\nEnter the option : ");
            int n;
            scanf("%d",&n);  //read the input from the user.
            if(n==1)  //if yes then go back to the label else exit from function.
                goto retry;
            break;
        }
        case 3:
        {
            edit_email(addressbook,new_email,real_index);  //if user enters 3, call the edit email function.
            loading_animation("Editing contact Mail ID.....");
            printf("--------------------\n");
            printf(GREEN "Contact Mail ID edited successfully." RESET "\n");  //once done display that editing is successfull.
            printf("Do you want to edit any other contact.\n");  //prompt user if he wants to edit any other contact.
            printf("1.YES\n2.NO\nEnter the option : ");
            int n;
            scanf("%d",&n);  //read the input from the user.
            if(n==1)  //if yes then go back to the label else exit from function.
                goto retry;
            break;
        }
        default:
        {
            printf(ORANGE "Invalid option. Choose from the above options." RESET "\n");  //if user enters any other character then print error message.
            printf("--------------------\n");
            goto invalid;  //go back to the label.
            break;
        }
    }
    return 0;
}


int edit_name(AddressBook *addressbook,char *new_name, int real_index)  //function to edit name.
{
        retry:  //label for goto
        printf("--------------------\n");
        printf("Enter a new name : ");  //prompt user to enter a new name.
        scanf(" %[^\n]",new_name);  //read the new name from user.
        if(!check_valid_name(new_name))  //call the function to check if name is valid or not.
        {
            goto retry;  //if not then go back to label.
        }
        strcpy(addressbook->contact_details[real_index].Name,new_name);  //if valid then copy the name to that particular index.
        return 0;
}

int edit_phone(AddressBook *addressbook,char *new_phone, int real_index)  //function to edit mobile number.
{
        retry:  //label for goto
        printf("--------------------\n");
        printf("Enter a new mobile number : ");  //prompt user to enter a new mobile number.
        scanf(" %[^\n]",new_phone);  //read the new mobile number from user.
        if(!check_valid_phone(addressbook,new_phone))  //call the function to check if mobile number is valid or not.
        {
            goto retry;  //if not then go back to label.
        }
        strcpy(addressbook->contact_details[real_index].Mobile_number,new_phone);  //if valid then copy the mobile number to that particular index.
        return 0;
}

int edit_email(AddressBook *addressbook,char *new_email, int real_index)  //function to edit mail id.
{
        retry:  //label for goto
        printf("--------------------\n");
        printf("Enter a new email ID : ");  //prompt user to enter a new mail id.
        scanf(" %[^\n]",new_email);  //read the new mail id from user.
        if(!check_valid_email(addressbook,new_email))  //call the function to check if mail id is valid or not.
        {
            goto retry;  //if not then go back to label.
        }
        strcpy(addressbook->contact_details[real_index].Mail_ID,new_email);  //if valid then copy the mail id to that particular index.
        return 0;
}
