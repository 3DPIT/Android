#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>halfPartGroup1;
vector<int>halfPartGroup2;

vector<int> partGroupMaker(int N, vector<int>arr) {
	vector<int>sumRet;
	for (int i = 0; i < (1 << N); i++) {

		int sum = 0;
		for (int k = 0; k < N; k++) {
			if (i&(1 << k)) {
				sum += arr[k];
			}
		}
		sumRet.push_back(sum);
	}

		sort(sumRet.begin(), sumRet.end());
		return sumRet;
}

int main(void)
{
	int N;
	long long S;
	cin >> N >> S;
	int m = N / 2;
	int n = N - m;
	vector<int> arr1;
	vector<int> arr2;	

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (n> i) {
			arr1.push_back(num);
		}
		else {
			arr2.push_back(num);
		}
	}
	reverse(arr2.begin(), arr2.end());
	
	halfPartGroup1=partGroupMaker(n, arr1);
	halfPartGroup2=partGroupMaker(m, arr2);

	int halfCheckNumber1[44];
	int halfCheckNumber2[44];

	for (int i = 0; i < n; i++) {
		halfCheckNumber1[halfPartGroup1[i]]++;
	}

	for (int i = 0; i < m; i++) {
		halfCheckNumber2[halfPartGroup2[i]]++;
	}

	int L = 0;
	long long ret = 0;
	n = 1 << n;
	m = 1 << m;
	int R = m - 1;

	while (L< n&&R>=0) {
		long sum = halfPartGroup1[L] + halfPartGroup2[R];
		if (sum > S) {
			R--;
		}
		else if (sum == S) {
		long num1 = 1;
		long num2 = 1;
			L++;
			R--;
			while (L < n && halfPartGroup1[L] == halfPartGroup1[L - 1]) {
				num1++;
				L++;
			}
			while (R >= 0 && halfPartGroup2[R] == halfPartGroup2[R+1]) {
				num2++;
				R--;
			}
			ret += num1 * num2;

		}
		else {
			L++;
		}
	}
	if(S==0) ret-=1;
	cout << ret << endl;

}


//#include<stdio.h>
//#include<iostream>
//#include<string.h>
//#include<vector>
//#include<algorithm>
//using namespace std;
//#define NS 41 //�ԷµǴ� �迭�� �ִ� ũ��
//int N;//�Է��� �迭�� ũ��
//long long S;//ã�ƾ��ϴ� ��
//int arr[NS];//�Էµ� ���ڰ� ����Ǵ� �迭
//long long int ret;//�����
//vector<int>leftV;//�߽��� �������� ������ �κ���
//vector<int>rightV;//�߽��� �������� �������� �κ���
//void init() {//�ʱ�ȭ �� �ʱ��Է� �Լ� 
//	N = S = ret = 0;
//	memset(arr, 0, sizeof(arr));
//	scanf("%d %lld", &N, &S);
//	for (int i = 0; i < N; i++) {
//		scanf("%d", &arr[i]);
//	}
//}
//int D[40];
//void dfs(int idx, int eidx, int sum, bool flag) {//�����ε���, ���ε���, ��, (0==L,1==R)
//	sum += arr[idx];
//	if (idx >= eidx)return;
//	if (flag == 0) {//���� 
//		if (S == sum)ret++;
//		leftV.push_back(sum);
//	}
//	if (flag == 1) {//������
//		if (S == sum)ret++;
//		rightV.push_back(sum);
//	}
//	dfs(idx + 1, eidx, sum - arr[idx], flag);
//	dfs(idx + 1, eidx, sum, flag);
//
//}
//void numSearch() {//�κм����� �� ��ġ
//	int m = (N / 2);
//	dfs(0, m, 0, 0);//���� ��
//	dfs(m, N, 0, 1);//������ ��
//
//	sort(leftV.begin(), leftV.end());
//
//	sort(rightV.begin(), rightV.end());
//	for (int i = 0; i < leftV.size(); i++) {
//		int num = S - leftV[i];
//		int low = lower_bound(rightV.begin(), rightV.end(), num) - rightV.begin();
//		int high = upper_bound(rightV.begin(), rightV.end(), num) - rightV.begin();
//		ret += (high - low);
//	}
//}
//int main(void) {
//	//���� N�� 1�϶� Ȯ��
//	init();
//	numSearch();
//	cout << ret << endl;
//	return 0;
//}
//
