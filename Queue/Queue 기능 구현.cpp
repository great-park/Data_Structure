# include<stdio.h>
# include<conio.h>
# define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void insert(void)
{
	int num;
	printf("\n ť�� ������ ���� �Է� : ");
	scanf("%d", &num);
	if (rear == MAX) // �� ��
		printf("overflow �߻�");
	else if (front == -1 && rear == -1) // �� ť
		front = rear = 0;
	else
		rear++;
	queue[rear] = num;
}

int delete_element()
{
	int val;
	if (front == -1 || front > rear)
	{
		printf("\n underflow �߻�");
		return -1;
	}
	else
	{
		val = queue[front];
		front++;
		if (front > rear) // front�� �Ű��� �� front�� rear���� ũ�ٸ�, ������ �� ť�� �� ť�� �Ǵ� ��
			front = rear = -1;
		return val; // ���� �� �˷��ֱ�
	}
}

int peek()
{
	if (front == -1 || front > rear)
	{
		printf("\n ť�� �����.");
		return -1;
	}
	else
		return queue[front];
}

void display()
{
	int i;
	printf("\n");
	if (front == -1 || front > rear)
		printf("\n ť�� �����.");
	else
	{
		for (i = front; i <= rear; i++)
			printf("\t %d", queue[i]);
	}
}

int main()
{
	int option, val;
	do
	{
		printf("\n main menu");
		printf("\n 1.��� ���� 2. ��� ���� 3. peek 4. ť ��� ��� 5. ������");
		printf("\n �޴� �Է� : ");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			insert();
			break;
		case 2:
			val = peek();
			if (val != -1)
				printf("\n ������ �� : %d", val);
			break;
		case 3:
			val = peek();
			if (val != -1)
				printf("\n queue�� front : %d", val);
			break;
		case 4:
			display();
			break;
		}
	} while (option != 5);
	getch();
	return 0;
}