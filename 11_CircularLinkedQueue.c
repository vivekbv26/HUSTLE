#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *last = NULL;

void insert()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("enter the data\n");
    scanf("%d", &temp->data);
    temp -> link = NULL;

    if(last == NULL)
    {
        last = temp;
        last->link = last;
    }
    else
    {
        temp->link = last->link;
        last->link = temp;
        last = temp;
    }
}


void delete()
{
    struct node *p ;

    if(last == NULL)
        printf("empty\n");

    else if(last->link == last)
    {
        last = NULL;
        free(last);
    }
    else
    {   p = last->link;
        last->link = p->link;
        p->link = NULL;
        free(p);
    }
}


void display()
{
    struct node *temp;

    if(last == NULL)
        printf("empty\n");
    else
    {
        temp = last->link;
        while(temp != last)
        {
            printf("%d-->",temp->data);
            temp = temp->link;
        }
        printf("%d-->", temp->data);
        printf("\n");
    }
}


void main()
{
    int ch;
    while(1)
    {
      printf("\nEnter your choice \n1.insert a node\n2.delete a node\n3.Display \n4.exit : ");
      scanf("%d", &ch);
        switch(ch)
        {
            case 1 : insert();
                     break;
            case 2 : delete();
                     break;
            case 3 : display();
                     break;

            case 9 : exit(0);
        }
    }
}
