# include<stdio.h>
# include<conio.h>
# include<malloc.h>

struct node
{
	struct node* next;
	int data;
	struct node* prev;
};

struct node* start = NULL;
struct node* create_ll(struct node *);
struct node* display(struct node *);

struct node* insert_beg(struct node*);
struct node* insert_end(struct node*);
struct node* insert_before(struct node*);
struct node* insert_after(struct node*);

struct node* delete_beg(struct node*);
struct node* delete_end(struct node*);
struct node* delete_before(struct node*);
struct node* delete_after(struct node*);
struct node* delete_list(struct node*);

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
		case 3 :
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

		}
	}
}




