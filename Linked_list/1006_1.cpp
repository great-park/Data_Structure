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


	printf("chanho.id�� �ּҰ� : %p\n", &chanho.id);
	printf("chanho.gpa�� �ּҰ� : %p\n", &chanho.gpa);
	printf("chanho.love�� �ּҰ� : %p\n", &chanho.love);

	printf("hahaha.id�� �ּҰ� : %p\n", &hahaha.id);
	printf("hahaha.gpa�� �ּҰ� : %p\n", &hahaha.gpa);
	printf("hahaha.love�� �ּҰ� : %p\n", &hahaha.love);

	printf("chanho.love ���尪 : %p, hahaha.love�� ���尪 : %p\n", chanho.love, hahaha.love);

	printf("chaho.love�� id : %d\n", (*chanho.love).id);
	printf("chaho.love�� id �ٿ����� : %d\n", chanho.love ->id);
	
	if (chanho.love->love == &chanho) {
		printf("chanho�� True love");
	}
	else {
		printf("chanho�� ¦���");
	}
	return 0;
}