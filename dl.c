#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;  
};

struct node *head=NULL,*newnode,*cur;

void insertion()
{
    newnode=malloc(sizeof(struct node));
    printf("enter the data : ");
    scanf("%d",&(newnode->data));
    newnode->next=NULL;
    if (head==NULL)
    {
        head=newnode;
        cur=newnode;
    }
    else
    {
        newnode->prev=cur;
        cur->next=newnode;
        cur=newnode;
    }
    
}

void deletion()
{
    struct node *temp=cur;
    cur->prev->next=NULL;
    cur=cur->prev;
    free(temp);
}

void display()
{
    struct node *tem=head;
    while (tem->next!=NULL)
    {
        printf("%d<->",tem->data);
        tem=tem->next;
    }
    printf("%d<->",tem->data);
}

int main(){
    do
    {
        printf("\n1.insertion\n2.deletion\n3.display\n4.exit\nenter the number of operation : ");
        int c;
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            insertion();
            break;
            case 2:
            deletion();
            break;
            case 3:
            display();
            break;
            case 4:
            return 0;
            default:
            printf("invalid choice\n");
        }
    } while (1);
}
