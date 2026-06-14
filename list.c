#include<stdio.h>  //include the required header files.
#include<ctype.h>
#include<string.h>
#include "contact.h"
#define RED       "\033[31m"   //define macros for colors.
#define RESET     "\033[0m"
#define GREEN     "\033[32m"
#define BBLUE     "\033[94m"
#define BCYAN     "\033[96m"
#define BMAGENTA  "\033[95m"
#define ORANGE    "\033[38;5;208m"

void list_contacts(AddressBook *addressbook)  //function to display all the contacts.
{
    printf(BMAGENTA "The number of contacts present are : %d" RESET "\n",addressbook->contact_count);  //print the contact count at the first.
    int index=0;
    printf("%-8s %-15s %-18s %-30s","S.No","Name","Mobile number","Email ID");  //print the headers for the contacts.
    printf("\n");
    printf("-----------------------------------------------------------------\n");
    for(int i=0; i<addressbook->contact_count;i++)  //run loop through all the contacts.
    { 
        printf("%-8d %-15s %-18s %-30s\n",index+1,addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);  //print all the contacts one by one.
        index++;
    }
}
