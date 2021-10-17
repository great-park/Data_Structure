# include<stdio.h>
# include<stdlib.h>

typedef struct node {
	int value;
	struct node* next;
	struct node* prev;
} Node;

typedef struct list {
	Node* first = NULL;
	Node* last = NULL;
} List;

List* create_list()
{
	List* new_list = (List*)malloc(sizeof(List));
	new_list->first = new_list->last = NULL;
	return new_list;
}

void print_list(List* l)
{
	for (Node* t = l->first; t != NULL; t = t->next) {
		printf("%d ->", t->value);
	}
	printf("\n");
}

void push_last(List *l, int value)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	//newNode는 지역변수라서 호출끝나면 삭제, malloc으로 할당한 메모리 공간은 유지
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

int main()
{
	List* random= create_list();

	push_last(random, 7);
	push_last(random, 8);
	push_last(random, 9);
	print_list(random);

	return 0;
}