#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *front=NULL,*newnode,*rear,*temp;
int max,current=1;

void enqueue()
{
    if (current>max)
    {
        printf("Queue if full");
    }
    else
    {
        newnode=malloc(sizeof(struct node));
        printf("enter the data : ");
        scanf("%d",&(newnode->data));
        newnode->next=NULL;
        current+=1;
        if (front==NULL)
    {
        front=newnode;
        rear=newnode;
    }
        else
    {
        rear->next=newnode;
        rear=newnode;
    }
    }  
}

void dequeue()
{
    if(front==NULL)
    {
        printf("Queue is Empty");
    }
    else
    {
        temp=front;
        front=front->next;
        free(temp);
    }
}

void display()
{
    temp=front;
    while (temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
}

int main(){
    printf("enter the size of queue : ");
    scanf("%d",&max);
    do
    {
        printf("\n1.insertion\n2.deletion\n3.display\n4.exit\nenter the number of operation : ");
        int c;
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
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