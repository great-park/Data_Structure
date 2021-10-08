#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int value;
	struct node* next;
} Node;

int main() {
	Node* front = (Node*)malloc(sizeof(Node));
	Node* last = front;
	front->value = -1;
	front->next = NULL;

	while (true) {
		int x;
		scanf("%d", &x);
		if (x == 0)break;

		last->value = x;
		last->next = (Node*)malloc(sizeof(Node));
		last = last->next;

		last->value = -1;
		last->next = NULL;
	}

	//for (Node* t = front; t != last; t = t->next) {
	//	printf("%d ", t->value);
	//}
	//printf("\n");
	Node* t = front;
	while (t->next != NULL) {
		printf("%d ", t->value);
		t = t->next;
	}
}
