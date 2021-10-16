# include<stdio.h>
# include<conio.h>
# include<malloc.h>

typedef struct node
{
	struct node* next;
	int data;
	struct node* prev;
} node;

node* start = NULL;
node* create_ll(struct node*);
node* display(struct node*);

node* insert_beg(struct node*);
node* insert_end(struct node*);
node* insert_before(struct node*);
node* insert_after(struct node*);

node* delete_beg(struct node*);
node* delete_end(struct node*);
node* delete_before(struct node*);
node* delete_after(struct node*);
node* delete_list(struct node*);

int main()
{
	int option;

	do
	{
		printf("\n\n *****Main Menu*****");
		printf("\n 1 : create a list");
		printf("\n 2 : display the list");
		printf("\n 3 : add a node at the beginning");
		printf("\n 4: add a node at end");
		printf("\n 5 : add a node before a given node");
		printf("\n 6 : add a node after a given node");
		printf("\n 7 : delete a node from the beginning");
		printf("\n 8 : delete a node from the end");
		printf("\n 9 : delete a node before a given node");
		printf("\n 10 : delete a node after a given node");
		printf("\n 11 : delete the entire list");
		printf("\n 12: 나가기");
		printf("\n 메뉴 입력 : ");
		scanf("%d", &option);

		switch (option)
		{
		case 1:
			start = create_ll(start);
			printf("doubly linked list 생성");
			break;
		case 2:
			start = display(start);
			break;
		case 3:
			start = insert_beg(start);
			break;
		case 4:
			start = insert_end(start);
			break;
		case 5:
			start = insert_before(start);
			break;
		case 6:
			start = insert_after(start);
			break;
		case 7:
			start = delete_beg(start);
			break;
		case 8:
			start = delete_end(start);
			break;
		case 9:
			start = delete_before(start);
			break;
		case 10:
			start = delete_after(start);
			break;
		case 11:
			start = delete_list(start);
			printf("doubly linked list 삭제");
			break;
		}
	} while (option != 12);
	getch();
	return 0;
}

node* create_ll(struct node* start)
{
	node* new_node, * ptr;
	int num;
	printf("\n -1 입력 시 종료");
	printf("\n 연결리스트 요소 입력 : ");
	scanf("%d", &num);

	while (num != -1)
	{
		if (start == NULL) // 처음
		{
			//위에서 선언했음
			new_node = (node*)malloc(sizeof(node));
			new_node->prev = NULL;
			new_node->data = num;
			new_node->next = NULL;

			start = new_node; //new_node의 주소를 가리킨다. start도 node구조체 포인터
		}
		else //이후
		{
			ptr = start; // new_node <<--- start <<--- ptr 요상태
			new_node = (node*)malloc(sizeof(node));
			new_node->data = num;

			while (ptr->next != NULL)
				ptr = ptr->next; //작업 후 기존 연결 리스트에서 맨 끝에 있는 node를 가리키게 됨
			ptr->next = new_node; // 한 방향 연결
			new_node->prev = ptr; // 남은 방향도 연결
			new_node->next = NULL; // ll의 한 쪽 끝
		}
		printf("\n 연결리스트 요소 입력 : ");
		scanf("%d", &num); // 반복. -1 입력시 종료
	}
	return start;  // start를 리턴하는 이유? -> 이후 삽입이나 삭제 등 작업을 이어가기 위해서.
				  // start는 처음 만든 node를 가리킨다.
}

node* display(node* start)
{
	node* ptr;
	ptr = start;
	while (ptr != NULL)
	{
		printf("\t %d", ptr->data);
		ptr = ptr->next;
	}
	return start;
}

node* insert_beg(node* start)
{
	node* new_node;
	int num;
	printf("\n 연결리스트 요소 입력 : ");
	scanf("%d", &num);
	new_node = (node*)malloc(sizeof(node));
	new_node->data = num;

	//현재 start는 연결리스트의 첫 node를 가리키고 있다.
	start->prev = new_node; // 한 방향 연결
	new_node->next = start;
	new_node->prev = NULL;
	start = new_node; //방금 만든 node가 첫 노드가 됨 
	return start;
}

