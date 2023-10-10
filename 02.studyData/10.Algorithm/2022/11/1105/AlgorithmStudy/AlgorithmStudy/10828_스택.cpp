#include<stdio.h>
#include<iostream>
#include<stack>
#include<string>
using namespace std;
stack<int>s;

void push(int X) {
	s.push(X);
}

void pop() {
	if (s.empty()) {
		cout << -1 << endl;
	}
	else {
		cout << s.top() << endl;
		s.pop();
	}
}

void size() {
	cout << s.size() << endl;
}

void empty() {
	if (s.empty()) cout << 1 << endl;
	else cout << 0 << endl;
}

void top() {
	if (s.empty()) cout << -1 << endl;
	else cout << s.top() << endl;
}

int main(void) {
	int N;
	string order; int X;
	cin >> N;
	while (N--) {
		cin>>order;
		if (order == "push") {
			cin >> X;
			push(X);
		}
		else if (order == "pop") {
			pop();
		}
		else if (order == "size") {
			size();
		}
		else if (order == "empty") {
			empty();
		}
		else if (order == "top") {
			top();
		}
	}
		//push X : ���� X�� ���ÿ� �ִ� �����̴�.
		//pop : ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�.���� ���ÿ� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
		//size : ���ÿ� ����ִ� ������ ������ ����Ѵ�.
		//empty : ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
		//top : ������ ���� ���� �ִ� ������ ����Ѵ�.���� ���ÿ� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
	return 0;
}