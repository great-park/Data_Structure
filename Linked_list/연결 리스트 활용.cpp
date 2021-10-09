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
		printf("----------주소록 메뉴------------------------------\n");
		printf("1) 목록보기    2) 추가   3) 검색   4) 삭제  5) 종료\n");
		printf("===================================================\n");

		int x;
		scanf("%d", &x);
		if (x == 1) {
			for (addressBook* t = front; t != NULL; t = t->next){
				printf("이름: %s  전화번호: %s  주소: %s  생일: %s\n", t->name, t->num, t->address,t->birth);
			}
		}
		else if (x == 2) {
			if (end == NULL) {
				front= end = (addressBook*)malloc(sizeof(addressBook)); //시작 노드 추가
				//front와 end 둘 다 시작 노드를 가리킴
			}
			else{
				end->next = (addressBook*)malloc(sizeof(addressBook));
				end = end->next;

				//새로운 노드를 만들고 end가 방금 만든 노드를 가리킴
			}
			//end는 포인터 변수이므로 -> 사용
			printf("추가할 이름: "); scanf("%s", end->name);
			printf("추가할 전화번호: "); scanf("%s", end->num);
			printf("추가할 주소: "); scanf("%s", end->address);
			printf("추가할 생일: "); scanf("%s", end->birth);
			end->next = NULL;
		}
		else if (x == 3) {
			char s_name[20];
			printf("검색할 이름: ");
			scanf("%s", s_name);

			addressBook* search_result = NULL;
			for (addressBook* t = front; t != NULL; t = t->next) {
				if (strcmp(t->name, s_name) == 0) {
					search_result = t; break;
				}
			}

			if (search_result == NULL) {
				printf("검색결과가 없습니다.\n");
			}
			else {
				printf("이름: %s  전화번호: %s  주소: %s  생일: %s\n", search_result->name, search_result->num, search_result->address, search_result->birth);
			}

		}
		else if (x == 4) {
			char d_name[20];
			printf("삭제할 이름: ");
			scanf("%s", d_name);

			addressBook* delete_index = NULL, * delete_front=NULL;
			for (addressBook* t = front; t != NULL; t = t->next) {
				if (strcmp(t->name, d_name) == 0) {
					delete_index = t; break;
				}
				delete_front = t; // 반복문이 윗 블럭에서 break되므로 delete_index보다 한 칸 앞(바로 이전 단계의 t를 front가 받는 것)

			}

			//맨 뒤를 지울때
			if (delete_index->next == NULL) {
				end = delete_front;  //맨 뒤를 지우면 end가 실종되므로
			}
			//맨 앞을 지울때
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
	printf("프로그램을 종료합니다.\n");


	return 0;
}