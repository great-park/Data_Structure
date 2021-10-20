#include <stdio.h>
#include <stdlib.h>

int head = 0, tail = 0;
int queue[1000];

typedef struct node {
    int value;
    struct node* next;
}Node;

Node* front = NULL, * rear = NULL;

void push_queue_arrary(int value)
{
	if (tail == 1000) {
		printf("overflow\n");
	}
	else {
		queue[tail++] = value;
	}
}

int pop_queue_arrary()
{
	if (head == tail) {
		printf("underflow\n");
	}
	else {
		return queue[head++ % 1000];
	}
}

int pop_queue_list()
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    if (rear!=NULL)rear->next = newNode;

    rear = newNode;
    if (front == NULL)front = newNode;
}

int pop_queue_list()
{
    if (front == NULL) {
        printf("underflow");
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
int main()
{
    while (true) {
        printf("명령을 입력해주세요 1) XX    2) 추가    3) 삭제 \n");
        int x;
        scanf("%d", &x);
        if (x == 1) {
            // 구현 안함
        }
        else if (x == 2) {
            printf("추가하려는 값을 입력하세요 : ");
            int value;
            scanf("%d", &value);

            push_queue_list(value);
        }
        else if (x == 3) {
            int x = pop_queue_list(); // 스택의 마지막 값을 삭제하면서 x에 저장
            if (x == -1) continue;
            printf("삭제된 값 : %d\n", x);
        }
    }

    return 0;
}