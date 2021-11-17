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

Node* search_value(Node* n, int value) //n의 value가 함수의 value와 같으면 n을 리턴, 못찾으면 null
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

//삽입 - 왼쪽 오른쪽,  이후 비어있으면 그냥 넣고, 안 비어있으면 한 번 더 내려감

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

Node* remove_node(Node* target) // n Node를 지우는 함수
{
	// 1. 리프노드를 삭제(자식 == 0)				
	// 2. 한 쪽만 자식이 있는 내부노드(자식 == 1)를 삭제
	// 3. 양 쪽에 자식이 있는 내부노드(자식 == 2)를 삭제


	//  target이 root인 경우는 따로 처리해야됨
	if (target->left == NULL && target->right == NULL) { // case 1.
		//부모와의 관계도 끊어야 됨
		if (target->parent->left == target) {
			target->parent->left = NULL;
		}
		else if (target->parent->right == target) {
			target->parent->right = NULL;
		}
	}
	else if (target->left != NULL && target->right != NULL) { //case 3.
		//me 기준으로 오른쪽 서브트리에서 left로 쭉 가기,  left-sided = me보다는 크고 right내에서는 가장 작음,   me와 교환 -> case 1, 2

		Node* left_sided = target->right;
		while (left_sided->left != NULL) {
			left_sided - left_sided->left;
		}

		remove_node(left_sided); // case 1, 2 처리
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
	else { //case 2.  //자식이 1개일 경우 연결리스트 삭제하듯이 삭제할 노드의 자식노드와 부모노드를 연결하면 됨
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

Node* remove_value(Node* n, int value)  // value를 지우는 함수
{
	Node* target = search_value(root, value);
}