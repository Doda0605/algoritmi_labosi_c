#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

struct node
{
   char d;
   struct node *left;
   struct node *right;
};

typedef struct node NODE;
typedef NODE *BINARY_TREE;

BINARY_TREE newnode(void);
BINARY_TREE init_node(char d, BINARY_TREE p1, BINARY_TREE p2);
BINARY_TREE create_tree(char a[], int i, int size);
void preorder(BINARY_TREE root);
void inorder(BINARY_TREE root);
void postorder(BINARY_TREE root);

int main()
{
   char arr[ARRAY_SIZE];
   BINARY_TREE root;
   int lop;

   printf("Enter %d characters: ", ARRAY_SIZE);
   for (lop = 0; lop < ARRAY_SIZE; lop++)
   {
      scanf("%c", &arr[lop]);
      fflush(stdin);
   }
   root = create_tree(arr, 0, ARRAY_SIZE);
   assert(root != NULL);
   printf("\n");
   printf("Inorder:\t");
   inorder(root);
   printf("\n");
   printf("Preorder:\t");
   preorder(root);
   printf("\n");
   printf("Postorder:\t");
   postorder(root);
   printf("\n");

   return 0;
}

BINARY_TREE new_node()
{
   return ((BINARY_TREE)malloc(sizeof(NODE)));
}

BINARY_TREE init_node(char d1, BINARY_TREE p1, BINARY_TREE p2)
{
   BINARY_TREE temp;

   temp = new_node();
   temp->d = d1;
   temp->left = p1;
   temp->right = p2;
   return temp;
}

BINARY_TREE create_tree(char a[], int i, int size)
{
   if (i >= size)
   {
      return NULL;
   }
   else
   {
      return (init_node(a[i], create_tree(a, 2 * i + 1, size), create_tree(a, 2 * i + 2, size)));
   }
}

void preorder(BINARY_TREE root)
{
   if (root != NULL)
   {
      printf("%c ", root->d);
      preorder(root->left);
      preorder(root->right);
   }
}

void inorder(BINARY_TREE root)
{
   if (root != NULL)
   {
      inorder(root->left);
      printf("%c ", root->d);
      inorder(root->right);
   }
}

void postorder(BINARY_TREE root)
{
   if (root != NULL)
   {
      postorder(root->left);
      postorder(root->right);
      printf("%c ", root->d);
   }
}
