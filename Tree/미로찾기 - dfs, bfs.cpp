#include <stdio.h>
#include <stdlib.h>
typedef struct xy {
	int x, y;
} XY;

typedef struct node {
	int value;
	struct node* left, * right;
} Node;

int n, m;
char miro[105][105];
int check[105][105];
XY Queue[10000];
int b_check[105][105];

int sx, sy;
int fx, fy;

int isPrint = 0;
//dfs
void dfs(int x, int y) 
{
	if (isPrint == 1) return;
	if (x < 0 || y < 0 || x >= n || y >= m) return;
	if (miro[x][y] == '#') return;
	if (check[x][y] == 1) return;

	check[x][y] = 1; // To do : 방문했던 순서로 만들기

	if (miro[x][y] == 'F') {
		//출력
		isPrint = 1;
		printf("dfs 결과");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				printf("%d", check[i][j]);
			}
			printf("\n");
		}
		/*exit(0);
		 isPrint 방식 대신 exit 함수 사용
		*/
		return;
	}
	
	// 조건문으로 #이 아닐때만 재귀 호출하는 식으로도 가능
	dfs(x + 1, y);
	dfs(x - 1, y);
	dfs(x, y + 1);
	dfs(x, y - 1);

	check[x][y] = 0;
}
int bfs()
{
	int front = 0, rear = 0;
	XY start = { sx,sy };
	Queue[rear++] = start;
	b_check[sx][sy] = 1;
	while (front != rear) {
		printf("bfs 결과");
		if (miro[Queue[front].x][Queue[front].y] == 'F') {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					printf("%3d", b_check[i][j]);
				}
				printf("\n");
			}
			return;
		}
		int tx, ty;
		tx = Queue[front].x + 1; ty = Queue[front].y;
		if (miro[tx][ty] != '#' && b_check[tx][ty] == 0 && (0 <= tx && tx < n && 0 <= ty && ty < m)) {
			Queue[rear].x = tx;
			Queue[rear].y = ty;
			rear++;
			b_check[tx][ty] = b_check[Queue[front].x][Queue[front].y] +1;
		}
		tx = Queue[front].x - 1; ty = Queue[front].y;
		if (miro[tx][ty] != '#' && b_check[tx][ty] == 0 && (0 <= tx && tx < n && 0 <= ty && ty < m)) {
			Queue[rear].x = tx;
			Queue[rear].y = ty;
			rear++;
			b_check[tx][ty] = 1;
		}
		tx = Queue[front].x; ty = Queue[front].y+1;
		if (miro[tx][ty] != '#' && b_check[tx][ty] == 0 && (0 <= tx && tx < n && 0 <= ty && ty < m)) {
			Queue[rear].x = tx;
			Queue[rear].y = ty;
			rear++;
			b_check[tx][ty] = 1;
		}
		tx = Queue[front].x; ty = Queue[front].y-1;
		if (miro[tx][ty] != '#' && b_check[tx][ty] == 0 && (0 <= tx && tx < n && 0 <= ty && ty < m)) {
			Queue[rear].x = tx;
			Queue[rear].y = ty;
			rear++;
			b_check[tx][ty] = 1;
		}

		front++;
	}

	printf("bfs 방법 존재하지 않는다.");
}


//bfs 재귀 방식
int main() 
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
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
	dfs(sx, sy);

	bfs();


}