node* insert_end(node* start)
{
	node* ptr, * new_node;
	int num;
	printf("\n 연결리스트 요소 입력 : ");
	scanf("%d", &num);
	new_node = (node*)malloc(sizeof(node));
	new_node->data = num;
	//맨 끝 찾아가기
	ptr = start; // 첫 노드 <<--- start <<--- ptr
	while (ptr->next != NULL)
		ptr = ptr->next; //작업 후 기존 연결리스트의 맨 끝 노드를 가리키게 됨
	ptr->next = new_node;
	new_node->prev = ptr;
	new_node->next = NULL;
	return start;
}

node* insert_before(node* start)
{
	node* new_node, * ptr;
	int num, val;
	printf("\n 연결리스트 요소 입력 : ");
	scanf("%d", &num);
	printf("삽입할 위치 앞 노드의 값 입력 : ");
	scanf("%d", &val);
	new_node = (node*)malloc(sizeof(node));
	new_node->data = num;

	//삽입위치 찾아가기
	ptr = start;
	while (ptr->data != val)
		ptr = ptr->next; // val이 담긴 node 위치로 이동
	new_node->next = ptr; // new_node에서 한 방향 연결 
	new_node->prev = ptr->prev; // new_node에서 나머지 방향 연결, 현 상황 :  a <- new_node -> b
	ptr->prev->next = new_node;  // a-> new_node 추가
	ptr->prev = new_node; // new_node <-b 추가  doubly linked list 노드 추가 완료.
	return start;
}

node* insert_after(node* start)
{
	node* new_node, * ptr;
	int num, val;
	printf("\n 연결리스트 요소 입력 : ");
	scanf("%d", &num);
	printf("\n 삽일할 위치의 이전 노드 값 입력");
	scanf("%d", &val);
	new_node = (node*)malloc(sizeof(node));
	new_node->data = num;
	//val위치로
	ptr = start;
	while (ptr->data != val)
		ptr = ptr->next;
	new_node->prev = ptr; // a <- new_node
	new_node->next = ptr->next; // a <- new_node -> b
	ptr->next->prev = new_node; // new_node <- b 추가
	ptr->next = new_node; // a -> new_node 추가  doubly linked list 노드 추가 완료
	return start;
}

node* delete_beg(node* start)
{
	node* ptr;
	ptr = start;
	start = start->next; //start 위치 다음으로 옮기기
	start->prev = NULL;
	free(ptr);
	return start;
}

node* delete_end(node* start)
{
	node* ptr;
	ptr = start;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->prev->next = NULL; // 마지막 노드로의 연결 끊기
	free(ptr);
	return start;
}

node* delete_after(node* start)
{
	node* ptr, * temp;
	int val;
	printf("\n 삭제할 노드의 다음 노드의 값을 입력");
	scanf("%d", &val);
	ptr = start;
	while (ptr->data != val)
		ptr = ptr->next; // 작업 후 ptr은 val을 가지는 노드를 가리킴
	temp = ptr->next; // ptr -> temp 연결
	ptr->next = temp->next;
	temp->next->prev = ptr;
	free(temp);
	return start;
}

node* delete_before(node* start)
{
	node* ptr, * temp;
	int val;
	printf("\n 삭제할 위치의 이전 노드 값 입력");
	scanf("%d", &val);
	ptr = start;
	while (ptr->data != val)
		ptr = ptr->next;  //ptr이 val 위치로
	temp = ptr->prev;
	if (temp == start)
		start = delete_beg(start); //delete_beg 함수 호출해서 맨 앞 노드 삭제하고 start를 위치 조정
	else
	{
		ptr->prev = temp->prev; // ??
		temp->prev->next = ptr;
	}
	free(temp);
	return start;
}

node* delete_list(node* start)
{
	while (start != NULL)
		start = delete_beg(start);
	return start;
}