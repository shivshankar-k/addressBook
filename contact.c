#include "contact.h"
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>
 

#define ac_red "\x1b[31m"
#define ac_green "\x1b[32m"
#define ac_normal "\x1b[m"
#define ac_magenta "\x1b[35m"
   // List All contacts
void listContacts(AddressBook *addressBook){
    FILE *ptr=fopen("contact.txt","r");
    if(ptr==NULL)
    printf("Not opened\n");
if(ptr!=NULL)
printf("opened\n");

char ch;
printf("\n");

         while(fread(&ch,1,1,ptr)>0)
         {
            printf("%c",ch);
         }

    fclose(ptr);
} 


             //create contact
void createContact(AddressBook *addressBook)
{
    char name[50];
    char phone[11];
    char mail[50];
   int i= addressBook-> contactCount;
   int name_l=1;
   printf("Enter contact name:");
   while(name_l)
   {
    scanf(" %[^\n]",name);
    if(name_validation(addressBook,name))
    {
        strcpy(addressBook->contacts[i].name,name);
        name_l=0;
        break;
    }
    printf("Enter a valid name:");
   }

    printf("Enter phone number:");
    int phone_l=1;
    while(phone_l)
    {
    scanf(" %[^\n]",phone);
    if(phone_validation(addressBook,phone)){
        strcpy(addressBook->contacts[i].phone,phone);
        phone_l=0;
        break;
    }
     printf("Enter a valid phone number:");
    }

    printf("Enter contact Mail ID:");
    int mail_l=1;
    while(mail_l)
    {
    scanf(" %[^\n]",mail);
    if(mail_validation(addressBook,mail))
    {
    strcpy(addressBook->contacts[i].email,mail);
    mail_l=0;
    break;
    }
    printf("Enter a valid Mail ID:");
    }
    printf(ac_green"\t\t\tContact created successfully\n"ac_normal);
    addressBook-> contactCount++;
    return;
}

   //Search contact
void searchContact(AddressBook *addressBook){
int i=1;
while(i){
    int opt;
    printf("\nSearch menu:\n1.search by contact name\n2.search by contact number\n3.search by Mail ID\n4.Exit\n");
    printf("Enter your choice:");
    scanf("%d",&opt);
    int flag=0;
    switch(opt)
    {
        case 1:
        int name_s=1;
        printf("Enter name to search for a contact:");
        while(name_s)
        {
        char name[20];
        scanf(" %[^\n]",name);
        int j=1;
        for(int i=0; i<addressBook-> contactCount; i++){
            if(strcasestr(addressBook->contacts[i].name,name)!=0){
                printf("%d.%-15s %-13s %-15s\n",j++,addressBook->contacts[i].name,
                    addressBook->contacts[i].phone,
            addressBook->contacts[i].email);
            flag=1;
            name_s=0;
        
            }
        }
            if(!flag)
            {
            printf(ac_red"\n\t\t\tNo Contacts\n"ac_normal);
        printf("Enter valid Name:");
            }
    }
        break;

        //search_by_phone
        case 2:
         char phone_ser[11];
         int phone_s=1;
         printf("Enter phone number to search for a contact:");
         while(phone_s)
         {
        scanf(" %[^\n]",phone_ser);
        int j=1;
        for(int i=0; i<addressBook-> contactCount; i++){
            if(strstr(addressBook->contacts[i].phone,phone_ser)){
                
                printf(ac_red"%d.%-15s %-13s %-15s\n" ac_normal,
                    j,
                    addressBook->contacts[i].name,
                    addressBook->contacts[i].phone,
            addressBook->contacts[i].email);
            j++;
           flag=1;
            phone_s=0;
            }
        }
}
        break;

         //search_by_mail_id
        case 3:
         char mail_ser[50];
         int mail_s=1;
         printf("Enter Mail ID to search for a contact:");
         while(mail_s)
         {
        scanf(" %[^\n]",mail_ser);
        for(int i=0; i<addressBook-> contactCount; i++){
            if(strcmp(mail_ser,addressBook->contacts[i].email)==0){
                printf("\n%s %s %s\n",addressBook->contacts[i].name,
                    addressBook->contacts[i].phone,
            addressBook->contacts[i].email);
            flag=1;
            mail_s=0;
            break;
            }
        }
            if(!flag)
            {
            printf(ac_red"\n\t\t\tno contacts\n"ac_normal);
        printf("Enter valid Mail ID:");
    }
}
        break;

        case 4:
        return;
        default:
        printf(ac_magenta"Warning:"ac_normal"Please choose valid option\n");   
    }
}
    return;
}
                  //edit contact
