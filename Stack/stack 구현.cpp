# include<stdio.h>
# include<stdlib.h>
int top=0; // �迭��
int stack[1000];

typedef struct node {
	int val;
	struct node* prev;
} Node;
Node* stacktop = NULL;

void push_array(int value);
int pop_arrary();

void push_list(int value);
int pop_list();



int main()
{
	while (true) {
		printf("��� �Է�. 1) xx   2)�߰�   3)����\n");
		int x;
		scanf("%d",&x);

		if (x == 1) {
			break;
		}
		else if (x == 2) {
			printf("�߰��Ϸ��� ���� �Է� :");
			int value;
			scanf("%d",&value);
			push_array(value);
			push_list(value);
		}
		else if (x == 3) {
			int x = pop_arrary();//������ ������ ���� �����ϸ鼭 x�� ����
			int y = pop_list();
			printf("�迭 ������ �� : %d\n",&x);
			printf("���Ḯ��Ʈ ������ �� : %d\n", &y);
		}
	}
}

void push_array(int value) {
	//������ ����־ ok, ������ ������ ������� ����ó��
	if (top == 1000) {
		printf("overflow");
	}
	else {
		stack[top] = value;
		top += 1;
	}
}

int pop_arrary() {
	//������ ��������� ����ó��
	if (top == 0) {
		printf("underflow");
		return 0;
	}
	else {
		int temp = stack[top];
		stack[top] = NULL;
		top -= 1;
		return temp;
	}
}

void push_list(int value) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->val = value;

	//���� ���������
	if (stacktop == NULL) {
		new_node->prev = NULL;
		stacktop = new_node;
	}
	else {
		new_node->prev = stacktop;
		stacktop = new_node;
	}
}


//ȣ���� �ڸ����� ������ int���� �޾Ƽ� ȣ��� �Լ������� ����ó�� �����̴��� ���� return?
int pop_list() {
	//��������� ����ó��
	if (stacktop == NULL) {
		printf("underflow");
		return 0; //??
	}
	else {
		int temp = stacktop->val;
		Node* ptr = stacktop;
		stacktop = stacktop->prev;
		free(ptr);
		return temp;
	}
}