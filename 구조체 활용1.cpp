#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct book{
	char name[10];
	char phoneNum[15];
	char address[50];
	char birth[8];
} Book;

//ù��° ��� ������
Book* p = (Book*)malloc(sizeof(Book)*100);
//addȣ�⸶�� 1����
int count = 0;

void list() {
	if (count == 0)printf("��ϵ� �ּҷ��� �����ϴ�.\n");
	else {
		printf("\n1.�̸� 2.��ȭ��ȣ 3.�ּ� 4.���� \n\n");
		for (int i = 0; i < count; i++) {
			printf("�̸� :%s || ��ȭ��ȣ :%s || �ּ� :%s || ���� :%s\n\n", (p+i)->name, (p+i)->phoneNum, (p+i)->address, (p+i)->birth);
		}
	}
}

void add() {
	
	//���� �߰� 
	Book* someone = (p+count);
	printf("�̸� :");
	scanf("%s", someone->name);
	printf("\n��ȭ��ȣ :");
	scanf("%s", someone->phoneNum);
	printf("\n�ּ� :");
	scanf("%s", someone->address);
	printf("\n���� :");
	scanf("%s", someone->birth);
	printf("\n�߰��Ǿ����ϴ�.\n");
	count++;
}
void search() {
	char s_name[20];
	int fail = 1;
	printf("�˻��� �̸� :");
	scanf("%s", s_name);

	for (int i = 0; i < count; i++) {
		if (strcmp(s_name, (p + i)->name) == 0) {
			printf("\n�˻����\n�̸� :%s || ��ȭ��ȣ :%s || �ּ� :%s || ���� :%s\n\n", (p+i)->name, (p+i)->phoneNum, (p+i)->address, (p+i)->birth);
			fail = 0;
		}
	}
	if (fail == 1) {
		printf("\n�˻� ����� �����ϴ�.\n");
	}
}
void del() {
	char d_name[20];
	int fail = 1;
	printf("������ �̸� : ");
	scanf("%s", d_name);
	int delete_index;

	for (int i = 0; i < count; i++) {
		if (strcmp(d_name, (p + i)->name) == 0) {
			delete_index = i;
			fail = 0; break;
		}
	}
	if (fail == 1) {
		printf("\n�˻� ����� �����ϴ�.\n");
	}else{
		count--;
		for(int i = delete_index;i<count;i++){
			(p+i)->name = (p+i+1)->name;
		}
		
	}
}

int main() {
	int i = 0;
	int end = 0;
	while (end == 0) {
		printf("===========================================\n");
		printf("----------------�ּҷ� �޴�----------------\n");
		printf("1)��Ϻ���  2)�߰�  3)�˻�  4)����  5)����\n");
		printf("===========================================\n");
		
		scanf("%d", &i);
		switch (i){
		case 1:
			list();
			break;
		case 2:
			add();
			break;
		case 3:
			search();
			break;
		case 4:
			del();
			break;
		case 5:
			end = 1;
			break;
		default:
			printf("1~5 ���� �Է�");
			break;
		}
	}

	printf("���α׷��� �����մϴ�.");
	return 0;
}
