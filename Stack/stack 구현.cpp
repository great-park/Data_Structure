# include<stdio.h>
# include<stdlib.h>
int top=0; // 배열용
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
		printf("명령 입력. 1) xx   2)추가   3)삭제\n");
		int x;
		scanf("%d",&x);

		if (x == 1) {
			break;
		}
		else if (x == 2) {
			printf("추가하려는 값을 입력 :");
			int value;
			scanf("%d",&value);
			push_array(value);
			push_list(value);
		}
		else if (x == 3) {
			int x = pop_arrary();//스택의 마지막 값을 삭제하면서 x에 저장
			int y = pop_list();
			printf("배열 삭제된 값 : %d\n",&x);
			printf("연결리스트 삭제된 값 : %d\n", &y);
		}
	}
}

void push_array(int value) {
	//스택이 비어있어도 ok, 스택이 꽉차서 못들어갈경우 예외처리
	if (top == 1000) {
		printf("overflow");
	}
	else {
		stack[top] = value;
		top += 1;
	}
}

int pop_arrary() {
	//스택이 비어있으면 예외처리
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

	//만약 비어있으면
	if (stacktop == NULL) {
		new_node->prev = NULL;
		stacktop = new_node;
	}
	else {
		new_node->prev = stacktop;
		stacktop = new_node;
	}
}


//호출한 자리에서 변수로 int형을 받아서 호출된 함수내에서 예외처리 구간이더라도 값을 return?
int pop_list() {
	//비어있으면 예외처리
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