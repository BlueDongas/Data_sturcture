#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
   int data;
   struct node *left, *right;
   int height;
}node;

int height(node *T)
{
   int leftH, rightH;
   if (T == NULL)
      return(0);
   if (T->left == NULL)
      leftH = 0;
   else
      leftH = 1 + T->left->height;
   if (T->right == NULL)
      rightH = 0;
   else
      rightH = 1 + T->right->height;
   if (leftH>rightH)
      return(leftH);
   return(rightH);
}

node * R_Rotate(node *x)
{
   node *y;
   y = x->left;
   x->left = y->right;
   y->right = x;
   x->height = height(x);
   y->height = height(y);
   return(y);
}

node * L_Rotate(node *x)
{
   node *y;
   y = x->right;
   x->right = y->left;
   y->left = x;
   x->height = height(x);
   y->height = height(y);
   return(y);
}

node * RR(node *T)
{
   T = L_Rotate(T);
   return(T);
}

node * LL(node *T)
{
   T = R_Rotate(T);
   return(T);
}

node * LR(node *T)
{
   T->left = L_Rotate(T->left);
   T = R_Rotate(T);
   return(T);
}

node * RL(node *T)
{
   T->right = R_Rotate(T->right);
   T = L_Rotate(T);
   return(T);
}

int GetBF(node *T)
{
   int leftH, rightH;
   if (T == NULL)
      return(0);

   if (T->left == NULL)
      leftH = 0;
   else
      leftH = 1 + T->left->height;

   if (T->right == NULL)
      rightH = 0;
   else
      rightH = 1 + T->right->height;

   return(leftH - rightH);
}

node * Insert(node *root, int data)
{
   if (root == NULL)
   {
      root = (node*)malloc(sizeof(node));
      root->data = data;
      root->left = NULL;
      root->right = NULL;
   }
   else
      if (data > root->data)
      {
         root->right = Insert(root->right, data);
         if (GetBF(root) == -2)
            if (data>root->right->data)
               root = RR(root);
            else
               root = RL(root);
      }
      else
         if (data<root->data)
         {
            root->left = Insert(root->left, data);
            if (GetBF(root) == 2)
               if (data < root->left->data)
                  root = LL(root);
               else
                  root = LR(root);
         }
   root->height = height(root);
   return(root);
}

node * Delete(node *root, int data)
{
   node *p;
   if (root == NULL)
   {
      return NULL;
   }
   else
      if (data > root->data)
      {
         root->right = Delete(root->right, data);
         if (GetBF(root) == 2)
            if (GetBF(root->left) >= 0)
               root = LL(root);
            else
               root = LR(root);
      }
      else
         if (data<root->data)
         {
            root->left = Delete(root->left, data);
            if (GetBF(root) == -2)
               if (GetBF(root->right) <= 0)
                  root = RR(root);
               else
                  root = RL(root);
         }
         else
         {
            if (root->right != NULL)
            {
               p = root->right;
               while (p->left != NULL)
                  p = p->left;
               root->data = p->data;
               root->right = Delete(root->right, p->data);
               if (GetBF(root) == 2)
                  if (GetBF(root->left) >= 0)
                     root = LL(root);
                  else
                     root = LR(root);
            }
            else
               return(root->left);
         }
   root->height = height(root);
   return(root);
}
void Preorder(node *root)
{
   if (root != NULL)
   {
      printf("%d ", root->data);
      Preorder(root->left);
      Preorder(root->right);
   }
}

int main()
{
   node *root = NULL;
   int num = 0,deletenum = 0;
   

   printf("Insert node to AVL tree:\n");
   while (1) 
   {
       char n[10] = "";
       gets(n);
       if (n[0] == '\0')
       {
           break;
       }
       else
       {  
           num = atoi(n);
           root = Insert(root, num);
       }
   }
   printf("\nPreorder traversal of the constructed AVL tree is\n");
   Preorder(root);

   printf("\nPreorder traversal after deletion of ");
   scanf("%d", &deletenum);
   root = Delete(root, deletenum);
   Preorder(root);

   return 0;
}