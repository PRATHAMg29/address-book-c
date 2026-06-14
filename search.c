#include<stdio.h>  //include required header files.
#include<ctype.h>
#include<string.h>
#include<strings.h>
#include "contact.h"
#include "animation.h"
#define RED       "\033[31m"  //define macros for colors.
#define RESET     "\033[0m"
#define GREEN     "\033[32m"
#define BBLUE     "\033[94m"
#define BCYAN     "\033[96m"
#define BMAGENTA  "\033[95m"
#define ORANGE    "\033[38;5;208m"
#define BGSKYBLUE "\033[48;5;117m"

//function prototypes.
int search_name(AddressBook *addressbook,int index[]);
int search_phone(AddressBook *addressbook,int index[]);
int search_email(AddressBook *addressbook,int index[]);

int search_contacts(AddressBook *addressbook,int index[],int search_again)  //function to search contacts.
{
    again:  //label for goto
    int num;
    if(addressbook->contact_count == 0)  //check if there any contacts present. if not, then print error message and exit from function.
    {
        printf("There are no contacts to search.\n");
        return 0;
    }
    printf(BBLUE "Search Contact menu : " RESET "\n1.Name \n2.Mobile number\n3.Mail ID\n4.Exit\n");  //display the menu to the user for what they want to search.
    printf("--------------------\n");
    printf("Enter the option : ");
    if(scanf(" %d",&num) != 1)  //read integer input from the user.
    {
        getchar();
    }
    printf("--------------------\n");
    if(num == 1)  
    {
        search_name(addressbook,index);  //if user enters 1, call the function to search the name.
    }
    else if(num == 2) 
    {
        search_phone(addressbook,index);  //if user enters 1, call the function to search the name.
    }
    else if(num == 3)
    {
        search_email(addressbook,index);  //if user enters 1, call the function to search the name.
    }
    else if(num == 4)
    {
        return 0;  //if user enters 1, exit from search function.
    }
    else
    {
        printf(ORANGE "Invalid option. Please choose from the above options." RESET "\n");  //if any other input is given then print error message.
        printf("--------------------\n");
        goto again;   //go back to the label.
    }
    if(search_again)  //if user wants to search any other contact. '1' is given only for search function and '0' for rest all the function which uses search function.
    {
        int n;
        printf("Do you want to search any other contacts.\n");
        printf("1.YES \n2.NO \nEnter the option : ");
        scanf("%d",&n);
        if(n==1)
            goto again;  //if user wants to search again go back to the label.
    }
}


int search_name(AddressBook *addressbook,int index[])  //function to search name.
{
    retry: //label for goto
    char search[20];  //declare a string variable.
    printf("Enter the name to search : ");  //prompt user to enter the name for searching.
    scanf(" %[^\n]",search);  //read the name from the user.
    int count=addressbook->contact_count,flag=0;  //store the total contact counts in a variable.
    index[addressbook->contact_count];   
    int index_pos=0; //intiliaze a variable to store index positions of names found.
    loading_animation("Searching contacts.....");
    for(int i=0;i<count;i++) //loop through all the contacts
    {
        if(strcasestr(addressbook->contact_details[i].Name,search))  //use strcasetr to search for the searched name so that it is case-insensitive.
        {
            if(flag == 0)  //print the headers only for the 1st time if match is found.
            {
                printf("%-8s %-15s %-18s %-30s","S.No","Name","Mobile number","Email ID");
                printf("\n");
                printf("-----------------------------------------------------------------\n");
            }
            index[index_pos]=i; //store the matched contact index.
            printf("%-8d %-15s %-18s %-30s\n",index_pos+1,addressbook->contact_details[i].Name, addressbook->contact_details[i].Mobile_number, addressbook->contact_details[i].Mail_ID);  //print that contact details.
            index_pos++; //increment index position.
            flag=1; //set flag as 1 each time.
        }
    }
    if(!flag)  //check if any contacts are found. if not, print the error message and go back to the label so user searches for any other contact.
    {
        printf(ORANGE "Contact details not found." RESET "\n");
        goto retry;
    }
    return index_pos;  //if contacts found then return index pos.
}


int search_phone(AddressBook *addressbook,int index[])  //function to search mobile number.
{
    retry: //label for goto
    char search[20];  //declare a string variable.
    printf("Enter the Mobile number to search : ");  //prompt user to enter the mobile number for searching.
    scanf(" %[^\n]",search);  //read the mobile number from the user.
    int count=addressbook->contact_count,flag=0;  //store the total contact counts in a variable.
    index[addressbook->contact_count];
    int index_pos=0;  //intiliaze a variable to store index positions of mobile number found.
    loading_animation("Searching contacts.....");
    for(int i=0;i<count;i++)  //loop through all the contacts
    {
        if(strcasestr(addressbook->contact_details[i].Mobile_number,search))  //use strcasetr to search for the searched mobile number so that it is case-insensitive.
        {
            if(flag == 0)  //print the headers only for the 1st time if match is found.
            {
                printf("%-8s %-15s %-18s %-30s","S.No","Name","Mobile number","Email ID");
                printf("\n");
                printf("-----------------------------------------------------------------\n");
            }
            index[index_pos] = i;  //store the matched contact index.
            printf("%-8d %-15s %-18s %-30s\n",index_pos+1,addressbook->contact_details[i].Name, addressbook->contact_details[i].Mobile_number, addressbook->contact_details[i].Mail_ID); //print that contact details.
            index_pos++;  //increment index position.
            flag=1;  //set flag as 1 each time.
        }
    }
    if(!flag)  //check if any contacts are found. if not, print the error message and go back to the label so user searches for any other contact.
    {
        printf(ORANGE "Contact details not found." RESET "\n");
        goto retry;
    }
    return index_pos;
}


int search_email(AddressBook *addressbook,int index[])  //function to search mail id.
{
    retry:  //label for goto
    char search[20];  //declare a string variable.
    printf("Enter the Email to search : ");  //prompt user to enter the maid id for searching.
    scanf(" %[^\n]",search);  //read the maid id from the user.
    int count=addressbook->contact_count,flag=0;  //store the total contact counts in a variable.
    index[addressbook->contact_count];
    int index_pos=0;  //intiliaze a variable to store index positions of maid id found.
    loading_animation("Searching contacts.....");
    for(int i=0;i<count;i++)  //loop through all the contacts
    {
        if(strcasestr(addressbook->contact_details[i].Mail_ID,search))  //use strcasetr to search for the searched maid id so that it is case-insensitive.
        {
            if(flag == 0)  //print the headers only for the 1st time if match is found.
            {
                printf("%-8s %-15s %-18s %-30s","S.No","Name","Mobile number","Email ID");
                printf("\n");
                printf("-----------------------------------------------------------------\n");
            }
            index[index_pos]=i;  //store the matched contact index.
            printf("%-8d %-15s %-18s %-30s\n",index_pos+1, addressbook->contact_details[i].Name, addressbook->contact_details[i].Mobile_number, addressbook->contact_details[i].Mail_ID);  //print that contact details.
            index_pos++;  //increment index position.
            flag=1;  //set flag as 1 each time.
        }
    }
    if(!flag)  //check if any contacts are found. if not, print the error message and go back to the label so user searches for any other contact.
    {
        printf(ORANGE "Contact details not found." RESET "\n");
        goto retry;
    }
    return index_pos;  //if contacts found then return index pos.
}