//implementing binary mirror on privately built tree
#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode{
   int data;
   struct treeNode* left;
   struct treeNode* right;
}TreeNode,*TreeNodePtr;

int main()
{
   int n;
   char* string;
   TreeNodePtr buildTree(TreeNodePtr,char*),initNode(),myTree,printTree(TreeNodePtr);
   TreeNodePtr mirrorMe(TreeNodePtr);
   printf("\nEnter The Elements of binary tree in the below described PREORDER format:\a\nfor NULL press '@' "); 
   printf("For example:1. A@@ is a tree with only root node A and\a\n'@' is the symbol for NULL\a\n");
   printf("2. A@B@C@@ is a tree with A as root, A->left NULL, A->right B,B->left NULL,\nB->right C,C has no children.\a\n");
   printf("Note: we use integer Tree Here. --------DON'T ENTER FALSE INPUT-------\a\n");
   printf("Input Convenction from Book: Advanced Topics in C by Neol Kalicharan\n\n");
   scanf("%s",string);
   myTree = buildTree(myTree,string);
   printf("The Entered Tree is:\a\n");
   printTree(myTree);
   printf("\n\nThe Mirrorred Tree is:\a\n");
   myTree = mirrorMe(myTree);
   printTree(myTree);
   printf("\a\n");
   printf("\n\n2.1 Time complexity in terms of n for mirrorring is: \n");
   printf("    T(n) = c + T(n-k-1)+T(k), where k is number of nodes in either subtree and 'c' constant\n");
   printf("    On solving the above formula in worst case(k=0) or Binary Tree is linked list: we get T(n) = O(n)\n");
   printf("2.2 If the tree given is perfectly Binary Tree(k~n/2): we get the above formula as: T(n) = c+ (constant)T(n/2)\n");
   printf("    We get T(n) = O(lg n).....So It is possible to do the above operation in O(lg n) time.\n");
   printf("2.3 The common thing between all the traversals is all of them use recursion,\n");
   printf("    All the traversals take worst case O(n) time.\n");
   printf("2.4 INORDER effects of mirrorring: print the elements of binary tree in reversed order.\n");
   printf("    PREORDER effect: pattern printed is changed\n");
   printf("    POSTORDER effect: pattern printed is changed\n\n");
   return 0;
}

TreeNodePtr initNode(){
   TreeNodePtr temp = (TreeNodePtr)malloc(sizeof(TreeNode));
   //TreeNodePtr right = (TreeNodePtr)malloc(sizeof(TreeNode));
   temp->left = NULL;
   temp->right = NULL;
   return temp;
}

TreeNodePtr buildTree(TreeNodePtr root,char* str){
   TreeNodePtr initNode();
   if(*str=='@')
     return NULL;
   root = initNode();
   root->data = *str-'0';
   str++;
   root->left = buildTree(root->left,str);
   str++;
   root->right = buildTree(root->right,str);
   return root;
}
TreeNodePtr printTree(TreeNodePtr root){
   if(root==NULL){
      printf("@");
      return NULL;
   }
   else printf("%d",root->data);
   printTree(root->left);
   printTree(root->right);
} 
//function for mirrorring the built tree
TreeNodePtr mirrorMe(TreeNodePtr root){                           //T(number of nodes in the tree)      
   TreeNodePtr temp;
   if(root->left==NULL && root->right== NULL)                     //constant k time
       return root;
   else{//returning root for safety purposes
          temp = root->left;
          root->left = root->right;                               //constant k time
          root->right = temp;
          if(root->left!=NULL)
             root->left = mirrorMe(root->left);                   //k*T(nodes in left sub tree)
          if(root->right!=NULL)
             root->right = mirrorMe(root->right);                 //k*T(nodes in right sub tree)
          return root;
   }
}
