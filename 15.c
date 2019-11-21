#include<stdio.h>
#include<malloc.h>
/*node structure*/
struct node
{
  int info;
  struct node *left;
  struct node *right;
};
typedef struct node* NODE;
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
/*creating a tree*/
NODE create(NODE root,int item)
{
  NODE temp,cur,suc;
  temp=getnode();
  temp->info=item;
  temp->left=NULL;
  temp->right=NULL;
  /*empty tree*/
  if(root==NULL)
  {
    root=temp;
    return root;
  }
  cur=root;
  suc=root;
  while(suc!=NULL)
  {
    cur=suc;
    if(item<cur->info)
      suc=suc->left;
    else
      suc=suc->right;
  }
  if(item<cur->info)
    cur->left=temp;
  else
    cur->right=temp;
  return root;
}
/*inodrer traversal*/
void inorder(NODE root)
{
  if(root!=NULL)
  {
    inorder(root->left);
    printf("%d\t",root->info);
    inorder(root->right);
  }
}
/*preorder traversal*/
void preorder(NODE root)
{
  if(root!=NULL)
  { 
    printf("%d\t",root->info);
    preorder(root->left);
    preorder(root->right);
  }
}
/*postorder traversal*/
void postorder(NODE root)
{
  if(root!=NULL)
  {
    postorder(root->right);
    postorder(root->left);
    printf("%d\t",root->info);
  }
}
void main()
{
  NODE root=NULL;
  int choice,item;
  printf("\n__________MENU_________\n");
  printf("1.CREATE \t 2.INORDER\t3.PREORDER\t4.POSTORDER\n");
  for(;;)
  {
    printf("\nenter choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 3: printf("preorder traversal\n");
              preorder(root);
              break;
      case 2: printf("inorder traversal\n");
              inorder(root);
              break;
      case 4: printf("postorder traversal\n");
              postorder(root);
              break;
      case 1: printf("enter item\n");
              scanf("%d",&item);
              root=create(root,item);
              break;
      default: return;
    }
  }
} 