void editContact(AddressBook *addressBook){
    int i=1;
    while(i)
    {
    printf("\nEdit menu:\n1.Edit contact name\n2.Edit by contact number\n3.Edit by Mail ID\n4.Exit\n");
    int opt;
    printf("Enter your choice:");
    scanf("%d",&opt);
    int flag=0;
    switch(opt)
    {
        case 1:
        char name[20];
        printf("Enter old name to search for a contact:");
        int name_e=1;
        while(name_e)
        {
        scanf(" %[^\n]",name);
        for(int i=0; i<addressBook-> contactCount; i++){
            if(strcmp(name,addressBook->contacts[i].name)==0){
                printf("Enter New name:");
                scanf(" %[^\n]",name);
                if(name_validation(addressBook,name))
                {
                strcpy(addressBook->contacts[i].name,name);
                printf("\n%s %s %s\n",addressBook->contacts[i].name,
                    addressBook->contacts[i].phone,
            addressBook->contacts[i].email);
            printf(ac_green"\t\t\tName changed successfully!"ac_normal);
            flag=1;
                }
                name_e=0;
            break;
            }
        }
        if(!flag)
        {
        printf(ac_red"\n\t\t\tno contacts\n"ac_normal);
    printf("Enter valid contact name:");
        }
    }
        break;

        //search_by_phone
        case 2:
         char phone_ser[11];
        printf("Enter old phone number to search for a contact:");
        int phone_e=1;
        while(phone_e)
        {
        scanf(" %[^\n]",phone_ser);
        for(int i=0; i<addressBook-> contactCount; i++){
            if(strcmp(phone_ser,addressBook->contacts[i].phone)==0){
                printf("Enter new phone number:");
                scanf(" %[^\n]",phone_ser);
                if(phone_validation(addressBook,phone_ser))
                {
                    strcpy(addressBook->contacts[i].phone,phone_ser);
                printf("\n%s %s %s\n",addressBook->contacts[i].name,
                    addressBook->contacts[i].phone,
            addressBook->contacts[i].email);
             printf(ac_green"\t\t\tPhone number changed successfully!"ac_normal);
                }
            flag=1;
            phone_e=0;
            break;
            }
        }
            if(!flag)
            {
            printf(ac_red"\n\t\t\tNo contacts\n"ac_normal);
        printf("Enter valid Phone number:");
    }
}
        break;

         //search_by_mail_id
        case 3:
         char mail_ser[50];
        printf("Enter old Mail ID to search for a contact:");
        int mail_e=1;
        while(mail_e)
        {
        scanf(" %[^\n]",mail_ser);
        for(int i=0; i<addressBook-> contactCount; i++){
            if(strcmp(mail_ser,addressBook->contacts[i].email)==0){
                printf("Enter new Mail ID:");
                scanf(" %[^\n]",mail_ser);
                if(mail_validation(addressBook,mail_ser))
                {
                strcpy( addressBook->contacts[i].email,mail_ser);
                printf("\n%s %s %s\n",addressBook->contacts[i].name,
                    addressBook->contacts[i].phone,
            addressBook->contacts[i].email);
             printf(ac_green"\t\t\tMail_id changed successfully!"ac_normal);
                }
            flag=1;
            mail_e=0;
            break;
            }
        }
            if(!flag)
            {
            printf(ac_red"\n\t\t\tNo contacts\n"ac_normal);
        printf("Enter valid mail ID:");
    }
}
        break;

        case 4:
        return;
        default:
        printf("Please choose valid option\n");
        
    }
}
}
    //Delete contacts
void deleteContact(AddressBook *addressBook){
     char name[20];
     printf("Enter name to delete contact:");
     scanf(" %[^\n]",name); 
     for(int i=0; i<addressBook-> contactCount; i++){
        if(strcmp(name,addressBook->contacts[i].name)==0){
            for(int j=i; j<addressBook-> contactCount; j++)
            {
            strcpy(addressBook->contacts[j].name,addressBook->contacts[j+1].name);
            strcpy(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone);
            strcpy(addressBook->contacts[j].email,addressBook->contacts[j+1].email);
            }
        }
    }
        addressBook-> contactCount--;
     printf(ac_green"\t\t\tcontact deleted successfully!\n"ac_normal);
    return;
}


        //save contacts
