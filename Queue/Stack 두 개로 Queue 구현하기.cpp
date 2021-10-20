#include <stdio.h>
#include <stdlib.h>

int top = 0;
int stack[1000];  // stack[0] ~ stack[999]

typedef struct node {
	int value;
	struct node* prev;
} Node;

void push_array(int value) // stack �迭�� value�� ����־��ִ� �Լ�
{
	if (top == 1000) {
		printf("�����÷ο� �߻��ߴ�\n");
	}
	else {
		stack[top++] = value;
	}
}


int pop_array()
{
	if (top == 0) {
		printf("����÷ο� �߻��ߴ�\n");
		return -1;
	}
	else {
		top--;
		int value = stack[top];
		stack[top] = NULL;
		return value;
	}
}

Node* stackTop = NULL;
void push_list(int value)
{
	Node* t = (Node*)malloc(sizeof(Node));
	t->value = value;
	t->prev = stackTop;
	stackTop = t;
}

int pop_list()
{
	Node* t = stackTop;
	int v = t->value;
	stackTop = stackTop->prev;
	free(t);
	return v;
}
// s1: array, s2: list
// PUSH / POP ���� �ΰ��� �̿��ؼ� ť ó�� ���ư��� �Լ� �����
void PUSH(int value)
{
	push_array(value);
}

int POP()
{
	if (stackTop == NULL) {
		while (top > 0) {
			int t = pop_array();
			push_list(t);
		}
	}

	if (stackTop == NULL) {
		printf("����÷ο� �߻�!\n");
		return -1;
	}
	return pop_list();
}

int main()
{
	PUSH(3);
	PUSH(7);
	PUSH(2);
	printf("%d\n", POP());
	PUSH(5);
	PUSH(6);
	printf("%d\n", POP());
	printf("%d\n", POP());
	PUSH(1);
	printf("%d\n", POP());
	printf("%d\n", POP());
	printf("%d\n", POP());

	return 0;
}