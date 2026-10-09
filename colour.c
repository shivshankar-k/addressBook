#include<stdio.h>

#define AC_white "\x1b[47m"


#define AC_BLACK "\x1b[30m"
#define AC_RED "\x1b[31m"
#define AC_GREEN "\x1b[32m"
#define AC_YELLOW "\x1b[33m"
#define AC_BLUE "\x1b[34m"
#define AC_MAGENTA "\x1b[35m"
#define AC_CYAN "\x1b[36m"
#define AC_WHITE "\x1b[37m"
#define AC_NORMAL "\x1b[m"
int main()
{
    // printf("Color test:\n");
    // printf("%sThis is red text%s\n",AC_RED,AC_normal);
    // printf("%sEnd test\n",AC_normal);  

     printf("%sHello shiva\n",AC_BLACK);
     printf("%sHello shiva\n",AC_RED);
     printf("%sHello shiva\n",AC_GREEN );
     printf("%sHello shiva\n",AC_YELLOW );
     printf("%sHello shiva\n",AC_BLUE);
     printf("%sHello shiva\n",AC_MAGENTA);
     printf("%sHello shiva\n",AC_CYAN);
     printf("%sHello shiva\n",AC_WHITE);
     printf("%sHello shiva\n",AC_NORMAL);
     

     printf(AC_GREEN "Contact added successfully!\n" AC_NORMAL);
printf(AC_RED "Invalid phone number!\n" AC_NORMAL);
printf(AC_YELLOW "Choose an option: " AC_NORMAL);
printf(AC_CYAN "1. Add Contact\n" AC_NORMAL);
printf(AC_CYAN "2. Search Contact\n" AC_NORMAL);
    return(0);
}
