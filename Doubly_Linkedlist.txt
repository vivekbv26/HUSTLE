#include<stdio.h>
#include<stdlib.h>
// create structure node
struct node
{
	int data;
	struct node *llink;
	struct node *rlink;
};

//initialize variables

struct node *start = NULL,*temp,*ptr,*cur,*newnode;


// create insert_end
void insert_end()
{
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter data:");
	scanf("%d",&newnode->data);
	newnode->rlink = newnode->llink = NULL;
	// 1st node
	if(start==NULL)
	{
		start = newnode;
	}
	else // many nodes
	{
		ptr = start;
// comming to the last node
		while(ptr->rlink!=NULL)
			ptr = ptr->rlink;
		// creating link
		ptr->rlink = newnode;
		newnode->llink = ptr;				
		
	}
}

//insert_beg
void insert_beg()
{
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter data:");
	scanf("%d",&newnode->data);
	newnode->rlink = newnode->llink = NULL;

	if(start==NULL)
	{
		start = newnode;
	}
	else	
	{
		
		newnode->rlink = start;
		start->llink = newnode;
		start = newnode;
	}

}

//insert at any node
void insert_pos()
{
	int count = 0,pos;
	ptr = start;
	while(ptr!=NULL) 	// counting nodes
	{
		count++;
		ptr = ptr->rlink;
	}
	printf("\nEnter Position:");
	scanf("%d",&pos);
	//1st pos	
	if(pos == 1)
		insert_beg();
	else if(pos == count +1)	//ending insertion
		insert_end();
	else if(pos>1 && pos<=count)	//general case
	{
		int i;
		ptr = start;
		for(i=1;i<pos-1;i++)	//transversing to one previous node than pos
		{
			ptr = ptr->rlink;
		}
		newnode = (struct node*)malloc(sizeof(struct node));
		printf("\nEnter data:");
		scanf("%d",&newnode->data);
newnode->rlink = newnode->llink = NULL;
		//linking
		newnode ->rlink = ptr->rlink;
		newnode->llink = ptr;
		ptr->rlink = newnode;
		newnode->rlink->llink = newnode;
		
	}
	else
	{
		printf("invalid position");
	}
}
//delete beg
void delete_beg()
{
	//no node present
	if(start == NULL)
		printf("List is Empty");
	else if(start->rlink == NULL)	//only 1 node present
	{
		free(start);
		start = NULL;
	}
	else	//general case
	{
		ptr = start;
		start = start->rlink;
		start->llink = NULL;
		free(ptr);
}
}
//delete end
void delete_end()
{
	//no node present
	if(start == NULL)
		printf("List is Empty");
	else if(start->rlink == NULL)	//only 1 node present
	{
		free(start);
		start = NULL;
	}
	else	//general case
	{
		ptr = start;
		while(ptr->rlink!=NULL) //traversing to last node
		{	cur = ptr;
			ptr = ptr->rlink;
		}
		cur = ptr->llink;
		cur->rlink = NULL;
		free(ptr);
		
	}
	
}

//delte any position
void delete_pos()
{
	int count = 0,pos;
	ptr = start;
	while(ptr!=NULL) 	// counting nodes
	{
		count++;
		ptr = ptr->rlink;
	}
	printf("\nEnter Position:");
	scanf("%d",&pos);
	if(pos == 1)
		delete_beg();
	else if(pos == count)
		delete_end();
	else if(pos>1 && pos<count)
	{
		int i;
		ptr = start;
		for(i=1;i<pos;i++)
			ptr = ptr->rlink;

		ptr->llink->rlink = ptr->rlink;
		ptr->rlink->llink = ptr->llink;
		free(ptr);
	}
	else
		printf("INVALID POSITION!");
}
// create display
void display()
{
	// NO NODE
	if(start==NULL)
		printf("LINK IS NOT THERE");
	else	// NODE PRESENT
	{	
		ptr = start;
		while(ptr->rlink != NULL)
		{
			printf("%d<-->",ptr->data);
			ptr = ptr->rlink;
		}
		printf("%d<-->\n",ptr->data);	//for last element
		
	}
}
//main fn
void main()
{
	int choice;
	printf("\t\tDOUBLY LINK LIST\n");
	while(1)
	{	printf("1.Insert at the end\n2.Display\n3.Insert At beg\n4.Delete at beg\n5.Delete at end\n6.Insert at any Position\n7.Delete at any position\n8.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: insert_end();
				break;
			case 2: display();
		break;
			case 3: insert_beg();
				break;
			case 4: delete_beg();
				break;
			case 5: delete_end();
				break;
			case 6: insert_pos();
				break;
			case 7: delete_pos();
				break;
			case 8: exit(0);
				break;			
			default: printf("INVALID INPUT");
		}
	}
}


