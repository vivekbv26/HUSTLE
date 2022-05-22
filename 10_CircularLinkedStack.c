#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *last = NULL;

void push()
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



void pop()
{
    struct node *cur;

    if(last == NULL)
        printf("empty\n");

    else if(last->link == last)
    {
        last = NULL;
        free(last);
    }
    else
    {   cur = last->link;
        while(cur->link != last)
        {
            cur = cur->link;
        }
        cur->link = last->link;
        free(last);
        last = cur;
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
        printf("\nEnter your choice \n1.PUSh a node\n2.POP a node\n3.Display \n4.exit : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1 : push();
                     break;
            case 2 : pop();
                     break;
            case 3 : display();
                     break;
            case 9 : exit(0);
        }
    }
}
