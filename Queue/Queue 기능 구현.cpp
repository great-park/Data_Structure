# include<stdio.h>
# include<conio.h>
# define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void insert(void)
{
	int num;
	printf("\n 큐에 삽입할 숫자 입력 : ");
	scanf("%d", &num);
	if (rear == MAX) // 꽉 참
		printf("overflow 발생");
	else if (front == -1 && rear == -1) // 빈 큐
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
		printf("\n underflow 발생");
		return -1;
	}
	else
	{
		val = queue[front];
		front++;
		if (front > rear) // front를 옮겼을 때 front가 rear보다 크다면, 지웠을 때 큐가 빈 큐가 되는 것
			front = rear = -1;
		return val; // 지운 값 알려주기
	}
}

int peek()
{
	if (front == -1 || front > rear)
	{
		printf("\n 큐가 비었다.");
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
		printf("\n 큐가 비었다.");
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
		printf("\n 1.요소 삽입 2. 요소 삭제 3. peek 4. 큐 요소 출력 5. 끝내기");
		printf("\n 메뉴 입력 : ");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			insert();
			break;
		case 2:
			val = peek();
			if (val != -1)
				printf("\n 삭제한 값 : %d", val);
			break;
		case 3:
			val = peek();
			if (val != -1)
				printf("\n queue의 front : %d", val);
			break;
		case 4:
			display();
			break;
		}
	} while (option != 5);
	getch();
	return 0;
}