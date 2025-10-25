#include<iostream>
using namespace std;
int n;
int main() {
	cin >> n;
	if (!cin.fail()) {
		cout << n << "年";
		if (n % 4 == 0 && n % 100 != 0 || n % 400 == 0)cout << "是闰年。";
		else cout << "不是闰年。";
	}
	else cout << "输入错误";
	return 0;
}