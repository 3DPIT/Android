

//������ �÷��� �Ӹ� ����ĭ
//�̵�ĭ ���. ������ ��� ���� ���� �̵� ����
//�̵�ĭ ��� ������ ������ �ٿ��� ������ ��ġ�� ĭ ���


#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#define NS 104

using namespace std;
int board[NS][NS];
int N,K,L;
int X;
char C;

void init() {
	cin >> N >> K;
	for (int k = 0; k < K; k++) {
		int y, x;
		cin >> y >> x;
		board[y][x] = -1;
	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	return 0;
}