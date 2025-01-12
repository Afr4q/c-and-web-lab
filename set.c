#include <stdio.h>

int ucheck(int ar[], int data, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (ar[i] == data)
        {
            return 1;
        }
    }
    return 0;
}

int scheck(int ar[], int data, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (ar[i] == data)
        {
            return 0;
        }
    }
    return 1;
}

void main()
{
    int u[20], s1[20], s2[20], bs1[20], bs2[20], and[20], or [20], usize, s1size, s2size, i, j, data, flag1, flag2;
    printf("Enter the size of universal set : ");
    scanf("%d", &usize);
    for (i = 0; i < usize; i++)
    {
        printf("Enter Element %d : ", i);
        scanf("%d", &u[i]);
        bs1[i] = 0;
        bs2[i] = 0;
    }
    printf("enter the size of first set : ");
    scanf("%d", &s1size);
    i = 0;
    while (i < s1size)
    {
        flag1 = 0, flag2 = 0;
        printf("Enter Element %d : ", i);
        scanf("%d", &data);
        if (ucheck(u, data, usize) && scheck(s1, data, s1size))
        {
            s1[i] = data;
            i++;
        }
        else
        {
            printf("element already in the set or not in universal set!!!!\n");
        }
    }
    printf("enter the size of second set : ");
    scanf("%d", &s2size);
    i = 0;
    while (i < s2size)
    {
        printf("Enter Element %d : ", i);
        scanf("%d", &data);
        if (ucheck(u, data, usize) && scheck(s2, data, s2size))
        {
            s2[i] = data;
            i++;
        }
        else
        {
            printf("element already in the set or not in universal set!!!!\n");
        }
    }
    for (i = 0; i < s1size; i++)
    {
        for (j = 0; j < usize; j++)
        {
            if (s1[i] == u[j])
            {
                bs1[j] = 1;
            }
        }
    }
    for (i = 0; i < s2size; i++)
    {
        for (j = 0; j < usize; j++)
        {
            if (s2[i] == u[j])
            {
                bs2[j] = 1;
            }
        }
    }
    for ( i = 0; i < usize; i++)
    {
        and[i]=bs1[i] & bs2[i];
        or[i]=bs1[i] | bs2[i];
    }
    
    printf("Universal Set : ");
    for (i = 0; i < usize; i++)
    {
        printf("%d ", u[i]);
    }
    printf("\nSet 1 : ");
    for (i = 0; i < s1size; i++)
    {
        printf("%d ", s1[i]);
    }
    printf("\nSet 2 : ");
    for (i = 0; i < s2size; i++)
    {
        printf("%d ", s2[i]);
    }
    printf("\nBitstring of Set 1 : ");
    for (i = 0; i < usize; i++)
    {
        printf("%d ", bs1[i]);
    }
    printf("\nBitstring of Set 2 : ");
    for (i = 0; i < usize; i++)
    {
        printf("%d ", bs2[i]);
    }
    printf("\nAnd Operation : ");
    for (i = 0; i < usize; i++)
    {
        printf("%d ", and[i]);
    }
    printf("\nOr Operation : ");
    for (i = 0; i < usize; i++)
    {
        printf("%d ", or[i]);
    }
}