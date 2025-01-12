#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int key)
{
    struct node *newnode;
    newnode = malloc(sizeof(struct node));
    newnode->data = key;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node *search(struct node *root, int key)
{
    if (root == NULL || root->data == key)
    {
        return root;
    }
    else if (root->data < key)
    {
        return search(root->right, key);
    }
    else
    {
        return search(root->left, key);
    }
}

struct node *insert(struct node *root, int key)
{
    if (root == NULL)
    {
        return createNode(key);
    }
    else if (root->data < key)
    {
        root->right = insert(root->right, key);
    }
    else
    {
        root->left = insert(root->left, key);
    }
    return root;
}

struct node *successor(struct node *root)
{
    if (root->left != NULL)
    {
        return successor(root->left);
    }
    else
    {
        return root;
    }
}

struct node *delete(struct node *root, int key)
{
    struct node *temp;
    if (root == NULL)
    {
        return root;
    }
    else if (root->data < key)
    {
        root->right = delete (root->right, key);
    }
    else if (root->data > key)
    {
        root->left = delete (root->left, key);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            return NULL;
        }
        else if (root->left == NULL || root->right == NULL)
        {
            if (root->left == NULL)
            {
                return root->right;
            }
            else
            {
                return root->left;
            }
        }
        else
        {
            temp = successor(root->right);
            root->data = temp->data;
            root->right = delete (root->right, temp->data);
            free(temp);
        }
    }
    return root;
}

void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d ", root->data);
    }
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf(" %d ", root->data);
        inOrder(root->right);
    }
}

void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf(" %d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

struct queue
{
    struct node *q[20];
    int front;
    int rear;
};

void bfs(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    struct queue *newq;
    struct node *temp;
    newq = malloc(sizeof(struct queue));
    newq->front = 0;
    newq->rear = 0;
    newq->q[newq->rear] = root;
    while (newq->front <= newq->rear)
    {
        temp = newq->q[newq->front];
        printf("%d ", temp->data);
        newq->front++;
        if (temp->left)
        {
            newq->rear++;
            newq->q[newq->rear] = temp->left;
        }
        if (temp->right)
        {
            newq->rear++;
            newq->q[newq->rear] = temp->right;
        }
    }
    free(newq);
}

void levelMax(struct node *root)
{
    if (root==NULL)
    {
        return;
    }
    
    int levelsize, max,level=0;
    struct queue *newq;
    struct node *temp;
    newq = malloc(sizeof(struct queue));
    newq->front = 0;
    newq->rear = 0;
    newq->q[newq->rear] = root;
    while (newq->front <= newq->rear)
    {
        levelsize = newq->rear - newq->front+1;
        max = INT_MIN;
        for (int i = 0; i < levelsize; i++)
        {
            temp = newq->q[newq->front++];
            if (temp->data>max)
            {
                max=temp->data;
            }
            if (temp->left)
            {
                newq->q[++newq->rear]=temp->left;
            }
            if (temp->right)
            {
                newq->q[++newq->rear]=temp->right;
            }    
        }
        printf("Largest at level %d : %d\n",level++, max);
    }
    free(newq);
}

int main()
{
    int c, value;
    struct node *root = NULL, *flag;
    do
    {
        printf("\n1.Search\n2.Insertion\n3.Deletion\n4.Indoredr Traversal\n5.Preorder Traversal\n6.Postorder Traversal\n7.Exit\n8.BFS\n9.Maximum at each level\nEnter the operation : ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter the value to search : ");
            scanf("%d", &value);
            flag = search(root, value);
            if (flag != NULL)
            {
                printf("Element Found !!!!");
            }
            else
            {
                printf("Element not found !!!");
            }
            break;
        case 2:
            printf("Enter the value to insert : ");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 3:
            printf("Enter the value to delete : ");
            scanf("%d", &value);
            root = delete (root, value);
            break;
        case 4:
            inOrder(root);
            break;
        case 5:
            preOrder(root);
            break;
        case 6:
            postOrder(root);
            break;
        case 7:
            break;
        case 8:
            bfs(root);
            break;
                    case 9:
            levelMax(root);
            break;
        default:
            printf("Enter valid operation!!!");
            break;
        }
    } while (c != 7);
}