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
struct node *findmin(struct node *root){
    while(root->left != NULL)
        root=root->left;
    return root;
}
struct node *deletenode(struct node *root,int value)
    {
    if(root==NULL)
    {
        printf("value not found\n");
        return root;
    }
    if(value < root->data)
        root->left=deletenode(root->left,value);
    else if(value > root->data)
        root->right=deletenode(root->right,value);
    else{
        //zero children
        if(root->left == NULL && root->right ==NULL)
        {
        free(root);
        printf("Delete node with zero children\n");
            return NULL;
        }
        //only right child
        else if(root->left == NULL)
        {
            struct node *temp=root->right;
            free(root);
            printf("Delete node with one child\n");
            return temp;
        }
            //only left child
        else if(root->right ==NULL)
        {
            struct node *temp=root->left;
            free(root);
            printf("Delete node with one child\n");
        return temp;
        }
    else{
        struct node *largest=findmin(root->right);
        root->data=largest->data;
        root->right=deletenode(root->right,largest->data);
        printf("Delete node with two children\n");
        }
    }
        return root;
}
int main()
{
    struct node *root=NULL;
    int n,value,deletevalue,i;
    printf("Enter number of values: ");
    scanf("%d",&n);
    printf("Enter %d unique integer values: \n",n);
    for(i=0;i<n;i++)
        {
            scanf("%d",&value);
            root=insert(root,value);
        }
    printf("\nInorder traversal before deletion: ");
    inorder(root);
    printf("\nEnter value to delete: ");
    scanf("%d",&deletevalue);
    root=deletenode(root,deletevalue);
    printf("Inorder traversal after deletion: ");
    inorder(root);
    return 0;
}