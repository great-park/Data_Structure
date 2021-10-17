# include<stdio.h>
# include<stdlib.h>

typedef struct node {
	int value;
	struct node* next;
	struct node* prev;
} Node;

typedef struct list {
	Node* first=NULL;
	Node* last=NULL;
} List;

void print_list(List *l)
{
	for (Node* t = l->first; t != NULL; t = t->next) {
		printf("%d ->", t->value);
	}
	printf("\n");
}

void push_last(List *l, int value)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	//newNode�� ���������� ����, malloc���� �Ҵ��� �޸� ������ ����
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
	List random;
	
	push_last(&random, 7);
	push_last(&random, 8);
	push_last(&random, 9);

	return 0;
}