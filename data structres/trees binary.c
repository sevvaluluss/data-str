#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
	//struct node *parents; // bazen lazim olabiliyor
};

typedef struct node BTREE;


BTREE *new_node(int x){
	
	BTREE *p=(BTREE*)malloc(sizeof(BTREE));
	
	p->data=x;
	p->left=NULL;
	p->right=NULL;
	
	return p;
	
}

 BTREE *insert(BTREE *root,int x){
 		
 		if(root==NULL)
 			root=new_node(x);
 			
 		else{
 			
 			if(x<root->data)
 				root->left=insert(root->left,x);
 			
 			else
 				root->right=insert(root->right,x);
		 }
	return root;
		 
 }


void inorder(BTREE *root){ //bastan siralama
	
	if(root!=NULL){
		
		inorder(root->left);
		printf("%5d",root->data);
		inorder(root->right);
		
	}
}

int countnode(BTREE *root){
	if(root==NULL){
		return 0;	
	}
	else 
		return 1 + countnode(root->left) + countnode(root->right);
}

int child(BTREE *root){ // parent sayiyor
	
	if(root==NULL)
		return 0;
	else if(root->left!=NULL || root->right!=NULL)
		return 1 + child(root->left) + child(root->right);
	
} 
static int count = 0;
int countnodes(BTREE *root)
{
    if(root != NULL)
    {
        countnodes(root->left);
        count++;
        countnodes(root->right);
    }
    return count;
}

int main(){
	
	BTREE *myroot=NULL;
	int i;
	
	printf("add to value to tree: ");
	scanf("%d",&i);
			
		while(i!=-1){
			
			myroot=insert(myroot,i);
			scanf("%d",&i);
		}
	inorder(myroot); // cause of the write values
	
	printf("\n cccccc %d",countnodes(myroot));
	printf("\n aaa %d",child(myroot));
	printf("\n node sayisi %d",countnode(myroot));
}


