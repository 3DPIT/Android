#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
int main(void)
{
	vector<string> record = {{"abc ���̺� a��c"},{"a��c ���̺� abc"}};
	string key[3];

	for (auto& rec : record) {
		istringstream iss(rec);
		iss >> key[0] >> key[1] >> key[2] ;
		cout << key[0] << key[1] << endl;
	}
	return 0;
}