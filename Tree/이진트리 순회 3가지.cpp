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

	Node* l = root->left;
	l = (Node*)malloc(sizeof(Node));
	l->value = 2;
	l->left = NULL;
	l->right = NULL;


	Node* r = root->right;
	r = (Node*)malloc(sizeof(Node));
	r->value = 5;

	r->left = (Node*)malloc(sizeof(Node));
	r->left->value = 8;
	r->left->right = NULL;

	r->left->left = (Node*)malloc(sizeof(Node));
	r->left->left->value = 1;
	r->left->left->left = NULL;
	r->left->left->right = NULL;

	r->right = (Node*)malloc(sizeof(Node));
	r->right->value = 4;
	r->right->left = NULL;
	r->right ->right = NULL;

	preorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	inorder(root);
}