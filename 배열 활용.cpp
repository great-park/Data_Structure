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
		printf("----------주소록 메뉴------------------------------\n");
		printf("1) 목록보기    2) 추가   3) 검색   4) 삭제  5) 종료\n");
		printf("===================================================\n");
		int x;
		scanf("%d", &x);
		if (x == 1) {
			for (int i = 0; i < size; i++) {
				printf("이름: %s  전화번호: %s  주소: %s  생일: %s\n", book[i].name, book[i].num, book[i].address, book[i].birth);
			}
			if (size == 0) {
				printf("목록이 없습니다.\n");
			}
		}
		else if (x == 2) {
			printf("추가할 이름: "); scanf("%s", book[size].name);
			printf("추가할 전화번호: "); scanf("%s", book[size].num);
			printf("추가할 주소: "); scanf("%s", book[size].address);
			printf("추가할 생일: "); scanf("%s", book[size].birth);
			size++;
			printf("-----추가 완료-----\n");
		}
		else if(x==3){
			char s_name[20];
			printf("검색할 이름: ");
			scanf("%s", s_name);
			bool suc = false;
			for (int i = 0; i < size; i++) {
				if (strcmp(book[i].name, s_name) == 0) {
					printf("이름: %s  전화번호: %s  주소: %s  생일: %s\n", book[i].name, book[i].num, book[i].address, book[i].birth);
					suc = true;
				}
			}
			if (suc == false) {
				printf("검색결과가 없습니다.");
			}
		}
		else if (x == 4) {
			char d_name[20];
			printf("삭제할 이름: ");
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
			if (suc == false)printf("입력한 이름이 목록에 없습니다.\n");
			else {
				// 한 칸씩 떙기기
				size--;
				for (int i = delete_index; i < size; i++) {
					book[i] = book[i + 1];
				}
				printf("삭제 성공\n");
			}
		}
		else if (x == 5)break;
		printf("\n");
	}
	printf("프로그램을 종료합니다.\n");
}