void saveContactsToFile(AddressBook *addressBook){
     
     FILE *ptr=fopen("contact.txt","w");
     FILE *ptr2=fopen("contacts.txt","r");

    if(ptr==NULL)
        printf("Not opened\n");
     if(ptr!=NULL)
        printf("opened\n");
     
    for(int i=0; i<addressBook-> contactCount; i++)
    {
        fprintf(ptr,"%-15s %-13s %-15s\n",
        addressBook->contacts[i].name,
        addressBook->contacts[i].phone,
        addressBook->contacts[i].email);
    }

    fclose(ptr);

    return;
}


void saveAndExit(AddressBook *addressBook){
    FILE *ptr=fopen("contact.txt","w");
    char name[20];

    if(ptr==NULL)
        printf("Not opened\n");
     if(ptr!=NULL)
        printf("opened\n");
    for(int i=0; i<addressBook-> contactCount; i++)
    {
        fprintf(ptr,"%-15s %-13s %-15s\n",
        addressBook->contacts[i].name,
        addressBook->contacts[i].phone,
        addressBook->contacts[i].email);
    }

    fclose(ptr);
    return;
}

    //Name Validation
int name_validation(AddressBook *addressBook,char *name){
    for(int i=0; name[i]!=0; i++){
        if(!isalpha(name[i])&& name[i]!=' '){
            printf(ac_red"\n\t\t\tInvalid name\n"ac_normal);
            return 0;
        }
    }
    for(int i=0; i<addressBook-> contactCount; i++){
        if(strcmp(name,addressBook->contacts[i].name)==0){
            printf(ac_red"\n\t\t\tyou entered a name matching  another contact\n"ac_normal);
            return 0;
        }
    }
    return 1;
}
    //Phone Number Validation
int phone_validation(AddressBook *addressBook,char *phone){
    int n=strlen(phone);
    for(int i=0; phone[i]!=0; i++)
    {
        if(!isdigit(phone[i]))
        {
            printf(ac_red"\n\t\t\tYou entered an invalid phone number\n"ac_normal);  
            return 0;
        }
    }
     
    if(n<10)
    {
        printf(ac_magenta"\nWarning:"ac_normal"You entered fewer than 10 digits\n");     
        return 0;
    }
    if(n>10)
    {
        printf(ac_magenta"\nwarning:"ac_normal"You entered more than 10 digits\n"); 
        return 0;
    }

    for(int i=0; i<addressBook-> contactCount; i++){
        if(strcmp(phone,addressBook->contacts[i].phone)==0){
            printf(ac_magenta"\nWarning:"ac_normal"You entered a phone number matching another contact phone number\n");
            return 0;
        }
    }
    return 1;
}
     //Mail ID validation
int mail_validation(AddressBook *addressBook,char *mail){
    int  count=0,flag=0;
    for(int i=0;mail[i]!=0; i++)
    {
        if((mail[i]>='a' && mail[i]<='z') ||
        (mail[i]>='0' &&mail[i]<='9') || 
        mail[i]=='@'||mail[i]=='.')
        {
        if(mail[i]=='@'||(mail[i]=='.' && 
            mail[i+1]=='c'&&mail[i+2]=='o'&&
            mail[i+3]=='m'&&mail[i+4]=='\0'))
        count++;
        }
        else
            flag=1;
    }
    if( count!=2 || flag)
    {
        printf(ac_red"\n\t\t\tInvalid Mail ID:\n"ac_normal);
        return 0;
    }

    for(int i=0; i<addressBook-> contactCount; i++){
        if(strcmp(mail,addressBook->contacts[i].email)==0){
            printf(ac_magenta"\nWarning:"ac_normal"You entered a Mail ID matching another contact Mail_id\n");
            return 0;
        }
    }
    return 1;
}


void whatsappContact(AddressBook *addressBook)
{
    char name[50];
    char command[300];
    char Message[100];

    printf("Enter contact name: ");
    scanf(" %[^\n]", name);


    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(addressBook->contacts[i].name, name) == 0)
        {
            printf("Contact found!\n");
            printf("Name  : %s\n", addressBook->contacts[i].name);
            printf("Phone : %s\n", addressBook->contacts[i].phone);
printf("Enter Meaasge:");
scanf(" %[^\n]",Message);
            // Open WhatsApp herechar command[100];

snprintf(command,sizeof(command),
                    "cmd.exe /c start \"\" \"https://wa.me/%s?text=%s\"",
                    addressBook->contacts[i].phone,
                    Message);
system(command);
            return;
        }
    }

    printf(ac_red"Contact not found\n"ac_normal);
}