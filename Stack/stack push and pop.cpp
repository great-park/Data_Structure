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

int main()
{
    while (true) {
        printf("����� �Է����ּ��� 1) XX    2) �߰�    3) ���� \n");
        int x;
        scanf("%d", &x);
        if (x == 1) {
            // ���� ����
        }
        else if (x == 2) {
            printf("�߰��Ϸ��� ���� �Է��ϼ��� : ");
            int value;
            scanf("%d", &value);

            push_list(value);
        }
        else if (x == 3) {
            int x = pop_list(); // ������ ������ ���� �����ϸ鼭 x�� ����
            if (x == -1) continue;
            printf("������ �� : %d\n", x);
        }
    }

    return 0;
}