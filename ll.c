#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL,*newnode,*cur;

void insertion()
{
    int pos;
    struct node *temp=head;
    newnode=malloc(sizeof(struct node));
    printf("enter the data : ");
    scanf("%d",&(newnode->data));
    newnode->next=NULL;
    printf("\n1.beginning\n2.end\n3.certain position\nenter where you want to insert : ");
    int cho;
    scanf("%d",&cho);
    switch (cho)
    {
        case 1:
            if(head==NULL)
    {
        head=newnode;
        cur=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
    break;
    case 2:
        if(head==NULL)
    {
        head=newnode;
        cur=newnode;
    }
    else
    {
        cur->next=newnode;
        cur=newnode;
    }
        break;
    case 3:
    printf("specify the position, where the node needs to be inserted : ");
    scanf("%d",&pos);
    for(int i=1;i<pos-2;i++)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    break;
    default:
        printf("invalid choice");
        break;
    }
}

void display()
{
    struct node *tem=head;
    while (tem->next!=NULL)
    {
        printf("%d->",tem->data);
        tem=tem->next;
    }
    printf("%d->",tem->data);
}

void deletion()
{
    int pos;
    struct node *temp=head,*te;
    newnode=malloc(sizeof(struct node));
    printf("\n1.beginning\n2.end\n3.certain position\nenter where you want to delete: ");
    int cho;
    scanf("%d",&cho);
    switch(cho){
        case 1:
            temp=head;
            head=head->next;
            free(temp);
            break;
        case 2:
        while (temp->next!=NULL)
        {
            te=temp;
            temp=te->next;
        }
        te->next=NULL;
        free(temp);
            break;
        case 3:
        printf("specify the position, where the node needs to be deleted : ");
        scanf("%d",&pos);
        for(int i=1;i<pos-1;i++)
        {   
            temp=temp->next;
        }
        te=temp->next;
        temp->next=temp->next->next;
        free(te);
        break;
        default:
            printf("invalid choice");
            break;
        }
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