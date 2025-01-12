#include<stdio.h>


void main()
{
    char str[30];
    printf("Enter te string 1: ");
    fgets(str,sizeof(str),stdin);
    printf("\nString 2 : %s",str);
    printf("\n%c",str[6]);
}
