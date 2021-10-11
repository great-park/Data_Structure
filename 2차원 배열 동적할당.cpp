#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	scanf("%d", &n);
	int x, y;
	int* numPtr = (int*)malloc(sizeof(int) * 2 * n);
	for (int i = 0; i < 2 * n; i += 2) {
		scanf("%d %d", &x, &y);
		*(numPtr + i) = x;
		*(numPtr + i + 1) = y;
	}
	

	return 0;
}