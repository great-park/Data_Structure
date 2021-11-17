#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	int height;
	int value;
	struct node* left;
	struct node* right;
	struct node* parent;
}Node;

Node* root = NULL;

Node* search_value(Node* n, int value) //n�� value�� �Լ��� value�� ������ n�� ����, ��ã���� null
{
	if (== NULL || n->value == value)
		return n;

	if (n->value > value) {
		return search_value(n->left, value);
	}
	else {
		return search_value(n->right, value);
	}

}

//���� - ���� ������,  ���� ��������� �׳� �ְ�, �� ��������� �� �� �� ������

void insert_node(Node* n, Node* newNode)
{
	if (n->value < newNode->value)
	{
		if (n->right == NULL) {
			n->right = newNode;
			newNode->parent = n;
		}
		else {
			insert_node(n->right, newNode);
		}
	}
	else {
		if (n->left == NULL) {
			n->left = newNode;
			newNode->parent = n;
		}
		else {
			insert_node(n->left, newNode);
		}
	}
}

Node* remove_node(Node* target) // n Node�� ����� �Լ�
{
	// 1. ������带 ����(�ڽ� == 0)				
	// 2. �� �ʸ� �ڽ��� �ִ� ���γ��(�ڽ� == 1)�� ����
	// 3. �� �ʿ� �ڽ��� �ִ� ���γ��(�ڽ� == 2)�� ����


	//  target�� root�� ���� ���� ó���ؾߵ�
	if (target->left == NULL && target->right == NULL) { // case 1.
		//�θ���� ���赵 ����� ��
		if (target->parent->left == target) {
			target->parent->left = NULL;
		}
		else if (target->parent->right == target) {
			target->parent->right = NULL;
		}
	}
	else if (target->left != NULL && target->right != NULL) { //case 3.
		//me �������� ������ ����Ʈ������ left�� �� ����,  left-sided = me���ٴ� ũ�� right�������� ���� ����,   me�� ��ȯ -> case 1, 2

		Node* left_sided = target->right;
		while (left_sided->left != NULL) {
			left_sided - left_sided->left;
		}

		remove_node(left_sided); // case 1, 2 ó��
		if (target->parent->left == target) {
			target->parent->left = left_sided;
		}
		else if (target->parent->right == target) {
			target->parent->right = left_sided;
		}
		left_sided->parent = target->parent;


		target->left->parent = left_sided;
		left_sided->left = target->right;

		target->right->parent = left_sided;
		left_sided->right = target->right;
	}
	else { //case 2.  //�ڽ��� 1���� ��� ���Ḯ��Ʈ �����ϵ��� ������ ����� �ڽĳ��� �θ��带 �����ϸ� ��
		Node* oneChild;
		if (target->left != NULL) {
			oneChild = target->left;
		}
		else {
			oneChild = target->right;
		}
		if (target->parent->left == target) {
			target->parent->left = oneChild;
			oneChild->parent = target->parent;
		}
		else if (target->parent->right == target) {
			target->parent->right = oneChild;
			oneChild->parent = target->parent;
		}
	}
	free(target);
}

Node* remove_value(Node* n, int value)  // value�� ����� �Լ�
{
	Node* target = search_value(root, value);
}