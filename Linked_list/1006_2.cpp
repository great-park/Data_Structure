#include <stdio.h>
#include <stdlib.h>

//앞에 typedef
typedef struct node {
	int value;
	struct node* next;
} Node; //뒤에 별칭

int main() {
	Node a, b, c;
	a.value = 5; a.next = &b;
	b.value = 7; b.next = &c;
	c.value = 6; c.next = NULL;


	Node* f = (Node*)malloc(sizeof(Node));
	Node* g = (Node*)malloc(sizeof(Node));
	Node* h = (Node*)malloc(sizeof(Node));

	f->value = 5; f->next = g;
	g->value = 7; g->next = h;
	h->value = 6; h->next = NULL;

	printf("a,b,c = %d %d %d\n", a.value, b.value, c.value);
	printf("f,g,h = %d %d %d\n", f->value, g->value, h->value);
}