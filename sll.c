#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL, *cur;

void reverse(struct node *head)
{
    if (head == NULL)
    {
        return;
    }
    reverse(head->next);
    printf("%d<--", head->data);
}

void push()
{
    struct node *newnode;
    newnode = malloc(sizeof(struct node));
    printf("Enter the value to insert : ");
    scanf("%d", &(newnode->data));
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        cur = newnode;
    }
    else
    {
        cur->next = newnode;
        cur = newnode;
    }
}

void sort()
{
    int temp;
    struct node *temp1 = head, *temp2;
    while (temp1->next != NULL)
    {
        temp2 = temp1->next;
        while (temp2->next != NULL)
        {
            if (temp1->data > temp2->data)
            {
                temp = temp1->data;
                temp1->data = temp2->data;
                temp2->data = temp;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}

void display()
{
    struct node *temp=head;
    while (temp!=NULL)
    {
        printf("%d-->",temp->data);
        temp=temp->next;
    }
}

int main()
{
    int o;
    do
    {
        printf("\n1.Insertion\n2.reverse\n3.Sort\n4.Display\n5.Exit\nEnter the operation No. :");
        scanf("%d", &o);
        switch (o)
        {
        case 1:
            push();
            break;
        case 2:
            reverse(head);
            break;
        case 3:
            sort(head);
            break;
        case 4:
            display();
            break;
        case 5:
            break;
        default:
            printf("Invalid Input");
            break;
        }
    } while (o != 5);
}