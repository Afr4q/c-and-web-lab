#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head;

struct node *tail=NULL,*newnode;

void insertionEnd()
{
    newnode=malloc(sizeof(struct node));
    printf("enter the data : ");
    scanf("%d",&(newnode->data));
    if(tail==NULL)
    {
        tail=newnode;
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
        tail=newnode;
    }
}
void insertionBegin(){
    newnode=malloc(sizeof(struct node));
    printf("enter the data : ");
    scanf("%d",&(newnode->data));
    newnode->next=head;
    head=newnode;
}
void insertionPos(){
    int pos;
    struct node *temp=head;
    newnode=malloc(sizeof(struct node));
    printf("enter the data : ");
    scanf("%d",&(newnode->data));
    printf("enter the pos : ");
    scanf("%d",&pos);
    for(int i=0;i<pos-2;i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
void  deletionEnd(){
    struct node *temp=head;
    while(temp->next->next!=head)
    {
        temp=temp->next;
    }
    temp->next=head;
    // head=NULL;
    tail=temp;
} 
void deletionbeginning(){
    struct node *temp=head;
}
void display(){
    struct node *temp=head;
    while(temp->next!=head)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
}

int main()
{
    do
    {
        printf("\n1.insertion at End\n2.insertion at beginning\n3.insertion at a position\n4.deletion at end\n5.deletion at beginning\n6.deletion at a position\n7.display\n8.exit\nenter the number of operation : ");
        int c;
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            insertionEnd();
            break;
        case 2:
            insertionBegin();
            break;
        case 3:
            insertionPos();
            break;
        case 4:
            deletionEnd();
            break;
        case 5:
            deletionbeginning();
            break;
        // case 6:
        //     deletionPos();
        //     break;
        case 7:
            display();
            break;
        case 8:
            return 0;
        default:
            printf("invalid choice\n");
            break;
        }
    } while (1);
}
