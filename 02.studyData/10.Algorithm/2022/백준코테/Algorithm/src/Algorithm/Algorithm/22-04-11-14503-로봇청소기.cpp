#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#define NS 51
using namespace std;
int N, M, ret;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
int board[NS][NS];
struct pos {
	int y, x, dir;
}robot;

void init() {
	N = M = ret = 0;
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &robot.y, &robot.x, &robot.dir);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &board[i][j]);
		}
	}
}

void cleanRoom()
{
	ret = 1;
	while (1)// û�� ����
	{
		if (board[robot.y][robot.x] == 0) {
			board[robot.y][robot.x] = ++ret;
		}

		int idx = 0;
		int y = robot.y, x = robot.x;
		int dir = robot.dir;
		for (idx = 0; idx < 4; idx++) {
			dir--;
			if (dir == -1) dir = 3;
			pos next;
			next.y = y + dy[dir];
			next.x = x + dx[dir];
			if (board[next.y][next.x] == 0) { // û�� ������ �ִ°�� ȸ���� ����
				robot.y = next.y;
				robot.x = next.x;
				robot.dir = dir;
				break;
			}
		}

		if (idx == 4)// û�ұ����� ���� ��� ���� �Ǵ� ����
		{
			pos prev;
			prev.y = robot.y - dy[dir];
			prev.x = robot.x - dx[dir];
			if (board[prev.y][prev.x] != 1)// ���� �ƴ� ��� ����
			{
				robot.y = prev.y;
				robot.x = prev.x;
			}
			else if (board[prev.y][prev.x] == 1)// ���� ��� ����
			{
				break;
			}
		}
	}
}
int main(void)
{
	init();
	cleanRoom();
	printf("%d", ret-1);
	return 0;
}