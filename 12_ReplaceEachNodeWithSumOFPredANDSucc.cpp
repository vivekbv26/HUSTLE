#include<bits/stdc++.h>
#define COUNT 10
using namespace std;

typedef struct node
{
    int data;
    struct node *rch;
    struct node *lch;
}Node;
Node *root = NULL,*temp = NULL, *ptr,*parent;

int is_lch(Node *tree)
{
    int ch;
    printf("\n Do you want a lch child for %d, Press 1 for yes/any other key for no:",tree->data);
    scanf("%d",&ch);
    return(ch);
}
int is_rch(Node *tree)
{
    int ch;
    printf("\n Do you want a rch child for %d, Press 1 for yes/any other key for no:",tree->data);
    scanf("%d",&ch);
    return(ch);
}

void create(Node *tree)
{
    if(is_rch(tree)==1)
    {
       temp = (Node *)malloc(sizeof(Node));
       printf("\n Enter the data");
       scanf("%d",&temp->data);
       tree->rch = temp;
       create(temp);
    }
    else{
        tree->rch=NULL;
    }
    if(is_lch(tree)==1)
    {
       temp = (Node *)malloc(sizeof(Node));
       printf("\n Enter the data");
       scanf("%d",&temp->data);
       tree->lch = temp;
       create(temp);
    }
    else{
        tree->lch=NULL;
    }
}


void inorderStore( Node* root, vector <int> & arr)
{

    if (root == NULL)
    {
        return;
    }
    inorderStore(root->lch, arr);
    arr.push_back(root->data);
    inorderStore(root->rch, arr);
}

void replaceNode( Node* root, vector <int> arr, int* i)
{
    if (root == NULL)
    {
      return;
    }
    replaceNode(root->lch, arr, i);

    root->data = arr[*i - 1] + arr[*i + 1];

    ++*i;

    replaceNode(root->rch, arr, i);
}

void replaceNodeWrapper( Node* root)
{

    if (!root)
        return;

    vector<int> arr;
    arr.push_back(0);

    inorderStore(root, arr);

    arr.push_back(0);

    int i = 1;
    replaceNode(root, arr, &i);
}


void preorder(Node *tree)
{
    if(tree!=NULL)
    {
        printf("%d ",tree->data);
        preorder(tree->lch);
        preorder(tree->rch);
    }
}
void postorder(Node *tree)
{
    if(tree!=NULL)
    {
        postorder(tree->lch);
        postorder(tree->rch);
        printf("%d ",tree->data);
    }
}
void inorder(Node *tree)
{
    if(tree!=NULL)
    {
        inorder(tree->lch);
        printf("%d ",tree->data);
        inorder(tree->rch);
    }
}


void print2Dimensional(Node *root, int space)
{

    if (root == NULL)
        return;


    space += COUNT;

    print2Dimensional(root->rch, space);

    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    print2Dimensional(root->lch, space);
}


void print2D()
{
   print2Dimensional(root, 0);
}

int main()
{ int ch;
	  root = (Node *)malloc(sizeof(Node));
    printf("\n Enter the data for the root");
    scanf("%d",&root->data);
    root->lch = NULL;
    root->rch = NULL;

    create(root);
    while(1)
    {
        printf("\nDo you want to print the tree \n1. Inorder Traversal\n2.Preorder Traveral\n3.Postorder Traversal\n4.print in 2 dinmension:\n\t");
        scanf("%d",&ch);
        switch (ch) {
        case 1: inorder(root);
                break;
        case 2: preorder(root);
                break;
        case 3: postorder(root);
                break;
        case 4: print2D();
                break;
        }
        replaceNodeWrapper(root);
        printf("\n\t THE NODES HAVE NOW BEEN REPLACED WITH THE SUM OF THEIR INORDER PREDECESSOR AND SUCCESSOR \n");
    }

    return 0;

}
