#include <stdio.h>
#include <stdlib.h>

int head = 0, tail = 0;
int queue[1000];

typedef struct node {
	int value;
	struct node* next;
}Node;

Node* front = NULL, * rear = NULL;

void push_queue_array(int value)
{
	if (tail == 1000) {
		printf("오버플로우 발생!\n");
	}
	else {
		queue[tail++ % 1000] = value;
	}
}

int pop_queue_array()
{
	if (head == tail) {    // Q1 왜 head랑 tail이 같을때 underflow인지.
		printf("언더플로우 발생!\n");
		return -1;
	}
	else {
		return queue[head++ % 1000];
	}
}

void push_queue_list(int value)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = NULL;
	
	if (rear != NULL) {
		rear->next = newNode;
	}

	rear = newNode;
	if (front == NULL) front = newNode;
}

int pop_queue_list()
{
	if (front == NULL) {
		printf("언더플로우 발생!\n");
		return -1;
	}
	else {
		Node* t = front;
		int value = front->value;
		free(t);
		front = front->next;
		return value;
	}
}

//main함수 생략 
