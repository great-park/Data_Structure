#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int value;
	struct node* left, * right;
} Node;

//전위순회 ULR
void preorder(Node* v) {
	if (v == NULL)return;

	printf("%d ", v->value);
	preorder(v->left);
	preorder(v->right);

	
}

//중위순회 LUR
void inorder(Node* v) {
	if (v == NULL)return;
	inorder(v->left);
	printf("%d ", v->value);
	inorder(v->right);
}

//후위순회 LRU
void postorder(Node* v) {
	if (v == NULL)return;
	postorder(v->left);
	postorder(v->right);
	printf("%d ", v->value);
}

int main() 
{
	Node* root = (Node*)malloc(sizeof(Node));
	root->value = 3;

	root->left = (Node*)malloc(sizeof(Node));
	root->left->value = 2;
	root->left->left = NULL;
	root->left->right = NULL;


	root->right = (Node*)malloc(sizeof(Node));
	root->right->value = 5;

	root->right->left = (Node*)malloc(sizeof(Node));
	root->right->left->value = 8;
	root->right->left->right = NULL;

	root->right->left->left = (Node*)malloc(sizeof(Node));
	root->right->left->left->value = 1;
	root->right->left->left->left = NULL;
	root->right->left->left->right = NULL;

	root->right->right = (Node*)malloc(sizeof(Node));
	root->right->right->value = 4;
	root->right->right->left = NULL;
	root->right->right ->right = NULL;

	preorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	inorder(root);
}
