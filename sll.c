#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node*newnode,*top=NULL,*temp;
int max,current=1;

void push()
{
    if (current>max)
    {
        printf("Stack is full");
    }
    else
    {
        newnode=malloc(sizeof(struct node));
        printf("enter the data : ");
        scanf("%d",&(newnode->data));
        newnode->next=top;
        top=newnode;
        current+=1; 
    } 
}

void pop()
{
    if (top==NULL)
    {
        printf("Stack is Empty");
    }
    else
    {
        temp=top;
        top=top->next;
        free(temp);
    }
}

void display()
{
    temp=top;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
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
            push();
            break;
            case 2:
            pop();
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