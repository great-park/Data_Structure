#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct addressBook {
	char name[20];
	char num[20];
	char address[20];
	char birth[20];
	struct addressBook* next;
} addressBook;

int main()
{
	addressBook* front = NULL, * end = NULL;

	while (true) {
		printf("===================================================\n");
		printf("----------�ּҷ� �޴�------------------------------\n");
		printf("1) ��Ϻ���    2) �߰�   3) �˻�   4) ����  5) ����\n");
		printf("===================================================\n");

		int x;
		scanf("%d", &x);
		if (x == 1) {
			for (addressBook* t = front; t != NULL; t = t->next){
				printf("�̸�: %s  ��ȭ��ȣ: %s  �ּ�: %s  ����: %s\n", t->name, t->num, t->address,t->birth);
			}
		}
		else if (x == 2) {
			if (end == NULL) {
				front= end = (addressBook*)malloc(sizeof(addressBook)); //���� ��� �߰�
				//front�� end �� �� ���� ��带 ����Ŵ
			}
			else{
				end->next = (addressBook*)malloc(sizeof(addressBook));
				end = end->next;

				//���ο� ��带 ����� end�� ��� ���� ��带 ����Ŵ
			}
			//end�� ������ �����̹Ƿ� -> ���
			printf("�߰��� �̸�: "); scanf("%s", end->name);
			printf("�߰��� ��ȭ��ȣ: "); scanf("%s", end->num);
			printf("�߰��� �ּ�: "); scanf("%s", end->address);
			printf("�߰��� ����: "); scanf("%s", end->birth);
			end->next = NULL;
		}
		else if (x == 3) {
			char s_name[20];
			printf("�˻��� �̸�: ");
			scanf("%s", s_name);

			addressBook* search_result = NULL;
			for (addressBook* t = front; t != NULL; t = t->next) {
				if (strcmp(t->name, s_name) == 0) {
					search_result = t; break;
				}
			}

			if (search_result == NULL) {
				printf("�˻������ �����ϴ�.\n");
			}
			else {
				printf("�̸�: %s  ��ȭ��ȣ: %s  �ּ�: %s  ����: %s\n", search_result->name, search_result->num, search_result->address, search_result->birth);
			}

		}
		else if (x == 4) {
			char d_name[20];
			printf("������ �̸�: ");
			scanf("%s", d_name);

			addressBook* delete_index = NULL, * delete_front=NULL;
			for (addressBook* t = front; t != NULL; t = t->next) {
				if (strcmp(t->name, d_name) == 0) {
					delete_index = t; break;
				}
				delete_front = t; // �ݺ����� �� ������ break�ǹǷ� delete_index���� �� ĭ ��(�ٷ� ���� �ܰ��� t�� front�� �޴� ��)

			}

			//�� �ڸ� ���ﶧ
			if (delete_index->next == NULL) {
				end = delete_front;  //�� �ڸ� ����� end�� �����ǹǷ�
			}
			//�� ���� ���ﶧ
			if (delete_front == NULL) {
				front = delete_index->next;
			}
			else{
				delete_front->next = delete_index->next;
			}
			free(delete_index);
		}
		else if (x == 5)break;
		printf("\n");
	}
	printf("���α׷��� �����մϴ�.\n");


	return 0;
}