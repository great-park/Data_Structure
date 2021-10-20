#include <stdio.h>
#include <stdlib.h>

int top = 0;
int stack[1000];  // stack[0] ~ stack[999]

typedef struct node {
    int value;
    struct node* prev;
} Node;

void push_array(int value) // stack 배열에 value를 집어넣어주는 함수
{
    if (top == 1000) {
        printf("오버플로우 발생했다\n");
    }
    else {
        stack[top++] = value;
    }
}


int pop_array()
{
    if (top == 0) {
        printf("언더플로우 발생했다\n");
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

            push_list(value);
        }
        else if (x == 3) {
            int x = pop_list(); // 스택의 마지막 값을 삭제하면서 x에 저장
            if (x == -1) continue;
            printf("삭제된 값 : %d\n", x);
        }
    }

    return 0;
}