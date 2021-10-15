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
		printf("\n 12: ������");
		printf("\n �޴� �Է� : ");
		scanf("%d", &option);

		switch (option)
		{
		case 1:
			start = create_ll(start);
			printf("doubly linked list ����");
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
			printf("doubly linked list ����");
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
	printf("\n -1 �Է� �� ����");
	printf("\n ���Ḯ��Ʈ ��� �Է� : ");
	scanf("%d", &num);

	while (num != -1)
	{
		if (start == NULL) // ó��
		{
			//������ ��������
			new_node = (node*)malloc(sizeof(node));
			new_node->prev = NULL;
			new_node->data = num;
			new_node->next = NULL;

			start = new_node; //new_node�� �ּҸ� ����Ų��. start�� node����ü ������
		}
		else //����
		{
			ptr = start; // new_node <<--- start <<--- ptr �����
			new_node = (node*)malloc(sizeof(node));
			new_node->data = num;

			while (ptr->next != NULL)
				ptr = ptr->next; //�۾� �� ���� ���� ����Ʈ���� �� ���� �ִ� node�� ����Ű�� ��
			ptr->next = new_node; // �� ���� ����
			new_node->prev = ptr; // ���� ���⵵ ����
			new_node->next = NULL; // ll�� �� �� ��
		}
		printf("\n enter the data : ");
		scanf("%d", &num); // �ݺ�. -1 �Է½� ����
	}
	return start;  // start�� �����ϴ� ����? -> ���� �����̳� ���� �� �۾��� �̾�� ���ؼ�.
				  // start�� ó�� ���� node�� ����Ų��.
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

	//���� start�� ���Ḯ��Ʈ�� ù node�� ����Ű�� �ִ�.
	start->prev = new_node; // �� ���� ����
	new_node->next = start;
	new_node->prev = NULL;
	start = new_node; //��� ���� node�� ù ��尡 �� 
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
	//�� �� ã�ư���
	ptr = start; // ù ��� <<--- start <<--- ptr
	while (ptr->next != NULL)
		ptr = ptr->next; //�۾� �� ���� ���Ḯ��Ʈ�� �� �� ��带 ����Ű�� ��
	ptr->next = new_node;
	new_node->prev = ptr;
	new_node->next = NULL;
	return start;
}



