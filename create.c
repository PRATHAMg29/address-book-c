#include<stdio.h>  //include required header files
#include<ctype.h>
#include<string.h>
#include "contact.h"
#include "animation.h"
#define RED       "\033[31m"  //define macros for colors
#define RESET     "\033[0m"
#define GREEN     "\033[32m"
#define BBLUE     "\033[94m"
#define BCYAN     "\033[96m"
#define BMAGENTA  "\033[95m"
#define ORANGE    "\033[38;5;208m"

//function prototypes.
int create_name(AddressBook *addressbook, char *temp_name,int *temp_count);  
int check_valid_name(char *temp_name);

int create_phone(AddressBook *addressbook, char *temp_phone,int *temp_count);
int check_valid_phone(AddressBook *addressbook, char *temp_name);

int create_email(AddressBook *addressbook, char *temp_email,int *temp_count);
int check_valid_email(AddressBook *addressbook, char *temp_email);


int create_contact(AddressBook *addressbook)  //function to create contact
{
    again:  //label used for goto 
    char temp_name[50],temp_phone[11],temp_email[50];  //declare variables
    int temp_count = 0,option;
    create_name(addressbook, temp_name, &temp_count); //call create name function by passing the address of temp_count
    create_phone(addressbook, temp_phone,&temp_count);  //call create phone function by passing the address of temp_count
    create_email(addressbook, temp_email, &temp_count); //call create email function by passing the address of temp_count

    if(temp_count == 3) //only if temp_count is 3, save the contact in structure.
    {
        strcpy(addressbook->contact_details[addressbook->contact_count].Name,temp_name);  //copy name into the structure
        strcpy(addressbook->contact_details[addressbook->contact_count].Mobile_number,temp_phone); //copy mobile number into the structure
        strcpy(addressbook->contact_details[addressbook->contact_count].Mail_ID,temp_email); //copy mail id into the structure
        addressbook->contact_count+=1;  //increase the count by 1 after adding the contact to the structure.
        loading_animation("Creating contact.....");
        printf("--------------------\n");
        printf(GREEN "Contact created successfully." RESET "\n");  //print contact created in green color.
        printf("Do you want to create another contact?\n");  //ask if user wants to create another contact.
        printf("1.YES\n2.NO\nEnter the option : ");  //if yes go back to the label or exit from this function.
        scanf("%d",&option);
        if(option == 1)
            goto again;
    }
    return 0;
}


int create_name(AddressBook *addressbook, char *temp_name,int *temp_count)   //function to create contact name.
{
    retry: //label used for goto
        printf("Enter a name : ");  //prompt user for a name.
        scanf(" %[^\n]",temp_name);  //store it in a temporary variable.
        if(!check_valid_name(temp_name))  //check if the name is valid by calling another function which checks for validation.
        {
            goto retry;  //if validation fails go back to label and take the name input again.
        }
        *temp_count+=1;  //if validation passes increase the temp_count.
        printf("----------------------\n");
}
int check_valid_name(char *temp_name)  //function for validation of name.
{
    int flag=0;
    int len = strlen(temp_name);  //calculate length of name.
    for(int i=0;i<len;i++)  //run loop until the end of the name
    {
        if(temp_name[i] == ' ') //name may contain spaces so if space is found skip that iteratiob.
        {
            continue;
        }
        if(!isalpha(temp_name[i]))  //if name has any other input except alphabets then print error message in orange color.
        {
            printf(ORANGE "Please enter a name which consists of only alphabets." RESET "\n");
            flag=1;
            break;
        }
    }
    if(!flag)
    {
        return 1;  //if name validation passes return 1 else return 0.
    }
    return 0;
}



int create_phone(AddressBook *addressbook, char *temp_phone,int *temp_count)  //function to create contact mobile number.
{
    retry:
        printf("Enter a phone number : "); //prompt user for a mobile number.
        scanf(" %[^\n]",temp_phone); //store it in a temporary variable.
        if(!check_valid_phone(addressbook,temp_phone))  //check if the mobile number is valid by calling another function which checks for validation.
        {
            goto retry;  //if validation fails go back to label and take the mobile number input again.
        }
        *temp_count+=1;  //if validation passes increase the temp_count.
        printf("----------------------\n");
}
int check_valid_phone(AddressBook *addressbook,char *temp_phone)  //function for validation of mobile number.
{
    for(int i=0;i<addressbook->contact_count;i++)  //run loop through all the contact details.
    {
        int c =strcmp(addressbook->contact_details[i].Mobile_number,temp_phone);  //compare each mobile number with user entered mobile number.
        if(c==0)  //if match is found, strcmp returns 0. display error message in ORANGE and ask user to enter a unique mobile number.
        {
            printf(ORANGE "Mobile number already exists." RESET "\n");
            printf(ORANGE "Enter a unique mobile number." RESET "\n");
            return 0;
        }
    }
    int flag=0;
    if(strlen(temp_phone) != 10)  //if mobile number doesn't consist 10 digits then print error message and return 0.
    {
        printf(ORANGE "Please enter a valid phone number consisting of 10 digits." RESET "\n");
        return 0;
    }
    if(temp_phone[0]< '6')  //if first number isn't in range of 6 to 9 then print error messageand return 0.
    {
        printf(ORANGE "First number should be in range of 6 to 9." RESET "\n");
        return 0;
    }
    for(int i=0;i<10;i++)  //run loop upto 10.
    {
        if(!isdigit(temp_phone[i]))  //if any of the input is not a digit then print error message and return 0.
        {
            printf(ORANGE "Please enter a phone number with only digits." RESET "\n");
            flag=1;
            break;            
        }
    }
    if(!flag)
    {
        return 1; //if mobile number validation passes return 1 else return 0.
    }
    return 0;
}


