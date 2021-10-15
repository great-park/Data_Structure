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
node* create_ll(struct node *);
node* display(struct node *);

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
			start = insert_before(start);
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
	} while (optiom != 12);
	getch();
	return 0;
}

node* create_ll(struct node* start)
{
	node *new_node, * ptr;
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
		printf("\n enter the data : ");
		scanf("%d", &num); // 반복. -1 입력시 종료
	}
	return start;  // start를 리턴하는 이유? -> 이후 삽입이나 삭제 등 작업을 이어가기 위해서.
				  // start는 처음 만든 node를 가리킨다.
}

node* distplay(node* start)
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
	printf("\n enter the data : ");
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
	printf("\n enter the data : ");
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



