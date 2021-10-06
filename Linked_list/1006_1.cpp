# include<stdio.h>

struct student {
	int id;
	float gpa;
	struct student* love;
};

int main() {

	struct student chanho;
	struct student hahaha;

	chanho.id = 18160;
	chanho.gpa = 9.9;

	hahaha.id = 123412;
	hahaha.gpa = 7.7;

	chanho.love = &hahaha;


	printf("chanho.id의 주소값 : %p\n", &chanho.id);
	printf("chanho.gpa의 주소값 : %p\n", &chanho.gpa);
	printf("chanho.love의 주소값 : %p\n", &chanho.love);

	printf("hahaha.id의 주소값 : %p\n", &hahaha.id);
	printf("hahaha.gpa의 주소값 : %p\n", &hahaha.gpa);
	printf("hahaha.love의 주소값 : %p\n", &hahaha.love);

	printf("chanho.love 저장값 : %p, hahaha.love의 저장값 : %p\n", chanho.love, hahaha.love);

	printf("chaho.love의 id : %d\n", (*chanho.love).id);
	printf("chaho.love의 id 줄여쓰기 : %d\n", chanho.love ->id);
	
	if (chanho.love->love == &chanho) {
		printf("chanho의 True love");
	}
	else {
		printf("chanho의 짝사랑");
	}
	return 0;
}