#include<stdio.h>
#include<stdlib.h>

struct dll
{
	int num;
	struct dll *left,*right;
};

typedef struct dll NODE;

NODE *head=NULL;

void main()
{
int rpt=1;
int ch,data;

	printf("Enter integest to create doubly linked list\n");
	scanf("%d",&data);

do{
	create(data);
	scanf("%d",&data); 
	
}while(data!=999);
show();	
	while(rpt)
	{
	printf("\nSelect a doubly linked list operation from the followings:\n");
	printf("1:Inset new node to the left of the node whos key value is read as an input\n");
	printf("2:Delete the node of a given data\n3:Display\n4:EXIT\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: insert();
		break;
		case 2: del();
		break;
		case 3: show();
		break;
		case 4: printf("END\n"); exit(0);
		break;
		default: printf("please enter correct choice\n");
	}	
	
	printf(" \nTo continue press non zero digit:\n");
	scanf("%d",&rpt);
	}
}
//end of main()---------------------------------------

create(int d)
{
	NODE *temp;
	temp=(NODE *)malloc(sizeof(NODE));

	temp->num=d;	
	temp->left = temp->right=NULL;

	if(head==NULL)
	{
		head=temp;return;
	}	
	
	temp->right=head;
	head->left=temp;
	head=temp;
	
	return;
}
//---------------------------------------------------------
insert()
{
	NODE *new,*temp,*temp2;
	int key,flag=0;
	new=(NODE *)malloc(sizeof(NODE));

	printf("Enter an integer of new node\n");
	scanf("%d",&new->num);

	new->left = new->right=NULL;

	if(head==NULL)
	{
		head=new;return;
	}	
	
	printf("enter the key value of existing node of the list\n");
	scanf("%d",&key);
		
	if(key==head->num)
	{
		head->left=new;
		new->right=head;
		head=new;
	}

	else
	{
		for(temp=head->right;temp!=NULL;temp=temp->right)
		{
			if(temp->num==key)
			{
				flag=1;
				break;
			}
		}

		if(flag==1)
		{	
			temp2=temp->left;
			
			new->left=temp2;
			new->right=temp;
			
			temp2->right=new;
			temp->left=new;
			
			
		}
		else
			printf("give proper input\n");

	}
return;
}	

//---end of insert()---------------------------------------
del()
{
	NODE *temp;
	int flag=0,key;

	if(head==NULL)
	{
		printf("empty\n");
		return;
	}

	printf("enter the key value of existing node of the list\n");
	scanf("%d",&key);

	if(key==head->num)
	{
		temp=head;
		head=head->right;
		
		if(head!=NULL)
			head->left=NULL;
		free(temp);
	}
	
	else
	{
		
		for(temp=head->right;temp!=NULL;temp=temp->right)
		
			if(temp->num==key)
			{
				flag=1;
				break;
			}
		
		if(flag==1)
		{	
			if(temp->right==NULL) //deleting last node
				temp->left->right=NULL;			
			else
			{
				temp->left->right=temp->right;
				temp->right->left=temp->left;
			}
			printf("Node with key value %d has been deleted\n",key);
			free(temp);
		}
		else
			printf("Node not found in the list\n");

	}

return;
}

//-end of delete()----------------------------------------

show()
{
	NODE *temp;

	if(head==NULL)
		printf("EMPTY\n");
	else
	{
		printf("Dougly linked list is\nSTART<---->");

		for(temp=head;temp!=NULL;temp=temp->right)
			printf("%d<---->",temp->num);
		
		printf("END\n");
	}
return;
}
