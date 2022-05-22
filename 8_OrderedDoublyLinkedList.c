#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};
struct node *start = NULL;



void OrderedInsert()
{
  struct node *temp ;
  temp = (struct node*)malloc(sizeof(struct node));
  printf("enter the data\n");
  scanf("%d", &temp->data);
  temp->llink=NULL;
  temp->rlink=NULL;

  if(start == NULL)
      start = temp;

  else if(start->rlink == NULL || start->data > temp->data)
  {
      if(temp->data > start->data)
      {
          start->rlink = temp;
          temp->llink = temp;
      }
      else
      {
          start->llink = temp;
          temp->rlink = start;
          start = temp;
      }
  }
  else
  {
      struct node*p=start;
      while(p->rlink!=NULL && p->data <temp->data)
      {
          p=p->rlink;
      }

      if(p->rlink ==NULL && p->data<temp->data)
      {
          p->rlink=temp;
          temp->llink=p;
      }
      else
      {
        temp->rlink=p;
        p->llink->rlink=temp;
        temp->llink=p->llink;
        p->llink=temp;
      }
    }
}
void display()
{
    if(start == NULL)
        printf("empty\n");
    else
    {
        struct node *p;
        p=start;
        while(p!=NULL)
        {
            printf("%d-->",p->data);
            p=p->rlink;
        }
        printf("\n");
    }
}

void main()
{
    int ch;
    while(1)
    {
        printf("1.insert in order\n2.display\n3.exit");
        printf("\n Enter the choice : \n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 : OrderedInsert();
                     break;
            case 2 : display();
                     break;
            case 3 : exit(0);
        }
    }
}
