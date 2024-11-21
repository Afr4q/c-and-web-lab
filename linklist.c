// Linked list using Structure
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main()
{
    
    struct node *head=NULL, *newnode, *current;
    int max, i;
    printf("Enter the number of nodes: ");
    scanf("%d", &max);
    
    printf("Enter the data:\n");
    for (i=0; i<max; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &(newnode->data));
        if(head==NULL)
        { 
            head = newnode;
            current = newnode;
        }
        else
        {
            current->next = newnode;
            current = newnode;
        }
        newnode->next = NULL;
        printf("%d\t", newnode->data);
    }
    for (i=0; i<max; i++) {
        printf("%d\t", head->next);
    }
}