int create_email(AddressBook *addressbook, char *temp_email,int *temp_count)  //function to create contact mail id.
{
    retry:
        printf("Enter a Email ID : "); //prompt user for a mail id.
        scanf(" %[^\n]",temp_email); //store it in a temporary variable.
        if(!check_valid_email(addressbook,temp_email))  //check if the mail id is valid by calling another function which checks for validation.
        {
            goto retry;  //if validation fails go back to label and take the mail id input again.
        }
        *temp_count+=1;  //if validation passes increase the temp_count.
        printf("--------------------\n");
}
int check_valid_email(AddressBook *addressbook,char *temp_email)  //function for validation of mail id.
{
    for(int i=0;i<addressbook->contact_count;i++)  //run loop through all the contact details.
    {
        int c =strcmp(addressbook->contact_details[i].Mail_ID,temp_email); //compare each mail id with user entered mail id.
        if(c==0)  //if match is found, strcmp returns 0. display error message in ORANGE and ask user to enter a unique mail id.
        {
            printf(ORANGE "Email ID already exits." RESET "\n");
            printf(ORANGE "Enter a unique Email ID." RESET "\n");
            return 0;
        }
    }
    int flag=0,count=0,len=0,found=0,a,b;
    while(temp_email[count]) //run loop until NULL character
    {
        if(temp_email[count] == '@')  //if '@' is found store its index in count and increment len value.
        {
            len++;
            a=count;
        }
        if(temp_email[count] == '.')  //if '.' is found store its index in count and increment found value.
        {
            found++;
            b=count;
        }
        count++;
    }
    if(len!=1 || found!=1)  //len and found should only be 1. not greater or not lesser.
    {
        printf(ORANGE "Enter a valid email with atleast/only one '@' and '.'." RESET "\n");
        return 0;
    }
    if(b-a<2)  //check if any character is present between '@' and '.'. if not print error message and return 0.
    {
        printf(ORANGE "Domain name cannot be empty." RESET "\n");
        return 0;
    }
    for(int i=a+1;i<=b-1;i++)  //run loop from next index of '@' upto '.'.
    {
        if(!islower(temp_email[i]))  //if there is any other characters other than lowercase letters then print error message and exit from function.
        {
            printf(ORANGE "The domain name should consist of only alphabets." RESET "\n");
            return 0;
        }
    }
    int i=0,j=0;
    char str1[50];
    while(temp_email[i])  //run loop until '@' and store all the characters upto there in another string.
    {
        if(temp_email[i] == '@') 
            break;
        str1[j] = temp_email[i];
        i++;
        j++;
    }
    str1[j] = '\0';  //add a null character at the end for the copied string.
    if(isdigit(temp_email[0]))  //check if first character of mail id is a digit. if yes, then print error message and exit from function.
    {
        printf(ORANGE "First character cannot be a digit." RESET "\n");
        return 0;
    }
    if(!islower(temp_email[0]))  //check if first character of mail id is a lowercase or not. if not, then print error message and exit from function.
    {
        printf(ORANGE "First character should be a lowercase alphabet." RESET "\n");
        return 0;
    }
    for(int i=0;i<strlen(str1);i++)  //run loop until the end of length of the copied string.
    {
        if(isdigit(str1[i]))  //if digits are present then skip that iteration.
        {
            continue;
        }
        if(!islower(str1[i]))  //if anything except lowercase characters are present then print error message and exit from the loop.
        {
            printf(ORANGE "Please enter the email id with only lowercase letters." RESET "\n");
            flag=1;
            break;
        }
    }
    if(!flag)
    {
        return 1; //if mail id validation passes return 1 else return 0.
    }
    return 0;
}

