#include <stdio.h>
#include <stdlib.h>
#define abs(x) x<0?(-x):x
//data item
typedef struct info{
    int num;
}Data;
//structure for tree node
typedef struct node{
    Data data;
    struct node* left;
    struct node* right;
    struct node* parent;
    int balance;
}Node,*NodePtr;

//--------------------------------------------------------------
//------------------MAIN ROUTINE--------------------------------
//--------------------------------------------------------------
int main()
{
    int n;
    int INORDER_WALK(NodePtr);
    NodePtr BST_INSERT(NodePtr&,int),AVL_INSERT(NodePtr&,int);
    int UPDATE_BALANCE(NodePtr);
    NodePtr root = NULL,x;
    printf("Enter The Elements in BST(to terminate press 0)\n");
    if(scanf("%d",&n)!=1) n=0;
    while(n!=0){
        AVL_INSERT(root,n);
        printf("%d\n",UPDATE_BALANCE(root));
        if(scanf("%d",&n)!=1) n=0;
    }
    INORDER_WALK(root);
    return 0;
}

//creating node
NodePtr initNode(int n){
    NodePtr temp = (NodePtr)malloc(sizeof(Node));
    temp->left = temp->right = temp->parent = NULL;
    temp->balance = 0;
    (temp->data).num = n;
}
//BST-INSERT METHOD-----
NodePtr BST_INSERT(NodePtr& root,int key){
    NodePtr initNode(int);
    NodePtr curr,prev,temp;
    prev=NULL; curr = root;
    while(curr!=NULL){
	prev = curr;
	if(key<=curr->data.num){
            curr = curr->left;
	}
	else curr = curr->right;
    }
    temp = initNode(key);
    temp->parent = prev;
    if(prev==NULL) root = temp;
    else if(key<=prev->data.num)
       prev->left = temp;
    else prev->right = temp;
    return temp;
}
//inorder walk
int INORDER_WALK(NodePtr root){
    if(root!=NULL){
  	INORDER_WALK(root->left);
	printf("%d\t",root->data.num);
	INORDER_WALK(root->right);
    }
    return 0;
}
//preorder walk
int PREORDER_WALK(NodePtr root){
    if(root!=NULL){
        printf("%d\t",root->data.num);
        PREORDER_WALK(root->left);
        PREORDER_WALK(root->right);
    }
    return 0;
}
//left-rotate
NodePtr LEFT_ROTATE(NodePtr& root,NodePtr& x){
    if(x->right==NULL||x==NULL) return NULL;
    NodePtr y = x->right;
    x->right = y->left;
    if(y->left!=NULL)
       y->left->parent = x;
    y->parent = x->parent;
    if(x->parent==NULL)
      root = y;
    else if(x==x->parent->left)
      x->parent->left = y;
    else x->parent->right = y;
    y->left = x;
    x->parent = y;
    return root;
}
//right-rotate
/*NodePtr RIGHT_ROTATE(NodePtr& root){
    if(root!=NULL && root->left!=NULL){
      NodePtr x = root;
      NodePtr y = root->left;
      y->parent = x->parent;
      if(x->parent!=NULL && x->parent->left==x)
         x->parent->left = y;
      if(x->parent!=NULL && x->parent->right==x)
         x->parent->right = y;
      NodePtr T1 = y->right;
      y->right = x;
      x->parent = y;
      x->left = T1;
      if(T1!=NULL)
         T1->parent = x;
      return y;
    }
    return NULL;
}*/
NodePtr RIGHT_ROTATE(NodePtr& root,NodePtr& x){
    if(x==NULL) return NULL;
    if(x->left==NULL) return NULL;
    NodePtr y = x->left;
    x->left = y->right;
    if(y->right!=NULL)
       y->right->parent = x;
    y->parent = x->parent;
    if(x->parent==NULL)
      root = y;
    else if(x==x->parent->left)
      x->parent->left = y;
    else x->parent->right = y;
    y->right = x;
    x->parent = y;
    return root;
}

//update balance
int UPDATE_BALANCE(NodePtr root){
    int TreeHeight(NodePtr);
    int leftHeight,rightHeight;
    if(root==NULL)
       return 0;
    leftHeight = TreeHeight(root->left);
    rightHeight = TreeHeight(root->right);
    return rightHeight-leftHeight;
}
int TreeHeight(NodePtr root){
    int leftHeight,rightHeight;
    if(root==NULL)
       return 0;
    leftHeight = TreeHeight(root->left);
    rightHeight = TreeHeight(root->right);
    if(leftHeight>rightHeight)
       return leftHeight+1;
    else return rightHeight+1;
}   
//AVL_INSERT as sir gave the algorithm
NodePtr AVL_INSERT(NodePtr& root,int key){
    NodePtr BST_INSERT(NodePtr&,int);
    NodePtr x = BST_INSERT(root,key);
    NodePtr y;
    x = x->parent;
    while(x!=NULL){
       x->balance = UPDATE_BALANCE(x);
       if(x->balance>1){
         y = x->right;
         if(y->balance==1 || y->balance==0)
            LEFT_ROTATE(root,x);
         else{
              RIGHT_ROTATE(root,y);
              LEFT_ROTATE(root,x);
         }
       }
       else if(x->balance<-1){
          y = x->left;
          if(y->balance==-1 || y->balance==0)
             RIGHT_ROTATE(root,x);
          else{
               LEFT_ROTATE(root,y);
               RIGHT_ROTATE(root,x);
          }
       }
       x = x->parent;
    }
    return x;
}
