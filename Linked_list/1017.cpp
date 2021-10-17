#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node* next;
	struct node* prev;
} Node;

typedef struct list {
	Node* first;
	Node* last;
} List;

List* create_list() {
	List* newList = (List*)malloc(sizeof(List));
	newList->first = newList->last = NULL;
	return newList;
}

void print_list(List *l)
{
	for (Node* t = l->first; t != NULL; t = t->next) {
		printf("%d->", t->value);
	}
	printf("\n");
}

Node* search_value(List* l, int value)
{
	for (Node* t = l->first; t != NULL; t = t->next) {
		if (t->value == value) {
			return t;
		}
	}
	return NULL;
}

void push_last(List *l, int value)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = NULL;
	newNode->prev = l->last;

	if (l->last == NULL) {
		l->first = l->last = newNode;
	}
	else {
		l->last->next = newNode;
		l->last = newNode;
	}
}

// search 값을 찾아서 그 다음에 value를 삽입해준다
// push_next(l, 7, 6) -> 7 값 뒤에 6을 삽입한다
void push_next(List* l, int search, int value)
{
	Node* ptr = search_value(l, search);
	if (ptr == NULL) {
		printf("위치를 찾을 수 없습니다!\n");
		return;
	}

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->value = value;
	if (ptr == l->last) {
		newNode->next = ptr->next;  // *  == 1
		newNode->prev = ptr;		// *  == 2
		ptr->next = newNode;
		l->last = newNode;
	}
	else {
		newNode->next = ptr->next;	// 1
		newNode->prev = ptr;		// 2
		ptr->next->prev = newNode;	// 3
		ptr->next = newNode;		// 4
	}
}

// push_prev(l, 9, 2) -> 9 값 앞에 2를 삽입한다
void push_prev(List* l, int search, int value);

void remove_value(List* l, int search)
{
	Node* ptr = search_value(l, search);
	if (ptr == NULL) {
		printf("위치를 찾을 수 없습니다!\n");
		return;
	}
	
	if (ptr == l->first && ptr == l->last) {
		l->first = l->last = NULL;
		free(ptr);
	}
	else if (ptr == l->last) {
		ptr->prev->next = NULL;
		l->last = ptr->prev;
		free(ptr);
	}
	else if (ptr == l->first) {
		ptr->next->prev = NULL;
		l->first = ptr->next;
		free(ptr);
	}
	else {
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
		free(ptr);
	}
}

int main()
{
	List* random = create_list();

	push_last(random, 7);
	push_last(random, 9);
	push_last(random, 2);
	print_list(random);
	remove_value(random, 9);
	print_list(random);
	return 0;
}