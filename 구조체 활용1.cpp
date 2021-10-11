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

//첫번째 사람 포인터
Book* p = (Book*)malloc(sizeof(Book)*100);
//add호출마다 1증가
int count = 0;

void list() {
	if (count == 0)printf("등록된 주소록이 없습니다.\n");
	else {
		printf("\n1.이름 2.전화번호 3.주소 4.생일 \n\n");
		for (int i = 0; i < count; i++) {
			printf("이름 :%s || 전화번호 :%s || 주소 :%s || 생일 :%s\n\n", (p+i)->name, (p+i)->phoneNum, (p+i)->address, (p+i)->birth);
		}
	}
}

void add() {
	
	//끝에 추가 
	Book* someone = (p+count);
	printf("이름 :");
	scanf("%s", someone->name);
	printf("\n전화번호 :");
	scanf("%s", someone->phoneNum);
	printf("\n주소 :");
	scanf("%s", someone->address);
	printf("\n생일 :");
	scanf("%s", someone->birth);
	printf("\n추가되었습니다.\n");
	count++;
}
void search() {
	char s_name[20];
	int fail = 1;
	printf("검색할 이름 :");
	scanf("%s", s_name);

	for (int i = 0; i < count; i++) {
		if (strcmp(s_name, (p + i)->name) == 0) {
			printf("\n검색결과\n이름 :%s || 전화번호 :%s || 주소 :%s || 생일 :%s\n\n", (p+i)->name, (p+i)->phoneNum, (p+i)->address, (p+i)->birth);
			fail = 0;
		}
	}
	if (fail == 1) {
		printf("\n검색 결과가 없습니다.\n");
	}
}
void del() {
	char d_name[20];
	int fail = 1;
	printf("삭제할 이름 : ");
	scanf("%s", d_name);
	int delete_index;

	for (int i = 0; i < count; i++) {
		if (strcmp(d_name, (p + i)->name) == 0) {
			delete_index = i;
			fail = 0; break;
		}
	}
	if (fail == 1) {
		printf("\n검색 결과가 없습니다.\n");
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
		printf("----------------주소록 메뉴----------------\n");
		printf("1)목록보기  2)추가  3)검색  4)삭제  5)종료\n");
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
			printf("1~5 숫자 입력");
			break;
		}
	}

	printf("프로그램을 종료합니다.");
	return 0;
}
