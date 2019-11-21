#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *left, *right;
};


struct node *root;

struct node* insert(struct node* r, int data);

int main()
{
	root = NULL;
	int n, v, i;
	char in_name[80];
   	FILE *in_file;
    	printf("Enter file name:\n");
	scanf("%s", in_name);
	in_file = fopen(in_name, "r");
	if (in_file == NULL)
	{             
		printf("Can't open %s for reading.\n", in_name);
    		return 0;
    	}	
    	else
    	{
		while (fscanf(in_file, "%d",&v) ==1)
        	root = insert(root, v);
    	}
	fclose(in_file);

	printf("printing numbers in ascending order:\n");
	intrav(root);
	return 0;
}

struct node* insert(struct node* r, int data)
{
	if(r==NULL) // BST is not created created
	{
        	r = (struct node*) malloc(sizeof(struct node)); // create a new node
        	r->value = data;  // insert data to new node
        	// make left and right childs empty
        	r->left = NULL;   
        	r->right = NULL;
    	}
    	// if the data is less than node value then we must put this in left sub-tree
	else if(data==r->value)
		;
    	else if(data < r->value)
        	r->left = insert(r->left, data);
    	
	// else this will be in the right subtree
    	else
	       	r->right = insert(r->right, data);
    	 return r;

}

intrav(struct node* r)
{
	if(r!=NULL)
	{
		intrav(r->left);		//Traverse left subtree.
		printf("%d\n",r->value);	 //Visit the root.
		intrav(r->right);		//Traverse right subtree.
	}
}
