#include<stdio.h>
#include<stdlib.h>

struct bstnode
{
    int data;
    struct bstnode *left,*right;
};

struct bstnode *newnode,*root=NULL,*temp;

struct bstnode* createnode(int value)
{
    newnode=malloc(sizeof(struct bstnode));
    newnode->data=value;
    newnode->left=newnode->right=NULL;
    return newnode;
}

struct bstnode* search(struct bstnode *root,int value)
{
    if (root==NULL||root->data==value)
    {
        return root;
    }
    else if (root->data<value)
    {
        return search(root->right,value);
    }
    else
    {
        return search(root->left,value);
    }
}

struct bstnode* insertNode(struct bstnode *root,int value)
{
    if(root==NULL)
    {
        return createnode(value);
    }
    if (root->data>value)
    {
        root->left = insertNode(root->left,value);
    }
    else
    {
        root->right = insertNode(root->right,value);
    }
    return root;
}

struct bstnode* successor(struct bstnode* root)
{
    if (root==NULL)
    {
        return NULL;
    }
    else if(root->left!=NULL)
    {
        return successor(root->left);
    }
    return root;
}

struct bstnode* deletion(struct bstnode* root,int value)
{
    if (root==NULL)
    {
        return NULL;
    }
    if(root->data<value)
    {
        root->right=deletion(root->right,value);
    }
    else if(root->data>value)
    {
        root->left=deletion(root->left,value);
    }
    else
    {
        if (root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left==NULL || root->right==NULL)
        {
            if (root->left==NULL)
            {
                temp=root->right;
                free(root);
                return temp;
            }
            else
            {
                temp=root->left;
                free(root);
                return temp;  
            }
        }
        else
        {
            temp=successor(root->right);
            root->data=temp->data;
            root->right=deletion(root->right,temp->data);
        }
    }
    return root;
}

struct bstnode* inordertrav(struct bstnode *root)
{
    if (root==NULL)
    {
        return NULL;
    }
    inordertrav(root->left);
    printf("%d ",root->data);
    inordertrav(root->right);
    return root;
}

struct bstnode* preordertrav(struct bstnode *root)
{
    if (root==NULL)
    {
        return NULL;
    }
    printf("%d ",root->data);
    preordertrav(root->left);
    preordertrav(root->right);
    return root;
}

struct bstnode* postordertrav(struct bstnode *root)
{
    if (root==NULL)
    {
        return NULL;
    }
    postordertrav(root->left);
    postordertrav(root->right);
    printf("%d ",root->data);
    return root;
}

int main()
{
    int choice,val;
    do
    {
        printf("\n1.search\n2.inserion\n3.deletion\n4.post order traversal\n5.inorder traversal\n6.pre order traversal\n7.exit\nEnter the operation no : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("enter the value to search : ");
            scanf("%d",&val);
            search(root,val);
            break;
        case 2:
            printf("enter the value to insert : ");
            scanf("%d",&val);
            root=insertNode(root,val);
            break;
        case 3:
            printf("enter the value to delete : ");
            scanf("%d",&val);
            root=deletion(root,val);
            break;
        case 4:
            postordertrav(root);
            break;
        case 5:
            inordertrav(root);
            break;
        case 6:
            preordertrav(root);
            break;
        case 7:
            return 0;
        default:
            printf("enter valid operation : ");
            break;
        }
    } while (1);
}