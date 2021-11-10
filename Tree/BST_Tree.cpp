#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int height;
	int value;
	struct node* parent;
	struct node* left, * right;
} Node;
// BST 삽입 

Node* search(Node* node, int value)
{
	if (node->left != NULL && value < node->value) {
		return search(node->left, value);
	}
	if (node->right != NULL && value > node->value) {
		return search(node->right, value);
	}
	return node;
}

Node* root = NULL;

int max_height(Node* left, Node* right)
{
	int height = 0;
	if (left != NULL && height < left->height) {
		height = left->height;
	}
	if (right != NULL && height < right->height) {
		height = right->height;
	}
	return height;
}

void insert_value(int value)
{
	if (root == NULL) {
		root = (Node*)malloc(sizeof(Node));
		root->height = 1;
		root->parent = NULL;
		root->value = value;
		root->left = NULL;
		root->right = NULL;
		return;
	}
	
	Node* s = search(root, value);
	if (value < s->value) {
		s->left = (Node*)malloc(sizeof(Node));
		s->left->value = value;
		s->left->left = NULL;
		s->left->right = NULL;
		s->left->height = 1;
		s->left->parent = s;
		
		for (Node* t = s; t != NULL; t = t->parent) {
			t->height = max_height(t->left, t->right) + 1;
		}
	}
	else if(value > s->value) {
		s->right = (Node*)malloc(sizeof(Node));
		s->right->value = value;
		s->right->left = NULL;
		s->right->right = NULL;
		s->right->height = 1;
		s->right->parent = s;

		for (Node* t = s; t != NULL; t = t->parent) {
			t->height = max_height(t->left, t->right) + 1;
		}
	}
	else {
		printf("동일 값 삽입!!\n");
		return;
	}
}

int main()
{
	while (true) {
		printf("\n동작을 선택하세요. 1) 삽입   2) 삭제   3) 검색\n");
		int x;
		scanf("%d", &x);

		printf("\n숫자를 입력하세요");
		int v;
		scanf("%d", &v);
		if (x == 1) { // 삽입
			insert_value(v);
		}
		else if (x == 2) {

		}
		else if (x == 3) {
			search(root, v);
		}
	}
}