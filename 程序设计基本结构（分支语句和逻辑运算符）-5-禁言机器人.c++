#include<iostream>
using namespace std;
int a, b;
int main() {
	cin >> a >> b;
	cout << "该用户禁言时间为";
	if (a == 15 && b >= 30)cout << 125 - b;
	else if (a == 16 && b < 15)cout << 65 - b;
	else if (a == 16 && b >= 20)cout << 65 - b;
	else if (a == 17 && b < 5)cout << 5 - b;
	else cout << 0;
	cout << "分钟。" << endl;
	return 0;
}