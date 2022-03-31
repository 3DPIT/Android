#include<stdio.h>
#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
int N, M, result;
int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };
char boardPlate[11][11] = { 0, };//�Է¹迭
bool visit[11][11][11][11] = { 0, };//�湮 üũ
int finalY, finalX;
struct Data {
	int ry, rx, by, bx, moveCount;
}ball;
void init()
{
	memset(boardPlate, 0, sizeof(boardPlate));
	memset(visit, 0, sizeof(visit));
	N = M = finalY = finalX = 0;
	result = -1;//�ּҰ� ����

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %1c", &boardPlate[i][j]);
			if (boardPlate[i][j] == 'B') {
				ball.by = i;
				ball.bx = j;
				boardPlate[i][j] = '.';
			}
			else if (boardPlate[i][j] == 'R') {
				ball.ry = i;
				ball.rx = j;
				boardPlate[i][j] = '.';
			}
			else if (boardPlate[i][j] == 'O') {
				finalY = i;
				finalX = j;
			}
		}
	}
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < M; j++)
	//	{
	//		printf("%c ", boardPlate[i][j]);
	//	}
	//	printf("\n");
	//}
}
void play()
{
	queue<Data>q;
	q.push({ ball.ry,ball.rx,ball.by,ball.bx,0 });
	while (!q.empty())
	{
		ball = q.front(); q.pop();
		if (ball.moveCount > 10) {
			result = -1;
			break;
		}
		if (ball.ry == finalY && ball.rx == finalX && (ball.by != finalY && ball.bx != finalX))
		{
			result = ball.moveCount;
			break;
		}
		for (int dir = 0; dir < 4; dir++) {
			Data n = ball;
			n.moveCount = ball.moveCount;
			//������ �̵�
			n.ry = ball.ry;
			n.rx = ball.rx;
			int redCount = 0;
			while (1)
			{
				redCount++;
				n.ry += dy[dir];
				n.rx += dx[dir];
				if (boardPlate[n.ry][n.rx] == '#') {
					n.ry -= dy[dir];
					n.rx -= dx[dir];
					break;
				}
				if (boardPlate[n.ry][n.rx] == 'O') {
					break;
				}
			}
			//�Ķ��� �̵�
			n.by = ball.by;
			n.bx = ball.bx;
			int blueCount = 0;
			while (1)
			{
				blueCount++;
				n.by += dy[dir];
				n.bx += dx[dir];
				if (boardPlate[n.by][n.bx] == '#') {
					n.by -= dy[dir];
					n.bx -= dx[dir];
					break;
				}
				if (boardPlate[n.by][n.bx] == 'O') {
					break;
				}
			}

			if (n.ry == n.by&& n.rx == n.bx)//���� ��ġ�� ��� ī��Ʈ�� ª������ ������Ź
			{
				if (redCount < blueCount)//������ ���� ����
				{
					n.by -= dy[dir];
					n.bx -= dx[dir];
				}
				else if (redCount > blueCount)//�Ķ��� ���� ����
				{
					n.ry -= dy[dir];
					n.rx -= dx[dir];
				}
			}

			if (visit[n.ry][n.rx][n.by][n.bx] == 0) {
				visit[n.ry][n.rx][n.by][n.bx] = 1;//�湮 üũ
				n.moveCount++;
				q.push({ n.ry,n.rx,n.by,n.bx,n.moveCount });
			}
		}
	}
}
int main(void)
{
	init();
	play();
	printf("%d", result);
	return 0;
}