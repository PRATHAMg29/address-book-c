#include<stdio.h>  //include header files
#include <string.h>
#include "contact.h"
#define RED       "\033[31m"  //define macros for colors.
#define RESET     "\033[0m"
#define GREEN     "\033[32m"
#define BBLUE     "\033[94m"
#define BCYAN     "\033[96m"
#define BMAGENTA  "\033[95m"
#define ORANGE    "\033[38;5;208m"

int load_file_data(AddressBook *addressbook)  //function to load the contacts from the file
{
    FILE *fptr;  //declare file pointer.
    if((fptr = fopen("contacts.txt","r")) == NULL)  //open file in read mode and check if file is present or not.
    {
        printf(ORANGE "File not found." RESET "\n");  //print error message if file not found and exit from function.
        return 0;
    }
    fscanf(fptr,"#%d\n",&addressbook->contact_count);  //read total number of contacts from the file.
    for(int i=0;i<addressbook->contact_count;i++)  //run loop through all contacts.
    {
        fscanf(fptr,"%[^,], %[^,], %[^\n]\n",addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);  //read the name, mobile number and mail id separated by commas.
    }
    fclose(fptr);  //close the file after reading.
}