// This program takes a long integer as an input from the user separate each digit from the integer then
// insert them one by one into a doubly linked list them check if the no is a palindrome
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};
struct node *start = NULL;

void ispalindrome()
{
    struct node *ptr, *p;
    ptr=start;
    while(ptr->rlink != NULL)
    {
        ptr=ptr->rlink;
    }
    p=start;
    while(p != ptr && ptr != p->llink)
    {
        if(p->data != ptr->data)
            break;

        p=p->rlink;
        ptr=ptr->llink;

    }
    if(p->data != ptr->data)
        printf("it is not a pallindrome\n");
    else
        printf("it is a pallindrome\n");


}
void insertend(int data)
{
    struct node *temp ;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->llink = NULL;
    temp->rlink = NULL;

    if(start == NULL)
        start = temp;
    else
    {
        struct node *p;
        p=start;
        while(p->rlink!=NULL)
            p=p->rlink;
        temp->llink=p;
        p->rlink=temp;
    }
}

void delete_all()
{
  start = NULL;
}

void display()
{
    if(start == NULL)
        printf("empty\n");
    else
    {
        struct node *p;
        p=start;
        while(p->rlink!=NULL)
        {
            p=p->rlink;
        }
        while(p != NULL)
        {
            printf("%d-->",p->data);
            p=p->llink;
        }
        printf("\n");
    }
}

void main()
{
    long int a;
    printf("\n Enter a no. (try to make it large): ");
    scanf("%d",&a);
    int temp;
    while(a>0)
    {
        insertend(a%10);
        a = a/10;
    }
    printf("\nThe Doubly linked list representation of the no is: \n");
    display();
    int ch;
    printf("\n Do you want to check if it is a palindrome ?? press 1 for yes/press any other key to enter another no. : \n ");
    scanf("%d",&ch);
    switch (ch) {
      case 1: ispalindrome();
              break;
      default: delete_all();
               main();
    }
}
