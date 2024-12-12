#include<stdio.h>

int main()
{
    int u[10]={1,2,3,4,5,6,7,8,9,10};
    int bit1[10]={0},bit2[10]={0};
    int size1,size2,i,temp,flag,j;
    for (i = 0; i < 10; i++)
    {
        if (i==0)
        {
            printf("U={");
        }
        printf("%d",u[i]);
        if (i==9)
        {
            printf("}");
            break;
        }
        printf(",");
    }
    printf("\nEnter the size first set : ");
    scanf("%d",&size1);
    int s1[size1];
    printf("Enter the first set\n");
    i=0;
    while (i<size1)
    {
        flag=0;
        printf("Element %d :",i+1);
        scanf("%d",&temp);
        for ( j = 0; j < 10;j++)
        {
            if (temp==u[j])
            {
                flag=1;
                break;
            }
        }
        for (int i = 0; i < size1; i++)
        {
            if (temp==s1[i])
            {
                flag=2;
                break;
            } 
        }
        if (flag==1)
        {
            s1[i]=temp;
            i++;
        }
        if (flag==0)
        {
            printf("Enter element from Universal set!!!\n");
        }
        if (flag==2)
        {
            printf("Element already in the set!!!\n");
        }
    }
    for ( i = 0; i < 10; i++)
    {
        for (j = 0; j < size1; j++)
        {
            if (u[i]==s1[j])
            {
                bit1[i]=1;
            }
        }  
    }
    printf("bitstring of set1 : ");
    for (i = 0; i < 10; i++)
    {
        printf("%d",bit1[i]);
    }
    printf("\nEnter the size second set : ");
    scanf("%d",&size2);
    int s2[size2];
    printf("Enter the second set\n");
    i=0;
    while (i<size2)
    {
        flag=0;
        printf("Element %d :",i+1);
        scanf("%d",&temp);
        for ( j = 0; j < 10;j++)
        {
            if (temp==u[j])
            {
                flag=1;
                break;
            }
        }
        for (int i = 0; i < size2; i++)
        {
            if (temp==s2[i])
            {
                flag=2;
                break;
            } 
        }
        if (flag==1)
        {
            s2[i]=temp;
            i++;
        }
        if (flag==0)
        {
            printf("Enter element from Universal set!!!\n");
        }
    }
    for ( i = 0; i < 10; i++)
    {
        for (j = 0; j < size2; j++)
        {
            if (u[i]==s2[j])
            {
                bit2[i]=1;
            }
        }  
    }
    printf("bitstring of set2 : ");
    for (i = 0; i < 10; i++)
    {
        printf("%d",bit2[i]);
    }
    int ubit[10]={0};
    for ( i = 0; i < 10; i++)
    {
        if (bit1[i]==1 || bit2[i]==1)
        {
            ubit[i]=1;
        }
    }
    printf("\nUnion of set1 and set2 : ");
    for (i = 0; i < 10; i++)
    {
        printf("%d",ubit[i]);
    }   
    int ibit[10]={0};
    for ( i = 0; i < 10; i++)
    {
        if (bit1[i]==1 && bit2[i]==1)
        {
            ibit[i]=1;
        }
    }
    printf("\nIntersection of set1 and set2 : ");
    for (i = 0; i < 10; i++)
    {
        printf("%d",ibit[i]);
    }   
}
