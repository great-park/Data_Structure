#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
typedef struct {
	char name[20];
	char num[20];
	char address[20];
	char birth[20];
} Book;
Book book[1000];
int size = 0;
int main()
{
	while (true) {
		printf("===================================================\n");
		printf("----------�ּҷ� �޴�------------------------------\n");
		printf("1) ��Ϻ���    2) �߰�   3) �˻�   4) ����  5) ����\n");
		printf("===================================================\n");
		int x;
		scanf("%d", &x);
		if (x == 1) {
			for (int i = 0; i < size; i++) {
				printf("�̸�: %s  ��ȭ��ȣ: %s  �ּ�: %s  ����: %s\n", book[i].name, book[i].num, book[i].address, book[i].birth);
			}
			if (size == 0) {
				printf("����� �����ϴ�.\n");
			}
		}
		else if (x == 2) {
			printf("�߰��� �̸�: "); scanf("%s", book[size].name);
			printf("�߰��� ��ȭ��ȣ: "); scanf("%s", book[size].num);
			printf("�߰��� �ּ�: "); scanf("%s", book[size].address);
			printf("�߰��� ����: "); scanf("%s", book[size].birth);
			size++;
			printf("-----�߰� �Ϸ�-----\n");
		}
		else if(x==3){
			char s_name[20];
			printf("�˻��� �̸�: ");
			scanf("%s", s_name);
			bool suc = false;
			for (int i = 0; i < size; i++) {
				if (strcmp(book[i].name, s_name) == 0) {
					printf("�̸�: %s  ��ȭ��ȣ: %s  �ּ�: %s  ����: %s\n", book[i].name, book[i].num, book[i].address, book[i].birth);
					suc = true;
				}
			}
			if (suc == false) {
				printf("�˻������ �����ϴ�.");
			}
		}
		else if (x == 4) {
			char d_name[20];
			printf("������ �̸�: ");
			scanf("%s", d_name);
			bool suc = false;
			int delete_index = -1;
			for (int i = 0; i < size; i++) {
				if (strcmp(book[i].name, d_name) == 0) {
					delete_index = i; 
					suc = true;
					break;
				}
			}
			if (suc == false)printf("�Է��� �̸��� ��Ͽ� �����ϴ�.\n");
			else {
				// �� ĭ�� �����
				size--;
				for (int i = delete_index; i < size; i++) {
					book[i] = book[i + 1];
				}
				printf("���� ����\n");
			}
		}
		else if (x == 5)break;
		printf("\n");
	}
	printf("���α׷��� �����մϴ�.\n");
}

