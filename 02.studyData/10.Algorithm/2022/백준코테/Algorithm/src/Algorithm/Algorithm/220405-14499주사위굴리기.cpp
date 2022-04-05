#include<stdio.h>
#include<iostream>
using namespace std;
#define NS 21
#define MS 21
int board[NS][MS];
int ret;
int N, M, y, x, K;
int cube[7] = { 0, };//�ֻ��� ��� �ʱ� 0
int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };
void init()
{
	scanf("%d %d %d %d %d", &N, &M, &y, &x, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &board[i][j]);
		}
	}
}

void move(int dir) {
	if (dir == 0) {
		int copy = cube[1];
		cube[1] = cube[4];
		//cube[2] = cube[2];
		cube[4] = cube[6];
		cube[6] = cube[3];
		cube[3] = copy;
		//cube[5] = cube[5];
	}
	if (dir == 1)
	{
		int copy = cube[1];
		cube[1] = cube[3];
		//cube[2] = cube[2];
		cube[3] = cube[6];
		cube[6] = cube[4];
		cube[4] = copy;
		//cube[5] = cube[5];
	}
	if (dir == 2)
	{
		int copy = cube[1];
		cube[1] = cube[5];
		cube[5] = cube[6];
		cube[6] = cube[2];
		cube[2] = copy;
		//cube[3] = cube[3];
		//cube[4] = cube[4];

	}
	if (dir == 3)
	{
		int copy = cube[1];
		cube[1] = cube[2];
		cube[2] = cube[6];
		cube[6] = cube[5];
		cube[5] = copy;
		//cube[3] = cube[3];
		//cube[4] = cube[4];
	
	}
}

void play()
{
	int dir = 0;
	//1.�̵��ϱ�
	//2. �̵��� ĭ�� 0 �̸� �ֻ��� ���ڸ� ĭ�� ����
	//2.1 0�� �ƴѰ�� ĭ�� ���ڸ� �ֻ����� ����, �� ĭ�� ���ڴ� 0���� �ʱ�ȭ
	//3.�ٱ����δ� �̵��ȵ� �������� ��� ��� ����
	for (int k = 0; k < K; k++) {
		scanf("%d",&dir);
		dir--;
		int ny = y+dy[dir]; int nx =x+ dx[dir];
		if (ny < 0 || ny >= N || nx < 0 || nx >= M)continue;
		move(dir);//�ֻ��� ��ġ ����

		if (board[ny][nx] == 0) {
			board[ny][nx] = cube[6];
		}
		else if (board[ny][nx] != 0) {
			cube[6] = board[ny][nx];
			board[ny][nx] = 0;
		}
		y = ny; x = nx;
		cout << cube[1] << " ";
	}
}

int main(void)
{
	init();
	play();
	return 0;
}