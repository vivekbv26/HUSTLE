#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
struct node *start=NULL,*temp,*ptr,*newnode;
int n;

void create_list()
{

		newnode=(struct node*)malloc(sizeof(struct node));
		printf("\n Enter the data ");
		scanf("%d", &(newnode->data));
		newnode->link=NULL;

		if (start==NULL)
		{		
			start=newnode;
		}
		else
		{
			ptr=start;
			while(ptr->link!=NULL)
			{	
				ptr=ptr->link;		

			}
			ptr->link=newnode;
	
		}
	
}


void insert_beg()
{
	newnode =(struct node*)malloc(sizeof(struct node));
	printf("\n Enter the data ");
	scanf("%d",&(newnode->data));
	newnode->link=NULL;
	if (start==NULL)
	{
		start=newnode;
	}
	else
	{
		newnode->link=start;
		start=newnode;
	}

	
}

void location_based()
{	int count=0,pos,i;
	
	ptr=start;
	while (ptr!=NULL)
	{
		count++;
		ptr=ptr->link;
	}
	printf("enter the position");
	scanf("%d",&pos);
	if (pos==1)
	{
	insert_beg();
	}
	else
	if (pos>1 && pos<=count)
	{	
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\n Enter the data ");
	scanf("%d",&(newnode->data));
	newnode->link=NULL;	
		ptr=start;
		for(i=1;i<pos-1;i++)
		{
			ptr=ptr->link;
		}
	newnode->link=ptr->link;
	ptr->link=newnode;
	}
	else 
	if (pos==count+1)
	create_list();
	else
	printf("position wrong");
}
		

void del_end()
{	if (start==NULL)
	{
		printf("the list is empty");
	}
	else
	if (start->link == NULL) 
	{	
		ptr = start;
		start = NULL;
	}
else
{
		ptr=start;
		while (ptr->link!=NULL)
		{	
			temp=ptr;
			ptr= ptr->link;
			
		}
		temp->link=NULL;
		free(ptr);
 }
}

void del_beg()
{	if (start==NULL)
	{
		printf("the list is empty");
	}
	else
	if (start->link == NULL)
		start = NULL;
	else
	{
		temp=start;
		start=start->link;
		free(temp);
		
	}
}

void loc_based_del()
{	int count=0,pos,i;
	
	ptr=start;
	while (ptr!=NULL)
	{
		count++;
		ptr=ptr->link;
	}
	printf("enter the position");
	scanf("%d",&pos);
	if (pos==1)
	{
	del_beg();
	}
	else
	if (pos>1 && pos<=count)
	{		
		ptr=start;
		for(i=1;i<pos;i++)
		{	temp=ptr;
			ptr=ptr->link;
		}
	temp->link=ptr->link;
	}
	else 
	printf("position wrong");
}

void display()
{
	if (start==NULL)
	{
		printf("List is empty");
	}
	else
	{
		ptr=start;
		while (ptr!=NULL)
		{	
			printf("\t %d --> ",ptr->data);
			ptr=ptr->link;		

		}
	}
}

void main()
{
	int ch;
	
	while (1)
	{
		printf("\n Menu \n 1. Insert_end  \n 2. Insert_beg  \n 3. Display  \n 4.Location based \n \n 5. Delete_end  6. Delete_beg 7. Loc_based_del");
		scanf("%d",&ch);
		switch(ch)
		{ 
			case 1: create_list();
				break;
			case 2: insert_beg();
				break;
			case 3: display();
				break;
			case 4: location_based();
				break;
			case 5: del_end();
				break;
			case 6: del_beg();
				break;
			case 7: loc_based_del();
				break;
		}
	}
}



