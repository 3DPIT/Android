#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
using namespace std;

vector<int>D;
vector<int> num;


void dfs(int cnt, int idx) {
	if (cnt == 6) {
		for (int i = 0; i < 6; i++) {
			printf("%d ", D[i]);
		}
		printf("\n");
		return;
	}

	// �ε��� ���� Ȯ��
	if (idx >= num.size()) {
		return;
	}

	// ���� �ε����� ���� ����
	D.push_back(num[idx]);
	dfs(cnt + 1, idx + 1);
	D.pop_back(); // ���� ���

	// ���� �ε����� ���� �������� ����
	dfs(cnt, idx + 1);
}


using namespace std;
int main(void)
{
	int numberCount = -1;

	while (1) {
		scanf("%d", &numberCount);
		if (numberCount == 0) break;
		int lottoNumber;
		for (int i = 0; i < numberCount; i++) {
			scanf("%d", &lottoNumber);
			num.push_back(lottoNumber);
		}
		sort(num.begin(), num.end());
		dfs(0, 0);
		num.clear();
		D.clear();
		printf("\n");
	}

	return 0;
}