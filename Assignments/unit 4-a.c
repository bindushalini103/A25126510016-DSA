#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=NULL;
struct node *createnode(int value)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct node *insert(struct node *root,int value)
{
    if(root == NULL)
        return createnode(value);
    if(value < root->data)
        root->left=insert(root->left,value);
    else if(value > root->data)
        root->right=insert(root->right,value);
    else
        printf("Duplicate value not allowed\n");
    return root;
}
void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
int search(struct node *root,int value)
{
    if(root == NULL)
        return 0;
    if(root->data == value)
        return 1;
    if(value < root->data)
        return search(root->left,value);
    else 
        return search(root->right,value);
    }
int main()
{
    struct node *root=NULL;
    int n,value,searchvalue,i;
    printf("Enter number of values: ");
    scanf("%d",&n);
    printf("Enter %d unique integer values: \n",n);
    for(i=0;i<n;i++)
        {
            scanf("%d",&value);
            root=insert(root,value);
        }
    printf("\nInorder traversal: ");
    inorder(root);
    printf("\nPreorder traversal: ");
    preorder(root);
    printf("\nPostorder traversal: ");
    postorder(root);
    printf("\nEnter value to search: ");
    scanf("%d",&searchvalue);
    if(search(root,searchvalue))
        printf("%d exists in the binary search tree \n",searchvalue);
    else
        printf("%d does not exist in the binary search tree\n");
    return 0;
}