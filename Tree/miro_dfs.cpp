#include <stdio.h>

typedef struct xy {
	int x, y;
} XY;

int n, m;
char miro[105][105];
int check[105][105]; // 전역변수니까 처음에 다 0으로 초기화 되어있음

XY stack[10000];
int top = 0;

void push(XY t) {
	check[t.x][t.y] = 1;
	stack[top++] = t;
}

XY pop() {
	return stack[--top];
}

int main()
{
	int sx, sy;
	int fx, fy;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &miro[i][j]);
			if (miro[i][j] == 'S') {
				sx = i; sy = j;
			}

			if (miro[i][j] == 'F') {
				fx = i; fy = j;
			}
		}
	}

	XY start = { sx, sy };
	push(start);

	while (top > 0) {
		XY cur = stack[top - 1]; // POP은 안하겠습니다.

		if (cur.x == fx && cur.y == fy) {
			// 출력처리
			for (int i = 0; i < top; i++) {
				printf("(%d,%d) ", stack[i].x, stack[i].y);
			}
			printf("\n");
			break;
		}
		// current 기준으로 상하좌우 체크해서 있으면 push
		if (miro[cur.x + 1][cur.y] != '#' && check[cur.x + 1][cur.y] == 0) {
			push({ cur.x + 1, cur.y });
			continue;
		}
		if (miro[cur.x - 1][cur.y] != '#' && check[cur.x - 1][cur.y] == 0) {
			push({ cur.x - 1, cur.y });
			continue;
		}
		if (miro[cur.x][cur.y + 1] != '#' && check[cur.x][cur.y + 1] == 0) {
			push({ cur.x, cur.y + 1});
			continue;
		}
		if (miro[cur.x][cur.y - 1] != '#' && check[cur.x][cur.y - 1] == 0) {
			push({ cur.x, cur.y - 1 });
			continue;
		}

		pop();
	}
}