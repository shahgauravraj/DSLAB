#include<stdio.h>
#include<malloc.h>
#define size 3
int count=0;
/*node structure*/
struct node
{
  int info;
  struct node *link;
};
typedef struct node* NODE;
NODE first=NULL;
/*getnode()*/
NODE getnode()
{
  NODE temp;
  temp=(NODE)malloc(sizeof(struct node));
  if(temp==NULL)
  {
    printf("allocation failed\n");
    return;
  }
  return temp;
}
/*push function()*/
void push(int item)
{
  NODE temp;
  temp=getnode();
  temp->info=item;
  temp->link=NULL;
  if(count==size)
  {
    printf("STACK OVERFLOW\n");
    return;
  }
  /*empty stack*/
  if(first==NULL)
    first=temp;
  else
  {
    temp->link=first;
    first=temp;
  }
  count++;
}
/*pop function()*/
void pop()
{
  NODE temp=first;
  if(count==0)
  {
    printf("STACK UNDERFLOW\n");
    return;
  }
  
    printf("item deleted = %d\n",first->info);
   	first=first->link;
	free(temp);
  count--;
}
/*display()*/
void display()
{ 
  NODE cur=first;
  if(first==NULL)
  {
    printf("STACK EMPTY\n");
    return;
  }
  printf("stack contents\n");
  while(cur!=NULL)
  {
    printf("%d\t",cur->info);
    cur=cur->link;
  }
}
void main()
{
  int choice,data;
  printf("_ _ _ _ _MENU_ _ _ _ _\n");
  printf("1.PUSH\t2.POP\t3.DISPLAY\n");
  for(;;)
  {
    printf("\nenter the choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1: printf("enter the element to be pushed\n");
              scanf("%d",&data);
              push(data);
              break;
      case 2: pop();
              break;
      case 3: display();
              break;
      default: return;
    }
  }}
