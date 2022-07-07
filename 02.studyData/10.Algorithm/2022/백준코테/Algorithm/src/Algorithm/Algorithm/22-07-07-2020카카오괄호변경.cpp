#include <string>
#include <vector>
#include <iostream>

using namespace std;
bool check(string p) {
	int t;
	for (int i = 0; i < p.length(); i++) {
		if (p[i] == '(') t++;
		else {
			//��ȣ�� ���� ����
			if (!t)     return false;
			t--;
		}
	}
	return true;
}

string dfs(string p)
{
	//1. �Է��� �� ���ڿ��� ���, �� ���ڿ��� ��ȯ�մϴ�.
	if (p == "") return p;
	//	2. ���ڿ� w�� �� "�������� ��ȣ ���ڿ�" u, v�� �и��մϴ�.��, u�� "�������� ��ȣ ���ڿ�"�� �� �̻� �и��� �� ����� �ϸ�, v�� �� ���ڿ��� �� �� �ֽ��ϴ�.
	int rightopen = 0;// (
	int leftopen = 0; // )
	string u;
	string v;
	for (int i = 0; i < p.length(); i++) {
		if (p[i] == '(')rightopen++;
		if (p[i] == ')') leftopen++;
		u += p[i];
		if (rightopen + leftopen != 0 && rightopen == leftopen) {//U ã��
			for (int j = i + 1; j < p.size(); j++) {
				v += p[j];
				i++;
			}
			break;
		}
	}
	//	3. ���ڿ� u�� "�ùٸ� ��ȣ ���ڿ�" �̶�� ���ڿ� v�� ���� 1�ܰ���� �ٽ� �����մϴ�.
	//	3 - 1. ������ ��� ���ڿ��� u�� �̾� ���� �� ��ȯ�մϴ�.
	if (check(u))return u + dfs(v);
	//	4. ���ڿ� u�� "�ùٸ� ��ȣ ���ڿ�"�� �ƴ϶�� �Ʒ� ������ �����մϴ�.

	else {
		//�� ���ڿ��� "("�� ���δ�
		string temp = "(";
		//v�� ��ͼ����� ")"�� ���δ�
		temp += dfs(v) + ")";
		//u��  ���Ͼհ� ������ ���ڸ� ����
		u = u.substr(1, u.length() - 2);
		//���ڿ� ��ȣ ����
		for (int i = 0; i < u.length(); i++) {
			if (u[i] == '(')    temp += ')';
			else    temp += '(';
		}
		return temp;
	}
}


string solution(string p) {
	string answer = "";
	answer = dfs(p);
	return answer;
}

int main(void)
{
	cout << solution("()))((()");
	return 0;
}