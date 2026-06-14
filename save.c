#include<stdio.h>  //includ required header files.
#include<string.h>
#include "contact.h"
#define RED       "\033[31m"  //define macros for colors.
#define RESET     "\033[0m"
#define GREEN     "\033[32m"
#define BBLUE     "\033[94m"
#define BCYAN     "\033[96m"
#define BMAGENTA  "\033[95m"
#define ORANGE    "\033[38;5;208m"

int save_contacts(AddressBook *addressbook)  //function to save contacts to the file.
{
    FILE *fptr = fopen("addressbook.txt","w");  //declare a file pointer and open the file in write mode so contacts can be over-written.
    if(fptr == NULL)  //if file pointer is NULL then no file is found.
    {
        printf(ORANGE "File not found." RESET "\n");  //print error message if file not found and exit from function.
        return 0;
    }
    fprintf(fptr,"#%d\n",addressbook->contact_count);  //write the total number of contacts to the file.
    for(int i=0;i<addressbook->contact_count;i++)  //run loop through all contacts.
    {
        fprintf(fptr,"%s,%s,%s\n",addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);  //write name, mobile number and mail id separated by commas one by one to the file.
    }
    fclose(fptr);  //close the file after writing.
}